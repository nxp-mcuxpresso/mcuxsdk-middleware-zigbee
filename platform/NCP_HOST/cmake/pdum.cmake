# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)  # CMake version check

set(NCPHOST_JENNIC_CHIP_FAMILY "JN518x")
set(NCPHOST_JENNIC_CHIP "JN5189")
set(NCPHOST_JENNIC_STACK "MAC")
set(NCPHOST_JENNIC_MAC "MiniMac")

# Add library target
add_library(ncphost-PDUM
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c
)
set_target_properties(ncphost-PDUM
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/pdum/lib"
)

if ("${MACHINE_TYPE}" STREQUAL "imx8")
    target_compile_options(ncphost-PDUM PRIVATE
        -Wno-implicit-function-declaration
        -Wno-format
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
        -Wno-int-conversion
    )
else()
    target_compile_options(ncphost-PDUM PRIVATE
        -Wno-format
        -m32
    )
    target_link_options(ncphost-PDUM PUBLIC -m32)
endif()

target_compile_definitions(ncphost-PDUM
    PRIVATE
        JENNIC_CHIP=${NCPHOST_JENNIC_CHIP}
        JENNIC_CHIP_${NCPHOST_JENNIC_CHIP}
        JENNIC_CHIP_NAME=_${NCPHOST_JENNIC_CHIP}
        JENNIC_CHIP_FAMILY=${NCPHOST_JENNIC_CHIP_FAMILY}
        JENNIC_CHIP_FAMILY_${NCPHOST_JENNIC_CHIP_FAMILY}
        JENNIC_CHIP_FAMILY_NAME=_${NCPHOST_JENNIC_CHIP_FAMILY}
        ${NCPHOST_JENNIC_CHIP}=5189
        ${NCPHOST_JENNIC_CHIP_FAMILY}=5189
        JENNIC_STACK_${NCPHOST_JENNIC_STACK}
        JENNIC_MAC_${NCPHOST_JENNIC_MAC}
)

target_include_directories(ncphost-PDUM
    PUBLIC
        ${NXP_ZB_BASE}/platform
        ${NXP_ZB_BASE}/platform/NCP_HOST/framework/Common
        ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Include
)
