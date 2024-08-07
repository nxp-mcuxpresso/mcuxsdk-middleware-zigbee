# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_policy(SET CMP0079 NEW)

set(MBEDTLS_CLONE ${NXP_ZB_BASE}/platform/NCP_HOST/third_party/mbedtls)
string(CONCAT MBEDTLS_GIT_VERSION "mbedtls-" ${MBEDTLS_MIN_VERSION} ".0")

if(EXISTS "${MBEDTLS_CLONE}/repo")
    message(STATUS "Repo for mbedtls is already available")
else()
    message(STATUS "Clone mbedtls repository")
    include(FetchContent)
    FetchContent_Declare(mbetls_repo
      GIT_REPOSITORY "https://github.com/Mbed-TLS/mbedtls.git"
      GIT_TAG ${MBEDTLS_GIT_VERSION}
      SOURCE_DIR "${MBEDTLS_CLONE}/repo"
    )
    FetchContent_MakeAvailable(mbetls_repo)
endif()


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT NCP_HOST_MBEDTLS_CONFIG_FILE)
    set(NCP_HOST_MBEDTLS_CONFIG_FILE "\"ncp_host-mbedtls-config.h\"")
endif()

if(NOT NCP_HOST_MBEDTLS_CONFIG_FILE_PATH)
    set(NCP_HOST_MBEDTLS_CONFIG_FILE_PATH ${NXP_ZB_BASE}/platform/NCP_HOST/third_party/mbedtls/)
endif()

set(NCP_HOST_MBEDTLS_PATH ${MBEDTLS_CLONE}/repo)

set(ENABLE_TESTING OFF CACHE BOOL "Disable mbedtls test" FORCE)
set(ENABLE_PROGRAMS OFF CACHE BOOL "Disable mbetls program" FORCE)

string(REPLACE "-Wconversion" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
string(REPLACE "-Wconversion" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(MBEDTLS_TARGET_PREFIX ncp-host-)
set(mbedtls_target    "${MBEDTLS_TARGET_PREFIX}mbedtls")
set(mbedx509_target   "${MBEDTLS_TARGET_PREFIX}mbedx509")
set(mbedcrypto_target "${MBEDTLS_TARGET_PREFIX}mbedcrypto")

#Make sure to disable some CMAKE_C_FLAGS that would be added by mbedtls
# Instead use only CMAKE_C_FLAGS set by the application
set(CMAKE_COMPILER_IS_GNUCC OFF)
string(REPLACE "GNU" "G-N-U" CMAKE_C_COMPILER_ID "${CMAKE_C_COMPILER_ID}")
add_subdirectory(${NCP_HOST_MBEDTLS_PATH} ${PROJECT_BINARY_DIR}/mbedtls)
string(REPLACE "G-N-U" "GNU" CMAKE_C_COMPILER_ID "${CMAKE_C_COMPILER_ID}")
set(CMAKE_COMPILER_IS_GNUCC ON)

set(MBEDTLS_INCLUDE ${MBEDTLS_CLONE}/repo/include)

if(${CMAKE_C_COMPILER_ID} MATCHES "GNU")
    target_compile_options(${mbedcrypto_target}
        PRIVATE
            -Wno-unused-function
            -Wno-unused-variable
            -Wno-unused-const-variable
            -Wno-memset-elt-size
            -Wno-int-conversion
    )
    if (NOT "${MACHINE_TYPE}" STREQUAL "imx8")
        target_compile_options(${mbedcrypto_target}
            PRIVATE
                -m32
        )
        target_compile_options(${mbedtls_target}
            PRIVATE
                -m32
        )
        target_compile_options(${mbedx509_target}
            PRIVATE
                -m32
        )
    endif()
endif()
