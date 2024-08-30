# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

CMAKE_MINIMUM_REQUIRED (VERSION 3.10.0)
if (DEFINED MCUX_DEVICE AND NOT (DEFINED CONFIG_DEVICE))
string (REGEX MATCH "^[A-Za-z0-9]+" CONFIG_DEVICE ${MCUX_DEVICE})
string (REGEX REPLACE "${CONFIG_DEVICE}_" "" CONFIG_CORE ${MCUX_DEVICE})
message("MCUX_DEVICE ${MCUX_DEVICE}")
message("CONFIG_DEVICE ${CONFIG_DEVICE}")
message("CONFIG_CORE ${CONFIG_CORE}")
endif()

list(APPEND CMAKE_MODULE_PATH
    ${NXP_SDK_CORE}/devices/${CONFIG_DEVICE}
)

if(EXISTS ${NXP_SDK_CORE}/devices/${CONFIG_DEVICE}/all_lib_device.cmake)
    include(all_lib_device)
elseif (DEFINED MCUX_DEVICE)
    include("all_lib_device_${MCUX_DEVICE}")
endif()
