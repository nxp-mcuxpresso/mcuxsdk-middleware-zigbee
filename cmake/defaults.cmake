# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

set(CONFIG_ZB_BDB ON CACHE BOOL "Build BDB sources as part of the application target")
set(CONFIG_ZB_ZCL ON CACHE BOOL "Build ZCIF and ZCL sources as part of the application target")
set(CONFIG_ZB_DEVICE_TYPE "ZCR" CACHE STRING "Zigbee device type. Set to ZED to select an End Device")
set(CONFIG_ZB_WWAH OFF CACHE BOOL "")
set(CONFIG_ZB_R23 OFF CACHE BOOL "Enable R23 support")
set(CONFIG_ZB_LEGACY OFF CACHE BOOL "Enable LEGACY mode.")
set(CONFIG_ZB_USE_FREERTOS ON CACHE BOOL "Use FreeRTOS as OS")
set(CONFIG_ZB_FREERTOS_CONFIG "" CACHE STRING "Path to FreeRTOSConfig.h")
set(CONFIG_ZB_CONSOLE_INTERFACE "UART" CACHE STRING "Selects which serial interface is used for the ZB console")
set(CONFIG_ZB_SINGLE_CHANNEL "12" CACHE STRING "If set, forces the channel used.")

set(CONFIG_ZB_MANUFACTURER_CODE "0x1307" CACHE STRING "Manufacturer code used for OTA image generation.")

set(CONFIG_ZB_BOOTLOADER_MCUBOOT OFF CACHE BOOL "This option signifies the target uses MCUBoot as a bootloader")
set(CONFIG_ZB_MCUBOOT_SIGNATURE_KEY_FILE "${NXP_SDK_MIDDLEWARE}/mcuboot_opensource/boot/nxp_mcux_sdk/keys/sign-rsa2048-priv.pem" CACHE STRING "Path to the mcuboot signing key file")
