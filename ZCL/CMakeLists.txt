# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_hf)
    mcux_add_include(
        INCLUDES Clusters/ApplianceManagement/Include
                 Clusters/General/Include
                 Clusters/Closures/Include
                 Clusters/GreenPower/Include
                 Clusters/HVAC/Include
                 Clusters/Lighting/Include
                 Clusters/MeasurementAndSensing/Include
                 Clusters/SecurityAndSafety/Include
                 Clusters/SmartEnergy/Include
                 Clusters/Commissioning/Include
    )
    mcux_add_source(
        SOURCES Clusters/Commissioning/Include/zll_commission.h
                Clusters/Commissioning/Include/zll_utility.h
                Clusters/OTA/Include/OTA.h
                Clusters/General/Include/Basic.h
                Clusters/General/Include/Identify.h
                Clusters/General/Include/Groups.h
                Clusters/General/Include/OnOff.h
                Clusters/General/Include/Scenes.h
                Clusters/General/Include/PowerConfiguration.h
                Clusters/General/Include/DeviceTemperatureConfiguration.h
                Clusters/General/Include/Alarms.h
                Clusters/General/Include/ZclTime.h
                Clusters/SmartEnergy/Include/SimpleMetering.h
                Clusters/HVAC/Include/Thermostat.h
                Clusters/ApplianceManagement/Include/ApplianceStatistics.h
                Clusters/MeasurementAndSensing/Include/ElectricalMeasurement.h
                Clusters/General/Include/LevelControl.h
                Clusters/General/Include/Groups.h
                Clusters/Lighting/Include/ColourControl.h
                Clusters/General/Include/OOSC.h
                Clusters/General/Include/LevelControl.h
                Clusters/MeasurementAndSensing/Include/TemperatureMeasurement.h
                Clusters/MeasurementAndSensing/Include/IlluminanceLevelSensing.h
                Clusters/MeasurementAndSensing/Include/IlluminanceMeasurement.h
                Clusters/General/Include/BinaryInputBasic.h
                Clusters/General/Include/BinaryOutputBasic.h
                Clusters/SmartEnergy/Include/SimpleMeteringAttributeCount.h
                Clusters/General/Include/AnalogInputBasic.h
                Clusters/General/Include/AnalogOutputBasic.h
                Clusters/General/Include/Diagnostics.h
                Clusters/General/Include/MultistateOutputBasic.h
                Clusters/General/Include/MultistateInputBasic.h
                Clusters/General/Include/PowerProfile.h
                Clusters/General/Include/TC.h
                Clusters/General/Include/WWAH.h
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_appliance_mgmt)
    mcux_add_source(
        SOURCES Clusters/ApplianceManagement/Source/ApplianceControl_internal.h
                Clusters/ApplianceManagement/Source/ApplianceEventsAndAlerts_internal.h
                Clusters/ApplianceManagement/Source/ApplianceStatistics_internal.h
                Clusters/ApplianceManagement/Source/ApplianceEventsAndAlerts.c
                Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsClientCommands.c
                Clusters/ApplianceManagement/Source/ApplianceIdentification.c
                Clusters/ApplianceManagement/Source/ApplianceStatisticsServerCommands.c
                Clusters/ApplianceManagement/Source/ApplianceControl.c
                Clusters/ApplianceManagement/Source/ApplianceControlCommandHandler.c
                Clusters/ApplianceManagement/Source/ApplianceStatisticsClientCommands.c
                Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsServerCommands.c
                Clusters/ApplianceManagement/Source/ApplianceStatistics.c
                Clusters/ApplianceManagement/Source/ApplianceStatisticsCommandHandler.c
                Clusters/ApplianceManagement/Source/ApplianceControlServerCommands.c
                Clusters/ApplianceManagement/Source/ApplianceEventsAndAlertsCommandHandler.c
                Clusters/ApplianceManagement/Source/ApplianceControlClientCommands.c
    )
    mcux_add_include(
        INCLUDES Clusters/ApplianceManagement/Include
                 Clusters/ApplianceManagement/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_APPLIANCE_MANAGEMENT)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_closures)
    mcux_add_source(
        SOURCES Clusters/Closures/Source/DoorLock.c
                Clusters/Closures/Source/DoorLock_internal.h
                Clusters/Closures/Source/WindowCoveringCommandHandler.c
                Clusters/Closures/Source/WindowCoveringCommands.c
                Clusters/Closures/Source/DoorLockCommands.c
                Clusters/Closures/Source/WindowCovering.c
                Clusters/Closures/Source/WindowCovering_internal.h
                Clusters/Closures/Source/DoorLockCommandHandler.c
    )
    mcux_add_include(
        INCLUDES Clusters/Closures/Include
                 Clusters/Closures/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_CLOSURE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_commissioning)
    mcux_add_source(
        SOURCES Clusters/Commissioning/Source/zll_CommissionCmdHandler.c
                Clusters/Commissioning/Source/zll_UtilityCmdHandler.c
                Clusters/Commissioning/Source/CommissioningClientCommands.c
                Clusters/Commissioning/Source/zll_commission.c
                Clusters/Commissioning/Source/CommissioningServerCommands.c
                Clusters/Commissioning/Source/CommissioningCmdHandler.c
                Clusters/Commissioning/Source/zll_utility.c
                Clusters/Commissioning/Source/Commissioning.c
                Clusters/Commissioning/Source/Commissioning_internal.h
                Clusters/Commissioning/Include/zll_commission.h
                Clusters/Commissioning/Include/Commissioning.h
    )
    mcux_add_include(
        INCLUDES Clusters/Commissioning/Include
                 Clusters/Commissioning/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_COMMISSIONING)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_general)
    mcux_add_source(
        SOURCES Clusters/General/Source/OOSC.c
                Clusters/General/Source/PowerProfileCommandHandler.c
                #ZCL/Clusters/General/Source/PollControl.c
                #ZCL/Clusters/General/Source/PollControl_internal.h
                Clusters/General/Source/IdentifyClientCommands.c
                Clusters/General/Source/LevelControl.c
                Clusters/General/Source/LevelControl_internal.h
                #ZCL/Clusters/General/Source/PollControlClientCommands.c
                Clusters/General/Source/BinaryOutputBasic.c
                Clusters/General/Source/BinaryOutputBasic_internal.h
                Clusters/General/Source/AlarmsServerCommands.c
                Clusters/General/Source/AnalogOutputBasic.c
                Clusters/General/Source/AnalogOutputBasic_internal.h
                Clusters/General/Source/ScenesClientCommands.c
                Clusters/General/Source/Basic.c
                Clusters/General/Source/Basic_internal.h
                Clusters/General/Source/BasicClientCommands.c
                Clusters/General/Source/WWAHServerCommands.c
                Clusters/General/Source/Diagnostics.c
                Clusters/General/Source/PowerConfiguration.c
                Clusters/General/Source/OnOffCommands.c
                Clusters/General/Source/PowerProfileClientCommands.c
                Clusters/General/Source/TC.c
                Clusters/General/Source/MultistateOutputBasic.c
                Clusters/General/Source/MultistateOutputBasic_internal.h
                Clusters/General/Source/ScenesServerCommands.c
                Clusters/General/Source/ScenesTableManager.c
                Clusters/General/Source/GroupsCommandHandler.c
                Clusters/General/Source/BasicCommandHandler.c
                Clusters/General/Source/IdentifyServerCommands.c
                Clusters/General/Source/IdentifyCommandHandler.c
                Clusters/General/Source/GroupsServerCommands.c
                Clusters/General/Source/AlarmsTableManager.c
                #ZCL/Clusters/General/Source/PollControlServerCommands.c
                Clusters/General/Source/WWAHCommandHandler.c
                Clusters/General/Source/WWAH.c
                Clusters/General/Source/WWAH_internal.h
                #ZCL/Clusters/General/Source/PollControlCommandHandler.c
                Clusters/General/Source/MultistateInputBasic.c
                Clusters/General/Source/MultistateInputBasic_internal.h
                Clusters/General/Source/LevelControlClientCommands.c
                Clusters/General/Source/PowerProfile.c
                Clusters/General/Source/PowerProfile_internal.h
                Clusters/General/Source/ScenesCommandHandler.c
                Clusters/General/Source/AlarmsCommandHandler.c
                Clusters/General/Source/OnOff.c
                Clusters/General/Source/OnOff_internal.h
                Clusters/General/Source/Identify.c
                Clusters/General/Source/Identify_internal.h
                Clusters/General/Source/AnalogInputBasic.c
                Clusters/General/Source/AnalogInputBasic_internal.h
                Clusters/General/Source/Scenes.c
                Clusters/General/Source/Scenes_internal.h
                Clusters/General/Source/Time.c
                Clusters/General/Source/Alarms.c
                Clusters/General/Source/Alarms_internal.h
                Clusters/General/Source/GroupsTableManager.c
                Clusters/General/Source/GroupsClientCommands.c
                Clusters/General/Source/OnOffCommandHandler.c
                Clusters/General/Source/AlarmsClientCommands.c
                Clusters/General/Source/DeviceTemperatureConfiguration.c
                Clusters/General/Source/PowerProfileServerCommands.c
                Clusters/General/Source/BinaryInputBasic.c
                Clusters/General/Source/BinaryInputBasic_internal.h
                Clusters/General/Source/LevelControlCommandHandler.c
                Clusters/General/Source/WWAHClientCommands.c
                Clusters/General/Source/ScenesClusterManagement.c
                Clusters/General/Source/Groups.c
                Clusters/General/Source/Groups_internal.h
    )
    mcux_add_include(
        INCLUDES Clusters/General/Include
                 Clusters/General/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_GENERAL)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_general_pollcontrol)
    mcux_add_source(
        SOURCES Clusters/General/Source/PollControl.c
                Clusters/General/Source/PollControl_internal.h
                Clusters/General/Source/PollControlClientCommands.c
                Clusters/General/Source/PollControlServerCommands.c
                Clusters/General/Source/PollControlCommandHandler.c
    )
    mcux_add_include(
        INCLUDES Clusters/General/Include
                 Clusters/General/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_POLLCONTROL)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_greenpower)
    mcux_add_source(
        SOURCES Clusters/GreenPower/Source/GreenPowerCommissioningNotification.c
                Clusters/GreenPower/Source/GreenPowerNotification.c
                Clusters/GreenPower/Source/GreenPowerCommon.c
                Clusters/GreenPower/Source/GreenPowerSinkTableResponse.c
                Clusters/GreenPower/Source/GreenPowerProxyGPDHandler.c
                Clusters/GreenPower/Source/GreenPowerProxyCommissioningMode.c
                Clusters/GreenPower/Source/GreenPowerDirectCommandHandler.c
                Clusters/GreenPower/Source/GreenPowerTranslationTableUpdate.c
                Clusters/GreenPower/Source/GreenPowerPairingSearch.c
                Clusters/GreenPower/Source/GreenPowerScheduler.c
                Clusters/GreenPower/Source/GreenPower.c
                Clusters/GreenPower/Source/GreenPower_internal.h
                Clusters/GreenPower/Source/GreenPowerProxyTableRequest.c
                Clusters/GreenPower/Source/GreenPowerCustomCommandResponses.c
                Clusters/GreenPower/Source/GreenPowerPairingConfiguration.c
                Clusters/GreenPower/Source/GreenPowerTranslationTableResponse.c
                Clusters/GreenPower/Source/GreenPowerProxyTableResponse.c
                Clusters/GreenPower/Source/GreenPowerPairing.c
                Clusters/GreenPower/Source/GreenPowerCustomCommandHandler.c
                Clusters/GreenPower/Source/GreenPowerDataIndication.c
                Clusters/GreenPower/Source/GreenPowerResponse.c
                Clusters/GreenPower/Source/GreenPowerTranslationTableRequest.c
                Clusters/GreenPower/Source/GreenPowerSinkTableRequest.c
    )
    mcux_add_include(
        INCLUDES Clusters/GreenPower/Include
    )
    #mcux_add_macro(CLD_GREENPOWER)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_hvac)
    mcux_add_source(
        SOURCES Clusters/HVAC/Source/FanControl.c
                Clusters/HVAC/Source/ThermostatCommandHandler.c
                Clusters/HVAC/Source/ThermostatUIConfig.c
                Clusters/HVAC/Source/ThermostatCommands.c
                Clusters/HVAC/Source/Thermostat.c
                Clusters/HVAC/Source/Thermostat_internal.h
    )
    mcux_add_include(
        INCLUDES Clusters/HVAC/Include
    )
    #mcux_add_macro(ZCL_CLUSTER_HVAC)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_lighting)
    mcux_add_source(
        SOURCES Clusters/Lighting/Source/ColourControlClientCommands.c
                Clusters/Lighting/Source/BallastConfiguration.c
                Clusters/Lighting/Source/ColourControlConversions.c
                Clusters/Lighting/Source/ColourControlCommandHandler.c
                Clusters/Lighting/Source/ColourControl.c
                Clusters/Lighting/Source/ColourControl_internal.h
    )
    mcux_add_include(
        INCLUDES Clusters/Lighting/Include
                 Clusters/Lighting/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_LIGHTING)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_measurement_sensing)
    mcux_add_source(
        SOURCES Clusters/MeasurementAndSensing/Source/OccupancySensing.c
                Clusters/MeasurementAndSensing/Source/TemperatureMeasurement.c
                Clusters/MeasurementAndSensing/Source/FlowMeasurement.c
                Clusters/MeasurementAndSensing/Source/ConcentrationMeasurement.c
                Clusters/MeasurementAndSensing/Source/RelativeHumidityMeasurement.c
                Clusters/MeasurementAndSensing/Source/IlluminanceLevelSensing.c
                Clusters/MeasurementAndSensing/Source/ElectricalMeasurement.c
                Clusters/MeasurementAndSensing/Source/IlluminanceMeasurement.c
                Clusters/MeasurementAndSensing/Source/PressureMeasurement.c
    )
    mcux_add_include(
        INCLUDES Clusters/MeasurementAndSensing/Include
    )
    #mcux_add_macro(ZCL_CLUSTER_MEASUREMENT_AND_SENSING)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_ota_server)
    mcux_add_source(
        SOURCES Clusters/OTA/Source/OTA_CustomCommandHandler.c
                Clusters/OTA/Source/OTA_ServerUpgradeManager.c
                Clusters/OTA/Source/OTA_common.c
                Clusters/OTA/Source/OTA.c
                Clusters/OTA/Source/OTA_CustomReceiveCommands.c
                Clusters/OTA/Source/OTA_server.c
                Clusters/OTA/Source/OTA_private.h
                Clusters/OTA/Include/OTA.h
    )
    mcux_add_include(
        INCLUDES Clusters/OTA/Include
    )
    #mcux_add_macro(OTA_NO_CERTIFICATE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_ota_client)
    mcux_add_source(
        SOURCES Clusters/OTA/Source/OTA_CustomCommandHandler.c
                Clusters/OTA/Source/OTA_client.c
                Clusters/OTA/Source/OTA_common.c
                Clusters/OTA/Source/OTA.c
                Clusters/OTA/Source/OTA_CustomReceiveCommands.c
                Clusters/OTA/Source/OTA_ClientUpgradeManager.c
                Clusters/OTA/Source/OTA_private.h
    )
    mcux_add_include(
        INCLUDES Clusters/OTA/Include
    )
    #mcux_add_macro(OTA_NO_CERTIFICATE)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_security_safety)
    mcux_add_source(
        SOURCES Clusters/SecurityAndSafety/Source/IASWDCommandHandler.c
                Clusters/SecurityAndSafety/Source/IASACEClientCommands.c
                Clusters/SecurityAndSafety/Source/IASZoneCommandHandler.c
                Clusters/SecurityAndSafety/Source/IASACECommandHandler.c
                Clusters/SecurityAndSafety/Source/IASZone.c
                Clusters/SecurityAndSafety/Source/IASZone_internal.h
                Clusters/SecurityAndSafety/Source/IASACEServerCommands.c
                Clusters/SecurityAndSafety/Source/IASZoneCommands.c
                Clusters/SecurityAndSafety/Source/IASWD.c
                Clusters/SecurityAndSafety/Source/IASWD_internal.h
                Clusters/SecurityAndSafety/Source/IASWDCommands.c
                Clusters/SecurityAndSafety/Source/IASACE.c
                Clusters/SecurityAndSafety/Source/IASACE_internal.h
    )
    mcux_add_include(
        INCLUDES Clusters/SecurityAndSafety/Include
    )
    #mcux_add_macro(ZCL_CLUSTER_SECURITY_AND_SAFETY)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.zcl_smart_energy)
    mcux_add_source(
        SOURCES Clusters/SmartEnergy/Source/PriceCustomCommandHandler.c
                Clusters/SmartEnergy/Source/DRLCScheduler.c
                Clusters/SmartEnergy/Source/PriceServerAttributeManager.c
                Clusters/SmartEnergy/Source/PriceCommandPublishCalorificValue.c
                Clusters/SmartEnergy/Source/SimpleMeteringCommandHandler.c
                Clusters/SmartEnergy/Source/PriceCommandPublishBlockPeriod.c
                Clusters/SmartEnergy/Source/DRLCTableManagerNoMutex.c
                Clusters/SmartEnergy/Source/DRLC.c
                Clusters/SmartEnergy/Source/DRLC_internal.h
                Clusters/SmartEnergy/Source/PriceCommandPublishPriceReceive.c
                Clusters/SmartEnergy/Source/DRLCCommandCanceAlllLoadControlEvents.c
                Clusters/SmartEnergy/Source/PriceCommandGetCurrentPrice.c
                Clusters/SmartEnergy/Source/DRLCTableManagerServer.c
                Clusters/SmartEnergy/Source/DRLCCustomCommandResponsesClient.c
                Clusters/SmartEnergy/Source/DRLCCustomCommandResponsesServer.c
                Clusters/SmartEnergy/Source/PriceTableManager.c
                Clusters/SmartEnergy/Source/DRLCUserEventOptInOut.c
                Clusters/SmartEnergy/Source/PriceCommandGetBlockPeriod.c
                Clusters/SmartEnergy/Source/PriceConversionFactorTableManager.c
                Clusters/SmartEnergy/Source/PriceCalorificValueTableManager.c
                Clusters/SmartEnergy/Source/PriceCommandPriceAck.c
                Clusters/SmartEnergy/Source/DRLCCommandLoadControlEvent.c
                Clusters/SmartEnergy/Source/PriceCommandGetScheduledPrices.c
                Clusters/SmartEnergy/Source/PriceCustomCommandResponses.c
                Clusters/SmartEnergy/Source/PriceCommandPublishConversionFactor.c
                Clusters/SmartEnergy/Source/PriceBlockPeriodTableManager.c
                Clusters/SmartEnergy/Source/Price.c
                Clusters/SmartEnergy/Source/Price_internal.h
                Clusters/SmartEnergy/Source/PriceCommandGetConversionFactor.c
                Clusters/SmartEnergy/Source/DRLCCommandGetScheduledEvents.c
                Clusters/SmartEnergy/Source/DRLCEffectiveTime.c
                Clusters/SmartEnergy/Source/PriceCommandPublishBlockPeriodReceive.c
                Clusters/SmartEnergy/Source/DRLCCommandCancelLoadControlEvent.c
                Clusters/SmartEnergy/Source/PriceCommandPublishCalorificValueReceive.c
                Clusters/SmartEnergy/Source/DRLCCommandHandler.c
                Clusters/SmartEnergy/Source/PriceCommandPublishPrice.c
                Clusters/SmartEnergy/Source/SimpleMetering.c
                Clusters/SmartEnergy/Source/SimpleMetering_internal.h
                Clusters/SmartEnergy/Source/PriceCommandPublishConversionFactorReceive.c
                Clusters/SmartEnergy/Source/SimpleMetering_SendRequest.c
                Clusters/SmartEnergy/Source/PriceScheduler.c
                Clusters/SmartEnergy/Source/DRLCCommandReportEventStatus.c
                Clusters/SmartEnergy/Source/PriceCommandGetCalorificValue.c
    )
    mcux_add_include(
        INCLUDES Clusters/SmartEnergy/Include
                 Clusters/SmartEnergy/Source
    )
    #mcux_add_macro(ZCL_CLUSTER_SMART_ENERGY)
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zgp)
    mcux_add_source(
        SOURCES Devices/ZGP/Source/gp.c
    )
    mcux_add_include(
        INCLUDES Devices/ZGP/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_appliance_mgmt)
    mcux_add_source(
        SOURCES Devices/ZHA/ApplianceManagement/Source/home_gateway.c
                Devices/ZHA/ApplianceManagement/Source/white_goods.c
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/ApplianceManagement/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_closures)
    mcux_add_source(
        SOURCES Devices/ZHA/Closures/Source/window_covering.c
                Devices/ZHA/Closures/Source/door_lock_controller.c
                Devices/ZHA/Closures/Source/door_lock.c
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/Closures/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_generic)
    mcux_add_source(
        SOURCES Devices/ZHA/Generic/Source/mains_power_outlet.c
                Devices/ZHA/Generic/Source/base_device.c
                Devices/ZHA/Generic/Source/simple_sensor.c
                Devices/ZHA/Generic/Source/on_off_output.c
                Devices/ZHA/Generic/Source/remote_control.c
                Devices/ZHA/Generic/Source/plug_control.c
                Devices/ZHA/Generic/Include/base_device.h
                Devices/ZHA/Generic/Include/mains_power_outlet.h
                Devices/ZHA/Generic/Include/on_off_output.h
                Devices/ZHA/Generic/Include/plug_control.h
                Devices/ZHA/Generic/Include/remote_control.h
                Devices/ZHA/Generic/Include/simple_sensor.h
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/Generic/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_hvac)
    mcux_add_source(
        SOURCES Devices/ZHA/HVAC/Source/thermostat_device.c
                Devices/ZHA/HVAC/Source/temperature_sensor.c
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/HVAC/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_security_safety)
    mcux_add_source(
        SOURCES Devices/ZHA/SecurityAndSafety/Source/zone.c
                Devices/ZHA/SecurityAndSafety/Source/ancillary_control_equipment.c
                Devices/ZHA/SecurityAndSafety/Source/control_and_indicating_equipment.c
                Devices/ZHA/SecurityAndSafety/Source/warning_device.c
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/SecurityAndSafety/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zha_smart_energy)
    mcux_add_source(
        SOURCES Devices/ZHA/SmartEnergy/Source/smart_plug.c
    )
    mcux_add_include(
        INCLUDES Devices/ZHA/SmartEnergy/Include
    )
endif()

if(CONFIG_MCUX_COMPONENT_middleware.wireless.zigbee.device_zlo)
    mcux_add_source(
        SOURCES Devices/ZLO/Source/colour_controller.c
                Devices/ZLO/Source/colour_dimmable_light.c
                Devices/ZLO/Source/colour_dimmer_switch.c
                Devices/ZLO/Source/colour_scene_controller.c
                Devices/ZLO/Source/colour_temperature_light.c
                Devices/ZLO/Source/commission_endpoint.c
                Devices/ZLO/Source/control_bridge.c
                Devices/ZLO/Source/dimmable_ballast.c
                Devices/ZLO/Source/dimmable_light.c
                Devices/ZLO/Source/dimmable_plug.c
                Devices/ZLO/Source/dimmer_switch.c
                Devices/ZLO/Source/extended_colour_light.c
                Devices/ZLO/Source/light_level_sensor.c
                Devices/ZLO/Source/light_sensor.c
                Devices/ZLO/Source/non_colour_controller.c
                Devices/ZLO/Source/non_colour_scene_controller.c
                Devices/ZLO/Source/occupancy_sensor.c
                Devices/ZLO/Source/on_off_ballast.c
                Devices/ZLO/Source/on_off_light_switch.c
                Devices/ZLO/Source/on_off_light.c
                Devices/ZLO/Source/on_off_plug.c
                Devices/ZLO/Source/on_off_sensor.c
    )
    mcux_add_include(
        INCLUDES Devices/ZLO/Include
    )
endif()
