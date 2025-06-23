# Thermostat Cluster structure and attributes

The Thermostat cluster is contained in the following `tsCLD_Thermostat` structure:

```
typedef struct
{
#ifdef THERMOSTAT_SERVER
    zint16                  i16LocalTemperature;
#ifdef CLD_THERMOSTAT_ATTR_OUTDOOR_TEMPERATURE
    zint16                  i16OutdoorTemperature;
#endif
#ifdef CLD_THERMOSTAT_ATTR_OCCUPANCY
    zbmap8                  u8Occupancy;
#endif
#ifdef CLD_THERMOSTAT_ATTR_ABS_MIN_HEAT_SETPOINT_LIMIT
    zint16                  i16AbsMinHeatSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_ABS_MAX_HEAT_SETPOINT_LIMIT
    zint16                  i16AbsMaxHeatSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_ABS_MIN_COOL_SETPOINT_LIMIT
    zint16                  i16AbsMinCoolSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_ABS_MAX_COOL_SETPOINT_LIMIT
    zint16                  i16AbsMaxCoolSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_PI_COOLING_DEMAND
    zuint8                  u8PICoolingDemand;
#endif
#ifdef CLD_THERMOSTAT_ATTR_PI_HEATING_DEMAND
    zuint8                  u8PIHeatingDemand;
#endif
/* Thermostat settings attribute set attribute IDs */
#ifdef CLD_THERMOSTAT_ATTR_LOCAL_TEMPERATURE_CALIBRATION
    zint8                   i8LocalTemperatureCalibration;
#endif
    zint16                  i16OccupiedCoolingSetpoint;
    zint16                  i16OccupiedHeatingSetpoint;
#ifdef CLD_THERMOSTAT_ATTR_UNOCCUPIED_COOLING_SETPOINT
    zint16                  i16UnoccupiedCoolingSetpoint;
#endif
#ifdef CLD_THERMOSTAT_ATTR_UNOCCUPIED_HEATING_SETPOINT
    zint16                  i16UnoccupiedHeatingSetpoint;
#endif
#ifdef CLD_THERMOSTAT_ATTR_MIN_HEAT_SETPOINT_LIMIT
    zint16                  i16MinHeatSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_MAX_HEAT_SETPOINT_LIMIT
    zint16                  i16MaxHeatSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_MIN_COOL_SETPOINT_LIMIT
    zint16                  i16MinCoolSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_MAX_COOL_SETPOINT_LIMIT
    zint16                  i16MaxCoolSetpointLimit;
#endif
#ifdef CLD_THERMOSTAT_ATTR_MIN_SETPOINT_DEAD_BAND
    zint8                   i8MinSetpointDeadBand;
#endif
#ifdef CLD_THERMOSTAT_ATTR_REMOTE_SENSING
    zbmap8                  u8RemoteSensing;
#endif
    zenum8                  eControlSequenceOfOperation;
    zenum8                  eSystemMode;
#ifdef CLD_THERMOSTAT_ATTR_ALARM_MASK
    zbmap8                  u8AlarmMask;
#endif
#ifdef CLD_THERMOSTAT_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                  u8AttributeReportingStatus;
#endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_Thermostat;

```

where:

## ‘Thermostat Information’ Attribute Set 

-   `i16LocalTemperature` is a mandatory attribute representing the measured temperature in degrees Celsius, as follows:

    -   `i16LocalTemperature` = 100 x temperature in degrees Celsius
    -   The possible values are used as follows:
    -   0x0000 to 0x7FFF represent positive temperatures from 0°C to 327.67ºC
    -   0x8000 indicates that the temperature measurement is invalid
    -   0x8001 to 0x954C are unused values
    -   0x954D to 0xFFFF represent negative temperatures from -273.15°C to
    -   -1°C \(in two’s complement form\)
-   `i16OutdoorTemperature` is an optional attribute representing the outside temperature in degrees Celsius. This temperature is represented as described above for `i16LocalTemperature`.

-   `u8Occupancy` is an optional attribute indicating whether the heated/cooled space has been detected as occupied. Bit 0 is used as a flag as follows \(all other bits are reserved\):

    -   1 = occupied

    -   0 = not occupied

-   `i16AbsMinHeatSetpointLimit` is an optional attribute specifying the absolute minimum possible temperature of the heating setpoint \(as determined by the manufacturer\). This temperature is represented as described above for `i16LocalTemperature`.

-   `i16AbsMaxHeatSetpointLimit` is an optional attribute specifying the absolute maximum possible temperature of the heating setpoint \(as determined by the manufacturer\). This temperature is represented as described above for `i16LocalTemperature`.

-   `i16AbsMinCoolSetpointLimit` is an optional attribute specifying the absolute minimum possible temperature of the cooling setpoint \(as determined by the manufacturer\). This temperature is represented as described above for `i16LocalTemperature`.

-   `i16AbsMaxCoolSetpointLimit` is an optional attribute specifying the absolute maximum possible temperature of the cooling setpoint \(as determined by the manufacturer\). This temperature is represented as described above for `i16LocalTemperature`.


## ‘Thermostat Settings’ Attribute Set 

-   `u8PICoolingDemand` is an optional attribute indicating the level of cooling required by the PI \(Proportional Integral\) control loop, if any, used by the thermostat. It is a percentage value and takes the value 0 when the thermostat is 'off' or in 'heating' mode.

-   `u8PIHeatingDemand` is an optional attribute indicating the level of heating required by the PI \(Proportional Integral\) control loop, if any, used by the thermostat. It is a percentage value and takes the value 0 when the thermostat is 'off' or in 'cooling' mode.

-   `i8LocalTemperatureCalibration` is an optional attribute representing a temperature offset \(in the range -2.5°C to 2.5°C\) that can be added to or subtracted from the displayed temperature:

    -   `i8LocalTemperatureCalibration` = 100 x offset in degrees Celsius
    -   The possible values are used as follows:
    -   0x00 to 0x19 represent positive offsets from 0°C to 2.5ºC
    -   0x20 to 0xE6 are unused values
    -   0xE7 to 0xFF represent negative offets from -2.5°C to -1°C \(in two’s complement form\)
-   `i16OccupiedCoolingSetpoint` is an optional attribute specifying the cooling setpoint \(target temperature\) when the cooling space is occupied. The value is calculated as described above for the `i16LocalTemperature` attribute and must take a value in the range defined by the attributes `i16MinCoolSetpointLimit` and `i16MaxCoolSetpointLimit`. If it is not known whether the space is occupied, this attribute will be used as the cooling setpoint \(rather than `i16UnoccupiedCoolingSetpoint`\).

-   `i16OccupiedHeatingSetpoint` is an optional attribute specifying the heating setpoint \(target temperature\) when the heating space is occupied. The value is calculated as described above for the `i16LocalTemperature` attribute and must take a value in the range defined by the attributes `i16MinHeatSetpointLimit` and `i16MaxHeatSetpointLimit`. If it is not known whether the space is occupied, this attribute will be used as the heating setpoint \(rather than `i16UnoccupiedHeatingSetpoint`\).


**Note:** `i16OccupiedCoolingSetpoint` must always be greater in value than `i16OccupiedHeatingSetpoint` by an amount at least equal to the value of `i8MinSetpointDeadBand` \(below\). An attempt to violate this condition will result in a default response with the status INVALID\_VALUE.

-   `i16UnoccupiedCoolingSetpoint` is an optional attribute specifying the cooling setpoint \(target temperature\) when the cooling space is unoccupied. The value is calculated as described above for the `i16LocalTemperature` attribute and must take a value in the range defined by the attributes `i16AbsMinCoolSetpointLimit` and `i16MaxCoolSetpointLimit`. If it is not known whether the space is occupied, this attribute will not be used \(`i16OccupiedCoolingSetpoint` will be used instead\).

-   `i16``UnoccupiedHeatingSetpoint` is an optional attribute specifying the heating setpoint \(target temperature\) when the heating space is unoccupied. The value is calculated as described above for the `i16LocalTemperature` attribute and must take a value in the range defined by the attributes `i16Min``HeatS``etpointLimit` and `i16MaxHeatSetpointLimit`. If it is not known whether the space is occupied, this attribute will not be used \(`i16Occupied``Heati``ngSetpoint` will be used instead\).


**Note:** `i16UnoccupiedCoolingSetpoint` must always be greater in value than `i16``Unoc``cupiedHeatingSetpoint` by an amount at least equal to the value of `i8MinSetpointDeadBand` \(below\). An attempt to violate this condition will result in a default response with the status INVALID\_VALUE.

-   `i16MinHeatSetpointLimit` is an optional attribute specifying the minimum possible temperature of the heating setpoint. This temperature is represented as described above for `i16LocalTemperature`. The value set must be greater than or equal to the value of `i16AbsMinHeatSetpointLimit`, which is also the default value for this attribute.

-   `i16MaxHeatSetpointLimit` is an optional attribute specifying the maximum possible temperature of the heating setpoint. This temperature is represented as described above for `i16LocalTemperature`. The value set must be less than or equal to the value of `i16AbsMaxHeatSetpointLimit`, which is also the default value for this attribute.

-   `i16MinCoolSetpointLimit` is an optional attribute specifying the minimum possible temperature of the cooling setpoint. This temperature is represented as described above for `i16LocalTemperature`. The value set must be greater than or equal to the value of `i16AbsMinCoolSetpointLimit`, which is also the default value for this attribute.

-   `i16MaxCoolSetpointLimit` is an optional attribute specifying the maximum possible temperature of the cooling setpoint. This temperature is represented as described above for `i16LocalTemperature`. The value set must be less than or equal to the value of `i16AbsMaxCoolSetpointLimit`, which is also the default value for this attribute.


**Note:** The above four ‘Limit’ attributes can be set in the compile-time options using macros, as described in [Section 33.10](compile-time_options.md#id_a6c5caa2-6d08-442f-b081-d58124b2489b).

-   `i8MinSetpointDeadBand` is an optional attribute specifying the minimum difference between the heating setpoint and cooling setpoint, in steps of 0.1°C. The attribute can take a value in the range 0x0A to 0x19, representing 1°C to 2.5°C. All other values are unused.

-   `u8RemoteSensing` is an optional attribute comprising an 8-bit bitmap which indicates whether remote \(networked\) or internal sensors are being used to measure/detect the local temperature, outside temperature and occupancy. The bitmap is detailed in the table below.

| Bit | Description                                                     |
| --- | --------------------------------------------------------------- |
| 0   | Local temperature<br>1 - Remote sensor<br>0 - Internal sensor  |
| 1   | Outside temperature<br>1 - Remote sensor<br>0 - Internal sensor |
| 2   | Occupancy<br>1 - Remote sensor<br>0 - Internal sensor              |
| 3-7 | Reserved                                                        |


-   `eControlSequenceOfOperation` is an optional attribute representing the operational capabilities/environment of the thermostat. The possible values are indicated in the table below:

| Value       | Capabilities                            | Notes<br>(see `eSystemMode`)                  |
| ----------- | --------------------------------------- | ------------------------------------------- |
| 0x00        | Cooling only                            | Heat and Emergency Heating are not possible |
| 0x01        | Cooling with Reheat                     | Heat and Emergency Heating are not possible |
| 0x02        | Heating only                            | Cool and Pre-cooling are not possible       |
| 0x03        | Heating with Reheat                     | Cool and Pre-cooling are not possible       |
| 0x04        | Cooling and Heating <br> 4-pipes             | All modes are possible                      |
| 0x05        | Cooling and Heating <br>4-pipes with Reheat | All modes are possible                      |
| 0x06 – 0xFE | Reserved                                | \-                                          |

 

-   `eSystemMode` is an optional attribute specifying the current operating mode of the thermostat. The possible modes/values are indicated in the table below:


|**Value**|**Description**|
|---------|---------------|
|0x00|Off|
|0x01|Auto|
|0x02|Reserved|
|0x03|Cool|
|0x04|Heat|
|0x05|Emergency Heating|
|0x06|Pre-cooling|
|0x07|Fan only|
|0x08 – 0xFE|Reserved|

-   `u8AlarmMask` is an optional attribute containing a 3-bit bitmap specifying which alarms are enabled from those listed in the table below \(use of the Alarms cluster is also required\):


| Bit | Description                                                                                                                 |
| --- | --------------------------------------------------------------------------------------------------------------------------- |
| 0   | Initialisation failure<br>(device failed to complete initialization at power-up)<br>1 - Alarm enabled<br>0 - Alarm disabled |
| 1   | Hardware failure<br>1 - Alarm enabled<br>0 - Alarm disabled                                                                 |
| 2   | Self-calibration failure<br>1 - Alarm enabled<br>0 - Alarm disabled                                                         |
| 3-7 | Reserved                                                                                                                    

## Global Attributes 

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Thermostat Cluster](../../thermostat_cluster/topics/thermostat_cluster.md)

