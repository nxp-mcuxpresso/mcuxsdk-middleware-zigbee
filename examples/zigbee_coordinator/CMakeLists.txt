# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.24)
find_package(NxpZb REQUIRED HINTS $ENV{NXP_ZB_BASE})
project(zb_coordinator VERSION 1.0.0)

# zb_app is created by the find_package() command, all linkage to NXP Zigbee interface is handled transparently
target_sources(zb_app PRIVATE
    ../zb_common/app_buttons.c
    ../zb_common/app_leds.c
    ../zb_common/app_ota_server.c
    ../zb_common/app_console.c
    ../zb_common/app_uart.c
    ../zb_common/app_zigbee_config.c
    ../zb_common/app_crypto.c
    src/app_coordinator.c
    src/app_start.c
    src/app_zcl_task.c
    src/pdum_apdu.S
    src/app_serial_commands.c
    src/zps_gen.c
    src/pdum_gen.c
    src/app_main.c
)

nxp_zb_include_directories(
    ../zb_common
    src
)

nxp_zb_compile_definitions(
    gMainThreadStackSize_c=4096
    gMainThreadPriority_c=OSA_PRIORITY_LOW
    SERIAL_MANAGER_TASK_PRIORITY=OSA_PRIORITY_BELOW_NORMAL
    TM_TASK_PRIORITY=OSA_PRIORITY_NORMAL
    FSL_OSA_TASK_ENABLE=1
    FSL_OSA_MAIN_FUNC_ENABLE=1
    gAppLedCnt_c=2
)

if(CONFIG_ZB_USE_FREERTOS)
    target_sources(zb_app PRIVATE
        ../zb_common/app_freertos_hooks.c
    )
    # Use nxp_zb_include_directories to expose FreeRTOSConfig.h to zb_interface
    nxp_zb_include_directories(
        src/freertos
    )
endif()

if(CONFIG_ZB_TRACE_APP)
    nxp_zb_compile_definitions(TRACE_APP=1)
endif()

if(CONFIG_ZB_TRACE_ZCL)
    nxp_zb_compile_definitions(TRACE_ZCL=1)
endif()

nxp_zb_generate_zpsconfig(${CMAKE_CURRENT_SOURCE_DIR}/src/coordinator.zpscfg "coordinator" ${CMAKE_CURRENT_SOURCE_DIR}/src)
nxp_zb_generate_pdumconfig(${CMAKE_CURRENT_SOURCE_DIR}/src/coordinator.zpscfg "coordinator" ${CMAKE_CURRENT_SOURCE_DIR}/src)
