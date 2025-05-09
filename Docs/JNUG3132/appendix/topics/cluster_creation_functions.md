# Appendix D.2: Cluster Creation Functions

For each of the following clusters, a creation function is provided which creates an instance of the cluster on an endpoint:

-   Basic: **eCLD\_BasicCreateBasic\(\)**

-   Power Configuration: **eCLD\_PowerConfigurationCreatePowerConfiguration\(\)**

-   Device Temperature Configuration: **eCLD\_DeviceTemperatureConfigurationCreateDeviceTemperatureConfiguration\(\)**

-   Identify: **eCLD\_IdentifyCreateIdentify\(\)**

-   Groups: **eCLD\_GroupsCreateGroups\(\)**

-   Scenes: **eCLD\_ScenesCreateScenes\(\)**

-   On/Off: **eCLD\_OnOffCreateOnOff\(\)**

-   On/Off Switch Configuration: **eCLD\_OOSCCreateOnOffSwitchConfig\(\)**

-   Level Control: **eCLD\_LevelControlCreateLevelControl\(\)**

-   Alarms: **eCLD\_AlarmsCreateAlarms\(\)**

-   Time: **eCLD\_TimeCreateTime\(\)**

-   Analogue Input \(Basic\): **eCLD\_AnalogInputBasicCreateAnalogInputBasic\(\)**

-   Analogue Output \(Basic\): **eCLD\_AnalogOutputBasicCreateAnalogOutputBasic\(\)**

-   Binary Input \(Basic\): **eCLD\_BinaryInputBasicCreateBinaryInputBasic\(\)**

-   Binary Output \(Basic\): **eCLD\_BinaryOutputBasicCreateBinaryOutputBasic\(\)**

-   Multistate Input \(Basic\): **eCLD\_MultistateInputBasicCreateMultistateInputBasic\(\)**

-   Multistate Output \(Basic\): **eCLD\_MultistateOutputBasicCreateMultistateOutputBasic\(\)**

-   Poll Control: **eCLD\_PollControlCreatePollControl\(\)**

-   Power Profile: **eCLD\_PPCreatePowerProfile\(\)**

-   Diagnostics: **eCLD\_DiagnosticsCreateDiagnostics\(\)**

-   Illuminance Measurement: **eCLD\_IlluminanceMeasurementCreateIlluminanceMeasurement\(\)**

-   Illuminance Level Sensing: **eCLD\_IlluminanceLevelSensingCreateIlluminanceLevelSensing\(\)**

-   Temperature Measurement: **eCLD\_TemperatureMeasurementCreateTemperatureMeasurement\(\)**

-   Pressure Measurement: **eCLD\_PressureMeasurementCreatePressureMeasurement\(\)**

-   Flow Measurement: **eCLD\_FlowMeasurementCreateFlowMeasurement\(\)**

-   Relative Humidity Measurement: **eCLD\_RelativeHumidityMeasurementCreateRelativeHumidityMeasurement\(\)**

-   Occupancy Sensing: **eCLD\_OccupancySensingCreateOccupancySensing\(\)**

-   Electrical Measurement: **eCLD\_ElectricalMeasurementCreateElectricalMeasurement\(\)**

-   Colour Control: **eCLD\_ColourControlCreateColourControl\(\)**

-   Ballast Configuration: **eCLD\_BallastConfigurationCreateBallastConfiguration\(\)**

-   Thermostat: **eCLD\_ThermostatCreateThermostat\(\)**

-   Thermostat User Interface Configuration: **eCLD\_ThermostatUIConfigCreateThermostatUIConfig\(\)**

-   Door Lock: **eCLD\_DoorLockCreateDoorLock\(\)**

-   IAS Zone: **eCLD\_IASZoneCreateIASZone\(\)**

-   IAS Ancillary Control Equipment \(ACE\): **eCLD\_IASACECreateIASACE\(\)**

-   IAS Warning Device \(WD\): **eCLD\_IASWDCreateIASWD\(\)**

-   Price: **eSE\_PriceCreate\(\)**

-   Demand-Response and Load Control \(DRLC\): **eSE\_DRLCCreate\(\)**

-   Simple Metering: **eSE\_SMCreate\(\)**

-   Commissioning:**eCLD\_CommissioningClusterCreateCommissioning\(\)**

-   Touchlink Commissioning: **eCLD\_ZllCommissionCreateCommission\(\)**

-   Appliance Control: **eCLD\_ApplianceControlCreateApplianceControl\(\)**

-   Appliance Identification: **eCLD\_ApplianceIdentificationCreateApplianceIdentification\(\)**

-   Appliance Events and Alerts: **eCLD\_ApplianceEventsAndAlertsCreateApplianceEventsAndAlerts\(\)**

-   Appliance Statistics: **eCLD\_ApplianceStatisticsCreateApplianceStatistics\(\)**

-   Over-The-Air \(OTA\) Upgrade: **eOTA\_Create\(\)**


More than one of the above functions can be called for the same endpoint in order to create multiple cluster instances on the endpoint.

**Note:** No more than one server instance and one client instance of a given cluster can be created on a single endpoint \(e.g. one Identify cluster server and one Identify cluster client, but no further Identify cluster instances\).

The creation functions for clusters are described in the corresponding chapters of this manual.

**Parent topic:**[Appendix D: Custom endpoints](../../appendix/topics/custom_endpoints.md)

