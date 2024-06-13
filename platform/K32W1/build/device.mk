###############################################################################
#
# MODULE:   device.mk
#
# DESCRIPTION: Configuration makefile for k32w1 SOC
#
###############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as K32W1]. 
# You, and any third parties must reproduce the copyright and warranty notice
# and any other legend of ownership on each copy or partial copy of the 
# software.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Copyright 2023 NXP
#
###############################################################################

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

CFLAGS += -DJENNIC_CHIP=$(JENNIC_CHIP)
CFLAGS += -DJENNIC_CHIP_$(JENNIC_CHIP)
CFLAGS += -DJENNIC_CHIP_NAME=_$(JENNIC_CHIP)

CFLAGS += -DJENNIC_CHIP_FAMILY=$(JENNIC_CHIP_FAMILY)
CFLAGS += -DJENNIC_CHIP_FAMILY_$(JENNIC_CHIP_FAMILY)
CFLAGS += -DJENNIC_CHIP_FAMILY_NAME=_$(JENNIC_CHIP_FAMILY)

CFLAGS += -D$(JENNIC_CHIP)=5189
CFLAGS += -D$(JENNIC_CHIP_FAMILY)=5189

CFLAGS += -DJENNIC_STACK_$(JENNIC_STACK)
CFLAGS += -DJENNIC_MAC_$(JENNIC_MAC)

CFLAGS += -DLITTLE_ENDIAN_PROCESSOR

CFLAGS += -DCPU_K32W1480VFTA
CFLAGS += -DCPU_K32W1480VFTA_cm33
CFLAGS += -mcpu=cortex-m33
CFLAGS += -mfloat-abi=hard
CFLAGS += -mfpu=fpv5-sp-d16
CFLAGS += -mthumb
CFLAGS += -DK32W1
CFLAGS += -DUSE_PB_RAM_AS_SYSTEM_MEMORY=1

# default to optimise for size
CFLAGS  += -Os
LDFLAGS += -Os

CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CLFAGS += -ffreestanding
CFLAGS += -fno-builtin

# omit frame pointer by default
CFLAGS  += -fomit-frame-pointer
LDFLAGS += -fomit-frame-pointer

# Default to smallest possible enums
CFLAGS  += -fshort-enums
LDFLAGS += -fshort-enums

LDFLAGS += -Xlinker --gc-sections
LDFLAGS += -Xlinker -print-memory-usage 
LDFLAGS += -mcpu=cortex-m33
LDFLAGS += -mfloat-abi=hard
LDFLAGS += -mfpu=fpv5-sp-d16
LDFLAGS += -mthumb

# Search for linker script
LDFLAGS += -L$(FRAMEWORK_BASE_DIR)/Common/devices/kw45_k32w1/gcc/

CFLAGS += -DSERIAL_PORT_TYPE_UART=1

INCFLAGS += -I$(SDK_BASE_DIR)/CMSIS/Core/Include
ifneq "$(wildcard $(SDK_BASE_DIR)/platform/drivers/common )" ""
# Bamboo builds libraries using the SDK GIT full layout
INCFLAGS += -I$(SDK_BASE_DIR)/platform/drivers/common
INCFLAGS += -I$(SDK_BASE_DIR)/platform/utilities/debug_console
INCFLAGS += -I$(SDK_BASE_DIR)/devices/KW45B41Z83/drivers
else
# Libs could be build in an SDK release package
INCFLAGS += -I$(SDK_BASE_DIR)/devices/K32W1480/drivers
INCFLAGS += -I$(SDK_BASE_DIR)/devices/K32W1480/utilities/debug_console
endif
INCFLAGS += -I$(SDK_BASE_DIR)/components/messaging
INCFLAGS += -I$(SDK_BASE_DIR)/components/lists
INCFLAGS += -I$(SDK_BASE_DIR)/components/mem_manager
INCFLAGS += -I$(SDK_BASE_DIR)/components/osa
INCFLAGS += -I$(SDK_BASE_DIR)/components/serial_manager
INCFLAGS += -I$(SDK_BASE_DIR)/components/uart
INCFLAGS += -I$(SDK_BASE_DIR)/components/timer_manager
INCFLAGS += -I$(SDK_BASE_DIR)/devices/K32W1480
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/LowPower
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/FunctionLib
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/../ieee-802.15.4/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/../ieee-802.15.4/ieee_802_15_4/mac/interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/../ieee-802.15.4/ieee_802_15_4/phy/interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/../ieee-802.15.4/utils
ifeq ($(LEGACY_SDK_2_12_MODE), 1)
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/kw45_k32w1
else
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/connected_mcu
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/connected_mcu/configs
endif

# K32W1 platform related include files
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/K32W1/framework/Common
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/K32W1/framework/PWRM/Include
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/K32W1/framework/RNG/Interface
INCFLAGS += -I$(ZIGBEE_BASE_DIR)/platform/K32W1/framework/SecLib

INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/RNG

###############################################################################
# Chip independent compiler options
###############################################################################

CFLAGS += -Wall
CFLAGS += -Wunreachable-code

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

CROSS_COMPILE ?= arm-none-eabi

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
