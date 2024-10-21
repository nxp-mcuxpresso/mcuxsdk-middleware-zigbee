# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Needed external symbols (provided by app config cmake file)
# ZIGBEE_BASE_DIR          - Path to Zigbee repo
# CONFIG_ZBPRO_DEVICE_TYPE - Zigbee Pro device type: ZCR/ZED

# General Include and Source
mcux_add_source(
    BASE_PATH ${NXP_ZB_BASE}
    SOURCES BDB/Source/Common/*.*
)
mcux_add_include(
    BASE_PATH ${NXP_ZB_BASE}
    INCLUDES BDB/Include
             BDB/Source/Common/
)

# Zigbee Pro device type
if(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZCR")
    mcux_add_configuration(CC "-DZBPRO_DEVICE_TYPE_ZCR")
elseif(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZED")
    mcux_add_configuration(CC "-DZBPRO_DEVICE_TYPE_ZED")
else()
    message(FATAL_ERROR "ZBPRO_DEVICE_TYPE must be set to either ZCR or ZED")
endif()

# Feature Specific Includes and Sources
if (CONFIG_ZB_BDB_SUPPORT_NWK_STEERING)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/NwkSteering/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/NwkSteering/
    )
    mcux_add_macro(BDB_SUPPORT_NWK_STEERING)
endif()

if (CONFIG_ZB_BDB_SUPPORT_NWK_FORMATION)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/NwkFormation/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/NwkFormation/
    )
    mcux_add_macro(BDB_SUPPORT_NWK_FORMATION)
endif()

if (CONFIG_ZB_BDB_SUPPORT_FIND_AND_BIND_INITIATOR)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/FindAndBind/bdb_fb_initiator.c
                BDB/Source/FindAndBind/bdb_fb_common.c
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/FindAndBind/
    )
    mcux_add_macro(BDB_SUPPORT_FIND_AND_BIND_INITIATOR)
endif()

if (CONFIG_ZB_BDB_SUPPORT_FIND_AND_BIND_TARGET)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/FindAndBind/bdb_fb_target.c
                BDB/Source/FindAndBind/bdb_fb_common.c
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/FindAndBind/
    )
    mcux_add_macro(BDB_SUPPORT_FIND_AND_BIND_TARGET)
endif()

if (CONFIG_ZB_BDB_SUPPORT_OUT_OF_BAND)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/OutOfBand/bdb_DeviceCommissioning.h
                BDB/Source/OutOfBand/bdb_DeviceCommissioning.c
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/OutOfBand/
    )
    mcux_add_macro(BDB_SUPPORT_OOBC)
endif()

if (CONFIG_ZB_BDB_SUPPORT_TOUCHLINK_ED)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/TouchLink/bdb_tl_end_device_initiator_target.c
                BDB/Source/TouchLink/bdb_tl_common.c
                BDB/Source/TouchLink/ecb_decrypt.c
                BDB/Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if (CONFIG_ZB_BDB_SUPPORT_TOUCHLINK_ROUTER)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/TouchLink/bdb_tl_router_initiator_target.c
                BDB/Source/TouchLink/bdb_tl_common.c
                BDB/Source/TouchLink/ecb_decrypt.c
                BDB/Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if (CONFIG_ZB_BDB_SUPPORT_TOUCHLINK_INITIATOR)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/TouchLink/bdb_tl_router_target.c
                BDB/Source/TouchLink/bdb_tl_common.c
                BDB/Source/TouchLink/ecb_decrypt.c
                BDB/Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if (CONFIG_ZB_BDB_SUPPORT_TRANSPORT_KEY_DECIDER)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES BDB/Source/TransportKeyDecider/*.*
    )
    mcux_add_include(
        BASE_PATH ${NXP_ZB_BASE}
        INCLUDES BDB/Source/TransportKeyDecider/
    )
    mcux_add_macro(BDB_SET_DEFAULT_TC_POLICY)
endif()
