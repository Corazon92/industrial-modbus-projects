#pragma once

#include <cstdint>
#include <vector>

namespace modbus {

std::uint16_t crc16(const std::vector<std::uint8_t>& bytes);

std::vector<std::uint8_t> build_read_holding_registers(
    std::uint8_t slave,
    std::uint16_t first_register,
    std::uint16_t register_count
);

std::vector<std::uint8_t> build_write_single_register(
    std::uint8_t slave,
    std::uint16_t register_address,
    std::uint16_t value
);

}  // namespace modbus
