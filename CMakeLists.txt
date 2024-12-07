# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(C64Raspico C CXX ASM)
set(CMAKE_C_STANDARD 11)   #
set(CMAKE_CXX_STANDARD 17) #

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(C64Raspico C64Raspico.cpp)

pico_set_program_name(C64Raspico "C64Raspico")
pico_set_program_version(C64Raspico "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(C64Raspico 1)
pico_enable_stdio_usb(C64Raspico 0)

# Add the standard library to the build
target_link_libraries(C64Raspico
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(C64Raspico PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/..
)

pico_generate_pio_header(C64Raspico ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

# Add any user requested libraries
target_link_libraries(C64Raspico pico_stdlib)

pico_add_extra_outputs(C64Raspico)

target_include_directories(C64Raspico PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries
(
    C64Raspico 
    pico_cyw43_arch_lwip_treadsafe_background 
    pico_stdlib 
    hardware_pwm 
    hardware_i2C
)

