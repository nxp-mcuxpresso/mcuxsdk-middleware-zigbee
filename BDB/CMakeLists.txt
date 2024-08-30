# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_common)
    mcux_add_source(
        SOURCES Source/Common/bdb_fr.c
                Source/Common/bdb_fr.h
                Source/Common/bdb_start.c
                Source/Common/bdb_start.h
                Source/Common/bdb_state_machine.c
                Include/bdb_api.h
    )
    mcux_add_include(
        INCLUDES Source/Common
        INCLUDES Include
    )

endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_nwksteering)
    mcux_add_source(
        SOURCES Source/NwkSteering/bdb_ns.h
                Source/NwkSteering/bdb_ns.c
    )
    mcux_add_include(
        INCLUDES Source/NwkSteering/
    )
    mcux_add_macro(BDB_SUPPORT_NWK_STEERING)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_nwkformation)
    mcux_add_source(
        SOURCES Source/NwkFormation/bdb_nf.h
                Source/NwkFormation/bdb_nf.c
    )
    mcux_add_include(
        INCLUDES Source/NwkFormation/
    )
    mcux_add_macro(BDB_SUPPORT_NWK_FORMATION)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_findbind_initiator)
    mcux_add_source(
        SOURCES Source/FindAndBind/bdb_fb_api.h
                Source/FindAndBind/bdb_fb_initiator.c
                Source/FindAndBind/bdb_fb_common.c
    )
    mcux_add_include(
        INCLUDES Source/FindAndBind/
    )
    mcux_add_macro(BDB_SUPPORT_FIND_AND_BIND_INITIATOR)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_findbind_target)
    mcux_add_source(
        SOURCES Source/FindAndBind/bdb_fb_api.h
                Source/FindAndBind/bdb_fb_target.c
                Source/FindAndBind/bdb_fb_common.c
    )
    mcux_add_include(
        INCLUDES Source/FindAndBind/
    )
    mcux_add_macro(BDB_SUPPORT_FIND_AND_BIND_TARGET)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_outofband)
    mcux_add_source(
        SOURCES Source/OutOfBand/bdb_DeviceCommissioning.h
                Source/OutOfBand/bdb_DeviceCommissioning.c
    )
    mcux_add_include(
        INCLUDES Source/OutOfBand/
    )
    mcux_add_macro(BDB_SUPPORT_OOBC)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_touchlink_initiator_ed)
    mcux_add_source(
        SOURCES Source/TouchLink/bdb_tl_end_device_initiator_target.c
                Source/TouchLink/bdb_tl_common.c
                Source/TouchLink/ecb_decrypt.c
                Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        INCLUDES Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_touchlink_initiator_router)
    mcux_add_source(
        SOURCES Source/TouchLink/bdb_tl_router_initiator_target.c
                Source/TouchLink/bdb_tl_common.c
                Source/TouchLink/ecb_decrypt.c
                Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        INCLUDES Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_touchlink_initiator_target)
    mcux_add_source(
        SOURCES Source/TouchLink/bdb_tl_router_target.c
                Source/TouchLink/bdb_tl_common.c
                Source/TouchLink/ecb_decrypt.c
                Source/TouchLink/bdb_tl.h
    )
    mcux_add_include(
        INCLUDES Source/TouchLink/
    )
    mcux_add_macro(BDB_SUPPORT_TOUCHLINK)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.bdb_transport_keydecider)
    mcux_add_source(
        SOURCES Source/TransportKeyDecider/bdb_tkd.c
                Source/TransportKeyDecider/bdb_tkd.h
    )
    mcux_add_include(
        INCLUDES Source/TransportKeyDecider
    )
    mcux_add_macro(BDB_SET_DEFAULT_TC_POLICY)
endif()
