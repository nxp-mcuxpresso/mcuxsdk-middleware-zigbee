# Copyright 2023-2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Needed external symbols (provided by config_ZBPro.mk)
# ZIGBEE_BASE_DIR    - Path to Zigbee repo
# ZIGBEE_COMMON_SRC  - Path to ZigbeeCommon sources
# FRAMEWORK_BASE_DIR - Path to SDK framework repo
# FSL_COMPONENTS     - Path to SDK components
# CHIP_STARTUP_SRC   - Path to SDK chip startup sources
# CHIP_SYSTEM_SRC    - Path to SDK chip system sources
# BOARD_LEVEL_SRC    - Path to SDK board sources

SECURE_SUBSYSTEM_DIR   ?= $(SDK_BASE_DIR)/middleware/secure-subsystem
DEVICE_SP_UTILITIES    = $(SDK_BASE_DIR)/platform/utilities
DEVICE_SP_DRIVERS      = $(SDK_BASE_DIR)/platform/drivers
DEVICE_SP_DRIVERS_KW45 = $(SDK_BASE_DIR)/devices/KW45B41Z83/drivers
XCVR_DIR               ?= $(SDK_BASE_DIR)/middleware/wireless/XCVR
MULTICORE_DIR          = $(SDK_BASE_DIR)/middleware/multicore

# Platform specifics
APPSRC += PDM_adapter.c
APPSRC += glue.c

LDLIBS += rt 
LDLIBS += m

CFLAGS += -pthread
LDFLAGS += -pthread

##################################################################################
## INCLUDE paths

INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/framework/PDUM/Include
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/framework/PDM/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Common
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/boards/k32w1_ncp_host
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/OtaSupport/Interface

ZIGBEE_BASE_SRC = $(ZIGBEE_COMMON_SRC)\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/framework/PDM/Source/Posix\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/platform\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/platform/Posix
