###############################################################################
#
# MODULE:   platform.mk
#
# DESCRIPTION: K32W0 Platform specific defines to be used in
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
# Copyright 2023 NXP
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

DEVICE_SP_UTILITIES  ?= $(SDK_BASE_DIR)/devices/$(SDK_DEVICE_NAME)/utilities
DEVICE_SP_DRIVERS    ?= $(SDK_BASE_DIR)/devices/$(SDK_DEVICE_NAME)/drivers

# Framework
GENERIC_LIST_SRC     ?= $(FRAMEWORK_BASE_DIR)/Lists
OS_ABSTRACT_SRC      ?= $(FRAMEWORK_BASE_DIR)/OSAbstraction/Source
FSL_EXCEPTIONS_SRC   ?= $(FRAMEWORK_BASE_DIR)/DebugExceptionHandlers_jn518x/src
DEBUG_FIFO_SRC       ?= $(FRAMEWORK_BASE_DIR)/DebugFifo/Source
FSL_EEPROM_INT       ?= $(FRAMEWORK_BASE_DIR)/Flash/Internal
FSL_EEPROM_GEN       ?= $(FRAMEWORK_BASE_DIR)/Flash/External/Source
FSL_OTA              ?= $(FRAMEWORK_BASE_DIR)/OtaSupport/Source
FRMWK_RNG_SRC        ?= $(FRAMEWORK_BASE_DIR)/RNG/Source
FRMWK_SECLIB_SRC     ?= $(FRAMEWORK_BASE_DIR)/SecLib
FRMWK_FUNCLIB_SRC    ?= $(FRAMEWORK_BASE_DIR)/FunctionLib
FRMWK_MSG_SRC        ?= $(FRAMEWORK_BASE_DIR)/Messaging/Source
FRMWK_MEMMGR_SRC     ?= $(FRAMEWORK_BASE_DIR)/MemManager/Source
FRMWK_TMRMGR_SRC     ?= $(FRAMEWORK_BASE_DIR)/TimersManager/Source
FRMWK_PANIC_SRC      ?= $(FRAMEWORK_BASE_DIR)/Panic/Source
FRMWK_HEAP_SRC       ?= $(FRAMEWORK_BASE_DIR)/Common
FRMWK_LOWPOWER_SRC   ?= $(FRAMEWORK_BASE_DIR)/LowPower/Source/$(SDK_BOARD)
FRMWK_GPIO_SRC       ?= $(FRAMEWORK_BASE_DIR)/GPIO

ifeq ($(OTA),1)
    ifeq ($(ZBPRO_DEVICE_TYPE), ZED)
        NXP_OTA_APP          ?= $(ZIGBEE_BASE_DIR)/ZigbeeCommon/SelectiveOtaApp1/JN518x_mcux/ReleaseEndDevice
    else
        NXP_OTA_APP          ?= $(ZIGBEE_BASE_DIR)/ZigbeeCommon/SelectiveOtaApp1/JN518x_mcux/Release
    endif
endif


##################################################################################
## Source included by default
ifeq ($(OTA),1)
    ifneq ($(SELOTA),NONE)
        CFLAGS += -D$(SELOTA)
        JN518X_TOOL = jn518x_image_tool.py -s 163840
        NXP_MANUFACTURER_CODE     ?= 0x1037
        ifeq ($(ZBPRO_DEVICE_TYPE), ZED)
            NXP_STRING                ?= ZBSTACK_JN5189_APP1_ENCRYPTEDZED
        else
            NXP_STRING                ?= ZBSTACK_JN5189_APP1_ENCRYPTEDZCR
        endif
        NXP_STACK_OTA_DEVICE_ID   ?= 0x0000
    endif
endif

ifneq ($(SELOTA),APP1)
    LDLIBS += _crypto_m4
    APPSRC += board.c
    APPSRC += clock_config.c
    APPSRC += system_$(SDK_DEVICE_NAME).c
    APPSRC += startup_$(SDK_DEVICE_NAME).c
    APPSRC += fsl_wwdt.c
    APPSRC += fsl_clock.c
    APPSRC += fsl_reset.c
    APPSRC += fsl_rng.c
    APPSRC += fsl_spifi.c
    APPSRC += fsl_usart.c
    APPSRC += fsl_flexcomm.c
    APPSRC += fsl_flash.c
    APPSRC += fsl_common.c
    APPSRC += fsl_aes.c
    APPSRC += fsl_power.c
    APPSRC += fsl_wtimer.c
    APPSRC += fsl_inputmux.c
    APPSRC += fsl_fmeas.c
    APPSRC += fsl_sha.c
    APPSRC += Exceptions_NVIC.c
    APPSRC += MicroExceptions_arm.c
    APPSRC += Debug.c
    ifeq ($(OTA),1)
        APPSRC += OtaSupport.c
        APPSRC += OtaUtils.c
        APPSRC += psector_api.c
    endif
    APPSRC += FunctionLib.c
    APPSRC += SecLib.c
    ifeq ($(R23_UPDATES),1)
        APPSRC += SecLib_ecp256_sw.c
    endif
    APPSRC += RNG.c
    APPSRC += GenericList.c
    APPSRC += Messaging.c
    APPSRC += MemManager.c
    APPSRC += TimersManager.c
    APPSRC += TMR_Adapter.c
    APPSRC += fsl_ctimer.c
    APPSRC += fsl_rtc.c
    APPSRC += Panic.c
    APPSRC += fsl_dma.c
    APPSRC += MicroInt_arm_sdk2.c
    APPSRC += PWR.c
    APPSRC += PWR_setjmp.S
    APPSRC += PWRLib.c
    APPSRC += GPIO_Adapter.c
    APPSRC += fsl_str.c
    APPSRC += serial_manager.c
    APPSRC += serial_port_uart.c
    APPSRC += usart_adapter.c
    APPSRC += fsl_assert.c
    APPSRC += Heap.c
    ifeq ($(OTA),1)
        ifeq ($(OTA_INTERNAL_STORAGE),1)
            APPSRC += Eeprom_InternalFlash.c
        else
            APPSRC += Eeprom_MX25R8035F.c
        endif
    endif
endif

ifeq ($(SELOTA),APP0)
    APPSRC += app_dependencies.c
    APPSRC += app_jumptable.S
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Selective_OTA/Include
endif


ifeq ($(SELOTA),APP1)
    APPSRC += startup_jn5189_app1.c
endif
##################################################################################
## INCLUDE paths

INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PWRM/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PDUM/Include

INCFLAGS += -I$(GENERIC_LIST_SRC)
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/PDM/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/DBG/Include

INCFLAGS += -I$(BOARD_LEVEL_SRC)
INCFLAGS += -I$(CHIP_SYSTEM_SRC)
INCFLAGS += -I$(FSL_EXCEPTIONS_SRC)/../inc
INCFLAGS += -I$(SEL_OTA_SRC)/../Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/DebugFifo/Include
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/OSAbstraction/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/FunctionLib
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/SecLib
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/RNG/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/MemManager/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Panic/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Messaging/Interface
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/OtaSupport/Source/../Interface/
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/TimersManager/Interface/
INCFLAGS += -I$(FSL_EEPROM_INT)
INCFLAGS += -I$(FSL_EEPROM_GEN)/../Interface/
INCFLAGS += -I$(FSL_EEPROM_INT)/../Interface/
INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/Panic/Interface/
INCFLAGS += -I$(DEVICE_SP_DRIVERS)
INCFLAGS += -I$(FSL_COMPONENTS)/serial_manager/
INCFLAGS += -I$(FSL_COMPONENTS)/uart

ifeq ($(OTA),1)
    ifeq ($(OTA_INTERNAL_STORAGE),1)
        CFLAGS +=  -DgFlashEraseDuringWrite=0
        CFLAGS +=  -DgInvalidateHeaderLength=336
        CFLAGS += -DgEepromType_d=gEepromDevice_InternalFlash_c
        CFLAGS += -DgOtaVerifyWrite_d=0
        CFLAGS += -DgBootData_None_c=1
        CFLAGS += -DgEePromParams_BufferSize_c=512
        CFLAGS += -DgEepromParams_bufferedWrite_c=1
        CFLAGS += -DgEepromParams_CurrentOffset=0
    else
        CFLAGS += -DgEepromParams_ResetBitmap=1
        CFLAGS += -DgFlashEraseDuringWrite=0
        CFLAGS += -DgOtaVerifyWrite_d=0
        CFLAGS += -DgBootData_None_c=1
        CFLAGS += -DgEepromType_d=gEepromDevice_MX25R8035F_c
    endif
endif

ifneq ($(SELOVERIDE),1)
    CFLAGS  += -DgPWRM_Support=1
    CFLAGS  += -DgSupportBle=0
    CFLAGS  += -DcPWR_FullPowerDownMode=1
    INCFLAGS += -I$(FRMWK_LOWPOWER_SRC)/../../Interface/$(SDK_BOARD)
    INCFLAGS += -I$(FRAMEWORK_BASE_DIR)/GPIO
endif

ZIGBEE_BASE_SRC = $(OSA_BASE_SRC):$(ZIGBEE_COMMON_SRC):$(OS_ABSTRACT_SRC):$(GENERIC_LIST_SRC):$(BOARD_LEVEL_SRC)\
                  :$(CHIP_STARTUP_SRC):$(CHIP_SYSTEM_SRC):$(FSL_EXCEPTIONS_SRC):$(DEBUG_FIFO_SRC)\
                  :$(FRMWK_RNG_SRC):$(FRMWK_SECLIB_SRC):$(FRMWK_FUNCLIB_SRC):$(FRMWK_MSG_SRC)\
                  :$(ZIGBEE_COMMON_SRC)/../SelectiveOtaApp0/Source:$(FRMWK_MEMMGR_SRC)\
                  :$(FRMWK_TMRMGR_SRC):$(ZIGBEE_COMMON_SRC)/../SelectiveOtaApp1/Source\
                  :$(FSL_EEPROM_INT):$(FSL_OTA):$(FSL_EEPROM_GEN):$(FUNCTIONLIB):$(FRMWK_PANIC_SRC)\
                  :$(FRMWK_HEAP_SRC):$(FRMWK_LOWPOWER_SRC):$(FRMWK_GPIO_SRC):$(DEVICE_SP_DRIVERS)\
                  :$(FSL_COMPONENTS)/serial_manager:$(FSL_COMPONENTS)/uart:$(DEVICE_SP_UTILITIES)\
                  :$(DEVICE_SP_UTILITIES)/str:$(DEVICE_SP_UTILITIES)/debug_console\
				  :$(ZIGBEE_BASE_DIR)/platform/$(ZIGBEE_PLAT)/platform

ifneq ($(SELOTA),APP1)
    # Currently there is no support for PWRM on K32W1
    APPLIBS += PWRM
endif

ifneq ($(SELOTA),APP0)
    ifneq ($(PDM_NONE),1)
        APPLIBS += PDM
    endif
endif

# K32W0 LDFLAGS
LDFLAGS += -Wl,--defsym,HEAP_SIZE=$(HEAP_SIZE)
LDFLAGS += -L $(ZIGBEE_BASE_DIR)/BuildConfig/ZBPro/Build
LDFLAGS += -L $(FRMWK_SECLIB_SRC)
