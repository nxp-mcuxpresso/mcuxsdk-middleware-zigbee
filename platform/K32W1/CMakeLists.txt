# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

mcux_set_variable(JENNIC_CHIP_FAMILY_NAME "_JN518x")
mcux_set_variable(JENNIC_CHIP_FAMILY "JN518x")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.kw45_k32w1_mcxw71)
    mcux_add_source(
        SOURCES ../zb_platform.h
                framework/Common/dbg.h
                framework/Common/glue.h
                framework/Common/Heap.h
                framework/Common/jendefs.h
                framework/Common/MicroSpecific.h
                framework/Common/MicroSpecific_arm_sdk2.h
                framework/Common/MicroSpecific_JN518x.h
                framework/PDM/PDM_adapter.c
                framework/PWRM/PWRM_adapter.c
                framework/PWRM/Include/pwrm.h
                framework/SecLib/aes_mmo.c
                framework/SecLib/aessw_ccm.h
                framework/SecLib/SecLib_.c
                platform/buttons.c
                platform/console.c
                platform/crypto.c
                platform/glue.c
                platform/leds.c
                platform/timer.c
                platform/uart_hal.c
                platform/uart.c
                platform/wdog.c
    )
    mcux_add_include(
        INCLUDES ../
                 framework/Common
                 framework/PWRM/Include
                 framework/SecLib
    )
    mcux_add_macro(
       "JENNIC_CHIP_FAMILY_NAME=${JENNIC_CHIP_FAMILY_NAME} \
        JENNIC_CHIP_FAMILY=${JENNIC_CHIP_FAMILY} \
        JENNIC_CHIP_FAMILY_JN518x \
        __JN518X__ \
       CPU_JN518X"
    )
endif()

if (CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.kw47_mcxw72)
    mcux_add_source(
        SOURCES ../zb_platform.h
                framework/Common/dbg.h
                framework/Common/glue.h
                framework/Common/Heap.h
                framework/Common/jendefs.h
                framework/Common/MicroSpecific.h
                framework/Common/MicroSpecific_arm_sdk2.h
                framework/Common/MicroSpecific_JN518x.h
                framework/PDM/PDM_adapter.c
                framework/PWRM/PWRM_adapter.c
                framework/PWRM/Include/pwrm.h
                framework/SecLib/aes_mmo.c
                framework/SecLib/aessw_ccm.h
                framework/SecLib/SecLib_.c
                platform/buttons.c
                platform/console.c
                platform/crypto.c
                platform/glue.c
                platform/leds.c
                platform/timer.c
                platform/uart_hal.c
                platform/uart.c
                platform/wdog.c
    )
    mcux_add_include(
        INCLUDES ../
                 framework/Common
                 framework/PWRM/Include
                 framework/SecLib
    )
    mcux_add_macro(
       "JENNIC_CHIP_FAMILY_NAME=${JENNIC_CHIP_FAMILY_NAME} \
        JENNIC_CHIP_FAMILY=${JENNIC_CHIP_FAMILY} \
        JENNIC_CHIP_FAMILY_JN518x \
        __JN518X__ \
       CPU_JN518X"
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.core_libs)
    mcux_add_library(
        LIBS libs/libZPSGP.a
             libs/libZPSIPAN.a
             libs/libZPSAPL.a
             libs/libZPSMAC_Mini_SOC.a
             libs/libZPSNWK.a
             libs/libZPSTSV.a
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.core_libs_r23)
    mcux_add_library(
        LIBS libs/libZPSGP.a
             libs/libZPSIPAN.a
             libs/libZPSAPL_R23.a
             libs/libZPSMAC_Mini_SOC.a
             libs/libZPSNWK_R23.a
             libs/libZPSTSV.a
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.zed_libs)
    mcux_add_library(
        LIBS libs/libZPSGP_ZED.a
             libs/libZPSIPAN_ZED.a
             libs/libZPSAPL.a
             libs/libZPSMAC_Mini_SOC.a
             libs/libZPSNWK_ZED.a
             libs/libZPSTSV.a
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.zed_libs_r23)
    mcux_add_library(
        LIBS libs/libZPSGP_ZED.a
             libs/libZPSIPAN_ZED.a
             libs/libZPSAPL_R23.a
             libs/libZPSMAC_Mini_SOC.a
             libs/libZPSNWK_ZED_R23.a
             libs/libZPSTSV.a
    )
endif()
