# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

# Symbols can be defined by the application cmake file, otherwise
# following default values will be used
# CONFIG_JENNIC_CHIP           - Default value JN5189
# CONFIG_JENNIC_CHIP_FAMILY    - Default value JN518x
# CONFIG_JENNIC_STACK          - Default value MAC
# CONFIG_JENNIC_MAC            - Default value MiniMac


if(NOT DEFINED CONFIG_JENNIC_CHIP)
    set(CONFIG_JENNIC_CHIP "JN5189" CACHE STRING "")
endif()

if(NOT DEFINED CONFIG_JENNIC_CHIP_FAMILY)
    set(CONFIG_JENNIC_CHIP_FAMILY "JN518x" CACHE STRING "")
endif()

if(NOT DEFINED CONFIG_JENNIC_STACK)
    set(CONFIG_JENNIC_STACK "MAC" CACHE STRING "")
endif()

if(NOT DEFINED CONFIG_JENNIC_MAC)
    set(CONFIG_JENNIC_MAC "MiniMac" CACHE STRING "")
endif()

mcux_add_configuration(
    CC "-DJENNIC_CHIP=${CONFIG_JENNIC_CHIP}\
        -DJENNIC_CHIP_${CONFIG_JENNIC_CHIP}\
        -DJENNIC_CHIP_NAME=_${CONFIG_JENNIC_CHIP}\
        -DJENNIC_CHIP_FAMILY=${CONFIG_JENNIC_CHIP_FAMILY}\
        -DJENNIC_CHIP_FAMILY_${CONFIG_JENNIC_CHIP_FAMILY}\
        -DJENNIC_CHIP_FAMILY_NAME=_${CONFIG_JENNIC_CHIP_FAMILY}\
        -D${CONFIG_JENNIC_CHIP}=5189\
        -D${CONFIG_JENNIC_CHIP_FAMILY}=5189\
        -DJENNIC_STACK_${CONFIG_JENNIC_STACK}\
        -DJENNIC_MAC_${CONFIG_JENNIC_MAC}"
)

mcux_add_configuration(
    CC "-DLITTLE_ENDIAN_PROCESSOR\
        -DUSE_PB_RAM_AS_SYSTEM_MEMORY=1"
)

# default to optimise for size
mcux_add_configuration(CC "-Os")
mcux_add_configuration(LD "-Os")
mcux_add_configuration(CC "-ffunction-sections -fdata-sections -ffreestanding -fno-builtin")

# omit frame pointer by default
mcux_add_configuration(CC "-fomit-frame-pointer")
mcux_add_configuration(LD "-fomit-frame-pointer")

# Default to smallest possible enums
mcux_add_configuration(CC "-fshort-enums")
mcux_add_configuration(LD "-fshort-enums")

mcux_add_armgcc_configuration(
   LD "-Xlinker --gc-sections\
       -Xlinker --print-memory-usage"
)

# Chip independent compiler options
mcux_add_configuration(CC "-Wall -Wunreachable-code")
