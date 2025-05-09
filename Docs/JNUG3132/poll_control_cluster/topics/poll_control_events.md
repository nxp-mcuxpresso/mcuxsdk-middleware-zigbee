# Poll Control Events

The Poll Control cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). The cluster contains its own event handler. However, if a device uses this cluster then application-specific Poll Control event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function will then be invoked when a Poll Control event occurs and needs the attention of the application.

For a Poll Control event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_PollControlCallBackMessage` structure:

```
typedef struct
{
 uint8 u8CommandId;
 union
 {
 tsCLD_PollControl_CheckinResponsePayload *psCheckinResponsePayload;
 #ifdef CLD_POLL_CONTROL_CMD_SET_LONG_POLL_INTERVAL 
 tsCLD_PollControl_SetLongPollIntervalPayload    
            *psSetLongPollIntervalPayload;
 #endif
 #ifdef CLD_POLL_CONTROL_CMD_SET_SHORT_POLL_INTERVAL    
       tsCLD_PollControl_SetShortPollIntervalPayload  
    *psSetShortPollIntervalPayload;
 #endif
 } uMessage;
} tsCLD_PollControlCallBackMessage;

```

The above structure is fully described in [Section 20.9.1](tscld_ppcallbackmessage.md#id_537650ed-82d1-4144-a3f0-b74bbded2518).

When a Poll Control event occurs, one of the command types listed in [Table 29](#id_6d7ef1d5-c2ac-4f6c-81c0-6b83708498e4) is specified through the `u8CommandId` field of the structure `tsCLD_PollControlCallBackMessage`. This command type determines which command payload is used from the union `uMessage`.

|**u8CommandId Enumeration**|**Description/Payload Type**|
|---------------------------|----------------------------|
|**On Client**|
|E\_CLD\_POLL\_CONTROL\_CMD\_CHECK\_IN|A Check-in command has been received by the client.|
|**On Server**|
|E\_CLD\_POLL\_CONTROL\_CMD\_CHECK\_IN|A Check-in Response has been received by the server, following a previously sent Check-In command.

 **tsCLD\_PollControl\_CheckinResponsePayload**

|
|E\_CLD\_POLL\_CONTROL\_CMD\_FAST\_POLL\_STOP|A ‘Fast Poll Stop’ command has been received by the server.|
|E\_CLD\_POLL\_CONTROL\_CMD\_SET\_LONG\_POLL\_INTERVAL|A ‘Set Long Poll Interval’ command has been received by the server.

 **tsCLD\_PollControl\_SetLongPollIntervalPayload**

|
|E\_CLD\_POLL\_CONTROL\_CMD\_SET\_SHORT\_POLL\_INTERVAL|A ‘Set Short Poll Interval’ command has been received by the server.

 **tsCLD\_PollControl\_SetShortPollIntervalPayload**

|

**Parent topic:**[Poll Control Cluster](../../poll_control_cluster/topics/poll_control_cluster.md)

