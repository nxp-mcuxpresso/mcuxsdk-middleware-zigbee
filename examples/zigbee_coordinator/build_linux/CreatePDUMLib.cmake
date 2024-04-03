# Copyright 2023 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)  # CMake version check

# Source files to create PDUM library
set(PDUM_SOURCES
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Source/pdum.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c
)

# Add library target
add_library(PDUM_NCP STATIC ${PDUM_SOURCES})

if ("${MACHINE}" STREQUAL "imx8")
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    target_compile_options(PDUM_NCP PRIVATE
        -Wno-implicit-function-declaration
        -Wno-format
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
        -Wno-int-conversion
    )
else()
    target_compile_options(PDUM_NCP PRIVATE
        -Wno-format
        -m32
    )
endif()

target_link_options(PDUM_NCP PUBLIC -m32)

target_include_directories(PDUM_NCP PUBLIC
    ${ZIGBEE_PATH}/platform
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/Common
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Include
)
target_compile_definitions(PDUM_NCP PRIVATE
    JENNIC_CHIP=JN5189
    JENNIC_CHIP_JN5189
    JENNIC_CHIP_NAME=_JN5189
    JENNIC_CHIP_FAMILY=JN518x
    JENNIC_CHIP_FAMILY_JN518x
    JENNIC_CHIP_FAMILY_NAME=_JN518x
    JN5189=5189
    JN518x=5189
    JENNIC_STACK_MAC
    JENNIC_MAC_MiniMac
    CPU_K32W1480VFTA
    K32W1
    SERIAL_PORT_TYPE_UART=1
    LITTLE_ENDIAN_PROCESSOR
)