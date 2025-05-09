# Power Configuration Cluster structure and attributes

The structure definition for the Power Configuration cluster is:

```
typedef struct
{
#ifdef POWER_CONFIGURATION_SERVER
#ifdef CLD_PWRCFG_ATTR_MAINS_VOLTAGE
    zuint16  u16MainsVoltage;
#endif
#ifdef CLD_PWRCFG_ATTR_MAINS_FREQUENCY
    zuint8   u8MainsFrequency;
#endif
#ifdef CLD_PWRCFG_ATTR_MAINS_ALARM_MASK
    zbmap8   u8MainsAlarmMask;
#endif
#ifdef CLD_PWRCFG_ATTR_MAINS_VOLTAGE_MIN_THRESHOLD
    uint16   u16MainsVoltageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_MAINS_VOLTAGE_MAX_THRESHOLD
    uint16   u16MainsVoltageMaxThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_MAINS_VOLTAGE_DWELL_TRIP_POINT
    uint16   u16MainsVoltageDwellTripPoint;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_VOLTAGE
    uint8    u8BatteryVoltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_PERCENTAGE_REMAINING
    uint8    u8BatteryPercentageRemaining;
#endif    
#ifdef CLD_PWRCFG_ATTR_BATTERY_MANUFACTURER
    tsZCL_CharacterString   sBatteryManufacturer;
    uint8    au8BatteryManufacturer[16];
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_SIZE
    zenum8   u8BatterySize;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_AHR_RATING
    zuint16      u16BatteryAHRating;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_QUANTITY
    zuint8   u8BatteryQuantity;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_RATED_VOLTAGE
    zuint8   u8BatteryRatedVoltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_ALARM_MASK
    zbmap8   u8BatteryAlarmMask;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_VOLTAGE_MIN_THRESHOLD
    zuint8   u8BatteryVoltageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_VOLTAGE_THRESHOLD1
    zuint8   u8BatteryVoltageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_VOLTAGE_THRESHOLD2
    zuint8   u8BatteryVoltageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_VOLTAGE_THRESHOLD3
    zuint8   u8BatteryVoltageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_PERCENTAGE_MIN_THRESHOLD
    zuint8   u8BatteryPercentageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_PERCENTAGE_THRESHOLD1
    zuint8   u8BatteryPercentageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_PERCENTAGE_THRESHOLD2
    zuint8   u8BatteryPercentageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_PERCENTAGE_THRESHOLD3
    zuint8   u8BatteryPercentageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_ALARM_STATE
    zbmap32      u32BatteryAlarmState;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_VOLTAGE
    uint8    u8Battery2Voltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_PERCENTAGE_REMAINING
    uint8    u8Battery2PercentageRemaining;
#endif    
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_MANUFACTURER
    tsZCL_CharacterString   sBattery2Manufacturer;
    uint8    au8Battery2Manufacturer[16];
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_SIZE
    zenum8   u8Battery2Size;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_AHR_RATING
    zuint16      u16Battery2AHRating;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_QUANTITY
    zuint8   u8Battery2Quantity;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_RATED_VOLTAGE
    zuint8   u8Battery2RatedVoltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_ALARM_MASK
    zbmap8   u8Battery2AlarmMask;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_2_VOLTAGE_MIN_THRESHOLD
    zuint8   u8Battery2VoltageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_VOLTAGE_THRESHOLD1
    zuint8   u8Battery2VoltageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_VOLTAGE_THRESHOLD2
    zuint8   u8Battery2VoltageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_VOLTAGE_THRESHOLD3
    zuint8   u8Battery2VoltageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_PERCENTAGE_MIN_THRESHOLD
    zuint8   u8Battery2PercentageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_PERCENTAGE_THRESHOLD1
    zuint8   u8Battery2PercentageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_PERCENTAGE_THRESHOLD2
    zuint8   u8Battery2PercentageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_PERCENTAGE_THRESHOLD3
    zuint8   u8Battery2PercentageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_2_ALARM_STATE
    zbmap32      u32Battery2AlarmState;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_VOLTAGE
    uint8    u8Battery3Voltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_PERCENTAGE_REMAINING
    uint8    u8Battery3PercentageRemaining;
#endif    
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_MANUFACTURER
    tsZCL_CharacterString   sBattery3Manufacturer;
    uint8    au8Battery3Manufacturer[16];
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_SIZE
    zenum8   u8Battery3Size;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_AHR_RATING
    zuint16      u16Battery3AHRating;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_QUANTITY
    zuint8   u8Battery3Quantity;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_RATED_VOLTAGE
    zuint8   u8Battery3RatedVoltage;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_ALARM_MASK
    zbmap8   u8Battery3AlarmMask;
#endif
#ifdef CLD_PWRCFG_ATTR_BATTERY_3_VOLTAGE_MIN_THRESHOLD
    zuint8   u8Battery3VoltageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_VOLTAGE_THRESHOLD1
    zuint8   u8Battery3VoltageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_VOLTAGE_THRESHOLD2
    zuint8   u8Battery3VoltageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_VOLTAGE_THRESHOLD3
    zuint8   u8Battery3VoltageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_PERCENTAGE_MIN_THRESHOLD
    zuint8   u8Battery3PercentageMinThreshold;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_PERCENTAGE_THRESHOLD1
    zuint8   u8Battery3PercentageThreshold1;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_PERCENTAGE_THRESHOLD2
    zuint8   u8Battery3PercentageThreshold2;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_PERCENTAGE_THRESHOLD3
    zuint8   u8Battery3PercentageThreshold3;
#endif
#ifdef CLD_PWRCFG_ATTR_ID_BATTERY_3_ALARM_STATE
    zbmap32      u32Battery3AlarmState;
#endif
#ifdef  CLD_PWRCFG_ATTR_ID_ATTRIBUTE_REPORTING_STATUS
    zuint8   u8AttributeReportingStatus;
#endif
#endif
    zuint16      u16ClusterRevision;
} tsCLD_PowerConfiguration;

```

The attributes are classified into four attribute sets: Mains Information, Mains Settings, Battery Information, Battery Settings and Global. The attributes from these sets are described below.

## Mains Information Attribute Set 

-   `u16MainsVoltage` is the measured AC \(RMS\) mains voltage or DC voltage currently applied to the device, in units of 100 mV.

-   `u8MainsFrequency` is half of the measured AC mains frequency, in Hertz, currently applied to the device. Actual frequency = 2 x `u8MainsFrequency`. This allows AC mains frequencies to be stored in the range 2-506 Hz in steps of 2 Hz. In addition:

    -   0x00 indicates a DC supply or that AC frequency is too low to be measured

    -   0xFE indicates that AC frequency is too high to be measured

    -   0xFF indicates that AC frequency could not be measured.


## Mains Settings Attribute Set 

-   `u8MainsAlarmMask` is a bitmap indicating which mains voltage alarms can be generated \(a bit is set to ‘1’ if the alarm is enabled\):


|**Bit**|**Description**|
|-------|---------------|
|0|Under-voltage alarm \(triggered when measured RMS mains voltage falls below a pre-defined threshold - see below\)|
|1|Over-voltage alarm \(triggered when measured RMS mains voltage rises above a pre-defined threshold - see below\)|
|2|Mains power supply has been lost or is unavailable - that is, the device is now running on battery power.|
|3-7|Reserved|

-   `u16MainsVoltageMinThreshold` is the threshold for the under-voltage alarm, in units of 100 mV. The RMS mains voltage is allowed to fall below this threshold for the duration specified by `16MainsVoltageDwellTripPoint` before the alarm is triggered \(see below\). 0xFFFF indicates that the alarm will not be generated.

-   `u16MainsVoltageMaxThreshold` is the threshold for the over-voltage alarm, in units of 100 mV. The RMS mains voltage is allowed to rise above this threshold for the duration specified by `16MainsVoltageDwellTripPoint` before the alarm is triggered \(see below\). 0xFFFF indicates that the alarm will not be generated.

-   `u16MainsVoltageDwellTripPoint` defines the time-delay, in seconds, before an over-voltage or under-voltage alarm will be triggered when the mains voltage crosses the relevant threshold. If the mains voltage returns within the limits of the thresholds during this time, the alarm will be cancelled. 0xFFFF indicates that the alarms will not be generated.


## Battery Information Attribute Set \(Battery 1\) 

-   `u8BatteryVoltage` is the measured battery voltage currently applied to the device, in units of 100 mV. 0xFF indicates that the measured voltage is invalid or unknown.

-   `u8BatteryPercentageRemaining` indicates the remaining battery life as a percentage of the complete battery lifespan, expressed to the nearest half-percent in the range 0 to 100 - for example, 0xAF represents 87.5%. The special value 0xFF indicates an invalid or unknown measurement.


## Battery Settings Attribute Set \(Battery 1\) 

-   `sBatteryManufacturer` is a pointer to the array containing the name of the battery manufacturer \(see below\).

-   `au8BatteryManufacturer[16]` is a 16-element array containing the name of the battery manufacturer \(maximum of 16 characters\).

-   `u8BatterySize` is an enumeration indicating the type of battery in the device - the enumerations are listed in [Section 9.5.2](tecld_pwrcfg_batterysize.md#id_4a33f6fd-7f06-47d9-8499-bf2c737d11fe).

-   `u16BatteryAHRating` is the Ampere-hour \(Ah\) charge rating of the battery, in units of 10 mAh.

-   `u8BatteryQuantity` is the number of batteries used to power the device.

-   `u8BatteryRatedVoltage` is the rated voltage of the battery, in units of

    100 mV.

-   `u8BatteryAlarmMask` is a bitmap indicating whether the battery-low alarm can be generated - if enabled, the alarm is generated when the battery voltage falls below a pre-defined threshold \(see below\). The alarm-enable bit is bit 0 \(which is set to ‘1’ if the alarm is enabled\).

-   `u8BatteryVoltageMinThreshold` is the battery voltage threshold, in units of 100 mV, below which the device cannot operate or transmit - a battery-low alarm can be triggered when the battery voltage falls below this threshold:

    |**Value**|**Description**|
    |---------|---------------|
    |0x00 - 0x39|Minimum battery voltage threshold, in units of 100 mV|
    |0x3A|Mains power supply has been lost or is unavailable - that is, the device is now running on battery power.|
    |0x3B - 0xFF|Reserved|

-   `u8BatteryVoltageThreshold1`is a battery voltage threshold, in units of 100 mV, which can correspond to a battery-low alarm - that is, if the battery voltage falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryVoltageMinThreshold. The special value 0xFF indicates that the threshold is not used.u8BatteryVoltageThreshold2 is a battery voltage threshold, in units of 100 mV, which can correspond to a battery-low alarm - that is, if the battery voltage falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryVoltageThreshold1. The special value 0xFF indicates that the threshold is not used.
-   `u8BatteryVoltageThreshold3`is a battery voltage threshold, in units of 100 mV, which can correspond to a battery-low alarm - that is, if the battery voltage falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryVoltageThreshold2. The special value 0xFF indicates that the threshold is not used.
-   `u8BatteryPercentageMinThreshold` is the minimum alarm threshold for percentage battery-life, expressed in half-percent steps in the range 0 to 100 - if the remaining percentage battery-life \(u8BatteryPercentageRemaining\) falls below this threshold, an alarm can be triggered.
-   `u8BatteryPercentageThreshold1` is an alarm threshold for percentage battery-life, expressed in half-percent steps in the range 0 to 100 - if the remaining percentage battery-life \(u8BatteryPercentageRemaining\) falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryPercentageMinThreshold. The special value 0xFF indicates that the threshold is not used.
-   `u8BatteryPercentageThreshold2`is an alarm threshold for percentage battery-life, expressed in half-percent steps in the range 0 to 100 - if the remaining percentage battery-life \(u8BatteryPercentageRemaining\) falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryPercentageThreshold1. The special value 0xFF indicates that the threshold is not used.
-   `u8BatteryPercentageThreshold3` is an alarm threshold for percentage battery-life, expressed in half-percent steps in the range 0 to 100 - if the remaining percentage battery-life \(u8BatteryPercentageRemaining\) falls below this threshold, an alarm can be triggered. It must be greater than the value defined for u8BatteryPercentageThreshold2. The special value 0xFF indicates that the threshold is not used.
-   `u32BatteryAlarmState` is a bitmap representing the current state of the alarms for the battery or batteries \(the bitmap includes status bits for optional additional batteries 2 and 3\). It indicates the state of the battery in relation to the voltage and percentage-life thresholds defined by the attributes above \(a bit is set to ‘1’ when the corresponding threshold has been reached\).


|**Bit**|**Description**|
|-------|---------------|
|**Bits for Battery**|
|0|Bit is set if one of the following thresholds has been reached:

 ```
u8BatteryVoltageMinThreshold
u8BatteryPercentageMinThreshold
```

|
|1|Bit is set if one of the following thresholds has been reached:

 ```
u8BatteryVoltageThreshold1
u8BatteryPercentageThreshold1
```

|
|2|Bit is set if one of the following thresholds has been reached:

 ```
u8BatteryVoltageThreshold2
u8BatteryPercentageThreshold2
```

|
|3|Bit is set if one of the following thresholds has been reached:

 ```
u8BatteryVoltageThreshold3
u8BatteryPercentageThreshold3
```

|
|4 - 9|Reserved|
|**Bits for Battery 2 \(Optional\)**|
|10|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery2VoltageMinThreshold
u8Battery2PercentageMinThreshold
```

|
|11|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery2VoltageThreshold1
u8Battery2PercentageThreshold1
```

|
|12|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery2VoltageThreshold2
u8Battery2PercentageThreshold2
```

|
|13|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery2VoltageThreshold3
u8Battery2PercentageThreshold3
```

|
|14 - 19|Reserved|
|**Bits for Battery 3 \(Optional\)**|
|20|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery3VoltageMinThreshold
u8Battery3PercentageMinThreshold
```

|
|21|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery3VoltageThreshold1
u8Battery3PercentageThreshold1
```

|
|22|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery3VoltageThreshold2
u8Battery3PercentageThreshold2
```

|
|23|Bit is set if one of the following thresholds has been reached:

 ```
u8Battery3VoltageThreshold3
u8Battery3PercentageThreshold3
```

|
|24 - 29|Reserved|
|30|Mains power supply has been lost or is unavailable - that is, the device is now running on battery power|
|31|Reserved|

**Battery Information and Battery Settings Attribute Sets for Battery &lt;X&gt;**

The Battery Information and Battery Settings attribute sets are repeated for up to two further \(optional\) batteries, denoted 2 and 3. The attributes are as follows, where &lt;X&gt; is 2 or 3, and their definitions are identical to those of the equivalent attributes in the Battery Information and Battery Settings attribute sets described above.

```
u8Battery<X>Voltage
u8Battery<X>PercentageRemaining
au8Battery<X>Manufacturer[16]
u8Battery<X>Size
u16Battery<X>AHRating
u8Battery<X>Quantity
u8Battery<X>RatedVoltage
u8Battery<X>AlarmMask
u8Battery<X>VoltageMinThreshold
u8Battery<X>VoltageThreshold1
u8Battery<X>VoltageThreshold2
u8Battery<X>VoltageThreshold3
u8Battery<X>PercentageMinThreshold
u8Battery<X>PercentageThreshold1
u8Battery<X>PercentageThreshold2
u8Battery<X>PercentageThreshold3
u32Battery<X>AlarmState

```

## Global Attribute Set 

```
u8AttributeReportingStatus is an optional attribute that should be enabled when attribute reporting is used for the cluster (see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)). The value of this attribute indicates whether there are attribute reports still pending (0x00) or the attribute reports are complete (0x01) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

```

**Parent topic:**[Power Configuration Cluster](../../Power_Configuration_cluster/topics/power_configuration_cluster.md)

