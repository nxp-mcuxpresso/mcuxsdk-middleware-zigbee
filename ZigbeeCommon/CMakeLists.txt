# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.core_common)
    mcux_add_source(
        SOURCES Source/app_zps_link_keys.c
                Source/appZdpExtraction.c
                Source/appZpsBeaconHandler.c
                Source/appZpsExtendedDebug.c
                Source/ZQueue.c
                Source/ZTimer.c
                Source/port_JN518x.c
                Source/tlv.c
                ../ZPSAPL/Include/zps_apl.h
                ../ZPSAPL/Include/zps_apl_af.h
                ../ZPSAPL/Include/zps_apl_aib.h
                ../ZPSAPL/Include/zps_apl_aps.h
                ../ZPSAPL/Include/zps_apl_zdo.h
                ../ZPSAPL/Include/zps_apl_zdp.h
                ../ZPSMAC/Include/zps_mac.h
                ../ZPSMAC/Include/mac_vs_sap.h
                ../ZPSMAC/Include/zps_mac_if_table.h
                ../ZPSMAC/Include/zps_mac_prv.h
                ../ZPSNWK/Include/zps_nwk_config.h
                ../ZPSNWK/Include/zps_nwk_mac_sap.h
                ../ZPSNWK/Include/zps_nwk_nib.h
                ../ZPSNWK/Include/zps_nwk_pub.h
                ../ZPSNWK/Include/zps_nwk_sap.h
                ../ZPSNWK/Include/zps_nwk_sec.h
                ../ZPSNWK/Include/zps_nwk_slist.h
                ../ZPSTSV/Include/zps_tsv.h
                Include/appZdpExtraction.h
                Include/appZpsBeaconHandler.h
                Include/ZQueue.h
                Include/ZTimer.h
                Include/portmacro_JN518x.h
                Include/tlv.h
    )
    mcux_add_include(
        INCLUDES Include
                 ../ZPSAPL/Include
                 ../ZPSMAC/Include
                 ../ZPSNWK/Include
                 ../ZPSTSV/Include
    )
endif()
