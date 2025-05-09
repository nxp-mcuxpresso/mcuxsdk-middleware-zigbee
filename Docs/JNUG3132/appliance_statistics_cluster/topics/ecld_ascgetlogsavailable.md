# eCLD\_ASCGetLogsAvailable

```
teZCL_CommandStatus eCLD_ASCGetLogsAvailable(
        uint8 u8SourceEndPointId,
        uint32 *pu32LogId,
        uint8 *pu8LogIdCount);

```

## Description 

This function can be used on an Appliance Statistics cluster server to obtain a list of the data logs in the log queue. The number of available logs and a list of their log IDs will be obtained.

## Parameter 

-   *u8SourceEndPointId* Number of the local endpoint on which the Appliance Statistics cluster server resides
-   *pu32LogId* Pointer to an area of memory to receive the list of 32-bit log IDs
-   *pu8LogIdCount* Pointer to an area of memory to receive the number of logs in the queue

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS
-   E\_ZCL\_CMDS\_FAIL

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

