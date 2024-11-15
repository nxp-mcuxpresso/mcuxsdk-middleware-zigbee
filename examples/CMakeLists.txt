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

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.ncp_host_examples_collaterals)
    mcux_add_source(
        SOURCES zb_common/app_common_ncp.h
                zb_common/app_zigbee_config_ncp.c
                zb_common/serial_link_cmds_ctrl.c
                zb_common/serial_link_cmds_ctrl.h
                zb_common/serial_link_ctrl_linux.c
                zb_common/serial_link_ctrl.c
                zb_common/serial_link_ctrl.h
                zb_common/linux/**
                ../ZigbeeCommon/Source/port_linux.c
                ../ZigbeeCommon/Include/portmacro_linux.h
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

if (CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.ncp_host_examples)
    mcux_add_source(
        SOURCES zigbee_coordinator/src/linux/**
                zigbee_coordinator/build_linux/**
                zigbee_coordinator/src/app_main.c
                zigbee_coordinator/src/app_main.h
                zigbee_coordinator/src/app_coordinator_ncp.c
                zigbee_coordinator/src/app_coordinator.h
                zigbee_coordinator/src/app_serial_commands.c
                zigbee_coordinator/src/app_serial_commands.h
                zigbee_coordinator/src/app_start.c
                zigbee_coordinator/src/app_zcl_task.c
                zigbee_coordinator/src/app_zcl_task.h
                zigbee_coordinator/src/bdb_options.h
                zigbee_coordinator/src/pdum_gen.h
                zigbee_coordinator/src/zcl_options.h
                zigbee_coordinator/src/zigbee_config.h
                zigbee_coordinator/src/zps_gen.h
                zigbee_coordinator/src/app_main.c
                zigbee_router/src/linux/**
                zigbee_router/build_linux/**
                zigbee_router/src/app_router_node_ncp.c
                zigbee_router/src/app_main.c
                zigbee_router/src/app_main.h
                zigbee_router/src/app_reporting.c
                zigbee_router/src/app_reporting.h
                zigbee_router/src/app_router_node.h
                zigbee_router/src/app_serial_commands.c
                zigbee_router/src/app_serial_commands.h
                zigbee_router/src/app_start.c
                zigbee_router/src/app_zcl_task.c
                zigbee_router/src/app_zcl_task.h
                zigbee_router/src/bdb_options.h
                zigbee_router/src/pdum_gen.h
                zigbee_router/src/zcl_options.h
                zigbee_router/src/zigbee_config.h
                zigbee_router/src/zps_gen.h
    )
endif()
