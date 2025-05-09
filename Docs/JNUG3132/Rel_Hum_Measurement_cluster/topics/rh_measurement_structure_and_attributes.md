# RH Measurement Structure and Attributes

The structure definition for the Relative Humidity Measurement cluster \(server\) is:

```
typedef struct
{
    zuint16    u16MeasuredValue;
    zuint16    u16MinMeasuredValue;
    zuint16    u16MaxMeasuredValue;
#ifdef E_CLD_RHMEAS_ATTR_TOLERANCE
    zuint16    u16Tolerance;
#endif
} tsCLD_RelativeHumidityMeasurement;

```

where:

-   `u1``6MeasuredValue` is a mandatory attribute representing the measured relatively humidity as a percentage in steps of 0.01%, as follows:

    -   `u1``6MeasuredValue` = 100 x relative humidity percentage
    -   So, for example, 0x197C represents a relative humidity measurement of 65.24%. The possible values are used as follows:
    -   0x0000 to 0x2710 represent relative humidities from 0% to 100%
    -   0x2711 to 0xFFFE are unused values
    -   0xFFFF indicates an invalid measurement
    -   This attribute is updated continuously as measurements are made.
-   `u16MinMeasuredValue` is a mandatory attribute specifying the value of the attribute u16MeasuredValue which corresponds to the minimum possible relative humidity that can be measured. Its value must be less than that of the attribute u16MaxMeasuredValue \(below\). The special value 0xFFFF is used to indicate that the minimum is not defined.

-   `u16MaxMeasuredValue` is a mandatory attribute specifying the value of the attribute u16MeasuredValue which corresponds to the maximum possible relative humidity that can be measured. Its value must be greater than that of the attribute u16MinMeasuredValue \(above\). The special value 0xFFFF is used to indicate that the maximum is not defined.

-   `u16Tolerance` is an optional attribute which indicates the magnitude of the maximum possible error in the value of the attribute u16MeasuredValue. The true value will be in the range \(u16MeasuredValue – u16Tolerance\) to \(u16MeasuredValue + u16Tolerance\).


-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Relative Humidity Measurement Cluster](../../Rel_Hum_Measurement_cluster/topics/relative_humidity_measurement_cluster.md)

