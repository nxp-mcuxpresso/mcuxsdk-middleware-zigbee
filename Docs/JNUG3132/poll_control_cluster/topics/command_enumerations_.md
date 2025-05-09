# ‘Command’ Enumerations

The following enumerations represent the commands that the Poll Control cluster generates.

```
typedef enum PACK
{
  E_CLD_POLL_CONTROL_CMD_CHECK_IN = 0x00,
  E_CLD_POLL_CONTROL_CMD_FAST_POLL_STOP,
  E_CLD_POLL_CONTROL_CMD_SET_LONG_POLL_INTERVAL,
  E_CLD_POLL_CONTROL_CMD_SET_SHORT_POLL_INTERVAL,
} teCLD_PollControl_CommandID;

```

The above enumerations are used to indicate types of Poll Control cluster events and are described in [Section 20.5](poll_control_events.md#id_742705fc-310f-4ac4-9d56-a2dbddef4ef2).

**Parent topic:**[Enumerations](../../poll_control_cluster/topics/enumerations.md)

