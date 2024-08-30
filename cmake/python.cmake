# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

set(PYTHON_MINIMUM_REQUIRED 3.6)

if(NOT DEFINED ENV{VIRTUAL_ENV})
    message(STATUS "No Python virtual environment activated - trying to find one...")
    if(EXISTS ${NXP_ZB_BASE}/.venv)
        message(STATUS "Found virtual environment at ${NXP_ZB_BASE}/.venv, activating it...")
        set(ENV{VIRTUAL_ENV} ${NXP_ZB_BASE}/.venv)
        set(Python3_FIND_VIRTUALENV FIRST)
    else()
        message(WARNING "Couldn't find a virtual environment - it is recommended to use one.")
    endif()
endif()

find_package(Python3 ${PYTHON_MINIMUM_REQUIRED} REQUIRED)