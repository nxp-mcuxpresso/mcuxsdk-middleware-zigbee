# eCLD\_ASCRemoveLog

```
teZCL_CommandStatus eCLD_ASCRemoveLog(
    uint8 u8SourceEndPointId,
    uint32 u32LogId);

```

## Description 

This function can be used on an Appliance Statistics cluster server to remove the specified data log from the log queue.

## Parameter 

-   *u8SourceEndPointId* Number of the local endpoint on which the Appliance Statistics cluster server resides
-   *u32LogId* Identifier of log

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS
-   E\_ZCL\_CMDS\_FAIL

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

