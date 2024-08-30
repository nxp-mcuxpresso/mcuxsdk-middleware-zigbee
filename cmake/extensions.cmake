# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

macro(nxp_zb_library_named name)
    # This is a macro because we need add_library() to be executed
    # within the scope of the caller.
    set(NXP_ZB_CURRENT_LIBRARY ${name})
    add_library(${name} STATIC "")
    target_link_libraries(${name} PUBLIC zb_interface)
endmacro()

function(nxp_zb_include_directories)
    target_include_directories(zb_interface INTERFACE ${ARGV})
endfunction()

function(nxp_zb_compile_definitions)
    target_compile_definitions(zb_interface INTERFACE ${ARGV})
endfunction()

function(nxp_zb_link_libraries)
    target_link_libraries(zb_interface INTERFACE ${ARGV})
endfunction()

function(nxp_zb_generate_zpsconfig configfile node_name output)
    get_target_property(TARGETHARDWARE zb_interface ZPSCONFIG_TARGETHARDWARE)
    get_target_property(ENDIANNESS zb_interface ZPSCONFIG_ENDIANNESS)
    get_target_property(ZPSAPL_LIB zb_interface ZPSCONFIG_ZSPAPL_LIB)
    get_target_property(ZPSNWK_LIB zb_interface ZPSCONFIG_ZSPNWK_LIB)
    add_custom_command(
        OUTPUT
        ${output}/zps_gen.c
        ${output}/zps_gen.h
        COMMAND sh ${NXP_ZB_BASE}/tools/ZPSConfig/Source/ZPSConfig
        ARGS
        -n ${node_name}
        -e ${ENDIANNESS}
        -t ${TARGETHARDWARE}
        -l ${ZPSNWK_LIB}
        -a ${ZPSAPL_LIB}
        -f ${configfile}
        -o ${output}
    )
endfunction()

function(nxp_zb_pad_string output_str input_str padchar length)
    # this is to support input strings that are larger than the output length
    string(SUBSTRING ${input_str} 0 ${length} _str)
    string(LENGTH "${_str}" _strlen)
    # compute the length to pad
    math(EXPR _padlen "${length} - ${_strlen}")
    if(_padlen GREATER 0)
        # just repeat the pad char at the end of the string
        string(REPEAT ${padchar} ${_padlen} _pad)
        string(APPEND _str ${_pad})
    endif()
    set(${output_str} ${_str} PARENT_SCOPE)
endfunction()

function(nxp_zb_build_mcuboot)
    add_custom_command(
        OUTPUT ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc/flash_release/sdk20-app.bin
        COMMAND sh
        ARGS ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc/build_flash_release.sh
        WORKING_DIRECTORY ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc
        USES_TERMINAL
    )
    add_custom_target(build_mcuboot ALL
        DEPENDS ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc/flash_release/sdk20-app.bin
    )
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mcuboot.bin
        COMMAND cp
        ARGS
        ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc/flash_release/sdk20-app.bin
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mcuboot.bin
        DEPENDS ${NXP_SDK_CORE}/boards/${CONFIG_ZB_BOARD}/ota_examples/mcuboot_opensource/armgcc/flash_release/sdk20-app.bin
    )
    add_custom_target(copy_mcuboot ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/mcuboot.bin
    )
endfunction()

function(nxp_zb_generate_versioned_elf target manufacturer_code image_type version_string version)
    get_target_property(name ${target} NAME)
    add_custom_command(
        OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${name}_v${version}.elf
        COMMAND ${Python3_EXECUTABLE} ${NXP_ZB_BASE}/tools/OTA/nxpzbota.py
        ARGS
        -log INFO
        --embed
        -i $<OUTPUT_CONFIG:$<TARGET_FILE:${target}>>
        -o ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${name}_v${version}.elf
        -OtaMan ${manufacturer_code}
        -OtaImgTyp ${image_type}
        -OtaVersionStr ${version_string}
        -OtaFileVersion ${version}
        DEPENDS $<OUTPUT_CONFIG:$<TARGET_FILE:${target}>>
    )
    add_custom_target(generate_${name}_v${version} ALL
        DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${name}_v${version}.elf
    )
endfunction()

function(nxp_zb_generate_pdumconfig configfile node_name output)
    get_target_property(ENDIANNESS zb_interface ZPSCONFIG_ENDIANNESS)
    add_custom_command(
        OUTPUT
        ${output}/pdum_apdu.S
        ${output}/pdum_gen.c
        ${output}/pdum_gen.h
        COMMAND sh ${NXP_ZB_BASE}/tools/PDUMConfig/Source/PDUMConfig
        ARGS
        -z ${node_name}
        -e ${ENDIANNESS}
        -f ${configfile}
        -o ${output}
    )
endfunction()

function(nxp_zb_export_target_to_bin target)
    get_target_property(type ${target} TYPE)
    get_target_property(name ${target} NAME)
    get_target_property(is_imported ${target} IMPORTED)
    if(is_imported)
        get_target_property(target_file ${target} IMPORTED_LOCATION)
    else()
        set(target_file $<OUTPUT_CONFIG:$<TARGET_FILE:${target}>>)
    endif()
    if(type MATCHES "EXECUTABLE")
        set(target_bin_filename ${name}.bin)
        add_custom_command(
            OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_bin_filename}
            COMMAND ${CMAKE_OBJCOPY}
            ARGS -v -O binary ${target_file} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_bin_filename}
            DEPENDS ${target_file}
        )
        add_custom_target(export_${target}_to_bin ALL
            DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_bin_filename}
        )
    endif()
endfunction()

function(nxp_zb_export_target_to_srec target)
    get_target_property(type ${target} TYPE)
    get_target_property(name ${target} NAME)
    if(type MATCHES "EXECUTABLE")
        # message(STATUS "Target ${target} will be exported to srec format")
        set(target_srec_filename ${name}.srec)
        add_custom_command(
            OUTPUT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_srec_filename}
            COMMAND ${CMAKE_OBJCOPY}
            ARGS -v -O srec $<OUTPUT_CONFIG:$<TARGET_FILE:${target}>> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_srec_filename}
            DEPENDS $<OUTPUT_CONFIG:$<TARGET_FILE:${target}>>
        )
        add_custom_target(export_${target}_to_srec ALL
            DEPENDS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${target_srec_filename}
        )
    endif()
endfunction()

function(message)
    list(GET ARGV 0 type)
    if(((type STREQUAL FATAL_ERROR OR type STREQUAL SEND_ERROR OR type STREQUAL WARNING OR type STREQUAL AUTHOR_WARNING) AND (QUIET))
        OR (NOT QUIET))
        list(REMOVE_AT ARGV 0)
        _message(${type} "${ARGV}")
    endif()
endfunction()

function(nxp_zb_print_config)
    message(STATUS "********************************")
    message(STATUS "*** NXP Zigbee configuration ***")
    get_cmake_property(vars VARIABLES)
    list(REMOVE_DUPLICATES vars)
    list(SORT vars)
    foreach(var ${vars})
        if(var MATCHES "CONFIG_ZB")
            message(STATUS "${var}=${${var}}")
        endif()
    endforeach()
    message(STATUS "********************************")
endfunction()

function(generate_unique_target_name_from_filename filename target_name)
    get_filename_component(basename ${filename} NAME)
    string(REPLACE "." "_" x ${basename})
    string(REPLACE "@" "_" x ${x})

    string(MD5 unique_chars ${filename})

    set(${target_name} gen_${x}_${unique_chars} PARENT_SCOPE)
endfunction()

function(generate_inc_file
    source_file    # The source file to be converted to hex
    generated_file # The generated file
    )
  add_custom_command(
    OUTPUT ${generated_file}
    COMMAND
    ${Python3_EXECUTABLE}
    ${NXP_ZB_BASE}/cmake/zephyr/tools/file2hex.py
    ${ARGN} # Extra arguments are passed to file2hex.py
    --file ${source_file}
    > ${generated_file} # Does pipe redirection work on Windows?
    DEPENDS ${source_file}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endfunction()

function(generate_inc_file_for_gen_target
    target          # The cmake target that depends on the generated file
    source_file     # The source file to be converted to hex
    generated_file  # The generated file
    gen_target      # The generated file target we depend on
                    # Any additional arguments are passed on to file2hex.py
    )
  generate_inc_file(${source_file} ${generated_file} ${ARGN})

  # Ensure 'generated_file' is generated before 'target' by creating a
  # dependency between the two targets

  add_dependencies(${target} ${gen_target})
endfunction()

function(generate_inc_file_for_target
    target          # The cmake target that depends on the generated file
    source_file     # The source file to be converted to hex
    generated_file  # The generated file
                    # Any additional arguments are passed on to file2hex.py
    )
  # Ensure 'generated_file' is generated before 'target' by creating a
  # 'custom_target' for it and setting up a dependency between the two
  # targets

  # But first create a unique name for the custom target
  generate_unique_target_name_from_filename(${generated_file} generated_target_name)

  add_custom_target(${generated_target_name} DEPENDS ${generated_file})
  generate_inc_file_for_gen_target(${target} ${source_file} ${generated_file} ${generated_target_name} ${ARGN})
endfunction()
