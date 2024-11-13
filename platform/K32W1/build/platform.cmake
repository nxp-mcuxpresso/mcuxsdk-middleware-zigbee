# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Symbols can be defined by the application cmake file, 
# otherwise following default values will be used
# CONFIG_ZB_HEAP_SIZE     - Default value 0x8000
# CONFIG_ZB_STACK_SIZE    - Default value 0x2000
# CONFIG_ZB_SPLIT_MODE    - Default value 0 (standalone mode)

if (NOT DEFINED CONFIG_ZB_HEAP_SIZE)
    set(CONFIG_ZB_HEAP_SIZE 0x8000 CACHE INTERNAL "")
endif()

if (NOT DEFINED CONFIG_ZB_STACK_SIZE)
    set(CONFIG_ZB_STACK_SIZE 0x2000 CACHE INTERNAL "")
endif()

if (NOT DEFINED CONFIG_ZB_SPLIT_MODE)
    set(CONFIG_ZB_SPLIT_MODE 0 CACHE INTERNAL "")
endif()

# Various FWK related defines
mcux_add_configuration(CC "-DgHwParamsProdDataPlacement_c=gHwParamsProdDataPlacementLegacyMode_c")

# K32W1 LDFLAGS
mcux_add_armgcc_configuration(LD "-Xlinker --defsym=gUseNVMLink_d=1")

# Find the suitable IEEE lib to use
if(CONFIG_ZB_SPLIT_MODE MATCHES "1")
    # PHY SPLIT
    mcux_add_configuration(CC "-DUSE_NBU=1")
    mcux_add_configuration(CC "-DUSE_SMU2_AS_SYSTEM_MEMORY=1")
    mcux_add_configuration(CC "-DHAL_RPMSG_SELECT_ROLE=0")
elseif(CONFIG_ZB_SPLIT_MODE MATCHES "2")
    # NBU on MAC
    mcux_add_configuration(CC "-DUSE_NBU=1")
    mcux_add_configuration(CC "-DUSE_SMU2_AS_SYSTEM_MEMORY=1")
    mcux_add_configuration(CC "-DHAL_RPMSG_SELECT_ROLE=0")
else()
    # Standalone mode
endif()

mcux_add_armgcc_configuration(
   LD "-Xlinker --defsym=__stack_size__=${CONFIG_ZB_STACK_SIZE}\
       -Xlinker --defsym=__heap_size__=${CONFIG_ZB_HEAP_SIZE}\
       -Xlinker --defsym=m_cstack_ram1=1"
)
# Defines specific to zigbee applications
mcux_add_configuration(
    CC "-DFSL_OSA_MAIN_FUNC_ENABLE=1\
        -DFSL_OSA_TASK_ENABLE=1\
        -DgNvStorageIncluded_d=1\
        -DgMemManagerLightExtendHeapAreaUsage=1\
        -DgAppHighSystemClockFrequency_d=1")

# Defines specific to OS
if(CONFIG_MCUX_COMPONENT_component.osa_bm)
    mcux_add_configuration(CC "-DSDK_OS_BAREMETAL")

    mcux_add_configuration(
        CC "-DosNumberOfSemaphores=0\
            -DosNumberOfMutexes=0\
            -DosNumberOfMessageQs=0\
            -DosNumberOfMessages=0\
            -DosNumberOfEvents=5\
            -DgMainThreadPriority_c=7\
            -DgTaskMultipleInstancesManagement_c=0\
            -DFSL_OSA_BM_TIMER_CONFIG=FSL_OSA_BM_TIMER_SYSTICK"
        )

elseif(CONFIG_MCUX_COMPONENT_component.osa_free_rtos)
    mcux_add_configuration(CC "-DFSL_RTOS_FREE_RTOS")
#    mcux_add_configuration(CC "-DZIGBEE_EVENT_IMPL")
    mcux_add_configuration(CC "-DSDK_OS_FREE_RTOS")
    mcux_add_configuration(CC "-DgMainThreadStackSize_c=5120")
    mcux_add_configuration(CC "-DgTotalHeapSize_c=12288")

endif()
