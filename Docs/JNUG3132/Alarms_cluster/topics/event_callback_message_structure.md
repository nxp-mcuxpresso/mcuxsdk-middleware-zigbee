# Event Callback Message Structure

For an Alarms event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_AlarmsCallBackMessage` structure:

```
typedef struct
{
   uint8  u8CommandId;
   union
   {
 tsCLD_AlarmsResetAlarmCommandPayload *psResetAlarmCommandPayload;
 tsCLD_AlarmsAlarmCommandPayload   *psAlarmCommandPayload;
 tsCLD_AlarmsGetAlarmResponsePayload  *psGetAlarmResponse;
} uMessage;
} tsCLD_AlarmsCallBackMessage;

```

where:

-   `u8CommandId` indicates the type of Alarms command that has been received by a cluster server or client, one of:

    -   E\_CLD\_ALARMS\_CMD\_RESET\_ALARM \(server event\)

    -   E\_CLD\_ALARMS\_CMD\_RESET\_ALL\_ALARMS \(server event\)

    -   E\_CLD\_ALARMS\_CMD\_GET\_ALARM \(server event\)

    -   E\_CLD\_ALARMS\_CMD\_RESET\_ALARM\_LOG \(server event\)

    -   E\_CLD\_ALARMS\_CMD\_ALARM \(client event\)

    -   E\_CLD\_ALARMS\_CMD\_GET\_ALARM\_RESPONSE \(client event\)

-   `uMessage` is a union containing the command payload in the following form:

    -   `psResetAlarmCommandPayload` is a pointer to a structure containing the Reset Alarm command payload - see [Section 17.7.3.1](reset_alarm_command_payload.md#id_22c0af95-0232-41d4-a7c4-f64012ad1f09)

    -   `psAlarmCommandPayload` is a pointer to a structure containing the Alarm notification payload - see [Section 17.7.3.2](alarm_notification_payload.md#id_98e1ead0-e8e5-4a3d-b11e-ad644549456f)

    -   `psGetAlarmResponse` is a pointer to a structure containing the Get Alarm response payload - see [Section 17.7.4.1](get_alarm_response_payload.md#id_bfc22e33-dd3e-40b6-8f89-87532a7e84e1)


For further information on the above events, refer to [Section 17.5](alarms_events.md#id_4007d52e-944d-4b75-a066-bb3dcb2ac878).

**Parent topic:**[Structures](../../Alarms_cluster/topics/structures.md)

