# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)  # CMake version check

set(pdum_target "pdum_static" CACHE STRING "Name of pdum target")

# Source files to create PDUM library
set(PDUM_SOURCES
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c
)
 
# Add library target
add_library(${pdum_target} STATIC ${PDUM_SOURCES})
set_target_properties(${pdum_target} PROPERTIES OUTPUT_NAME pdum)

set_target_properties(${pdum_target}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/pdum/lib"
)

if ("${MACHINE}" STREQUAL "imx8")
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    target_compile_options(${pdum_target} PRIVATE
        -Wno-implicit-function-declaration
        -Wno-format
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
        -Wno-int-conversion
    )
else()
    target_compile_options(${pdum_target} PRIVATE
        -Wno-format
        -m32
    )
endif()

target_link_options(${pdum_target} PUBLIC -m32)

target_include_directories(${pdum_target} PUBLIC
    ${NXP_ZB_BASE}/platform
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/Common
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Include
)
target_compile_definitions(${pdum_target} PRIVATE
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