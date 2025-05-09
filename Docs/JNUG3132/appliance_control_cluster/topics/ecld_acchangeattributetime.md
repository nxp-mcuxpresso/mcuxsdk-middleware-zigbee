# eCLD\_ACChangeAttributeTime

```
teZCL_Status eCLD_ACChangeAttributeTime(
        uint8 u8SourceEndPointId,
        teCLD_ApplianceControl_Cluster_AttrID eAttributeTimeId,
        uint16 u16TimeValue);

```

## Description 

This function can be used on an Appliance Control cluster server \(appliance\) to update the time attributes of the cluster \(start time, finish time, remaining time\). This is particularly useful if the host node has its own timer.

The target attribute must be specified using one of:

-   E\_CLD\_APPLIANCE\_CONTROL\_ATTR\_ID\_START\_TIME

-   E\_CLD\_APPLIANCE\_CONTROL\_ATTR\_ID\_FINISH\_TIME

-   E\_CLD\_APPLIANCE\_CONTROL\_ATTR\_ID\_REMAINING\_TIME


## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the message. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values
-   *eAttributeTimeId*: Identifier of attribute to be updated \(see above and [Section 45.9.1](tscld_appliancecontrolcallbackmessage.md#id_8b206e95-86fc-4bef-b8d4-29d1d3e63345)\)
-   *u16TimeValue*: UTC time to set

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../appliance_control_cluster/topics/functions.md)

