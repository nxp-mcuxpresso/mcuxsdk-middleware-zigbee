# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.24)
find_package(NxpZb REQUIRED HINTS $ENV{NXP_ZB_BASE})
project(zb_router VERSION 1.0.0)

# zb_app is created by the find_package() command, all linkage to NXP Zigbee interface is handled transparently
target_sources(zb_app PRIVATE
    ../zb_common/app_buttons.c
    ../zb_common/app_leds.c
    ../zb_common/app_ota_client.c
    ../zb_common/app_console.c
    ../zb_common/app_uart.c
    ../zb_common/app_zigbee_config.c
    ../zb_common/app_crypto.c
    src/app_router_node.c
    src/app_start.c
    src/app_zcl_task.c
    src/app_reporting.c
    src/app_main.c
    src/pdum_gen.c
    src/pdum_apdu.S
    src/zps_gen.c
)

target_compile_options(zb_app PRIVATE
    -imacros ${NXP_ZB_BASE}/examples/zigbee_router/src/bdb_options.h
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
    Router
    gAppButtonCnt_c=1
    gAppLedCnt_c=2
    gEepromParams_bufferedWrite_c=1
    INTERNAL_ENCRYPTED
    CLD_OTA_KEY=\"${CONFIG_ZB_OTA_ENCRYPTION_KEY}\"
)

if(CONFIG_ZB_USE_CLI)
    target_sources(zb_app PRIVATE
        src/app_serial_commands.c
    )
    nxp_zb_compile_definitions(APP_ROUTER_NODE_CLI)
endif()

if(CONFIG_ZB_USE_FREERTOS)
    target_sources(zb_app PRIVATE
        ../zb_common/app_freertos_hooks.c
    )
    # Use nxp_zb_include_directories to expose FreeRTOSConfig.h to zb_interface
    nxp_zb_include_directories(
        ../../platform/${CONFIG_ZB_PLATFORM}
    )
endif()

if(CONFIG_ZB_TRACE_APP)
    nxp_zb_compile_definitions(TRACE_APP=1)
endif()

if(CONFIG_ZB_TRACE_ZCL)
    nxp_zb_compile_definitions(TRACE_ZCL=1)
endif()

nxp_zb_generate_zpsconfig(${CMAKE_CURRENT_SOURCE_DIR}/src/router.zpscfg "router" ${CMAKE_CURRENT_SOURCE_DIR}/src)
nxp_zb_generate_pdumconfig(${CMAKE_CURRENT_SOURCE_DIR}/src/router.zpscfg "router" ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Generate v1 elf
nxp_zb_generate_versioned_elf(zb_app ${CONFIG_ZB_MANUFACTURER_CODE} ${CONFIG_ZB_OTA_IMAGE_TYPE} ${CONFIG_ZB_OTA_VERSION_STR} 1)
add_executable(zb_app_v1 IMPORTED GLOBAL)
set_target_properties(zb_app_v1 PROPERTIES
    IMPORTED_LOCATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.elf
)
nxp_zb_export_target_to_bin(zb_app_v1)

# Generate v2 elf
nxp_zb_generate_versioned_elf(zb_app ${CONFIG_ZB_MANUFACTURER_CODE} ${CONFIG_ZB_OTA_IMAGE_TYPE} ${CONFIG_ZB_OTA_VERSION_STR} 2)
add_executable(zb_app_v2 IMPORTED GLOBAL)
set_target_properties(zb_app_v2 PROPERTIES IMPORTED_LOCATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.elf)
nxp_zb_export_target_to_bin(zb_app_v2)

# Generate v3 elf
nxp_zb_generate_versioned_elf(zb_app ${CONFIG_ZB_MANUFACTURER_CODE} ${CONFIG_ZB_OTA_IMAGE_TYPE} ${CONFIG_ZB_OTA_VERSION_STR} 3)
add_executable(zb_app_v3 IMPORTED GLOBAL)
set_target_properties(zb_app_v3 PROPERTIES IMPORTED_LOCATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.elf)
nxp_zb_export_target_to_bin(zb_app_v3)

if(CONFIG_ZB_BOOTLOADER_MCUBOOT)
    # When using MCUBoot, the image is signed, so we offload the verification to MCUBoot
    # The reason is that the CRC is calculated on the whole image, including the MCUBoot header
    # So, we have to compute the CRC after the MCUBoot signature, and patch the OTA header section
    # in the image, but this would invalidate the MCUBoot signature.
    # For the link key verification, as the image now contains the MCUBoot header, the link key
    # can be significantly offset, so increase arbitrarily to 8k
    nxp_zb_compile_definitions(
        OTA_IGNORE_CRC_CHECK=1
        APP_OTA_OFFSET_WRITEN_BEFORE_LINKKEY_VERIFICATION=8128
    )

    # Build mcuboot application from the SDK and copy the output binary to our build folder
    nxp_zb_build_mcuboot()

    # Generated a signed and confirmed v1 image to be used as the active image
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.signed.confirmed.bin
        COMMAND ${Python3_EXECUTABLE} ${NXP_SDK_MIDDLEWARE}/mcuboot_opensource/scripts/imgtool.py
        ARGS
            sign
            --confirm
            --key ${CONFIG_ZB_MCUBOOT_SIGNATURE_KEY_FILE}
            --align 4
            --header-size 0x1000
            --pad-header
            --slot-size 0x440000
            --max-sectors 1088
            --version "1.0.0+0"
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.bin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.signed.confirmed.bin
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.bin
    )
    add_custom_target(generate_zb_app_v1_signed ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.signed.confirmed.bin
    )

    # Merge the MCUBoot binary with the V1 signed+confirmed image into a single binary so we can flash everything once
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1_full.bin
        COMMAND dd # fill the first 1k with 0xFF because the mcuboot image starts at the offset 0x400
        ARGS
            if=/dev/zero
            bs=1024
            count=1
            |
            LC_ALL=C
            tr
            \"\\000\"
            \"\\377\"
            >
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1_full.bin
        COMMAND dd # append mcuboot binary
        ARGS
            if=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mcuboot.bin
            of=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1_full.bin
            bs=1024
            seek=1
        COMMAND dd # append zigbee application starting from the slot0 partition
        ARGS
            if=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.signed.confirmed.bin
            of=${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1_full.bin
            bs=1024
            seek=128
        DEPENDS
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mcuboot.bin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1.signed.confirmed.bin
    )
    add_custom_target(merge_mcuboot ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v1_full.bin
    )

    # Generate a signed (not confirmed) v2 image
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.signed.bin
        COMMAND ${Python3_EXECUTABLE} ${NXP_SDK_MIDDLEWARE}/mcuboot_opensource/scripts/imgtool.py
        ARGS
            sign
            --key ${CONFIG_ZB_MCUBOOT_SIGNATURE_KEY_FILE}
            --align 4
            --header-size 0x1000
            --pad-header
            --slot-size 0x440000
            --max-sectors 1088
            --version "2.0.0+0"
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.bin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.signed.bin
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.bin
    )
    add_custom_target(generate_zb_app_v2_signed ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.signed.bin
    )

    # Generate a signed (not confirmed) v3 image
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.signed.bin
        COMMAND ${Python3_EXECUTABLE} ${NXP_SDK_MIDDLEWARE}/mcuboot_opensource/scripts/imgtool.py
        ARGS
            sign
            --key ${CONFIG_ZB_MCUBOOT_SIGNATURE_KEY_FILE}
            --align 4
            --header-size 0x1000
            --pad-header
            --slot-size 0x440000
            --max-sectors 1088
            --version "3.0.0+0"
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.bin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.signed.bin
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.bin
    )
    add_custom_target(generate_zb_app_v3_signed ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.signed.bin
    )

    # Generate an OTA image from v2 signed binary
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.ota.bin
        COMMAND ${Python3_EXECUTABLE} ${NXP_ZB_BASE}/tools/OTA/nxpzbota.py
        ARGS
        -log INFO
        -i ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.elf
        --signed ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.signed.bin
        -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.ota.bin
        -OtaMan ${CONFIG_ZB_MANUFACTURER_CODE}
        -OtaImgTyp ${CONFIG_ZB_OTA_IMAGE_TYPE}
        -OtaVersionStr ${CONFIG_ZB_OTA_VERSION_STR}
        -OtaFileVersion 2
        --encrypt
        --key ${CONFIG_ZB_OTA_ENCRYPTION_KEY}
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.signed.bin
    )
    add_custom_target(generate_zb_app_v2_ota ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v2.ota.bin
    )

    # Generate an OTA image from v3 signed binary
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.ota.bin
        COMMAND ${Python3_EXECUTABLE} ${NXP_ZB_BASE}/tools/OTA/nxpzbota.py
        ARGS
        -log INFO
        -i ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.elf
        --signed ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.signed.bin
        -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.ota.bin
        -OtaMan ${CONFIG_ZB_MANUFACTURER_CODE}
        -OtaImgTyp ${CONFIG_ZB_OTA_IMAGE_TYPE}
        -OtaVersionStr ${CONFIG_ZB_OTA_VERSION_STR}
        -OtaFileVersion 3
        --encrypt
        --key ${CONFIG_ZB_OTA_ENCRYPTION_KEY}
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.signed.bin
    )
    add_custom_target(generate_zb_app_v3_ota ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/zb_app_v3.ota.bin
    )
endif()
