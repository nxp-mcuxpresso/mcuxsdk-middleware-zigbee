include_guard(GLOBAL)


if (CONFIG_USE_middleware_wireless_zigbee_cmake)
# Add set(CONFIG_USE_middleware_wireless_zigbee_cmake true) in config.cmake to use this component

message("middleware_wireless_zigbee_cmake component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_doc)
# Add set(CONFIG_USE_middleware_wireless_zigbee_doc true) in config.cmake to use this component

message("middleware_wireless_zigbee_doc component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_all_libs)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_all_libs true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_all_libs component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_libs)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_libs true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_libs component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_libs_r23)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_libs_r23 true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_libs_r23 component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_ZED_libs)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_ZED_libs true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_ZED_libs component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_ZED_libs_r23)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_ZED_libs_r23 true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_ZED_libs_r23 component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee)
# Add set(CONFIG_USE_middleware_wireless_zigbee true) in config.cmake to use this component

message("middleware_wireless_zigbee component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_examples)
# Add set(CONFIG_USE_middleware_wireless_zigbee_examples true) in config.cmake to use this component

message("middleware_wireless_zigbee_examples component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_platform_common)
# Add set(CONFIG_USE_middleware_wireless_zigbee_platform_common true) in config.cmake to use this component

message("middleware_wireless_zigbee_platform_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/console.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/crypto.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/framework/PDM/PDM_adapter_nvs.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/framework/PWRM/PWRM_adapter.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/framework/SecLib/SecLib_.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/framework/SecLib/aes_mmo.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/common/timer.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_platform_k32w1)
# Add set(CONFIG_USE_middleware_wireless_zigbee_platform_k32w1 true) in config.cmake to use this component

message("middleware_wireless_zigbee_platform_k32w1 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/framework/PDM/PDM_adapter.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/framework/PWRM/PWRM_adapter.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/framework/SecLib/SecLib_.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/framework/SecLib/aes_mmo.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/buttons.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/console.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/crypto.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/glue.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/leds.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/timer.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/uart.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/uart_hal.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/K32W1/platform/wdog.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_platform_rw612)
# Add set(CONFIG_USE_middleware_wireless_zigbee_platform_rw612 true) in config.cmake to use this component

message("middleware_wireless_zigbee_platform_rw612 component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/buttons.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/glue.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/leds.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/rw61x_cpu2.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/uart.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/RW612/platform/wdog.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_libs_rw612)
# Add set(CONFIG_USE_middleware_wireless_zigbee_libs_rw612 true) in config.cmake to use this component

message("middleware_wireless_zigbee_libs_rw612 component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_platform_ncp_host)
# Add set(CONFIG_USE_middleware_wireless_zigbee_platform_ncp_host true) in config.cmake to use this component

message("middleware_wireless_zigbee_platform_ncp_host component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/OtaSupport/Source/Posix/OtaSupport_adapter.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/PDM/Source/Posix/PDM_adapter.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/PDUM/Source/pdum.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/PDUM/Source/pdum_apl.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/PDUM/Source/pdum_dbg.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/framework/PDUM/Source/pdum_nwk.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/console.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/crypto.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/glue.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/leds.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/timer.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/uart.c
  ${CMAKE_CURRENT_LIST_DIR}/platform/NCP_HOST/platform/Posix/wdog.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_zb_examples_common)
# Add set(CONFIG_USE_middleware_wireless_zigbee_zb_examples_common true) in config.cmake to use this component

message("middleware_wireless_zigbee_zb_examples_common component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_leds.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_zigbee_config.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_buttons.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_console.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_uart.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_crypto.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_zb_examples_common_ota_client)
# Add set(CONFIG_USE_middleware_wireless_zigbee_zb_examples_common_ota_client true) in config.cmake to use this component

message("middleware_wireless_zigbee_zb_examples_common_ota_client component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_ota_client.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_zb_examples_common_ota_server)
# Add set(CONFIG_USE_middleware_wireless_zigbee_zb_examples_common_ota_server true) in config.cmake to use this component

message("middleware_wireless_zigbee_zb_examples_common_ota_server component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/app_ota_server.c
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_zb_examples_collaterals)
# Add set(CONFIG_USE_middleware_wireless_zigbee_zb_examples_collaterals true) in config.cmake to use this component

message("middleware_wireless_zigbee_zb_examples_collaterals component is included from ${CMAKE_CURRENT_LIST_FILE}.")


endif()


if (CONFIG_USE_middleware_wireless_zigbee_zb_serial_link)
# Add set(CONFIG_USE_middleware_wireless_zigbee_zb_serial_link true) in config.cmake to use this component

message("middleware_wireless_zigbee_zb_serial_link component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/serial_link_cmds_wkr.c
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/serial_link_wkr.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/examples/zb_common/.
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Server)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Server true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Server component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_common.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_CustomCommandHandler.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_CustomReceiveCommands.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_server.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_ServerUpgradeManager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Include
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source
)


endif()


if (CONFIG_USE_middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Client)
# Add set(CONFIG_USE_middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Client true) in config.cmake to use this component

message("middleware_wireless_zigbee_core_ZCL_Clusters_OTA_Client component is included from ${CMAKE_CURRENT_LIST_FILE}.")

target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_common.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_CustomCommandHandler.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_CustomReceiveCommands.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_client.c
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source/OTA_ClientUpgradeManager.c
)

target_include_directories(${MCUX_SDK_PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Include
  ${CMAKE_CURRENT_LIST_DIR}/ZCL/Clusters/OTA/Source
)


endif()

