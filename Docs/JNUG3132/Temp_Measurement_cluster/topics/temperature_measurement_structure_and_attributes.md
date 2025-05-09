# Temperature Measurement Structure and Attributes

The structure definition for the Temperature Measurement cluster \(server\) is:

```
typedef struct
{
#ifdef TEMPERATURE_MEASUREMENT_SERVER
  zint16    i16MeasuredValue;
  zint16    i16MinMeasuredValue;
  zint16    i16MaxMeasuredValue;
#ifdef CLD_TEMPMEAS_ATTR_TOLERANCE
  zuint16  u16Tolerance;
#endif
#ifdef CLD_TEMPMEAS_ATTR_ATTRIBUTE_REPORTING_STATUS
  zenum8    u8AttributeReportingStatus;
#endif
#endif
 zuint16 u16ClusterRevision;
} tsCLD_TemperatureMeasurement;

```

where:

-   `i16MeasuredValue` is a mandatory attribute representing the measured temperature in degrees Celsius, as follows:

    -   `i16MeasuredValue` = 100 x temperature in degrees Celsius
    -   The possible values are used as follows:
        -   0x0000 to 0x7FFF represent positive temperatures from 0°C to 327.67ºC.
        -   0x8000 indicates that the temperature measurement is invalid.
        -   0x8001 to 0x954C are unused values.
        -   0x954D to 0xFFFF represent negative temperatures from -273.15°C to -1°C \(in two’s complement form\).
    -   This attribute is updated continuously as measurements are made.
-   `i16MinMeasuredValue` is a mandatory attribute specifying the value of the attribute i16MeasuredValue which corresponds to the minimum possible temperature that can be measured. Its value must be less than that of the attribute i16MaxMeasuredValue \(below\). The special value 0x8000 indicates that the minimum is not known.

-   `i16MaxMeasuredValue` is a mandatory attribute specifying the value of the attribute i16MeasuredValue which corresponds to the maximum possible temperature that can be measured. Its value must be greater than that of the attribute i16MinMeasuredValue \(above\). The special value 0x8000 indicates that the maximum is not known.

-   `u16Tolerance` is an optional attribute which indicates the magnitude of the maximum possible error in the value of the attribute u16MeasuredValue. The true value is in the range \(u16MeasuredValue – u16Tolerance\) to \(u16MeasuredValue + u16Tolerance\).


-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Temperature Measurement Cluster](../../Temp_Measurement_cluster/topics/temperature_measurement_cluster.md)

