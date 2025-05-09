# Illuminance Measurement Structure and Attributes

The structure definition for the Illuminance Measurement cluster is:

```
typedef struct
{
#ifdef ILLUMINANCE_MEASUREMENT_SERVER
   zuint16    u16MeasuredValue;
   zuint16    u16MinMeasuredValue;
   zuint16    u16MaxMeasuredValue;
#ifdef CLD_ILLMEAS_ATTR_TOLERANCE
  zuint16   u16Tolerance;
#endif
#ifdef CLD_ILLMEAS_ATTR_LIGHT_SENSOR_TYPE
   zenum8   eLightSensorType;
#endif
#ifdef CLD_ILLMEAS_ATTR_ATTRIBUTE_REPORTING_STATUS
   zenum8  u8AttributeReportingStatus;
#endif
#endif
  zuint16  u16ClusterRevision;
} tsCLD_IlluminanceMeasurement;

```

where:

-   `u16MeasuredValue` is a mandatory attribute representing the measured illuminance in logarithmic form, calculated as *\(10000 x log10Illuminance\) + 1*, where the illuminance is measured in Lux \(lx\). The possible illumination values are in the range 1 lx to 3.576 x 106 lx, corresponding to attribute values of 1 to 0xFFFE. The following attribute values have special meaning:

    -   0x0000: Illuminance is too low to be measured.

    -   0xFFFF: Illuminance measurement is invalid.

        -   The valid range of values of `u16MeasuredValue` can be restricted using the attributes `u16MinMeasuredValue` and `u16MaxMeasuredValue` below - in this case, the attribute can take any value in the range `u16MinMeasuredValue` to `u16MaxMeasuredValue`.
-   `u16MinMeasuredValue` is a mandatory attribute representing a lower limit on the value of the attribute `u16MeasuredValue`. The value must be less than that of `u16MaxMeasuredValue`. The value 0xFFFF indicates that the attribute is unused.

-   `u16MaxMeasuredValue` is a mandatory attribute representing an upper limit on the value of the attribute `u16MeasuredValue`. The value must be greater than that of `u16MinMeasuredValue`. The value 0xFFFF indicates that the attribute is unused.

-   `u16Tolerance` is an optional attribute which indicates the magnitude of the maximum possible error in the value of the attribute `u16MeasuredValue`. The true value is in the range \(`u16MeasuredValue` – `u16Tolerance`\) to \(`u16MeasuredValue` + `u16Tolerance`\) .

-   `eLightSensorType` is an optional attribute that indicates the type of light sensor to which the cluster is interfaced:

    -   0x00: Photodiode

    -   0x01: CMOS

    -   0x02–0x3F: Reserved

    -   0x40–0xFE: Reserved for manufacturer-specific light sensor types

    -   0xFF: Unknown

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Illuminance Measurement Cluster](../../Illuminance_Measurement_cluster/topics/illuminance_measurement_cluster.md)

