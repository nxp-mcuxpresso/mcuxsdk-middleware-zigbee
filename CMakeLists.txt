cmake_minimum_required(VERSION 3.24)

enable_language(C CXX ASM)
set(CMAKE_C_STANDARD 99)

project(nxp_zb VERSION 1.0.0)

add_library(zb_interface INTERFACE)

nxp_zb_include_directories(
    BDB/Include
    BDB/Source/Common
    BDB/Source/FindAndBind
    BDB/Source/NwkFormation
    BDB/Source/NwkSteering
    BDB/Source/OutOfBand
    BDB/Source/TouchLink
    ZCIF/Include
    ZCIF/Source
    ZCL/Clusters/ApplianceManagement/Include
    ZCL/Clusters/ApplianceManagement/Source
    ZCL/Clusters/Closures/Include
    ZCL/Clusters/Closures/Source
    ZCL/Clusters/Commissioning/Include
    ZCL/Clusters/Commissioning/Source
    ZCL/Clusters/General/Include
    ZCL/Clusters/General/Source
    ZCL/Clusters/GreenPower/Include
    ZCL/Clusters/GreenPower/Source
    ZCL/Clusters/HVAC/Include
    ZCL/Clusters/HVAC/Source
    ZCL/Clusters/Lighting/Include
    ZCL/Clusters/Lighting/Source
    ZCL/Clusters/MeasurementAndSensing/Include
    ZCL/Clusters/OTA/Include
    ZCL/Clusters/OTA/Source
    ZCL/Clusters/SecurityAndSafety/Include
    ZCL/Clusters/SecurityAndSafety/Source
    ZCL/Clusters/SmartEnergy/Include
    ZCL/Clusters/SmartEnergy/Source
    ZCL/Devices/ZGP/Include
    ZCL/Devices/ZHA/ApplianceManagement/Include
    ZCL/Devices/ZHA/Closures/Include
    ZCL/Devices/ZHA/Generic/Include
    ZCL/Devices/ZHA/HVAC/Include
    ZCL/Devices/ZHA/SecurityAndSafety/Include
    ZCL/Devices/ZHA/SmartEnergy/Include
    ZCL/Devices/ZLO/Include
    ZPSAPL/Include
    ZPSNWK/Include
    ZPSTSV/Include
    ZPSMAC/Include
)

if(CONFIG_ZB_SINGLE_CHANNEL)
    nxp_zb_compile_definitions(SINGLE_CHANNEL=${CONFIG_ZB_SINGLE_CHANNEL})
endif()

add_subdirectory(platform/${CONFIG_ZB_PLATFORM} platform)

# Find the suitable ZPSNWK, ZPSGP, ZPSIPAN libs to use
if(CONFIG_ZB_DEVICE_TYPE MATCHES "ZED")
    set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP_ZED.a)
    set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN_ZED.a)
    if(CONFIG_ZB_WWAH)
        set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_WWAH_ZED.a)
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_ZED_R23.a)
        else()
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_ZED.a)
        endif()
    endif()
else()
    set(CONFIG_ZB_ZPSGP_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSGP.a)
    set(CONFIG_ZB_ZPSIPAN_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSIPAN.a)
    if(CONFIG_ZB_WWAH)
        set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_WWAH.a)
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK_R23.a)
        else()
            set(CONFIG_ZB_ZPSNWK_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSNWK.a)
        endif()
    endif()
endif()

# Find the suitable ZPSAPL lib to use
if(CONFIG_ZB_WWAH)
    set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_WWAH.a)
    nxp_zb_compile_definitions(WWAH_SUPPORT)
else()
    if(CONFIG_ZB_LEGACY)
        set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_LEGACY.a)
        nxp_zb_compile_definitions(LEGACY_SUPPORT)
    else()
        if(CONFIG_ZB_R23)
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL_R23.a)
            nxp_zb_compile_definitions(R23_UPDATES=1)
        else()
            set(CONFIG_ZB_ZPSAPL_LIB ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSAPL.a)
        endif()
    endif()
endif()

add_library(zpsapl STATIC IMPORTED)
set_target_properties(zpsapl PROPERTIES IMPORTED_LOCATION ${CONFIG_ZB_ZPSAPL_LIB})
set_target_properties(zb_interface PROPERTIES ZPSCONFIG_ZSPAPL_LIB ${CONFIG_ZB_ZPSAPL_LIB})
add_library(zpsnwk STATIC IMPORTED)
set_target_properties(zpsnwk PROPERTIES IMPORTED_LOCATION ${CONFIG_ZB_ZPSNWK_LIB})
set_target_properties(zb_interface PROPERTIES ZPSCONFIG_ZSPNWK_LIB ${CONFIG_ZB_ZPSNWK_LIB})
add_library(zpstsv STATIC IMPORTED)
set_target_properties(zpstsv PROPERTIES IMPORTED_LOCATION ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSTSV.a)
add_library(zpsmac STATIC IMPORTED)
set_target_properties(zpsmac PROPERTIES IMPORTED_LOCATION ${NXP_ZB_BASE}/platform/${CONFIG_ZB_PLATFORM}/libs/libZPSMAC_Mini_SOC.a)
add_library(zpsgp STATIC IMPORTED)
set_target_properties(zpsgp PROPERTIES IMPORTED_LOCATION ${CONFIG_ZB_ZPSGP_LIB})
add_library(zpsipan STATIC IMPORTED)
set_target_properties(zpsipan PROPERTIES IMPORTED_LOCATION ${CONFIG_ZB_ZPSIPAN_LIB})
nxp_zb_link_libraries(
    zpsapl
    zpsnwk
    zpstsv
    zpsmac
    zpsgp
    zpsipan
)
target_link_libraries(zpsmac INTERFACE zb_platform)
target_link_libraries(zpsnwk INTERFACE zb_platform)
target_link_libraries(zpsapl INTERFACE zpsnwk zpsmac)
