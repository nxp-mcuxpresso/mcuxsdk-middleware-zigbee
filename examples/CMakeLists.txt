# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.examples_common)
    mcux_add_source(
        SOURCES zb_common/PDM_IDs.h
                zb_common/app_leds.c
                zb_common/app_zigbee_config.c
                zb_common/app_buttons.c
                zb_common/app_leds.h
                zb_common/app_buttons.h
                zb_common/app_console.c
                zb_common/app_uart.c
                zb_common/app_crypto.c
                zb_common/app_common.h
                zb_common/app_console.h
                zb_common/app_uart.h
                zb_common/app_crypto.h
                zb_common/app_common.h
                zb_common/app_signals.c
                zb_common/app_signals.h
    )
    mcux_add_include(
        INCLUDES zb_common
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.freertos_common)
    mcux_add_source(
        SOURCES zb_common/app_freertos_hooks.c
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.examples_common_ota_client)
    mcux_add_source(
        SOURCES zb_common/app_ota_client.c
                zb_common/app_ota_client.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.examples_common_ota_server)
    mcux_add_source(
        SOURCES zb_common/app_ota_server.c
                zb_common/app_ota_server.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.ncp_host)
    mcux_add_source(
        SOURCES zb_common/app_common_ncp.h
                zb_common/app_zigbee_config_ncp.c
                zb_common/serial_link_cmds_ctrl.c
                zb_common/serial_link_cmds_ctrl.h
                zb_common/serial_link_ctrl_linux.c
                zb_common/serial_link_ctrl.c
                zb_common/serial_link_ctrl.h
                ../ZigbeeCommon/source/port_linux.c
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.serial_link_wkr)
    mcux_add_source(
        SOURCES zb_common/serial_link_cmds_wkr.c
                zb_common/serial_link_cmds_wkr.h
                zb_common/serial_link_wkr.c
                zb_common/serial_link_wkr.h
    )
endif()