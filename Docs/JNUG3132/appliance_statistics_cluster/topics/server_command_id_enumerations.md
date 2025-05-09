# ‘Server Command ID’ enumerations

The following enumerations are used in commands issued on a cluster server.

```
typedef enum PACK
{
    E_CLD_APPLIANCE_STATISTICS_CMD_LOG_NOTIFICATION = 0x00,
    E_CLD_APPLIANCE_STATISTICS_CMD_LOG_RESPONSE,
    E_CLD_APPLIANCE_STATISTICS_CMD_LOG_QUEUE_RESPONSE,
    E_CLD_APPLIANCE_STATISTICS_CMD_STATISTICS_AVAILABLE
} teCLD_ApplianceStatistics_ServerCommandId;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_NOTIFICATION|A ‘Log Notification’ message|
|E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_RESPONSE|A ‘Log Response’ message|
|E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_RESPONSE|A ‘Log Queue Response’ message|
|E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_STATISTICS\_AVAILABLE|A ‘Statistics Available’ message|

**Parent topic:**[Enumerations](../../appliance_statistics_cluster/topics/enumerations.md)

