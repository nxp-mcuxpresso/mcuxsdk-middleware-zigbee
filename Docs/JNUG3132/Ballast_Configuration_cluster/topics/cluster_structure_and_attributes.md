# Cluster structure and attributes

The structure definition for the Device Temperature Configuration cluster is:

```
typedef struct
{
#ifdef BALLAST_CONFIGURATION_SERVER
/*Ballast Information attribute set */
#ifdef CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MIN_LEVEL
zuint8 u8PhysicalMinLevel;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MAX_LEVEL
zuint8 u8PhysicalMaxLevel;
#endif
zbmap8 u8BallastStatus;
/* Ballast Settings attribute set */
#ifdef CLD_BALLASTCONFIGURATION_ATTR_MIN_LEVEL
zuint8 u8MinLevel;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_MAX_LEVEL
zuint8 u8MaxLevel;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_LEVEL
zuint8 u8PowerOnLevel;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_FADE_TIME
zuint16 u16PowerOnFadeTime;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_INTRINSIC_BALLAST_FACTOR
zuint8 u8IntrinsicBallastFactor;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_BALLAST_FACTOR_ADJUSTMENT
zuint8 u8BallastFactorAdjustment;
#endif
/* Lamp Information attribute set */
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_QUANTITY
zuint8 u8LampQuantity;
#endif
/* Lamp Settings attribute set */
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_TYPE
tsZCL_CharacterString sLampType;
uint8 au8LampType[16];
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_MANUFACTURER
tsZCL_CharacterString sLampManufacturer;
uint8 au8LampManufacturer[16];
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_RATED_HOURS
zuint24 u32LampRatedHours;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS
zuint24 u32LampBurnHours;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_ALARM_MODE
zbmap8 u8LampAlarmMode;
#endif
#ifdef CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS_TRIP_POINT
zuint24 u32LampBurnHoursTripPoint;
#endif
#endif
zuint16 u16ClusterRevision;
} tsCLD_BallastConfiguration;
```

In some attributes described below, a light level is specified as an 8-bit value. This is mapped to a percentage light level by means of a manufacturer-defined light curve, where 0x01 corresponds to 0.1% and 0xFE corresponds to 100% \(0xFF is reserved\).

## Ballast Information Attribute Set 

-   u8PhysicalMinLevel is an optional attribute representing the minimum light level that the lamps can physically achieve with the ballast. The valid range of values of this attribute is 0x01 to 0xFE.
-   u8PhysicalMaxLevel is an optional attribute representing the maximum light level that the lamps can physically achieve with the ballast. The valid range of values of this attribute is 0x01 to 0xFE. u8BallastStatus is a mandatory attribute containing a bitmap which indicates the status of the ballast and associated lamps:

|**Bits**|**Status**|
|--------|----------|
|0|Ballast operational status:

 0: Ballast is fully operational

 1: Ballast is not fully operational

|
|1|Lamp status:

 0: All associated lamps are in their sockets

 1: Not all associated lamps are in their sockets

|
|2-7|Reserved|

## Ballast Settings Attribute Set 

-   u8MinLevel is an optional attribute representing the minimum light level that the lamps are allowed to achieve with the ballast. The valid range of values is 0x01 to 0xFE, but the value of this attribute must be in the range u8PhysicalMinLevel to u8MaxLevel \(if implemented\).
-   u8MaxLevel is an optional attribute representing the maximum light level that the lamps are allowed to achieve with the ballast. The valid range of values is 0x01 to 0xFE, but the value of this attribute must be in the range u8MinLevel to u8PhysicalMaxLevel \(if implemented\).
-   u8PowerOnLevel is an optional attribute representing the light level that the will be produced from the associated lamps when the ballast is switched on. The valid range of values is 0x01 to 0xFE, but the value of this attribute must be in the range u8MinLevel to u8MaxLevel \(if implemented\). The value 0xFF is used to indicate that the last light level \(before the previous switch-off\) should be implemented on switch-on.
-   u16PowerOnFadeTime is an optional attribute representing the time, in tenths of a second, that the ballast will take to move the light level to the value of u8PowerOnLevel on switch-on.
-   u8IntrinsicBallastFactor is an optional attribute representing the ballast factor of the ballast/lamp combination, as a percentage. This is a multiplication factor which, if used, is applied to the light level before any adjustment via u8BallastFactorAdjustment. The value 0xFF is used to indicate an invalid ballast factor.
-   u8BallastFactorAdjustment is an optional attribute representing a multiplication factor, as a percentage, to be applied to the configured light output of the lamps associated with the ballast - for example, to compensate for a reduction in the efficiency of a lamp over its lifetime.

## Lamp Information Attribute Set 

```
u8LampQuantity is an optional attribute indicating the number of lamps connected to the ballast (regardless of whether the lamps are in their sockets).
```

## Lamp Settings Attribute Set 

-   The following optional pair of attributes are used to store a human readable description of the type of lamp connected to the ballast:

    -   LampType is a tsZCL\_CharacterString structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 16 characters representing the lamp type
    -   au8LampType\[16\] is a byte-array which contains the character data bytes representing the lamp type

-   The following optional pair of attributes are used to store a human readable name of the manufacturer of the lamps connected to the ballast:

    -   LampManufacturer is a tsZCL\_CharacterString structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 16 characters representing the manufacturer name
    -   au8LampManufacturer\[16\] is a byte-array which contains the character data bytes representing the manufacturer name
    -   u32LampRatedHours is an optional 24-bit attribute indicating the manufacturer’s estimated lifetime of the lamps, in hours, in the range 0x00000000 to 0x00FFFFFE. The value 0x00FFFFFF is used to indicate that the lamp lifetime is unknown. All other values are invalid.
    -   u32LampBurnHours is an optional 24-bit attribute indicating the cumulative total hours of operation of the lamps \(only the hours while the lamps are switched on are counted\), in the range 0x00000000 to 0x00FFFFFE. The value 0x00FFFFFF is used to indicate that the operational hours of the lamp are unknown. All other values are invalid. The attribute value should be reset when the lamps are replaced.
    -   u8LampAlarmMode is an optional attribute containing a bitmap that specifies the attributes that can cause an alarm condition:

        |**Bits**|**Alarm Trigger**|
        |--------|-----------------|
        |0|Alarm triggered when `u32LampBurnHours` reaches `u32LampBurnHoursTripPoint`:

 0: Alarm trigger disabled

 1: Alarm trigger enabled

|
        |1-7|Reserved|


```
u32LampBurnHoursTripPoint is an optional attribute specifying the number of hours of operation recorded in the attribute u32LampBurnHours that will trigger an alarm (provided that this alarm has been enabled through u8LampAlarmMode). The value 0xFFFFFFFF is used to indicate that this alarm will not be triggered.
```

## Global Attribute Set 

```
u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
```

**Parent topic:**[Ballast Configuration Cluster](../../Ballast_Configuration_cluster/topics/ballast_configuration_cluster.md)

