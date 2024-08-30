# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.tools)
    mcux_add_source(
        SOURCES Eclipse_plugins/*.*
                JET/win/*.*
                PDUMConfig/Source/PDUMConfig
                PDUMConfig/Source/PDUMConfig.py
                Zigbee3ConfigEditor/*.*
                ZPSConfig/Source/ZPSConfig
                ZPSConfig/Source/ZPSConfig.py
                OTA/*.*
                OTA/SB3/*.*
                OTA/keys_and_certs/*.*
    )
endif()
