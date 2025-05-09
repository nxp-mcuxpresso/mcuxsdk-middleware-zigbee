# eCLD\_ASCAddLog

```
teZCL_CommandStatus eCLD_ASCAddLog(
        uint8 u8SourceEndPointId,
        uint32 u32LogId,
        uint8 u8LogLength,
        uint32 u32Time,
        uint8 *pu8LogData);

```

## Description 

This function can be used on an Appliance Statistics cluster server to add a data log to the log queue. The function also sends out a ‘Log Notification’ message to all bound Appliance Statistics cluster clients.

The length of the data log, in bytes, must be less than the defined value of CLD\_APPLIANCE\_STATISTICS\_ATTR\_LOG\_MAX\_SIZE \(which must be less than or equal to 70\).

## Parameter 

-   *u8SourceEndPointId* Number of the local endpoint on which the Appliance Statistics cluster server resides
-   *u32LogId* Identifier of log
-   *u8LogLength* Length of log, in bytes
-   *u32Time* UTC time at which log was produced
-   *pu8LogData* Pointer to log data

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS
-   E\_ZCL\_CMDS\_FAIL
-   E\_ZCL\_CMDS\_INVALID\_VALUE \(log too long\)
-   E\_ZCL\_CMDS\_INVALID\_FIELD \(NULL pointer to log data\)
-   E\_ZCL\_CMDS\_INSUFFICIENT\_SPACE

**Parent topic:**[Functions](../../appliance_statistics_cluster/topics/functions.md)

