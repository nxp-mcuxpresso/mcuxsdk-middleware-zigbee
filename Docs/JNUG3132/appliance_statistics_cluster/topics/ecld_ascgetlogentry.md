# eCLD\_ASCGetLogEntry

```
teZCL_CommandStatus eCLD_ASCGetLogEntry(
        uint8 u8SourceEndPointId,
        uint32 u32LogId,
        tsCLD_LogTable **ppsLogTable);

```

## Description 

This function can be used on an Appliance Statistics cluster server to obtain the data log with the specified log ID.

## Parameter 

-   *u8SourceEndPointId* Number of the local endpoint on which the Appliance Statistics cluster server resides
-   *u32LogId* Log ID of the required data log
-   *ppsLogTable* Pointer to a memory location to receive a pointer to the required data log

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS
-   E\_ZCL\_CMDS\_FAIL
-   E\_ZCL\_CMDS\_NOT\_FOUND \(specified log not present\)

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

