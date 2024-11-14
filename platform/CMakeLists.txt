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
    mcux_add_cmakelists(${CMAKE_CURRENT_LIST_DIR}/NCP_HOST)
endif()


