# Cluster structure and attributes

The structure definition for the Illuminance Level Sensing cluster is:

```
typedef struct
{
#ifdef ILLUMINANCE_LEVEL_SENSING_SERVER zenum8 u8LevelStatus;
#ifdef CLD_ILS_ATTR_LIGHT_SENSOR_TYPE zenum8 eLightSensorType;
#endif
 zuint16 u16IlluminanceTargetLevel;
#ifdef CLD_ILS_ATTR_ATTRIBUTE_REPORTING_STATUS
 zenum8 u8AttributeReportingStatus;
#endif
#endif
 zuint16 u16ClusterRevision;
} tsCLD_IlluminanceLevelSensing;

```

where:

## Illuminance Level Sensing Information Attributes 

-   `u8LevelStatus` is a mandatory attribute indicating whether the current illuminance is above, within or below the target band, as follows:


|**Value**|**Enumeration**|**Description**|
|---------|---------------|---------------|
|0x00|E\_CLD\_ILS\_LLS\_ON\_TARGET|Measured illuminance is within the target band|
|0x01|E\_CLD\_ILS\_LLS\_BELOW\_TARGET|Measured illuminance is below the target band|
|0x02|E\_CLD\_ILS\_LLS\_ABOVE\_TARGET|Measured illuminance is above the target band|
|0x03 - 0xFF|-|Reserved|

-   `eLightSensorType` is an optional attribute indicating the type of light-level sensor used, as follows:


|**Value**|**Enumeration**|**Description**|
|---------|---------------|---------------|
|0x00|E\_CLD\_ILS\_LST\_PHOTODIODE|Photodiode|
|0x01|E\_CLD\_ILS\_LST\_CMOS|CMOS|
|0x02 - 0x3F|-|Reserved|
|0x40 - 0xFE|-|Manufacturer-specific types|
|0xFF|-|Unknown|

## Illuminance Level Sensing Settings Attribute 

-   `u16IlluminanceTargetLevel` is a mandatory attribute representing the illuminance level at the centre of the target band. The value of this attribute is calculated as

    -   10000 x log10*Illuminance*
    -   where *Illuminance* is measured in Lux \(lx\) and can take values in the range
    -   1 lx ≤ *Illuminance* ≤ 3.576x106 lx, corresponding to attribute values in the range 0x0000 to 0xFFFE. The value 0xFFFF is used to indicate that the attribute is invalid.

**Note:** **Note 1:** The target band is a ‘dead band’ around the above target level, in which the sensing device is not able to differentiate between different illuminance levels. The width of this band is device-specific.

**Note:** **Note 2:** The illuminance status relative to the target band can be monitored by regularly reading the `u8LevelStatus` attribute.

## Global Attributes 

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Illuminance Level Sensing Cluster](../../Illuminance_Level_Sensing_cluster/topics/illuminance_level_sensing_cluster.md)

