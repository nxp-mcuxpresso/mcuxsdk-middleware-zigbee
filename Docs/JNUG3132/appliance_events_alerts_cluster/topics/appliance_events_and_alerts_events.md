# Appliance Events and Alerts Events

The Appliance Events and Alerts cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). The cluster contains its own event handler. If a device uses this cluster then application-specific Appliance Events and Alerts event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function is then invoked when an Appliance Events and Alerts event occurs and needs the attention of the application.

For an Appliance Events and Alerts event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceEventsAndAlertsCallBackMessage` structure:

```
typedef struct
{
  uint8  u8CommandId
  union
  {
  tsCLD_AEAA_GetAlertsResponseORAlertsNotificationPayload
  *psGetAlertsResponseORAlertsNotificationPayload;
  tsCLD_AEAA_EventNotificationPayload    
  *psEventNotificationPayload;
  }uMessage;
} tsCLD_ApplianceEventsAndAlertsCallBackMessage;

```

When an Appliance Events and Alerts event occurs, one of four command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command types are detailed the tables below for events generated on a server and a client.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS|A ‘Get Alerts’ request has been received by the server \(appliance\)|

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS|A response to a ‘Get Alerts’ request has been received by the client, containing the requested alerts \(up to 15\)|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION|An ‘Alerts Notification’ message has been received by the client, containing unsolicited alerts \(up to 15\)|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_EVENT\_NOTIFICATION|An ‘Event Notification’ message has been received by the client|

**Parent topic:**[Appliance Events and Alerts Cluster](../../appliance_events_alerts_cluster/topics/appliance_events_and_alerts_cluster.md)

