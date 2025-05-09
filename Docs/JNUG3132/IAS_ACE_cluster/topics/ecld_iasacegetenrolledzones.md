# eCLD\_IASACEGetEnrolledZones

```
teZCL_CommandStatus eCLD_IASACEGetEnrolledZones(
    uint8 u8SourceEndPointId,
    uint8 *pu8ZoneID,
    uint8 *pu8NumOfEnrolledZones);

```

## Description

This function can be used on an IAS ACE cluster server to obtain a list of the enrolled zones from the local Zone table.

The function searches the Zone table and returns a list of the Zone IDs of all the enrolled zones \(for which there are table entries\). The number of enrolled zones is also returned.

## Parameters

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *pu8ZoneID*: Pointer to a location to receive the first Zone ID in the reported list of enrolled zones
-   *pu8NumOfEnrolledZones*: Pointer to a location to receive the number of enrolled zones reported in the above list

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS \(zone list successfully obtained from Zone table\)
-   E\_ZCL\_CMDS\_FAILURE \(cluster instance not found\)
-   E\_ZCL\_CMDS\_INVALID\_FIELD \(a supplied pointer is NULL\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

