# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.kw45_k32w1_mcxw71 OR
    CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.kw47_mcxw72)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/K32W1)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform.rw61x)
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/RW612)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.platform_ncp_host)
    mcux_add_source(
        SOURCES zb_platform.h
                NCP_HOST/cmake/mbedtls_sdk.cmake
                NCP_HOST/cmake/mbedtls_git.cmake
                NCP_HOST/cmake/pdum.cmake
                NCP_HOST/cmake/utils.cmake
                NCP_HOST/cmake/NxpZbNcpHostConfig.cmake
                NCP_HOST/cmake/toolchains/arm-linux-gnueabihf.cmake
                NCP_HOST/cmake/toolchains/x86_64-linux-gnu.cmake
                NCP_HOST/framework/Common/app.h
                NCP_HOST/framework/Common/dbg.h
                NCP_HOST/framework/Common/glue.h
                NCP_HOST/framework/Common/jendefs.h
                NCP_HOST/framework/Common/MicroSpecific.h
                NCP_HOST/framework/Common/EmbeddedTypes.h
                NCP_HOST/framework/OtaSupport/Interface/OtaSupport.h
                NCP_HOST/framework/OtaSupport/Source/Posix/OtaSupport_adapter.c
                NCP_HOST/framework/PDM/Interface/PDM.h
                NCP_HOST/framework/PDM/Source/Posix/PDM_adapter.c
                NCP_HOST/framework/PDUM/Include/pdum_apl.h
                NCP_HOST/framework/PDUM/Include/pdum_common.h
                NCP_HOST/framework/PDUM/Include/pdum_nwk.h
                NCP_HOST/framework/PDUM/Source/pdum_private.h
                NCP_HOST/framework/PDUM/Source/pdum.c
                NCP_HOST/framework/PDUM/Source/pdum_apl.c
                NCP_HOST/framework/PDUM/Source/pdum_dbg.c
                NCP_HOST/framework/PDUM/Source/pdum_nwk.c
                NCP_HOST/framework/PWRM/Include/pwrm.h
                NCP_HOST/framework/SecLib/Interface/SecLib.h
                NCP_HOST/framework/SecLib/Interface/aessw_ccm.h
                NCP_HOST/ieee-802.15.4/AppApi.h
                NCP_HOST/ieee-802.15.4/mac_pib.h
                NCP_HOST/ieee-802.15.4/mac_sap.h
                NCP_HOST/ieee-802.15.4/MiniMac.h
                NCP_HOST/ieee-802.15.4/MiniMac_Pib.h
                NCP_HOST/ieee-802.15.4/MMAC.h
                NCP_HOST/ieee-802.15.4/tsv_pub.h
                NCP_HOST/platform/Posix/console.c
                NCP_HOST/platform/Posix/crypto.c
                NCP_HOST/platform/Posix/glue.c
                NCP_HOST/platform/Posix/leds.c
                NCP_HOST/platform/Posix/timer.c
                NCP_HOST/platform/Posix/uart.c
                NCP_HOST/platform/Posix/wdog.c
                NCP_HOST/third_party/mbedtls/ncp_host-mbedtls-config.h
    )
    mcux_add_include(
        INCLUDES .
    )
endif()


