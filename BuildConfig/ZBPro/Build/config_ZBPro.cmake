# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Needed external symbols (provided by app config cmake file)
# ZIGBEE_BASE_DIR       - Path to Zigbee repo
# CONFIG_ZB_MAC_TYPE    - Default value MAC
# CONFIG_ZB_ZCP         - Default value off
# CONFIG_ZB_NODE_NAME   - Node name
# CONFIG_ZB_ZPSCFG      - zpscfg file to be used
# ZPSCONFIG             - Path to ZPSCONFIG tool


if((NOT DEFINED CONFIG_ZB_NODE_NAME) OR (NOT DEFINED CONFIG_ZB_ZPSCFG) OR (NOT DEFINED ZPSCONFIG))
    message(FATAL_ERROR "CONFIG_ZB_NODE_NAME & CONFIG_ZB_ZPSCFG & ZPSCONFIG must be set")
endif()

if (NOT DEFINED CONFIG_ZB_MAC_TYPE)
    set(CONFIG_ZB_MAC_TYPE "SOC" CACHE STRING "")
endif()

# Platform & OSA specific configs
include (${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/build/device.cmake)
include (${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/build/platform.cmake)

# Zigbee Common Sources
mcux_add_source(
    BASE_PATH ${NXP_ZB_BASE}
    SOURCES ZigbeeCommon/Source/ZQueue.c
            ZigbeeCommon/Source/ZTimer.c
            ZigbeeCommon/Source/app_zps_link_keys.c
            ZigbeeCommon/Source/appZdpExtraction.c
            ZigbeeCommon/Source/appZpsBeaconHandler.c
            ZigbeeCommon/Source/appZpsExtendedDebug.c
            ZigbeeCommon/Source/port_JN518x.c
)

if(CONFIG_ZB_R23)
    mcux_add_source(
        BASE_PATH ${NXP_ZB_BASE}
        SOURCES ZigbeeCommon/Source/tlv.c
    )
endif()

# Zigbee Common Includes
mcux_add_include(
    BASE_PATH ${NXP_ZB_BASE}
    INCLUDES ZigbeeCommon/Include
            ZPSAPL/Include
            ZPSMAC/Include
            ZPSNWK/Include
            ZPSTSV/Include
            ZPSAPL/Source
            ZPSAPL/Source/ZDO
            ZPSAPL/Source/AF
            ZPSAPL/Source/APS
            ZPSAPL/Source/ZDP
            ZPSNWK/Source
            SerialMAC/Include
)

# Trace mode
if (CONFIG_ZB_TRACE)
    mcux_add_configuration(CC "-DDBG_ENABLE")
    mcux_add_configuration(CC "-DDEBUG_ENABLE")
    message(STATUS "Building trace version ...")
endif()

# ZBPro specific defines
mcux_add_configuration(
    CC "-DENABLE_RAM_VECTOR_TABLE\
        -DPDM_USER_SUPPLIED_ID\
        -DPDM_NO_RTOS\
        -DZIGBEE_USE_FRAMEWORK=1"
)

set(CONFIG_ZB_ZPSTSV_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSTSV.a)

# Find the suitable ZPSAPL lib to use
if(CONFIG_ZB_WWAH)
    set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_WWAH.a)
    mcux_add_configuration(CC "-DWWAH_SUPPORT")
else()
    if(CONFIG_ZB_LEGACY)
        if(CONFIG_ZB_ZCP)
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_LEGACY_ZCP-GU.a)
            mcux_add_configuration(CC "-DZCP=1")
        else()
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_LEGACY.a)
        endif()
        mcux_add_configuration(CC "-DLEGACY_SUPPORT")
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_R23.a)
            mcux_add_configuration(CC "-DR23_UPDATES=1")
            mcux_add_configuration(CC "-DPDM_BUFFER_SIZE=4096")
        else()
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL.a)
            mcux_add_configuration(CC "-DPDM_BUFFER_SIZE=2048")
        endif()
    endif()
endif()

# Find the suitable ZPSNWK lib to use
if(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZED")
    if(CONFIG_ZB_WWAH)
        set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_WWAH_ZED.a)
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_ZED_R23.a)
        else()
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_ZED.a)
        endif()
    endif()
elseif(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZCR")
    if(CONFIG_ZB_WWAH)
        set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_WWAH.a)
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_R23.a)
        else()
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK.a)
        endif()
    endif()
else()
    message(FATAL_ERROR "ZBPRO_DEVICE_TYPE must be set to either ZCR or ZED")
endif()

# Determine if ZPSIPAN & ZPSGP libs are required
execute_process(
    COMMAND sh ${ZPSCONFIG} -n ${CONFIG_ZB_NODE_NAME} -f ${CONFIG_ZB_ZPSCFG} -y
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE OPTIONAL_STACK_FEATURES
    OUTPUT_STRIP_TRAILING_WHITESPACE)

# Find the suitable ZPSIPAN lib to use
if(OPTIONAL_STACK_FEATURES MATCHES "1")
    if(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZED")
        set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN_ZED.a)
    else()
        set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN.a)
    endif()
endif()

# Find the suitable ZPSGP lib to use
if(OPTIONAL_STACK_FEATURES MATCHES "2")
    if(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZED")
        set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP_ZED.a)
    else()
        set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP.a)
    endif()
endif()

# Find the suitable ZPSIPAN & ZPSGP lib to use
if(OPTIONAL_STACK_FEATURES MATCHES "3")
    if(CONFIG_ZBPRO_DEVICE_TYPE MATCHES "ZED")
        set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN_ZED.a)
        set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP_ZED.a)
    else()
        set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN.a)
        set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP.a)
    endif()
endif()

# Find the suitable ZPSMAC lib to use
if(CONFIG_ZB_MAC_TYPE MATCHES "SOC")
    set(CONFIG_ZB_MAC_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSMAC_Mini_SOC.a)
elseif(CONFIG_ZB_MAC_TYPE MATCHES "SERIAL")
    set(CONFIG_ZB_MAC_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSMAC_Mini_SERIAL.a)
    set(CONFIG_ZB_MAC_SERIAL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libSerialMiniMacUpper.a)
elseif(CONFIG_ZB_MAC_TYPE MATCHES "MULTI")
    set(CONFIG_ZB_MAC_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSMAC_Mini_MULTI.a)
    set(CONFIG_ZB_MAC_SERIAL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libSerialMiniMacUpper.a)
else()
    message(FATAL_ERROR "Valid configuration for MAC Type: SOC, Serial or MULTI")
endif()

mcux_add_armgcc_configuration(
   LD "-Xlinker --defsym=vector_table_size=512\
       -Xlinker --defsym=__ram_vector_table__=1"
)

# Link zigbee libraries
mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_ZPSAPL_LIB})
mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_ZPSNWK_LIB})
mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_ZPSTSV_LIB})

if(CONFIG_ZB_ZPSGP_LIB)
    mcux_add_configuration(LIB ${CONFIG_ZB_ZPSGP_LIB})
endif()

if(CONFIG_ZB_ZPSIPAN_LIB)
    mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_ZPSIPAN_LIB})
endif()

mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_MAC_LIB})
if(CONFIG_ZB_MAC_SERIAL_LIB)
    mcux_add_configuration(TOOLCHAINS armgcc LIB ${CONFIG_ZB_MAC_SERIAL_LIB})
endif()
