set(CONFIG_ZB_USE_FREERTOS ON)
set(CONFIG_ZB_FREERTOS_CONFIG "${APPLICATION_SOURCE_DIR}/src/freertos/FreeRTOSConfig.h" CACHE STRING "")
set(CONFIG_ZB_TRACE_APP ON CACHE BOOL "Enable TRACE_APP logs")
set(CONFIG_ZB_TRACE_ZCL ON CACHE BOOL "Enable TRACE_ZCL logs")