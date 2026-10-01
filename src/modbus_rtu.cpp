#include "modbus_rtu.hpp"

#include <stdexcept>

namespace {

void append_u16_be(std::vector<std::uint8_t>& frame, std::uint16_t value) {
    frame.push_back(static_cast<std::uint8_t>(value >> 8));
    frame.push_back(static_cast<std::uint8_t>(value & 0xFF));
}

void append_crc(std::vector<std::uint8_t>& frame) {
    const auto checksum = modbus::crc16(frame);
    frame.push_back(static_cast<std::uint8_t>(checksum & 0xFF));
    frame.push_back(static_cast<std::uint8_t>(checksum >> 8));
}

}  // namespace

namespace modbus {

std::uint16_t crc16(const std::vector<std::uint8_t>& bytes) {
    std::uint16_t crc = 0xFFFF;

    for (const auto byte : bytes) {
        crc ^= byte;
        for (int bit = 0; bit < 8; ++bit) {
            const bool least_significant_bit = (crc & 0x0001U) != 0;
            crc >>= 1;
            if (least_significant_bit) {
                crc ^= 0xA001U;
            }
        }
    }

    return crc;
}

std::vector<std::uint8_t> build_read_holding_registers(
    std::uint8_t slave,
    std::uint16_t first_register,
    std::uint16_t register_count
) {
    if (register_count == 0 || register_count > 125) {
        throw std::invalid_argument("register_count must be between 1 and 125");
    }

    std::vector<std::uint8_t> frame{slave, 0x03};
    append_u16_be(frame, first_register);
    append_u16_be(frame, register_count);
    append_crc(frame);
    return frame;
}

std::vector<std::uint8_t> build_write_single_register(
    std::uint8_t slave,
    std::uint16_t register_address,
    std::uint16_t value
) {
    std::vector<std::uint8_t> frame{slave, 0x06};
    append_u16_be(frame, register_address);
    append_u16_be(frame, value);
    append_crc(frame);
    return frame;
}

}  // namespace modbus
