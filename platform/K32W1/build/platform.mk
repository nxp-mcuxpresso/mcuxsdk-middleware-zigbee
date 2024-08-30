###############################################################################
#
# MODULE:   platform.mk
#
# DESCRIPTION: K32W1 Platform specific defines to be used in
#              conjuction with config_ZBPro.mk
#
###############################################################################
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN514x, JN516x, JN517x].
# You, and any third parties must reproduce the copyright and warranty notice
# and any other legend of ownership on each  copy or partial copy of the software.
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
# Copyright 2023-2024 NXP
#
###############################################################################

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

# System & startup
APPSRC += system_$(SDK_DEVICE_NAME).c
APPSRC += startup_$(SDK_DEVICE_NAME).S

# Drivers
APPSRC += fsl_assert.c
APPSRC += fsl_ccm32k.c
APPSRC += fsl_clock.c
APPSRC += fsl_cmc.c
APPSRC += fsl_common_arm.c
APPSRC += fsl_common.c
APPSRC += fsl_edma.c
APPSRC += fsl_format.c
APPSRC += fsl_gpio.c
APPSRC += fsl_imu.c
APPSRC += fsl_k4_controller.c
APPSRC += fsl_k4_flash.c
APPSRC += fsl_lptmr.c
APPSRC += fsl_lpuart.c
APPSRC += fsl_lpuart_edma.c
APPSRC += fsl_ltc.c
APPSRC += fsl_elemu.c
APPSRC += fsl_spc.c
APPSRC += fsl_str.c
APPSRC += fsl_tpm.c
APPSRC += fsl_vref.c
APPSRC += fsl_wuu.c
APPSRC += fsl_crc.c
APPSRC += fsl_wdog32.c
APPSRC += fsl_debug_console.c
APPSRC += fsl_trdc.c

# Security
APPSRC += SecLib_sss.c
APPSRC += sss_aes.c
APPSRC += sss_ecdh.c
APPSRC += sss_ccm.c
APPSRC += sss_init.c
APPSRC += fsl_sss_sscp.c
APPSRC += fsl_sscp_mu.c

# Framework
APPSRC += FunctionLib.c
APPSRC += RNG.c
APPSRC += NV_Flash.c
APPSRC += HWParameter.c

# PWR
APPSRC += PWR.c
ifeq ($(LEGACY_SDK_2_12_MODE), 1)
    APPSRC += fsl_pm_board.c
else
    APPSRC += fsl_pm_device.c
endif
APPSRC += fsl_pm_core.c
# this should be guarded for FreeRTOS builds
APPSRC += PWR_systicks_bm.c

# Components
APPSRC += fsl_component_generic_list.c
APPSRC += fsl_component_messaging.c
APPSRC += fsl_component_timer_manager.c
APPSRC += fsl_adapter_lptmr_time_stamp.c
APPSRC += fsl_component_mem_manager_light.c
APPSRC += fsl_component_panic.c
APPSRC += fsl_adapter_k4_flash.c
APPSRC += fsl_adapter_lpuart.c
APPSRC += fsl_adapter_lptmr.c
APPSRC += fsl_adapter_gpio.c
APPSRC += fsl_adapter_rpmsg.c

# Platform specifics
APPSRC += SecLib_.c
APPSRC += aes_mmo.c
APPSRC += PDM_adapter.c
APPSRC += PWRM_adapter.c
APPSRC += glue.c
APPSRC += fwk_platform.c
APPSRC += fwk_platform_ot.c
APPSRC += fwk_platform_ics.c
APPSRC += fwk_platform_rng.c
APPSRC += fwk_platform_crypto.c
ifeq ($(LEGACY_SDK_2_12_MODE), 1)
    APPSRC += platform_genfsk.c
else
    APPSRC += fwk_platform_genfsk.c
endif

# Multi core
APPSRC += mcmgr.c
APPSRC += mcmgr_internal_core_api_k32w1.c
APPSRC += mcmgr_imu_internal.c
APPSRC += mcmgr_internal_core_api_k32w1_ext.c


# RP Message
APPSRC += rpmsg_platform.c
APPSRC += rpmsg_lite.c
APPSRC += rpmsg_env_bm.c
ifneq ($(LEGACY_SDK_2_12_MODE), 1)
   ifneq (x$(SPLIT), x)
       APPSRC += rpmsg_platform_ext.c
   endif
endif
APPSRC += virtqueue.c
APPSRC += llist.c

# XCVR specifics
APPSRC += rfmc_ctrl.c
APPSRC += nxp_xcvr_lcl_ctrl.c
APPSRC += nxp_xcvr_ext_ctrl.c
APPSRC += mathfp.c
APPSRC += dma_capture.c
APPSRC += dbg_ram_capture.c
APPSRC += nxp2p4_xcvr.c
APPSRC += nxp_xcvr_trim.c
APPSRC += nxp_xcvr_oqpsk_802p15p4_config.c
APPSRC += nxp_xcvr_msk_config.c
APPSRC += nxp_xcvr_mode_config.c
APPSRC += nxp_xcvr_lcl_config.c
APPSRC += nxp_xcvr_gfsk_bt_0p5_h_1p0_config.c
APPSRC += nxp_xcvr_gfsk_bt_0p5_h_0p7_config.c
APPSRC += nxp_xcvr_gfsk_bt_0p5_h_0p5_config.c
APPSRC += nxp_xcvr_gfsk_bt_0p5_h_0p32_config.c
APPSRC += nxp_xcvr_common_config.c
APPSRC += nxp_xcvr_coding_config.c

##################################################################################
## INCLUDE paths

INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PWRM/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PDUM/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PDM/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/DBG

INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/FunctionLib
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/SecLib
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/RNG/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Common
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/NVM/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/NVM/Source
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/HWParameter
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/LowPower

# Platform configs
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/include
ifeq ($(LEGACY_SDK_2_12_MODE), 1)
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/kw45_k32w1/configs
else
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/connected_mcu
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/platform/connected_mcu/configs
endif

# Drivers
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/gpio
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/port
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/lpuart
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/lptmr
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/flash_k4
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/imu
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/tpm
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/vref_1
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/spc
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/elemu
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/ltc
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/dma3
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/common
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/cmc
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/wuu
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/crc
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/ccm32k
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/lpadc
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/wdog32
INCFLAGS += -I$(DEVICE_SP_DRIVERS)/trdc
INCFLAGS += -I$(DEVICE_SP_DRIVERS_KW45)

# Utilities

# Components include
INCFLAGS += -I$(FSL_COMPONENTS)/serial_manager/
INCFLAGS += -I$(FSL_COMPONENTS)/uart
INCFLAGS += -I$(FSL_COMPONENTS)/gpio
INCFLAGS += -I$(FSL_COMPONENTS)/panic
INCFLAGS += -I$(FSL_COMPONENTS)/timer_manager
INCFLAGS += -I$(FSL_COMPONENTS)/time_stamp
INCFLAGS += -I$(FSL_COMPONENTS)/timer
INCFLAGS += -I$(FSL_COMPONENTS)/mem_manager
INCFLAGS += -I$(FSL_COMPONENTS)/messaging
INCFLAGS += -I$(FSL_COMPONENTS)/internal_flash
INCFLAGS += -I$(FSL_COMPONENTS)/led
INCFLAGS += -I$(FSL_COMPONENTS)/button
INCFLAGS += -I$(FSL_COMPONENTS)/lists
INCFLAGS += -I$(FSL_COMPONENTS)/rpmsg
INCFLAGS += -I$(FSL_COMPONENTS)/power_manager/core
INCFLAGS += -I$(FSL_COMPONENTS)/debug_console
INCFLAGS += -I$(FSL_COMPONENTS)/debug_console_lite
INCFLAGS += -I$(FSL_COMPONENTS)/str
INCFLAGS += -I$(FSL_COMPONENTS)/misc_utilities
INCFLAGS += -I$(FSL_COMPONENTS)/assert


ifeq ($(LEGACY_SDK_2_12_MODE), 1)
   INCFLAGS += -I$(FSL_COMPONENTS)/power_manager/boards/K32W148-EVK
else
   INCFLAGS += -I$(FSL_COMPONENTS)/power_manager/devices/KW45B41Z83
endif

INCFLAGS += -I$(SECURE_SUBSYSTEM_DIR)/inc
INCFLAGS += -I$(SECURE_SUBSYSTEM_DIR)/inc/elemu
INCFLAGS += -I$(SECURE_SUBSYSTEM_DIR)/port/kw45_k4w1
INCFLAGS += -I$(SECURE_SUBSYSTEM_DIR)/src/sscp

#XCVR
INCFLAGS += -I$(XCVR_DIR)/drv
INCFLAGS += -I$(XCVR_DIR)/drv/nb2p4ghz
INCFLAGS += -I$(XCVR_DIR)/drv/nb2p4ghz/configs/gen45

# Multi core
INCFLAGS += -I$(MULTICORE_DIR)/mcmgr/src
INCFLAGS += -I$(MULTICORE_DIR)/rpmsg_lite/lib/include
INCFLAGS += -I$(MULTICORE_DIR)/rpmsg_lite/lib/include/environment/bm
INCFLAGS += -I$(MULTICORE_DIR)/rpmsg_lite/lib/include/platform/k32w1

# Secure subsystem defines
CFLAGS += -DgRngUseSecureSubSystem_d=1
CFLAGS += -DSSS_CONFIG_FILE='"fsl_sss_config_elemu.h"'
CFLAGS += -DSSCP_CONFIG_FILE='"fsl_sscp_config_elemu.h"'

# Various FWK related defines
CFLAGS += -DgHwParamsProdDataPlacement_c=gHwParamsProdDataPlacementLegacyMode_c

ZIGBEE_BASE_SRC = $(ZIGBEE_COMMON_SRC)\
    :$(OS_ABSTRACT_SRC)\
    :$(BOARD_LEVEL_SRC)\
    :$(CHIP_STARTUP_SRC)\
    :$(CHIP_SYSTEM_SRC)\
    :$(OSA_BASE_SRC)\
    :$(DEVICE_SP_DRIVERS)/gpio\
    :$(DEVICE_SP_DRIVERS)/vref_1\
    :$(DEVICE_SP_DRIVERS)/tpm\
    :$(DEVICE_SP_DRIVERS)/spc\
    :$(DEVICE_SP_DRIVERS)/elemu\
    :$(DEVICE_SP_DRIVERS)/ltc\
    :$(DEVICE_SP_DRIVERS)/lptmr\
    :$(DEVICE_SP_DRIVERS)/flash_k4\
    :$(DEVICE_SP_DRIVERS)/imu\
    :$(DEVICE_SP_DRIVERS)/lpuart\
    :$(DEVICE_SP_DRIVERS)/dma3\
    :$(DEVICE_SP_DRIVERS)/common\
    :$(DEVICE_SP_DRIVERS)/cmc\
    :$(DEVICE_SP_DRIVERS)/wuu\
    :$(DEVICE_SP_DRIVERS)/crc\
    :$(DEVICE_SP_DRIVERS)/wdog32\
    :$(DEVICE_SP_DRIVERS)/ccm32k\
    :$(DEVICE_SP_DRIVERS)/trdc\
    :$(DEVICE_SP_DRIVERS_KW45)\
    :$(DEVICE_SP_UTILITIES)\
    :$(FSL_COMPONENTS)/misc_utilities\
    :$(FSL_COMPONENTS)/str\
    :$(FSL_COMPONENTS)/assert\
    :$(SECURE_SUBSYSTEM_DIR)/port/kw45_k4w1\
    :$(SECURE_SUBSYSTEM_DIR)/src/sscp\
    :$(FSL_COMPONENTS)/serial_manager\
    :$(FSL_COMPONENTS)/lists\
    :$(FSL_COMPONENTS)/uart\
    :$(FSL_COMPONENTS)/gpio\
    :$(FSL_COMPONENTS)/panic\
    :$(FSL_COMPONENTS)/timer_manager\
    :$(FSL_COMPONENTS)/time_stamp\
    :$(FSL_COMPONENTS)/timer\
    :$(FSL_COMPONENTS)/mem_manager\
    :$(FSL_COMPONENTS)/messaging\
    :$(FSL_COMPONENTS)/internal_flash\
    :$(FSL_COMPONENTS)/osa\
    :$(FSL_COMPONENTS)/led\
    :$(FSL_COMPONENTS)/button\
    :$(FSL_COMPONENTS)/lists\
    :$(FSL_COMPONENTS)/panic\
    :$(FSL_COMPONENTS)/power_manager/core\
    :$(FSL_COMPONENTS)/rpmsg\
    :$(FSL_COMPONENTS)/debug_console_lite\
    :$(FSL_COMPONENTS)/assert\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/framework/SecLib\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/framework/PDM\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/framework/PWRM\
    :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/platform\
    :$(FRAMEWORK_BASE_DIR)/NVM/Source\
    :$(FRAMEWORK_BASE_DIR)/RNG\
    :$(FRAMEWORK_BASE_DIR)/SecLib\
    :$(FRAMEWORK_BASE_DIR)/HWParameter\
    :$(FRAMEWORK_BASE_DIR)/FunctionLib\
    :$(FRAMEWORK_BASE_DIR)/LowPower\
    :$(XCVR_DIR)/drv\
    :$(XCVR_DIR)/drv/nb2p4ghz\
    :$(XCVR_DIR)/drv/nb2p4ghz/configs/gen45\
    :$(MULTICORE_DIR)/rpmsg_lite/lib/common\
    :$(MULTICORE_DIR)/rpmsg_lite/lib/rpmsg_lite\
    :$(MULTICORE_DIR)/rpmsg_lite/lib/virtio\
    :$(MULTICORE_DIR)/rpmsg_lite/lib/rpmsg_lite/porting/platform/k32w1\
    :$(MULTICORE_DIR)/rpmsg_lite/lib/rpmsg_lite/porting/environment\
    :$(MULTICORE_DIR)/mcmgr/src

ifeq ($(LEGACY_SDK_2_12_MODE), 1)
    ZIGBEE_BASE_SRC += :$(FSL_COMPONENTS)/power_manager/boards/K32W148-EVK\
                       :$(FRAMEWORK_BASE_DIR)/platform/kw45_k32w1
else
    ZIGBEE_BASE_SRC += :$(FSL_COMPONENTS)/power_manager/devices/KW45B41Z83\
                       :$(FRAMEWORK_BASE_DIR)/platform/connected_mcu\
                       :$(FRAMEWORK_BASE_DIR)/platform/connected_mcu/configs
endif

# K32W1 LDFLAGS
ifneq ($(PDM_NONE),1)
    LDFLAGS += -Wl,--defsym=gUseNVMLink_d=1
endif

# Add ieee library
ifeq ($(SPLIT), 1)
# PHY split
LDLIBS += ieee-802.15.4_split
else
  ifeq ($(SPLIT), 2)
    # NBU on MAC
    LDLIBS += ieee-802.15.4_MAC_intf
  else
    # Standalone
    LDLIBS += ieee-802.15.4
  endif
endif

LDLIBS += _crypto_m33

LDFLAGS += -Wl,--defsym,__heap_size__=$(HEAP_SIZE)
LDFLAGS += -Wl,--defsym,__stack_size__=$(STACK_SIZE)
# Make stack location RAM1, as it might collide with data section.
LDFLAGS += -Wl,--defsym,m_cstack_ram1=1
LDFLAGS += -L$(SDK_BASE_DIR)/middleware/wireless/ieee-802.15.4/ieee_802_15_4/lib
LDFLAGS += -L$(FRAMEWORK_BASE_DIR)/PDM/Library
LDFLAGS += -L$(FRAMEWORK_BASE_DIR)/PDUM/Library
LDFLAGS += -L$(FRAMEWORK_BASE_DIR)/SecLib
