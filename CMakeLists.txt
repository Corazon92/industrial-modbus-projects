cmake_minimum_required(VERSION 3.16)
project(industrial_modbus_gateway LANGUAGES CXX)

add_library(modbus_rtu src/modbus_rtu.cpp)
target_include_directories(modbus_rtu PUBLIC include)
target_compile_features(modbus_rtu PUBLIC cxx_std_17)

add_executable(modbus_rtu_tests tests/modbus_rtu_tests.cpp)
target_link_libraries(modbus_rtu_tests PRIVATE modbus_rtu)

enable_testing()
add_test(NAME modbus_rtu_tests COMMAND modbus_rtu_tests)
