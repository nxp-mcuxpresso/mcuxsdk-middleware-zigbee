# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

set(MCUX_SDK_PROJECT_NAME "zb_platform")
set(MCUX_DEVICE "RW612")
set(CONFIG_CORE "cm33")
set(CONFIG_DEVICE "RW612")
set(CONFIG_DEVICE_ID "RW612")
set(CONFIG_FPU "SP_FPU")
set(CONFIG_DSP "NO_DSP")
set(CONFIG_CORE_ID "cm33")
set(CONFIG_TOOLCHAIN "armgcc")
set(CONFIG_USE_COMPONENT_CONFIGURATION OFF)
set(CONFIG_USE_device_RW612_CMSIS ON)
set(CONFIG_USE_device_RW612_system ON)
set(CONFIG_USE_device_RW612_startup ON)
set(CONFIG_USE_CMSIS_Include_core_cm ON)
set(CONFIG_USE_driver_common ON)
set(CONFIG_USE_driver_reset ON)
set(CONFIG_USE_driver_clock ON)
set(CONFIG_USE_driver_flexcomm ON)
set(CONFIG_USE_driver_ostimer ON)
set(CONFIG_USE_driver_ctimer ON)
set(CONFIG_USE_driver_trng ON)
set(CONFIG_USE_driver_power ON)
set(CONFIG_USE_driver_gdma ON)
set(CONFIG_USE_driver_imu ON)
set(CONFIG_USE_driver_inputmux ON)
set(CONFIG_USE_driver_pint ON)
set(CONFIG_USE_driver_inputmux_connections ON)
set(CONFIG_USE_driver_flexspi ON)
set(CONFIG_USE_driver_cache_cache64 ON)
set(CONFIG_USE_driver_lpc_gpio ON)
set(CONFIG_USE_driver_lpc_rtc ON)
set(CONFIG_USE_driver_conn_fwloader ON)
set(CONFIG_USE_driver_cns_io_mux ON)
set(CONFIG_USE_driver_ocotp ON)
set(CONFIG_USE_driver_cns_adc ON)
set(CONFIG_USE_component_lists ON)
set(CONFIG_USE_component_osa_interface ON)
set(CONFIG_USE_component_serial_manager ON)
set(CONFIG_USE_component_ostimer_time_stamp_adapter ON)
set(CONFIG_USE_component_trng_adapter ON)
set(CONFIG_USE_component_wireless_imu_adapter ON)
set(CONFIG_USE_component_mflash_common ON)
set(CONFIG_USE_component_power_manager_core ON)
set(CONFIG_USE_component_power_manager_rdrw610 ON)
set(CONFIG_USE_component_timer_manager ON)
set(CONFIG_USE_component_ctimer_adapter ON)
set(CONFIG_USE_component_messaging ON)
set(CONFIG_USE_component_panic ON)
set(CONFIG_USE_component_button ON)
set(CONFIG_USE_component_led ON)
set(CONFIG_USE_component_lpc_gpio_adapter ON)
set(CONFIG_USE_component_els_pkc_platform_rw61x_interface_files ON)
set(CONFIG_USE_component_els_pkc ON)
set(CONFIG_USE_component_els_pkc_trng_type_rng4 ON)
set(CONFIG_USE_component_els_pkc_standalone_gdet ON)
set(CONFIG_USE_component_els_pkc_random_modes_ctr ON)
set(CONFIG_USE_component_els_pkc_els ON)
set(CONFIG_USE_component_els_pkc_pkc ON)
set(CONFIG_USE_component_els_pkc_trng ON)
set(CONFIG_USE_component_els_pkc_doc_rw61x ON)
set(CONFIG_USE_component_els_pkc_static_lib_rw61x ON)
set(CONFIG_USE_component_els_pkc_els_header_only ON)
set(CONFIG_USE_component_els_pkc_els_common ON)
set(CONFIG_USE_component_els_pkc_standalone_keyManagement ON)
set(CONFIG_USE_component_els_pkc_hash ON)
set(CONFIG_USE_component_els_pkc_core ON)
set(CONFIG_USE_component_els_pkc_session ON)
set(CONFIG_USE_component_els_pkc_key ON)
set(CONFIG_USE_component_els_pkc_mac_modes ON)
set(CONFIG_USE_component_els_pkc_aead_modes ON)
set(CONFIG_USE_component_els_pkc_data_integrity ON)
set(CONFIG_USE_component_els_pkc_cipher_modes ON)
set(CONFIG_USE_component_els_pkc_memory ON)
set(CONFIG_USE_component_els_pkc_param_integrity ON)
set(CONFIG_USE_component_els_pkc_flow_protection ON)
set(CONFIG_USE_component_els_pkc_secure_counter ON)
set(CONFIG_USE_component_els_pkc_pre_processor ON)
set(CONFIG_USE_component_els_pkc_toolchain ON)
set(CONFIG_USE_component_els_pkc_hashmodes ON)
set(CONFIG_USE_component_els_pkc_buffer ON)
set(CONFIG_USE_component_els_pkc_random ON)
set(CONFIG_USE_component_els_pkc_random_modes ON)
set(CONFIG_USE_component_els_pkc_prng ON)
set(CONFIG_USE_component_els_pkc_aes ON)
set(CONFIG_USE_component_els_pkc_ecc ON)
set(CONFIG_USE_component_els_pkc_math ON)
set(CONFIG_USE_component_els_pkc_rsa ON)
set(CONFIG_USE_component_els_pkc_mac ON)
set(CONFIG_USE_component_els_pkc_padding ON)
set(CONFIG_USE_component_els_pkc_hmac ON)
set(CONFIG_USE_component_els_pkc_aead ON)
set(CONFIG_USE_component_els_pkc_cipher ON)
set(CONFIG_USE_component_els_pkc_platform_rw61x ON)
set(CONFIG_USE_component_els_pkc_platform_rw61x_inf_header_only ON)
set(CONFIG_USE_utility_debug_console ON)
set(CONFIG_USE_utility_str ON)
set(CONFIG_USE_utility_assert ON)
set(CONFIG_USE_middleware_mbedtls ON)
set(CONFIG_USE_middleware_mbedtls_port_els_pkc ON)
set(CONFIG_USE_middleware_mbedtls_port_els ON)
set(CONFIG_USE_middleware_mbedtls_els_pkc_config ON)

if(CONFIG_ZB_BOARD MATCHES "rdrw612bga")
    set(CONFIG_BOARD "rdrw612bga")
    set(CONFIG_KIT "rdrw612bga")
    set(CONFIG_USE_component_mflash_rdrw610 ON)
    set(CONFIG_USE_driver_flash_config_rdrw612bga ON)
elseif(CONFIG_ZB_BOARD MATCHES "frdmrw612")
    set(CONFIG_BOARD "frdmrw612")
    set(CONFIG_KIT "frdmrw612")
    set(CONFIG_USE_component_mflash_frdmrw612 ON)
    set(CONFIG_USE_driver_flash_config_frdmrw612 ON)
else()
    message(WARNING "CONFIG_ZB_BOARD: This board is not supported by the SDK, you may have to provide your own files.")
endif()

if(CONFIG_ZB_CONSOLE_INTERFACE MATCHES "UART")
    set(CONFIG_USE_driver_flexcomm_usart ON)
    set(CONFIG_USE_component_usart_adapter ON)
    set(CONFIG_USE_component_serial_manager_uart ON)
else()
    message(FATAL_ERROR "CONFIG_ZB_CONSOLE_INTERFACE: Unsupported value. Only UART is supported for this platform.")
endif()

if(CONFIG_ZB_USE_FREERTOS)
    set(CONFIG_USE_driver_flexcomm_usart_freertos ON)
    set(CONFIG_USE_component_osa_free_rtos ON)
    set(CONFIG_USE_component_mem_manager_freertos ON)
    set(CONFIG_USE_middleware_freertos-kernel ON)
    set(CONFIG_USE_middleware_freertos-kernel_cm33_non_trustzone ON)
    set(CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_non_secure OFF)
    set(CONFIG_USE_middleware_freertos-kernel_cm33_trustzone_secure OFF)
    set(CONFIG_USE_middleware_freertos-kernel_heap_4 ON)
    set(CONFIG_USE_middleware_freertos-kernel_template ON)
    set(CONFIG_USE_middleware_freertos-kernel_extension ON)
    if(CONFIG_ZB_FREERTOS_CONFIG)
        target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
            ${CONFIG_ZB_FREERTOS_CONFIG}
        )
        set_source_files_properties(${CONFIG_ZB_FREERTOS_CONFIG} PROPERTIES COMPONENT_CONFIG_FILE "middleware_freertos-kernel_template")
    endif()
else()
    message(FATAL_ERROR "RW612 supports only FreeRTOS based applications. Please, enable CONFIG_ZB_USE_FREERTOS")
endif()

include(mcux_config)
include(all_devices)