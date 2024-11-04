# Copyright 2023-2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause
#
# Set up defaults for stack configuration
# JENNIC_STACK specifies the full stack (MAC only, JenNet-IP, etc.) and
#   determines which set of libraries and include paths are added to the build
# JENNIC_MAC allows selection of the MAC layer:
#   MAC         for full MAC
#   MiniMac     for size-optimised variant
#   MiniMacShim for size-optimised with shim to the old API
#
# Values are normally specified by the application make file; the defaults here
# are for legacy builds that pre-date the selection process
#
###############################################################################

JENNIC_STACK ?= MAC
JENNIC_MAC   ?= MiniMac

###############################################################################
# Include the chip or chip family definitions.
# Chip takes precendence over chip family
###############################################################################
SDK_DEVICE_FAMILY ?= K32W1
SDK_DEVICE_NAME   ?= K32W1480
SDK_BOARD         ?= k32w148evk

###############################################################################
# Define the selected Jennic chip
###############################################################################

CFLAGS += -DJENNIC_CHIP_FAMILY=$(JENNIC_CHIP_FAMILY)
CFLAGS += -DJN518x=5189

INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/ieee-802.15.4

CFLAGS += -DLITTLE_ENDIAN_PROCESSOR
CFLAGS += -DNCP_HOST
CFLAGS += -DTRACE_SERIAL=1
CFLAGS += -DTRACE_ZCL=1
CFLAGS += -DDEBUG_ZQUEUE=1
CFLAGS += -DTRACE_APP=0

INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/k32w1_ncp_host
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/boards/k32w1_ncp_host

# K32W1 NCP platform related include files
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/framework/Common
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/framework/PWRM/Include
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/platform
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/NCP_HOST/misc 

###############################################################################
# Compiler options
###############################################################################
CFLAGS += -ffunction-sections
ifeq ($(MACHINE),IMX8)
# Compiling for IMX8
CROSS_COMPILE ?= arm-linux-gnueabihf-gcc

ifeq ($(HOST_DEBUG),1)
CFLAGS += -Og
CFLAGS += -g3
else
CFLAGS += -Os
LDFLAGS += -Os
endif
CFLAGS += -Wno-implicit-function-declaration
CFLAGS += -Wno-format
CFLAGS += -Wno-incompatible-pointer-types
CFLAGS += -Wno-discarded-qualifiers
CFLAGS += -Wno-int-conversion
else 
# Compiling for X86
ifeq ($(HOST_DEBUG),1)
CFLAGS += -Og
CFLAGS += -g3
CFLAGS += -ggdb
else 
CFLAGS += -Os
endif
CFLAGS += -Wno-incompatible-pointer-types
CFLAGS += -Wno-discarded-qualifiers
endif 

ifeq ($(TARGET_32bits), 1)
   CFLAGS += -m32
   LDFLAGS += -m32
endif
###############################################################################
# Compiler Paths
###############################################################################

#TOOL_BASE_DIR ?= $(SDK_BASE_DIR)/Tools

###############################################################################
# Toolchain
###############################################################################

CC  = gcc
AS  = as
LD  = gcc
AR  = ar
NM  = nm
STRIP   = strip
SIZE    = size
OBJCOPY = objcopy
OBJDUMP = objdump
RANLIB  = ranlib

ifdef CROSS_COMPILE
CC:=$(CROSS_COMPILE)-$(CC)
AS:=$(CROSS_COMPILE)-$(AS)
LD:=$(CROSS_COMPILE)-$(LD)
AR:=$(CROSS_COMPILE)-$(AR)
NM:=$(CROSS_COMPILE)-$(NM)
STRIP:=$(CROSS_COMPILE)-$(STRIP)
SIZE:=$(CROSS_COMPILE)-$(SIZE)
OBJCOPY:=$(CROSS_COMPILE)-$(OBJCOPY)
OBJDUMP:=$(CROSS_COMPILE)-$(OBJDUMP)
endif

###############################################################################
