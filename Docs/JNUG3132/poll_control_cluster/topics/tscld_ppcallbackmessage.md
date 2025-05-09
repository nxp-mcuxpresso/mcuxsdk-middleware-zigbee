# tsCLD\_PPCallBackMessage

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

where:

-   `u``8CommandId` indicates the type of Poll Control command that has been received, one of:

    -   E\_CLD\_POLL\_CONTROL\_CMD\_CHECK\_IN

    -   E\_CLD\_POLL\_CONTROL\_CMD\_FAST\_POLL\_STOP

    -   E\_CLD\_POLL\_CONTROL\_CMD\_SET\_LONG\_POLL\_INTERVAL

    -   E\_CLD\_POLL\_CONTROL\_CMD\_SET\_SHORT\_POLL\_INTERVAL

        -   If they are required, the last two commands must be enabled in the compile-time options, as described in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed).
-   `uMessage` is a union containing the command payload, as one of \(depending on the value of `u8CommandId`\):

    -   psCheckinResponsePayload is a pointer to the payload of a ‘Check-in Response’ \(see [Section 20.9.2](tscld_pollcontrol_checkinresponsepayload.md#id_00a9d130-1180-415c-8ef5-bfe98d6ea45f)\)
    -   psSetLongPollIntervalPayload is a pointer to the payload of a ‘Set Long Poll Interval’ command \(see [Section 20.9.3](tscld_pollcontrol_setlongpollintervalpayload.md#id_0dc61324-708b-4c75-b93c-123cdf209ef8)\)
    -   psSetShortPollIntervalPayload is a pointer to the payload of a ‘Set Short Poll Interval’ command \(see [Section 20.9.4](tscld_pollcontrol_setshortpollintervalpayload.md#id_cd41ad68-90dc-48da-9798-12215b11f255)\)

The command payload for each command type is indicated in [Table 29](poll_control_events.md#id_6d7ef1d5-c2ac-4f6c-81c0-6b83708498e4) in [Section 20.5](poll_control_events.md#id_742705fc-310f-4ac4-9d56-a2dbddef4ef2).

**Parent topic:**[Structures](../../poll_control_cluster/topics/structures.md)

