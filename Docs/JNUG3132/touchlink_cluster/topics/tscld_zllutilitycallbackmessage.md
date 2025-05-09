# tsCLD\_ZllUtilityCallBackMessage

This structure contains the command ID and payload for a received Commissioning Utility command.

```
typedef struct
{
 uint8u8CommandId;
 union
 {
  tsCLD_ZllUtility_EndpointInformationCommandPayload 
 *psEndpointInfoPayload;
  tsCLD_ZllUtility_GetGroupIdReqCommandPayload 
 *psGetGroupIdReqPayload;
  tsCLD_ZllUtility_GetGroupIdRspCommandPayload 
 *psGetGroupIdRspPayload;
  tsCLD_ZllUtility_GetEndpointListReqCommandPayload  
 *psGetEndpointlistReqPayload;
  tsCLD_ZllUtility_GetEndpointListRspCommandPayload  
 *psGetEndpointListRspPayload;
 } uMessage;
} tsCLD_ZllUtilityCallBackMessage;

```

where:

-   `u8CommandId` is the command ID - enumerations are provided, as detailed in [Section 44.6.2](commissioning_utility_command_events.md#id_d88afd92-48c3-4a35-9e96-6dd83d1c174b).

-   `uMessage` contains the payload of the command, where the structure used depends on the command ID \(the structures are detailed in the sections below\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

