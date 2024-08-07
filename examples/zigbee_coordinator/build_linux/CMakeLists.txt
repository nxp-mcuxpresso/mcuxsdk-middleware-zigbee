# Copyright 2023-2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.13)  # CMake version check

set(MBEDTLS_MIN_VERSION "2.28" CACHE STRING "")
message(STATUS "Setting mbedtls minimum required version: ${MBEDTLS_MIN_VERSION}")

if("${CONFIG_ZB_SINGLE_CHANNEL}" STREQUAL "")
    set(CONFIG_ZB_SINGLE_CHANNEL "13" CACHE STRING "Force the channel to be used.")
endif()

if ("${NXP_SDK_BASE}" STREQUAL "")
    set(NXP_ZB_BASE_RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/../../..)
    get_filename_component(NXP_ZB_BASE ${NXP_ZB_BASE_RELATIVE} ABSOLUTE)
    get_filename_component(NXP_SDK_BASE ${NXP_ZB_BASE}/../../.. ABSOLUTE)
else()
    #not implemented for now
endif()

# Determine whether the SDK used is the github repo, a package or the internal repo
if(EXISTS ${NXP_SDK_BASE}/core/)
    message(STATUS "Found MCUXPRESSO SDK GITHUB")
    message(STATUS "Using SDK root path " ${NXP_SDK_BASE})
    set(NXP_SDK_TYPE "GITHUB")
elseif(EXISTS ${NXP_SDK_BASE}/bin/generator)
    message(STATUS "Found MCUXPRESSO SDK internal")
    message(STATUS "Using SDK root path " ${NXP_SDK_BASE})
    set(NXP_SDK_TYPE "INTERNAL")
elseif(EXISTS ${NXP_SDK_BASE}/SW-Content-Register.txt)
    message(STATUS "Found MCUXPRESSO SDK")
    message(STATUS "Using SDK root path " ${NXP_SDK_BASE})
    set(NXP_SDK_TYPE "PACKAGE")
else()
    set(NXP_SDK_TYPE "NONE")
endif()
message(STATUS "Using Zigbee root path " ${NXP_ZB_BASE})

# Use toolchain file
if ("${MACHINE}" STREQUAL "imx8")
    include(${NXP_ZB_BASE}/platform/NCP_HOST/cmake/toolchains/arm-linux-gnueabihf.cmake)
    message(WARNING "Cross-compiling for imx8")
    set(MACHINE_TYPE imx8 CACHE INTERNAL "imx8")
else()
    include(${NXP_ZB_BASE}/platform/NCP_HOST/cmake/toolchains/x86_64-linux-gnu.cmake)
    message(WARNING "Compiling for x86")
endif()
enable_language(C CXX ASM)

# Function for mbedtls validation
include(${NXP_ZB_BASE}/platform/NCP_HOST/cmake/utils.cmake)

project(zb_coord_linux)               # Create project

set(ENV_MBEDTLS_ORIGIN $ENV{MBEDTLS_ORIGIN})
if("${ENV_MBEDTLS_ORIGIN}" STREQUAL "")
    if ("${NXP_SDK_TYPE}" STREQUAL "NONE")
        use_mbedtls_as_package()
    else()
        set(MBEDTLS_VALID "YES")
        check_mbedtls_is_valid(MBEDTLS_VALID)
        if ("${MBEDTLS_VALID}" STREQUAL "YES")
            set(MBEDTLS_ORIGIN "SDK")
            set(MBEDTLS_INCLUDE ${NXP_SDK_BASE}/middleware/mbedtls/include/)
        else()
            message(FATAL_ERROR "")
        endif()
    endif()
elseif("${ENV_MBEDTLS_ORIGIN}" STREQUAL "SDK")
    message(STATUS "Using mbedtls from SDK")
    set(MBEDTLS_ORIGIN "SDK")
    set(MBEDTLS_INCLUDE ${NXP_SDK_BASE}/middleware/mbedtls/include/)
elseif("${ENV_MBEDTLS_ORIGIN}" STREQUAL "GIT")
    message(STATUS "Using mbedtls from GIT")
    set(MBEDTLS_ORIGIN "GIT")
    set(MBEDTLS_INCLUDE )
elseif("${ENV_MBEDTLS_ORIGIN}" STREQUAL "SYSTEM")
    use_mbedtls_as_package()
else()
    message(STATUS "Valid options for environment variable MBEDTLS_ORIGIN options are: SDK,GIT,SYSTEM")
    message(FATAL_ERROR "Usage example: `export MBEDTLS_ORIGIN=SDK`, `export MBEDTLS_ORIGIN=GIT` OR `export MBEDTLS_ORIGIN=SYSTEM`")
endif()

set(PDUM_LIB_PATH ${PROJECT_BINARY_DIR}/pdum/lib/libpdum.a)
set(CRYPTO_USE_MBEDTLS "CRYPTO_USE_MBEDTLS")

set(NXP_NCP_HOST_COORDINATOR_INCLUDES

    # Coordinator includes
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/linux
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src

    # Platform specific includes
    ${NXP_ZB_BASE}/platform
    ${NXP_ZB_BASE}/platform/NCP_HOST/ieee-802.15.4
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/Common
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/OtaSupport/Interface
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDUM/Include
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDM/Interface
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PWRM/Include
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/SecLib/Interface
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform

    # Zigbee module specific includes
    ${NXP_ZB_BASE}/examples/zb_common
    ${NXP_ZB_BASE}/ZigbeeCommon/Include
    ${NXP_ZB_BASE}/BDB/Include
    ${NXP_ZB_BASE}/BDB/Source/Common
    ${NXP_ZB_BASE}/BDB/Source/NwkSteering
    ${NXP_ZB_BASE}/BDB/Source/FindAndBind
    ${NXP_ZB_BASE}/BDB/Source/NwkFormation
    ${NXP_ZB_BASE}/BDB/Source/OutOfBand

    ${NXP_ZB_BASE}/ZCIF/Include
    ${NXP_ZB_BASE}/ZCIF/Source
    ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Include

    ${NXP_ZB_BASE}/ZCL/Clusters/General/Include
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/
    ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Include

    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Include
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source

    ${NXP_ZB_BASE}/ZPSAPL/Include
    ${NXP_ZB_BASE}/ZPSMAC/Include
    ${NXP_ZB_BASE}/ZPSNWK/Include
    ${NXP_ZB_BASE}/ZPSTSV/Include
)

set(NXP_NCP_HOST_COORDINATOR_SOURCES
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/linux/pdum_gen_glue.c

    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/app_coordinator_ncp.c
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/app_main.c
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/app_start.c
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/app_zcl_task.c
    ${NXP_ZB_BASE}/examples/zigbee_coordinator/src/app_serial_commands.c

    ${NXP_ZB_BASE}/examples/zb_common/app_console.c
    ${NXP_ZB_BASE}/examples/zb_common/app_uart.c
    ${NXP_ZB_BASE}/examples/zb_common/app_crypto.c
    ${NXP_ZB_BASE}/examples/zb_common/app_zigbee_config_ncp.c
    ${NXP_ZB_BASE}/examples/zb_common/app_ota_server.c
    ${NXP_ZB_BASE}/examples/zb_common/serial_link_ctrl.c
    ${NXP_ZB_BASE}/examples/zb_common/serial_link_cmds_ctrl.c
    ${NXP_ZB_BASE}/examples/zb_common/serial_link_ctrl_linux.c

    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/PDM/Source/Posix/PDM_adapter.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/framework/OtaSupport/Source/Posix/OtaSupport_adapter.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/console.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/uart.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/glue.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/leds.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/crypto.c
    ${NXP_ZB_BASE}/platform/NCP_HOST/platform/Posix/timer.c

    ${NXP_ZB_BASE}/BDB/Source/Common/bdb_start.c
    ${NXP_ZB_BASE}/BDB/Source/Common/bdb_state_machine.c
    ${NXP_ZB_BASE}/BDB/Source/Common/bdb_fr.c
    ${NXP_ZB_BASE}/BDB/Source/Common/bdb_start.c

    ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_common.c
    ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_common.c
    ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_initiator.c
    ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_target.c

    ${NXP_ZB_BASE}/BDB/Source/NwkFormation/bdb_nf.c
    ${NXP_ZB_BASE}/BDB/Source/NwkFormation/bdb_nf.h
    ${NXP_ZB_BASE}/BDB/Source/NwkFormation/

    ${NXP_ZB_BASE}/BDB/Source/NwkSteering/bdb_ns.c

    ${NXP_ZB_BASE}/ZigbeeCommon/Source/port_linux.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZdpExtraction.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/ZTimer.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/ZQueue.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZpsBeaconHandler.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZpsExtendedDebug.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/app_zps_link_keys.c

    ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/base_device.c

    ${NXP_ZB_BASE}/ZCIF/Source/dlist.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_CustomCommandReceive.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_CustomCommandSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_PDUbufferReadWrite.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_PDUbufferReadWriteString.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesRequestHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesRequestSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_attribute.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_buffer.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_clusterCommand.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_command.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_common.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingCommandHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingCommandSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_defaultResponse.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedRequestHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedRequestSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesRequestHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesRequestSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsRequestHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsRequestSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_event.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_heap.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_library_options.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesRequestHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesRequestSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationCommandHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationCommandSend.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationResponseHandle.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportManager.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportMaths.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportScheduler.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportStringHandling.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportStructure.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_search.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_timer.c
    ${NXP_ZB_BASE}/ZCIF/Source/zcl_transmit.c

    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Basic.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BasicCommandHandler.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BasicClientCommands.c

    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Identify.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyCommandHandler.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyClientCommands.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyServerCommands.c

    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Groups.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsClientCommands.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsCommandHandler.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsServerCommands.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsTableManager.c

    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOff.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOffCommandHandler.c
    ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOffCommands.c

    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_common.c
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_CustomCommandHandler.c
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_CustomReceiveCommands.c
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_server.c
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_ServerUpgradeManager.c
    ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA.c
)

# Build pdum library
include("${NXP_ZB_BASE}/platform/NCP_HOST/cmake/pdum.cmake")

# Build mbedtls library
if (MBEDTLS_ORIGIN STREQUAL "SDK")
    include("${NXP_ZB_BASE}/platform/NCP_HOST/cmake/mbedtls_sdk.cmake")
elseif(MBEDTLS_ORIGIN STREQUAL "GIT")
    include("${NXP_ZB_BASE}/platform/NCP_HOST/cmake/mbedtls_git.cmake")
endif()

# Add executable target
add_executable(zb_coord_linux ${NXP_NCP_HOST_COORDINATOR_SOURCES})

if ("${MACHINE_TYPE}" STREQUAL "imx8")
     target_compile_options(zb_coord_linux PRIVATE
        -Wno-implicit-function-declaration
        -Wno-format
        -Wno-incompatible-pointer-types
        -Wno-discarded-qualifiers
        -Wno-int-conversion
    )
else()
    target_compile_options(zb_coord_linux PRIVATE
        -O0
        -g3
        -ggdb
        -m32
    )

    target_link_options(zb_coord_linux PUBLIC -m32)
endif()

target_include_directories(zb_coord_linux
    PUBLIC
    ${NXP_NCP_HOST_COORDINATOR_INCLUDES}
    ${thirdparty_inc_public}
    ${MBEDTLS_INCLUDE}
)

target_compile_options(zb_coord_linux
    PRIVATE
        -include ${CMAKE_CURRENT_SOURCE_DIR}/../src/linux/linux_glue.h
)
target_compile_definitions(zb_coord_linux
    PRIVATE
        NCP_HOST
        TRACE_SERIAL=1
        TRACE_ZCL=1
        DEBUG_ZQUEUE=1
        TRACE_REMOTE_ECHO=1
        DEBUG_BDB=1
        SINGLE_CHANNEL=${CONFIG_ZB_SINGLE_CHANNEL}
        TRACE_APP=1
        LITTLE_ENDIAN_PROCESSOR=1
        SERIAL_BAUD_RATE=B1000000
        ${CRYPTO_USE_MBEDTLS}
)

if(MBEDTLS_ORIGIN STREQUAL "SDK")
    #Make sure mbedtls is built before executable
    add_dependencies(zb_coord_linux ${mbedtls_target})

    set(MBEDTLS_LIB_PATH ${PROJECT_BINARY_DIR}/mbedtls/library/libmbedcrypto.a)
    set(MBEDTLS_LIB_NAME mbedcrypto)

    add_library(mbedcrypto STATIC IMPORTED)
    set_target_properties(mbedcrypto PROPERTIES IMPORTED_LOCATION ${MBEDTLS_LIB_PATH})
endif()

if(MBEDTLS_ORIGIN STREQUAL "GIT")
    #Make sure mbedtls is built before executable
    add_dependencies(zb_coord_linux ${mbedtls_target})

    set(MBEDTLS_LIB_NAME ${PROJECT_BINARY_DIR}/mbedtls/library/libmbedcrypto.a)
endif()

add_library(pdum STATIC IMPORTED)
set_target_properties(pdum PROPERTIES IMPORTED_LOCATION ${PDUM_LIB_PATH})

target_link_libraries(zb_coord_linux rt pthread m pdum ${MBEDTLS_LIB_NAME})


