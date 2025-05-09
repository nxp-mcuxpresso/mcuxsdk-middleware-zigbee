# eCLD\_AlarmsGetAlarmFromLog

```
teZCL_Status eCLD_AlarmsGetAlarmFromLog(
  tsZCL_EndPointDefinition *psEndPointDefinition,
  tsZCL_ClusterInstance *psClusterInstance,
  uint8 *pu8AlarmCode,
  uint16 *pu16ClusterId,
  uint32 *pu32TimeStamp);

```

## Description 

This function can be called on the Alarms cluster server to obtain an entry from the local Alarms table. Information on the logged alarm with the earliest timestamp in the device’s Alarms table is returned - pointers to memory locations to receive the retrieved alarm data must be provided. As a result of this command, the retrieved entry is also deleted from the table.

## Parameters 

-   *psEndPointDefinition*: Pointer to the ZCL endpoint definition structure for the application \(see [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\)
-   *psClusterInstance*: Pointer to structure containing information about the Alarms cluster instance \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\)
-   *pu8AlarmCode*: Pointer to location to receive the alarm code which identifies the retrieved alarm type
-   *pu16ClusterId*: Pointer to location to receive the Cluster ID of the cluster which generated the alarm
-   *pu32TimeStamp*: Pointer to location to receive timestamp \(UTC\) of the retrieved alarm \(a value of 0XFFFFFFFF indicates that no timestamp is available for the alarm\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Alarms_cluster/topics/functions.md)

