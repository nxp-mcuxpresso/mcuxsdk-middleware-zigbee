# teCLD\_Commissioning\_Command

The following structure contains the enumerations used to identify commands of the Commissioning cluster \(the same enumerations are used for requests and their corresponding responses\).

```
typedef enum 
{
    E_CLD_COMMISSIONING_CMD_RESTART_DEVICE             = 0x00,
    E_CLD_COMMISSIONING_CMD_SAVE_STARTUP_PARAMS,
    E_CLD_COMMISSIONING_CMD_RESTORE_STARTUP_PARAMS,
    E_CLD_COMMISSIONING_CMD_RESET_STARTUP_PARAMS 
} teCLD_Commissioning_Command;

```

The above enumerations are described in the table below:

|**Enumeration**|**Command**|
|---------------|-----------|
|E\_CLD\_COMMISSIONING\_CMD\_RESTART\_DEVICE|Restart Device request or response|
|E\_CLD\_COMMISSIONING\_CMD\_SAVE\_STARTUP\_PARAMS|Save Start-up Parameters request or response|
|E\_CLD\_COMMISSIONING\_CMD\_RESTORE\_STARTUP\_PARAMS|Restore Start-up Parameters request or response|
|E\_CLD\_COMMISSIONING\_CMD\_RESET\_STARTUP\_PARAMS|Reset Start-up Parameters request or response|

**Parent topic:**[Enumerations](../../Commissioning_cluster/topics/enumerations.md)

