# Cluster structure and attributes

The structure definition for the Device Temperature Configuration cluster is:

```
typedef struct
{
#ifdef DEVICE_TEMPERATURE_CONFIGURATION_SERVER
    zint16                  i16CurrentTemperature;
#ifdef CLD_DEVTEMPCFG_ATTR_ID_MIN_TEMP_EXPERIENCED
    zint16                  i16MinTempExperienced;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_MAX_TEMP_EXPERIENCED
    zint16                  i16MaxTempExperienced;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_OVER_TEMP_TOTAL_DWELL
    zuint16                 u16OverTempTotalDwell;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_DEVICE_TEMP_ALARM_MASK
    zbmap8                  u8DeviceTempAlarmMask;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_THRESHOLD
    zint16                  i16LowTempThreshold;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_THRESHOLD
    zint16                  i16HighTempThreshold;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_DWELL_TRIP_POINT
    zuint24                 u24LowTempDwellTripPoint;
#endif
#ifdef CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_DWELL_TRIP_POINT
    zuint24                 u24HighTempDwellTripPoint;
#endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_DeviceTemperatureConfiguration;

```

The attributes are classified into three attribute sets: Device Temperature Information, Device Temperature Settings, and Global. The attributes from these sets are described below.

## Device Temperature Information Attribute Set 

-   `i16CurrentTemperature` is a mandatory attribute representing the current internal temperature of the local device, in degrees Celsius. The valid temperature range is -200 to +200 oC \(and the value is 0xFFFF is invalid\).
-   `i16MinTempExperienced` is an optional attribute representing the minimum internal temperature experienced by the local device while powered, in degrees Celsius. The valid temperature range is -200 to +200oC \(and the value is 0xFFFF is invalid\).
-   `i16MaxTempExperienced` is an optional attribute representing the maximum internal temperature experienced by the local device while powered, in degrees Celsius. The valid temperature range is -200 to +200oC \(and the value is 0xFFFF is invalid\).
-   `u16OverTempTotalDwell` is an optional attribute representing the total time, in hours, that the device has spent \(in its lifetime\) above the temperature specified in the attribute `i16HighTempThreshold` \(see below\).

## Device Temperature Settings Attribute Set 

-   `u8DeviceTempAlarmMask` is an optional attribute containing a bitmap that specifies the device temperature alarms that are enabled and disabled. The relevant bit is set to ‘1’ for alarm enabled and ‘0’ for alarm disabled, as shown in the table below.


|**Bit**|**Alarm**|
|-------|---------|
|0|Under-temperature alarm \(device temperature too low\)|
|1|Over-temperature alarm \(device temperature too high\)|
|2-7|Reserved|

-   `i16LowTempThreshold` is an optional attribute representing the lower temperature threshold, in degrees Celsius, for an under-temperature alarm. The device temperature is allowed to fall below this threshold for the duration specified by `u24LowTempDwellTripPoint` before the alarm is triggered \(see below\). 0x8000 indicates that the alarm is not generated.

-   `i16HighTempThreshold` is an optional attribute representing the upper temperature threshold, in degrees Celsius, for an over-temperature alarm. The device temperature is allowed to rise above this threshold for the duration specified by `u24HighTempDwellTripPoint` before the alarm is triggered \(see below\). 0x8000 indicates that the alarm is not generated.

-   `u24LowTempDwellTripPoint` is an optional attribute representing the time delay, in seconds, before an under-temperature alarm is triggered when the device temperature falls below the lower threshold value specified in `i16LowTempThreshold`. If the device temperature returns above the threshold during this time, the alarm is canceled. 0xFFFFFF indicates that the under-temperature alarm is not generated.

-   `u24HighTempDwellTripPoint` is an optional attribute represent time-delay, in seconds. This attribute specifies the time before an over-temperature alarm is triggered when the device temperature rises above the upper threshold value specified in `i16HighTempThreshold`. If the device temperature returns below the threshold during this time, the alarm is canceled. 0xFFFFFF indicates that the over-temperature alarm is not generated.


## Global Attribute Set 

`u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md).

**Parent topic:**[Device Temperature Configuration Cluster](../../Device_Temp_Configuration_cluster/topics/device_temperature_configuration_cluster.md)

