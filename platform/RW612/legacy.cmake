# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

set(CONFIG_JENNIC_CHIP_FAMILY "JN518x")
set(CONFIG_JENNIC_CHIP "JN5189")
set(CONFIG_JENNIC_STACK "MAC")
set(CONFIG_JENNIC_MAC "MiniMac")

if(NOT CONFIG_ZB_PLATFORM_LINKER_FILE)
    if(CONFIG_ZB_BOOTLOADER_MCUBOOT)
        set(CONFIG_ZB_PLATFORM_LINKER_FILE "${NXP_SDK_MIDDLEWARE}/wireless/framework/Common/devices/rw61x/gcc/RW61x_flash_zb_mcuboot.ld" CACHE STRING "Linker file used to link executables")
    else()
        set(CONFIG_ZB_PLATFORM_LINKER_FILE "${NXP_SDK_MIDDLEWARE}/wireless/framework/Common/devices/rw61x/gcc/RW61x_flash.ld" CACHE STRING "Linker file used to link executables")
    endif()
endif()

if(NOT CONFIG_ZB_MBEDTLS_CONFIG_FILE)
    set(CONFIG_ZB_MBEDTLS_CONFIG_FILE "${NXP_SDK_MIDDLEWARE}/wireless/framework/platform/rw61x/configs/rw61x-mbedtls-config.h")
endif()

list(PREPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/build
)

if(NOT DEFINED CONFIG_ZB_BOARD)
    set(CONFIG_ZB_BOARD "rdrw612bga" CACHE STRING "Board name")
endif()

nxp_zb_library_named(zb_platform)
nxp_zb_link_libraries(zb_platform)

set_target_properties(zb_interface PROPERTIES ZPSCONFIG_TARGETHARDWARE "JN518x")
set_target_properties(zb_interface PROPERTIES ZPSCONFIG_ENDIANNESS "LITTLE_ENDIAN")

target_sources(zb_platform PRIVATE
    ../common/framework/PDM/PDM_adapter_nvs.c
    ../common/framework/PWRM/PWRM_adapter.c
    ../common/framework/SecLib/aes_mmo.c
    ../common/framework/SecLib/SecLib_.c
    ../common/timer.c
    ../common/console.c
    ../common/crypto.c
    platform/buttons.c
    platform/uart.c
    platform/glue.c
    platform/wdog.c
    platform/leds.c
    platform/rw61x_cpu2.c
)

target_compile_options(zb_platform PUBLIC
    -mcpu=cortex-m33+nodsp
    -mfloat-abi=hard
    -mthumb
    -mfpu=fpv5-sp-d16
)

target_link_options(zb_platform PUBLIC
    -mcpu=cortex-m33+nodsp
    -mfloat-abi=hard
    -mthumb
    -mfpu=fpv5-sp-d16
    -u flexspi_config
    LINKER:--defsym,gUseNVMLink_d=1
    LINKER:--defsym,gNVMSectorCountLink_d=8
    LINKER:-T,${CONFIG_ZB_PLATFORM_LINKER_FILE}
)

# Add a dependency to the linker script so the binary is re-linked if the linker script is changed
set_target_properties(zb_interface PROPERTIES INTERFACE_LINK_DEPENDS ${CONFIG_ZB_PLATFORM_LINKER_FILE})

nxp_zb_include_directories(
    ../
    ../common/framework/Common
    ../common/framework/PWRM/Include
    ../common/framework/SecLib
    ${NXP_SDK_MIDDLEWARE}/wireless/ieee-802.15.4/Include
)

target_compile_definitions(zb_platform
    PUBLIC
    CPU_RW612ETA2I
    __USE_CMSIS
    MCUXPRESSO_SDK
    BOOT_HEADER_ENABLE=1
    OSA_USED=1
    SDK_DEBUGCONSOLE=1
    DEBUG_CONSOLE_TRANSFER_NON_BLOCKING=1
    IMU_TASK_PRIORITY=OSA_PRIORITY_REAL_TIME
    MBEDTLS_MCUX_ELS_PKC_API
    MBEDTLS_CONFIG_FILE="${CONFIG_ZB_MBEDTLS_CONFIG_FILE}"
    CONFIG_NVS_LOOKUP_CACHE=1
    CONFIG_NVS_LOOKUP_CACHE_SIZE=32
    gAppNvsExternalFlash_c=1
    gAppNvsInternalFlash_c=0
    gAppOtaExternalStorage_c=1
    JENNIC_CHIP=${CONFIG_JENNIC_CHIP}
    JENNIC_CHIP_${CONFIG_JENNIC_CHIP}
    JENNIC_CHIP_NAME=_${CONFIG_JENNIC_CHIP}
    JENNIC_CHIP_FAMILY=${CONFIG_JENNIC_CHIP_FAMILY}
    JENNIC_CHIP_FAMILY_${CONFIG_JENNIC_CHIP_FAMILY}
    JENNIC_CHIP_FAMILY_NAME=_${CONFIG_JENNIC_CHIP_FAMILY}
    ${CONFIG_JENNIC_CHIP}=5189
    ${CONFIG_JENNIC_CHIP_FAMILY}=5189
    JENNIC_STACK_${CONFIG_JENNIC_STACK}
    JENNIC_MAC_${CONFIG_JENNIC_MAC}
    ZIGBEE_USE_FRAMEWORK=1
    LITTLE_ENDIAN_PROCESSOR
    gPlatformMonolithicApp_d=1
    TIMER_PORT_TYPE_CTIMER=1
    PRINTF_ADVANCED_ENABLE=1
)

if(CONFIG_ZB_CONSOLE_INTERFACE MATCHES "UART")
    target_compile_definitions(zb_platform
        PUBLIC
        SDK_DEBUGCONSOLE_UART
        SERIAL_PORT_TYPE_UART=1
    )
endif()

if(CONFIG_ZB_USE_FREERTOS)
    target_compile_definitions(zb_platform
        PUBLIC
        SDK_OS_FREE_RTOS
        FSL_RTOS_FREE_RTOS
    )
endif()

set(QUIET ON)
# Include the mcux-sdk config file to build the required sdk files for this platform
include(mcux_sdk)

# we need to convert the framework cmake files to the legacy version
execute_process(
    COMMAND bash ${NXP_SDK_MIDDLEWARE}/wireless/framework/scripts/select_cmake_mode.sh legacy
    WORKING_DIRECTORY ${NXP_SDK_MIDDLEWARE}/wireless/framework
)

# build the framework libraries
set(CONNFWK_PLATFORM "rw61x")
set(CONNFWK_BOARD "${CONFIG_ZB_BOARD}")
set(CONNFWK_BOARD_INCLUDE_COMP ON)
set(CONNFWK_MCUX_SDK_LIB_EXTERNAL zb_platform)
set(CONNFWK_FLIB ON)
set(CONNFWK_OTA ON)
set(CONNFWK_PWR ON)
set(CONNFWK_PDM ON)
set(CONNFWK_PDUM ON)
set(CONNFWK_NVS ON)
set(CONNFWK_IGNORE_OTA_INTERNAL_FLASH ON)
set(CONNFWK_IGNORE_NVS_INTERNAL_FLASH ON)
set(CONNFWK_SECLIB "MBEDTLS")
set(CONNFWK_RNG "MBEDTLS")
set(CONNFWK_LIB_CRYPTO_SUFFIX "m33_nodsp")
add_subdirectory(${NXP_SDK_MIDDLEWARE}/wireless/framework ${PROJECT_BINARY_DIR}/framework)
set(QUIET OFF)

# restore the fwk cmake files
execute_process(
    COMMAND bash ${NXP_SDK_MIDDLEWARE}/wireless/framework/scripts/select_cmake_mode.sh
    WORKING_DIRECTORY ${NXP_SDK_MIDDLEWARE}/wireless/framework
)

add_library(ieee_802_15_4 STATIC IMPORTED)
set_target_properties(ieee_802_15_4 PROPERTIES IMPORTED_LOCATION ${NXP_SDK_MIDDLEWARE}/wireless/ieee-802.15.4/ieee_802_15_4/lib/libieee-802.15.4_MAC_intf_RW612.a)
target_link_libraries(ieee_802_15_4 INTERFACE zb_interface)

# link all needed libraries
# the order is important to resolve cyclic dependencies, change with caution
nxp_zb_link_libraries(
    ieee_802_15_4
    connfwk-config
    connfwk-LowPower
    connfwk-FunctionLib
    connfwk-SecLib
    connfwk-SecLib-CL
    connfwk-RNG
    connfwk-PDM
    connfwk-PDUM
    connfwk-NVS
    connfwk-OtaSupport
    connfwk-board-${CONFIG_ZB_BOARD}
    connfwk-platform-${CONNFWK_PLATFORM}
    $<LINK_GROUP:RESCAN,
        zb_platform,
        ieee_802_15_4,
        connfwk-LowPower,
        connfwk-FunctionLib,
        connfwk-SecLib,
        connfwk-SecLib-CL,
        connfwk-RNG,
        connfwk-NVS,
        connfwk-OtaSupport,
        connfwk-board-${CONFIG_ZB_BOARD},
        connfwk-platform-${CONNFWK_PLATFORM}
    >
)

# This is a workaround, normally this path should be set in zb_interface, but due to conflict with portmacro.h files
# between FreeRTOS and this ZigbeeCommon path, we need to set this path AFTER the FreeRTOS' path, otherwise the
# include will be wrong
# ZigbeeCommon/Include/portmacro.h needs to be renamed to avoid this
target_include_directories(zb_platform PUBLIC
    ${PROJECT_SOURCE_DIR}/ZigbeeCommon/Include
)

# Monolithic feature: find ble/15.4 combo firmware and generate an array of bytes to link directly with the application
# This feature simplifies the OTA process and guarantee the firmware linked with the application will be compatible
set(fw_bin_dir ${NXP_SDK_CORE}/components/conn_fwloader/fw_bin)
list(APPEND output_include ${APPLICATION_BINARY_DIR}/include/generated/rw61x_combo_fw.bin.inc)
nxp_zb_include_directories(${APPLICATION_BINARY_DIR}/include/generated)

# Depending on the chip revision, the firmware name change
if(CONFIG_SOC_SERIES_RW6XX_REVISION_A1)
    set(signed_binary_name rw61x_sb_combo_a1.bin)
    set(raw_binary_name rw61xn_combo_raw_cpu2_ble_15_4_combo_a1.bin)
else()
    set(signed_binary_name rw61x_sb_ble_15d4_combo_a2.bin)
    set(raw_binary_name rw61xn_raw_cpu2_ble_zb_combo.bin)
endif()
set(signed_binary ${fw_bin_dir}/${signed_binary_name})
set(raw_binary ${fw_bin_dir}/${raw_binary_name})

# Check if either one of the binaries exists, use signed binary in priority
if(EXISTS ${signed_binary})
    set(binary ${signed_binary})
elseif(EXISTS ${raw_binary})
    set(binary ${raw_binary})
else()
    message(FATAL_ERROR "Couldn't find signed nor raw firmware ! ${signed_binary} ${raw_binary}")
endif()

message(STATUS "Generate include of binary blob: ${binary}")
generate_inc_file_for_target(zb_platform ${binary} ${output_include})

target_compile_definitions(zb_platform PUBLIC
    BLE_FW_ADDRESS=0
    WIFI_FW_ADDRESS=0
)
