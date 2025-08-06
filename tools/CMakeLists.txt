# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.tools)
    mcux_add_source(
        SOURCES JET/win/*.*
                PDUMConfig/Source/PDUMConfig
                PDUMConfig/Source/PDUMConfig.py
                ZPSConfig/Source/ZPSConfig
                ZPSConfig/Source/ZPSConfig.py
                OTA/*.*
                OTA/SB3/*.*
                OTA/keys_and_certs/*.*
                memsize2/*.*
    )
endif()
