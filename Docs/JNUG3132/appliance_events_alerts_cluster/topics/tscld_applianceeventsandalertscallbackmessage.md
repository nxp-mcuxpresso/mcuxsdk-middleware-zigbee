# tsCLD\_ApplianceEventsAndAlertsCallBackMessage

For an Appliance Events and Alerts event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceEventsAndAlertsCallBackMessage` structure:

```
typedef struct
{
 uint8     u8CommandId
 union
 {
 tsCLD_AEAA_GetAlertsResponseORAlertsNotificationPayload            
         *psGetAlertsResponseORAlertsNotificationPayload;
 tsCLD_AEAA_EventNotificationPayload                                
         *psEventNotificationPayload;
 } uMessage;
} tsCLD_ApplianceEventsAndAlertsCallBackMessage; 

```

where:

-   `u``8CommandId` indicates the type of Appliance Events and Alerts command that has been received, one of:

    -   E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS

    -   E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION

    -   E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_EVENT\_NOTIFICATION

-   `u``Message` is a union containing the command payload as one of \(depending on the value of `u8CommandId`\):

    -   `psGetAlertsResponseORAlertsNotificationPayload` is a pointer to the payload of an "Get Alerts" response message or an alerts notification message \(see [Section 47.8.2](tscld_aeaa_getalertsresponseoralertsnotificationpa.md#id_4aa90637-5913-4ddd-a5e2-4c731b6406ce)\)

    -   `psEventNotificationPayload` is a pointer to the payload of an events notification message \(see [Section 47.8.3](tscld_aeaa_eventnotificationpayload.md#id_33bccf57-59fb-4e37-a22e-aec54e48ddd1)\)


**Parent topic:**[Structures](../../appliance_events_alerts_cluster/topics/structures.md)

