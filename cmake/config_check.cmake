# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_ZB_LEGACY AND CONFIG_ZB_R23)
    message(FATAL_ERROR "CONFIG_ZB_LEGACY and CONFIG_ZB_R23 are mutually exclusive, select only one of them.")
endif()
