cmake_minimum_required(VERSION 3.12)

set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(console)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()
add_executable(console main.c console.c command.c)

target_link_libraries(console pico_stdlib pico_multicore)
pico_add_extra_outputs(console)

pico_enable_stdio_uart(console 1)
pico_enable_stdio_usb(console 1)
