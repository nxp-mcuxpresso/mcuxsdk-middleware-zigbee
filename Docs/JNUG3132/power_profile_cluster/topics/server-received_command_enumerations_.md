# ‘Server-Received Command’ Enumerations

The following enumerations represent the commands that can be received by the cluster server \(and are therefore generated on the cluster client\).

```
typedef enum PACK
{
  E_CLD_PP_CMD_POWER_PROFILE_REQ = 0x00,
  E_CLD_PP_CMD_POWER_PROFILE_STATE_REQ,
  E_CLD_PP_CMD_GET_POWER_PROFILE_PRICE_RSP,
  E_CLD_PP_CMD_GET_OVERALL_SCHEDULE_PRICE_RSP, 
  E_CLD_PP_CMD_ENERGY_PHASES_SCHEDULE_NOTIFICATION,
  E_CLD_PP_CMD_ENERGY_PHASES_SCHEDULE_RSP,
  E_CLD_PP_CMD_POWER_PROFILE_SCHEDULE_CONSTRAINTS_REQ,
  E_CLD_PP_CMD_ENERGY_PHASES_SCHEDULE_STATE_REQ,        
  E_CLD_PP_CMD_GET_POWER_PROFILE_PRICE_EXTENDED_RSP
 } teCLD_PP_ServerReceivedCommandID;

```

The above enumerations are used to indicate types of Power Profile cluster events and are described in [Section 21.6](power_profile_events.md#id_c65ba54d-c1c7-47c1-bd6c-5463e6afa17e).

**Parent topic:**[Enumerations](../../power_profile_cluster/topics/enumerations.md)

