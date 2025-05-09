# Cluster structure and attributes

The structure definition for the Pressure Measurement cluster \(server\) is:

```
typedef struct
{
#ifdef PRESSURE_MEASUREMENT_SERVER
  zint16 i16MeasuredValue;     
  zint16 i16MinMeasuredValue;
  zint16 i16MaxMeasuredValue;
#ifdef CLD_PRESSUREMEAS_ATTR_TOLERANCE
  zuint16 u16Tolerance;
#endif
#ifdef CLD_PRESSUREMEAS_ATTR_ATTRIBUTE_REPORTING_STATUS
  zenum8 u8AttributeReportingStatus;
#endif
#endif
    zuint16 u16ClusterRevision;
} tsCLD_PressureMeasurement;

```

where:

## ‘Pressure Measurement Information’ Attribute Set 

-   i16MeasuredValue is a mandatory attribute corresponding to 10 times the measured pressure, in units of kPa, in two's complement form. The range of possible values is 0x8001 \(representing -3276.7 kPa\) through 0x0000 \(0 kPa\) to 0x7FFF \(representing +3276.7 kPa\). The value 0x8000 is used to indicate that the measurement was invalid. In practice, the stored value is limited within the range i16MinMeasuredValue to i16MaxMeasuredValue \(see below\).

-   i16MinMeasuredValue is a mandatory attribute representing a lower limit on the value that can be stored in i16MeasuredValue. It is a two’s complement value in the range 0x8001 to 0x7FFE, and it must be less than the value of the attribute i16MaxMeasuredValue.

-   i16MaxMeasuredValue is a mandatory attribute representing an upper limit on the value that can be stored in i16MeasuredValue. It is a two’s complement value in the range 0x8002 to 0x7FFF, and it must be greater than the value of the attribute i16MinMeasuredValue.


## Global Attributes 

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Pressure Measurement Cluster](../../pressure_measurement_cluster/topics/pressure_measurement_cluster.md)

