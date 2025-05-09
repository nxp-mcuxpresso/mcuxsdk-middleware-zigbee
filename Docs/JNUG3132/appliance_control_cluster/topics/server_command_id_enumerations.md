# ‘Server command ID’ enumerations

The following enumerations are used in commands issued on a cluster server.

```
typedef enum PACK
{
    E_CLD_APPLIANCE_CONTROL_CMD_SIGNAL_STATE_RESPONSE = 0x00,
    E_CLD_APPLIANCE_CONTROL_CMD_SIGNAL_STATE_NOTIFICATION
} teCLD_ApplianceControl_ServerCommandId;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_RESPONSE|A response to a ‘Signal State’ request|
|E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_NOTIFICATION|A ‘Signal State’ notification|

**Parent topic:**[Enumerations](../../appliance_control_cluster/topics/enumerations.md)

