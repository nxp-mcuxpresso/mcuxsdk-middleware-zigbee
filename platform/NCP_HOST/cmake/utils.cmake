# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

function(check_mbedtls_is_valid mbedtls_valid)
    if(EXISTS ${NXP_SDK_BASE}/middleware/mbedtls/include/mbedtls/version.h)
        # Retrieve version (major.minor) from version file and check against minimum requirement
        execute_process(
            COMMAND sed -n "s/.*VERSION_STRING *\"\\(.*\\)\"/\\1/p" ${NXP_SDK_BASE}/middleware/mbedtls/include/mbedtls/version.h
            COMMAND cut -d "." -f 1-2
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            OUTPUT_VARIABLE SDK_MBEDTLS_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE)

        if (${SDK_MBEDTLS_VERSION} LESS ${MBEDTLS_MIN_VERSION})
            message(STATUS "SDK MBEDTLS version is below ${MBEDTLS_MIN_VERSION}, use environment variable MBEDTLS_ORIGIN")
            message(STATUS "Usage example: `export MBEDTLS_ORIGIN=GIT` OR `export MBEDTLS_ORIGIN=SYSTEM`")
            set(${mbedtls_valid} "NO" PARENT_SCOPE)
        endif()
    else()
        message(STATUS "MBEDTLS is not present in SDK, use environment variable MBEDTLS_ORIGIN")
        message(STATUS "Usage example: `export MBEDTLS_ORIGIN=GIT` OR `export MBEDTLS_ORIGIN=SYSTEM`")
        set(${mbedtls_valid} "NO" PARENT_SCOPE)
    endif()
endfunction()

function(use_mbedtls_as_package)
    set(ENV_MbedTLS_DIR $ENV{MbedTLS_DIR})
    find_package(MbedTLS)
    if(MbedTLS_FOUND)
        message(STATUS "Using preinstalled MbedTLS package " ${MbedTLS_DIR})
        set(MBEDTLS_LIB_NAME MbedTLS::mbedcrypto PARENT_SCOPE)
    else()
        if("$ENV{MbedTLS_DIR}" STREQUAL "")
            message(FATAL_ERROR "Please set MbedTLS_DIR with mbedtls installation path")
        endif()
        message(FATAL_ERROR "Unable to find mbedtls package")
    endif()
    set(MBEDTLS_ORIGIN "SYSTEM" PARENT_SCOPE)
endfunction()