#include "modbus_rtu.hpp"

#include <cassert>
#include <cstdint>
#include <vector>

int main() {
    const std::vector<std::uint8_t> request_without_crc{
        0x01, 0x03, 0x00, 0x00, 0x00, 0x0A
    };
    assert(modbus::crc16(request_without_crc) == 0xCDC5);

    const std::vector<std::uint8_t> expected_read{
        0x01, 0x03, 0x00, 0x00, 0x00, 0x0A, 0xC5, 0xCD
    };
    assert(modbus::build_read_holding_registers(1, 0, 10) == expected_read);

    const auto write = modbus::build_write_single_register(1, 2, 250);
    assert(write.size() == 8);
    assert(write[0] == 0x01);
    assert(write[1] == 0x06);
    assert(write[2] == 0x00 && write[3] == 0x02);
    assert(write[4] == 0x00 && write[5] == 0xFA);

    const std::vector<std::uint8_t> write_payload(write.begin(), write.end() - 2);
    const auto write_crc = modbus::crc16(write_payload);
    assert(write[6] == static_cast<std::uint8_t>(write_crc & 0xFF));
    assert(write[7] == static_cast<std::uint8_t>(write_crc >> 8));
}
