# tsCLD\_AC\_ExecutionOfCommandPayload

This structure contains the payload for an "Execution of Command" message.

```
typedef struct
{
           zenum8                  eExecutionCommandId;
} stsCLD_AC_ExecutionOfCommandPayload;

```

where `eExecutionCommandId` is a value representing the command to be executed - the commands are detailed in the British Standards document BS EN 50523.

**Parent topic:**[Structures](../../appliance_control_cluster/topics/structures.md)

