# Cluster structure and attributes

The structure definition for the Appliance Control cluster \(server\) is:

```
typedef struct
{
#ifdef APPLIANCE_CONTROL_SERVER    
    zuint16                         u16StartTime;
    zuint16                         u16FinishTime;
#ifdef CLD_APPLIANCE_CONTROL_REMAINING_TIME
    zuint16                         u16RemainingTime;
#endif
#ifdef CLD_APPLIANCE_CONTROL_ATTRIBUTE_REPORTING_STATUS
    zenum8                          u8AttributeReportingStatus;
#endif
#endif
    zuint16                         u16ClusterRevision; 
} tsCLD_ApplianceControl;

```

where:

-   `u16StartTime` is a bitmap representing the start-time of a ‘running’ cycle of the appliance, as follows:


|**Bits**|**Description**|
|--------|---------------|
|0-5|Minutes part of the start-time, in the range 0 to 59

 \(may be absolute or relative time - see below\)

|
|6-7|Type of time encoding:

 -   0x0: Relative time - start-time is a delay from the time that the attribute was set

-   0x1: Absolute time - start-time is an actual time of the 24-hour clock

-   0x2-0x3: Reserved


 The defaults are absolute time for ovens and relative time for other appliances.

|
|8-15|Hours part of the start-time:

 -   in the range 0 to 255, if relative time selected

-   in the range 0 to 23, if absolute time selected


|

-   `u16FinishTime` is a bitmap representing the stop-time of a ‘running’ cycle of the appliance, as follows:


|**Bits**|**Description**|
|--------|---------------|
|0-5|Minutes part of the stop-time, in the range 0 to 59

 \(may be absolute or relative time - see below\)

|
|6-7|Type of time encoding:

 -   0x0: Relative time - stop-time is a delay from the time that the attribute was set

-   0x1: Absolute time - stop-time is an actual time of the 24-hour clock

-   0x2-0x3: Reserved


 The defaults are absolute time for ovens and relative time for other appliances.

|
|8-15|Hours part of the stop-time:

 -   in the range 0 to 255, if relative time selected

-   in the range 0 to 23, if absolute time selected


|

-   `u16RemainingTime` is an optional attribute indicating the time, in minutes, remaining in the current ‘running’ cycle of the appliance \(time until the end of the cycle\) - this attribute is constantly updated during the running cycle and is zero when the appliance is not running

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Appliance Control Cluster](../../appliance_control_cluster/topics/appliance_control_cluster.md)

