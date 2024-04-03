# Copyright 2023 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)  # CMake version check
project(zb_coord_linux)               # Create project

if ("${NXP_NCP_ROOT}" STREQUAL "")
    set(NXP_NCP_ROOT "../../../..")
endif()

set(FWK_PATH "${NXP_NCP_ROOT}/framework")
set(ZIGBEE_PATH "${NXP_NCP_ROOT}/zigbee")

message(STATUS "Using FWK root path " ${FWK_PATH})
message(STATUS "Using ZB root path " ${ZIGBEE_PATH})

set(PDUM_LIB_NAME PDUM_NCP)
set(PDUM_LIB_PATH ${ZIGBEE_PATH}/examples/zigbee_coordinator/build_linux/out)

find_library(PDUM_LIB_FOUND ${PDUM_LIB_NAME} PATHS ${PDUM_LIB_PATH})
if (NOT PDUM_LIB_FOUND)
    message(STATUS "PDUM NCP Library not found. Creating it...")

    # Create library
    include(CreatePDUMLib.cmake)
else()
    message(STATUS "PDUM NCP Library found at: ${PDUM_LIB_FOUND}")

    # Add library target
    add_library(PDUM_NCP STATIC IMPORTED)
    set_target_properties(PDUM_NCP PROPERTIES IMPORTED_LOCATION "${PDUM_LIB_FOUND}")
endif()


# Add main.cpp file of project root directory as source file
set(COORDINATOR_NCP_SOURCES
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/linux/pdum_gen_glue.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/linux/linux_glue.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/linux/app_node.c

    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/app_coordinator.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/app_main.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/app_start.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/app_zcl_task.c
    ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/app_serial_commands.c

    ${ZIGBEE_PATH}/examples/zb_common/app_console.c
    ${ZIGBEE_PATH}/examples/zb_common/app_uart.c
    ${ZIGBEE_PATH}/examples/zb_common/app_crypto.c
    ${ZIGBEE_PATH}/examples/zb_common/app_zigbee_config.c
    ${ZIGBEE_PATH}/examples/zb_common/app_ota_server.c
    ${ZIGBEE_PATH}/examples/zb_common/serial_link_ctrl.c
    ${ZIGBEE_PATH}/examples/zb_common/serial_link_cmds_ctrl.c
    ${ZIGBEE_PATH}/examples/zb_common/serial_link_ctrl_linux.c
    ${ZIGBEE_PATH}/examples/zb_common/app_leds.c

    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDM/Source/Posix/PDM_adapter.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/framework/OtaSupport/Source/Posix/OtaSupport_adapter.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/console.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/uart.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/glue.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/leds.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/crypto.c
    ${ZIGBEE_PATH}/platform/NCP_HOST/platform/Posix/timer.c

    ${ZIGBEE_PATH}/BDB/Source/Common/bdb_start.c
    ${ZIGBEE_PATH}/BDB/Source/Common/bdb_state_machine.c
    ${ZIGBEE_PATH}/BDB/Source/Common/bdb_fr.c
    ${ZIGBEE_PATH}/BDB/Source/Common/bdb_start.c

    ${ZIGBEE_PATH}/BDB/Source/FindAndBind/bdb_fb_common.c
    ${ZIGBEE_PATH}/BDB/Source/FindAndBind/bdb_fb_common.c
    ${ZIGBEE_PATH}/BDB/Source/FindAndBind/bdb_fb_initiator.c
    ${ZIGBEE_PATH}/BDB/Source/FindAndBind/bdb_fb_target.c

    ${ZIGBEE_PATH}/BDB/Source/NwkFormation/bdb_nf.c
    ${ZIGBEE_PATH}/BDB/Source/NwkFormation/bdb_nf.h
    ${ZIGBEE_PATH}/BDB/Source/NwkFormation/

    ${ZIGBEE_PATH}/BDB/Source/NwkSteering/bdb_ns.c

    ${ZIGBEE_PATH}/ZigbeeCommon/Source/appZdpExtraction.c
    ${ZIGBEE_PATH}/ZigbeeCommon/Source/ZTimer.c
    ${ZIGBEE_PATH}/ZigbeeCommon/Source/ZQueue.c
    ${ZIGBEE_PATH}/ZigbeeCommon/Source/appZpsBeaconHandler.c
    ${ZIGBEE_PATH}/ZigbeeCommon/Source/appZpsExtendedDebug.c
    ${ZIGBEE_PATH}/ZigbeeCommon/Source/app_zps_link_keys.c

    ${ZIGBEE_PATH}/ZCL/Devices/ZHA/Generic/Source/base_device.c

    ${ZIGBEE_PATH}/ZCIF/Source/dlist.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_CustomCommandReceive.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_CustomCommandSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_PDUbufferReadWrite.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_PDUbufferReadWriteString.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_WriteAttributesRequestHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_WriteAttributesRequestSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_WriteAttributesResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_attribute.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_buffer.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_clusterCommand.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_command.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_common.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_configureReportingCommandHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_configureReportingCommandSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_configureReportingResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_defaultResponse.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesExtendedRequestHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesExtendedRequestSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesExtendedResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesRequestHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesRequestSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverAttributesResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverCommandsRequestHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverCommandsRequestSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_discoverCommandsResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_event.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_heap.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_library_options.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readAttributesRequestHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readAttributesRequestSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readAttributesResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readReportingConfigurationCommandHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readReportingConfigurationCommandSend.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_readReportingConfigurationResponseHandle.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_reportManager.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_reportMaths.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_reportScheduler.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_reportStringHandling.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_reportStructure.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_search.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_timer.c
    ${ZIGBEE_PATH}/ZCIF/Source/zcl_transmit.c

    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/Basic.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/BasicCommandHandler.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/BasicClientCommands.c

    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/Identify.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/IdentifyCommandHandler.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/IdentifyClientCommands.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/IdentifyServerCommands.c

    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/Groups.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/GroupsClientCommands.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/GroupsCommandHandler.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/GroupsServerCommands.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/GroupsTableManager.c

    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/OnOff.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/OnOffCommandHandler.c
    ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/OnOffCommands.c

    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA_common.c
    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA_CustomCommandHandler.c
    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA_CustomReceiveCommands.c
    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA_server.c
    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA_ServerUpgradeManager.c
    ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source/OTA.c
)

# Add executable target
add_executable(zb_coord_linux ${COORDINATOR_NCP_SOURCES})

if ("${MACHINE}" STREQUAL "imx8")
    message(WARNING "Cross-compiling for ${MACHINE}")
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    target_compile_options(zb_coord_linux PRIVATE
        -Wno-implicit-function-declaration
        -Wno-format
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
        -Wno-int-conversion
    )
else()
    message(WARNING "Compiling for x86")
    target_compile_options(zb_coord_linux PRIVATE
        -O0
        -g3
        -ggdb
        -m32
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
    )

    target_compile_options(zb_coord_linux
        PRIVATE
            -include ${CMAKE_CURRENT_SOURCE_DIR}/../src/linux/linux_glue.h
    )
    target_link_options(zb_coord_linux PUBLIC -m32)
endif()

target_include_directories(zb_coord_linux
    PUBLIC
        ${ZIGBEE_PATH}/examples/zigbee_coordinator/src/linux

        ${ZIGBEE_PATH}/examples/zigbee_coordinator/src
        ${ZIGBEE_PATH}/platform
        ${ZIGBEE_PATH}/platform/NCP_HOST/ieee-802.15.4
        ${ZIGBEE_PATH}/platform/NCP_HOST/framework/Common
        ${ZIGBEE_PATH}/platform/NCP_HOST/framework/OtaSupport/Interface
        ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDUM/Include
        ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PDM/Interface
        ${ZIGBEE_PATH}/platform/NCP_HOST/framework/PWRM/Include
        ${ZIGBEE_PATH}/platform/NCP_HOST/platform
        ${ZIGBEE_PATH}/platform/NCP_HOST/misc
        ${ZIGBEE_PATH}/platform/K32W1/framework/SecLib

        ${ZIGBEE_PATH}/examples/zb_common

        ${ZIGBEE_PATH}/ZigbeeCommon/Include
        ${ZIGBEE_PATH}/BDB/Include
        ${ZIGBEE_PATH}/BDB/Source/Common
        ${ZIGBEE_PATH}/BDB/Source/NwkSteering
        ${ZIGBEE_PATH}/BDB/Source/FindAndBind
        ${ZIGBEE_PATH}/BDB/Source/NwkFormation
        ${ZIGBEE_PATH}/BDB/Source/OutOfBand

        ${ZIGBEE_PATH}/ZCIF/Include
        ${ZIGBEE_PATH}/ZCIF/Source
        ${ZIGBEE_PATH}/ZCL/Devices/ZHA/Generic/Include

        ${ZIGBEE_PATH}/ZCL/Clusters/General/Include
        ${ZIGBEE_PATH}/ZCL/Clusters/General/Source/
        ${ZIGBEE_PATH}/ZCL/Clusters/Commissioning/Include

        ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Include
        ${ZIGBEE_PATH}/ZCL/Clusters/OTA/Source

        ${ZIGBEE_PATH}/ZPSAPL/Include
        ${ZIGBEE_PATH}/ZPSMAC/Include
        ${ZIGBEE_PATH}/ZPSNWK/Include
        ${ZIGBEE_PATH}/ZPSTSV/Include

        ${FWK_PATH}/Common
        ${FWK_PATH}/SecLib
)

target_compile_definitions(zb_coord_linux
    PRIVATE
        NCP_HOST
        TRACE_SERIAL=1
        TRACE_ZCL=1
        DEBUG_ZQUEUE=1
        TRACE_REMOTE_ECHO=1
        DEBUG_BDB=1
        SINGLE_CHANNEL=13
        TRACE_APP=1
        LITTLE_ENDIAN_PROCESSOR=1
        SERIAL_BAUD_RATE=B1000000
)

target_link_libraries(zb_coord_linux rt pthread m ${PDUM_LIB_NAME})


