# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform_ncp_host)
    mcux_add_source(
        SOURCES cmake/mbedtls_sdk.cmake
                cmake/NxpZbNcpHostConfig.cmake
                cmake/pdum.cmake
                cmake/utils.cmake
                cmake/toolchains/arm-linux.cmake
                cmake/toolchains/x86_64-linux-gnu.cmake
                framework/Common/app.h
                framework/Common/dbg.h
                framework/Common/glue.h
                framework/Common/jendefs.h
                framework/Common/MicroSpecific.h
                framework/Common/EmbeddedTypes.h
                framework/OtaSupport/Interface/OtaSupport.h
                framework/OtaSupport/Source/Posix/OtaSupport_adapter.c
                framework/PDM/Interface/PDM.h
                framework/PDM/Source/Posix/PDM_adapter.c
                framework/PDUM/Include/pdum_apl.h
                framework/PDUM/Include/pdum_common.h
                framework/PDUM/Include/pdum_nwk.h
                framework/PDUM/Source/pdum_private.h
                framework/PDUM/Source/pdum.c
                framework/PDUM/Source/pdum_apl.c
                framework/PDUM/Source/pdum_dbg.c
                framework/PDUM/Source/pdum_nwk.c
                framework/PWRM/Include/pwrm.h
                ieee-802.15.4/AppApi.h
                ieee-802.15.4/mac_pib.h
                ieee-802.15.4/mac_sap.h
                ieee-802.15.4/MiniMac.h
                ieee-802.15.4/MiniMac_Pib.h
                ieee-802.15.4/MMAC.h
                ieee-802.15.4/tsv_pub.h
                platform/Posix/console.c
                platform/Posix/crypto.c
                platform/Posix/glue.c
                platform/Posix/leds.c
                platform/Posix/timer.c
                platform/Posix/uart.c
                platform/Posix/wdog.c
                third_party/mbedtls/mbedtls.cmake
                third_party/mbedtls/ncp_host-mbedtls-config.h
    )
    mcux_add_include(
        INCLUDES .
    )
endif()






