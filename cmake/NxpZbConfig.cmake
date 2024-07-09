# Copyright 2024 NXP
#
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.24)

set(ENV_NXP_ZB_BASE $ENV{NXP_ZB_BASE})
if((NOT DEFINED NXP_ZB_BASE) AND (DEFINED ENV_NXP_ZB_BASE))
    # Get rid of any double folder string before comparison, as example, user provides
    # NXP_ZB_BASE=//path/to//nxp_zb_base/ must also work.
    get_filename_component(NXP_ZB_BASE ${ENV_NXP_ZB_BASE} ABSOLUTE)
    set(NXP_ZB_BASE ${NXP_ZB_BASE} CACHE PATH "NXP Zigbee base")
endif()

get_filename_component(NXP_SDK_BASE ${NXP_ZB_BASE}/../../.. ABSOLUTE)
set(NXP_SDK_BASE ${NXP_SDK_BASE} CACHE PATH "NXP MCUXPRESSO SDK base")
if(EXISTS ${NXP_SDK_BASE}/core)
    message(STATUS "Found MCUXPRESSO SDK GITHUB")
    set(NXP_SDK_CORE ${NXP_SDK_BASE}/core)
elseif(EXISTS ${NXP_SDK_BASE}/bin/generator)
    message(STATUS "Found MCUXPRESSO SDK internal")
    set(NXP_SDK_CORE ${NXP_SDK_BASE})
elseif(EXISTS ${NXP_SDK_BASE}/SW-Content-Register.txt)
    message(STATUS "Found MCUXPRESSO SDK package")
    set(NXP_SDK_CORE ${NXP_SDK_BASE})
else()
    message(FATAL_ERROR "MCUXPRESSO SDK not found.")
endif()
set(NXP_SDK_MIDDLEWARE ${NXP_SDK_BASE}/middleware)

if(NOT CONFIG_ZB_PLATFORM)
    message(FATAL_ERROR "CONFIG_ZB_PLATFORM must be set !")
endif()

if(NOT DEFINED APPLICATION_SOURCE_DIR)
    set(APPLICATION_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH
        "Application Source Directory"
    )
endif()

if(NOT DEFINED APPLICATION_BINARY_DIR)
    set(APPLICATION_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} CACHE PATH
        "Application Binary Directory"
    )
endif()

list(PREPEND CMAKE_MODULE_PATH
    ${NxpZb_DIR}
    ${NxpZb_DIR}/toolchains
    ${NXP_SDK_CORE}/tools/cmake_toolchain_files
    ${APPLICATION_SOURCE_DIR}
)

# Include the config file from the application if it exists
include(app_config OPTIONAL)

# Include default configs
include(defaults)

# Check the config set by defaults and the application to detect dependencies issues early on
include(config_check)

# Use armgcc toolchain file
include(armgcc)
enable_language(C CXX ASM)

# Find python interpreter
include(python)

# Include nxp_zb extensions
include(extensions)

# Set ouput directories to find libs and binaries consistently
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${APPLICATION_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${APPLICATION_BINARY_DIR}/$<CONFIG>/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${APPLICATION_BINARY_DIR}/$<CONFIG>/bin)

if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES
        Debug
        Release
        MinSizeRel
        RelWithDebInfo
    )
    set(CMAKE_DEFAULT_BUILD_TYPE "MinSizeRel")
    set(CMAKE_CROSS_CONFIGS "all")
    set(CMAKE_DEFAULT_CONFIGS
        Debug
        MinSizeRel
    )
elseif(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "MinSizeRel")
endif()

# Configure NXP Zigbee project
add_subdirectory(${NXP_ZB_BASE} ${APPLICATION_BINARY_DIR}/zigbee)

set(NxpZb_FOUND True)

# Display the final config to the user
nxp_zb_print_config()

# Create a generic zb_app executable
# This allows a very simple applicative CMakeLists file, the application developer
# just has to add his sources to the zb_app target, here we make sure to provide default
# link to zb_interface and other default options
add_executable(zb_app "")

# Generate raw binary from the executable
nxp_zb_export_target_to_bin(zb_app)

target_link_libraries(zb_app
    PRIVATE
    zb_interface
    m
)

target_link_options(zb_app
    PRIVATE
    LINKER:-Map,$<TARGET_FILE_DIR:zb_app>/$<TARGET_PROPERTY:zb_app,NAME>.map
    LINKER:-print-memory-usage
)

set(ZB_APP_OPTIONAL_SOURCES)
if(CONFIG_ZB_BDB)
    list(APPEND ZB_APP_OPTIONAL_SOURCES
        ${NXP_ZB_BASE}/BDB/Source/Common/bdb_fr.c
        ${NXP_ZB_BASE}/BDB/Source/Common/bdb_start.c
        ${NXP_ZB_BASE}/BDB/Source/Common/bdb_state_machine.c
        ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_common.c
        ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_initiator.c
        ${NXP_ZB_BASE}/BDB/Source/FindAndBind/bdb_fb_target.c
        ${NXP_ZB_BASE}/BDB/Source/NwkFormation/bdb_nf.c
        ${NXP_ZB_BASE}/BDB/Source/NwkSteering/bdb_ns.c
        ${NXP_ZB_BASE}/BDB/Source/OutOfBand/bdb_DeviceCommissioning.c
    )
endif()
if(CONFIG_ZB_ZCL)
    list(APPEND ZB_APP_OPTIONAL_SOURCES
        ${NXP_ZB_BASE}/ZCIF/Source/dlist.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_attribute.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_buffer.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_clusterCommand.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_command.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_common.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_common.h
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingCommandHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingCommandSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_configureReportingResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_CustomCommandReceive.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_CustomCommandSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_defaultResponse.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedRequestHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedRequestSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesExtendedResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesRequestHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesRequestSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverAttributesResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsRequestHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsRequestSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_discoverCommandsResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_event.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_heap.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_internal.h
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_library_options.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_PDUbufferReadWrite.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_PDUbufferReadWriteString.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesRequestHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesRequestSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readAttributesResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationCommandHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationCommandSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_readReportingConfigurationResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportManager.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportMaths.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportScheduler.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportStringHandling.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_reportStructure.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_search.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_timer.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_transmit.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesRequestHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesRequestSend.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl_WriteAttributesResponseHandle.c
        ${NXP_ZB_BASE}/ZCIF/Source/zcl.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/mains_power_outlet.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/base_device.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/simple_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/on_off_output.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/remote_control.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Generic/Source/plug_control.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/ApplianceManagement/Source/home_gateway.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/ApplianceManagement/Source/white_goods.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Closures/Source/window_covering.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Closures/Source/door_lock_controller.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/Closures/Source/door_lock.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/HVAC/Source/thermostat_device.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/HVAC/Source/temperature_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/SecurityAndSafety/Source/zone.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/SecurityAndSafety/Source/ancillary_control_equipment.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/SecurityAndSafety/Source/control_and_indicating_equipment.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/SecurityAndSafety/Source/warning_device.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZHA/SmartEnergy/Source/smart_plug.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/colour_controller.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/colour_dimmable_light.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/colour_dimmer_switch.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/colour_scene_controller.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/colour_temperature_light.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/commission_endpoint.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/control_bridge.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/dimmable_ballast.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/dimmable_light.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/dimmable_plug.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/dimmer_switch.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/extended_colour_light.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/light_level_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/light_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/non_colour_controller.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/non_colour_scene_controller.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/occupancy_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/on_off_ballast.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/on_off_light_switch.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/on_off_light.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/on_off_plug.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZLO/Source/on_off_sensor.c
        ${NXP_ZB_BASE}/ZCL/Devices/ZGP/Source/gp.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_CustomCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_ServerUpgradeManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_client.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_common.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_CustomReceiveCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_server.c
        ${NXP_ZB_BASE}/ZCL/Clusters/OTA/Source/OTA_ClientUpgradeManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceEventsAndAlerts.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceIdentification.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceStatisticsServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceControl.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceControlCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceStatisticsClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceStatistics.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceStatisticsCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceControlServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/ApplianceManagement/Source/ApplianceControlClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/DoorLock.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/WindowCoveringCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/WindowCoveringCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/DoorLockCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/WindowCovering.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Closures/Source/DoorLockCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/OccupancySensing.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/TemperatureMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/FlowMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/ConcentrationMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/RelativeHumidityMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/IlluminanceLevelSensing.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/ElectricalMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/IlluminanceMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/MeasurementAndSensing/Source/PressureMeasurement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/zll_CommissionCmdHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/zll_UtilityCmdHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/CommissioningClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/zll_commission.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/CommissioningServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/CommissioningCmdHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/zll_utility.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Commissioning/Source/Commissioning.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerCommissioningNotification.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerNotification.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerCommon.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerSinkTableResponse.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerProxyGPDHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerProxyCommissioningMode.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerDirectCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerTranslationTableUpdate.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerPairingSearch.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerScheduler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPower.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerProxyTableRequest.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerCustomCommandResponses.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerPairingConfiguration.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerTranslationTableResponse.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerProxyTableResponse.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerPairing.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerCustomCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerDataIndication.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerResponse.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerTranslationTableRequest.c
        ${NXP_ZB_BASE}/ZCL/Clusters/GreenPower/Source/GreenPowerSinkTableRequest.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Lighting/Source/ColourControlClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Lighting/Source/BallastConfiguration.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Lighting/Source/ColourControlConversions.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Lighting/Source/ColourControlCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/Lighting/Source/ColourControl.c
        ${NXP_ZB_BASE}/ZCL/Clusters/HVAC/Source/FanControl.c
        ${NXP_ZB_BASE}/ZCL/Clusters/HVAC/Source/ThermostatCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/HVAC/Source/ThermostatUIConfig.c
        ${NXP_ZB_BASE}/ZCL/Clusters/HVAC/Source/ThermostatCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/HVAC/Source/Thermostat.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OOSC.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PowerProfileCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PollControl.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/LevelControl.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PollControlClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BinaryOutputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AlarmsServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AnalogOutputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/ScenesClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Basic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BasicClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/WWAHServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Diagnostics.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PowerConfiguration.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOffCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PowerProfileClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/TC.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/MultistateOutputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/ScenesServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/ScenesTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BasicCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/IdentifyCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AlarmsTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PollControlServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/WWAHCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/WWAH.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PollControlCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/MultistateInputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/LevelControlClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PowerProfile.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/ScenesCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AlarmsCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOff.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Identify.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AnalogInputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Scenes.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Time.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Alarms.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/GroupsClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/OnOffCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/AlarmsClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/DeviceTemperatureConfiguration.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/PowerProfileServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/BinaryInputBasic.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/LevelControlCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/WWAHClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/ScenesClusterManagement.c
        ${NXP_ZB_BASE}/ZCL/Clusters/General/Source/Groups.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASWDCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASACEClientCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASZoneCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASACECommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASZone.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASACEServerCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASZoneCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASWD.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASWDCommands.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SecurityAndSafety/Source/IASACE.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCustomCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCScheduler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceServerAttributeManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishCalorificValue.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/SimpleMeteringCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishBlockPeriod.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCTableManagerNoMutex.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLC.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishPriceReceive.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandCanceAlllLoadControlEvents.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandGetCurrentPrice.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCTableManagerServer.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCustomCommandResponsesClient.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCustomCommandResponsesServer.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCUserEventOptInOut.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandGetBlockPeriod.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceConversionFactorTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCalorificValueTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPriceAck.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandLoadControlEvent.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandGetScheduledPrices.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCustomCommandResponses.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishConversionFactor.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceBlockPeriodTableManager.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/Price.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandGetConversionFactor.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandGetScheduledEvents.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCEffectiveTime.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishBlockPeriodReceive.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandCancelLoadControlEvent.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishCalorificValueReceive.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandHandler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishPrice.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/SimpleMetering.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandPublishConversionFactorReceive.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/SimpleMetering_SendRequest.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceScheduler.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/DRLCCommandReportEventStatus.c
        ${NXP_ZB_BASE}/ZCL/Clusters/SmartEnergy/Source/PriceCommandGetCalorificValue.c
    )
endif()

# Put those files as part of the application, as some of them depends on pdumconfig or zpsconfig
# instead of splitting this list, we can just build everything in the app
target_sources(zb_app PRIVATE
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/app_zps_link_keys.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZdpExtraction.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZpsBeaconHandler.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/appZpsExtendedDebug.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/ZQueue.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/ZTimer.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/port_JN518x.c
    ${NXP_ZB_BASE}/ZigbeeCommon/Source/tlv.c
    ${ZB_APP_OPTIONAL_SOURCES}
)
