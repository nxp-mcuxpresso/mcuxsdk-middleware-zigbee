# ‘Event Notification’ Messages from Server to Client

The cluster server on the appliance can send unsolicited event notifications to the client in ‘Event Notification’ messages, where each message reports a single appliance event \(for example, oven has reached its target temperature\). A message of this kind can be sent by the application on the server by calling the function **eCLD\_AEAAEventNotificationSend\(\)**.

The appliance event information from the ‘Event Notification’ message is reported to the application on the cluster client through the event E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION, which is generated when the notification arrives from the server \(Appliance Events and Alerts events are described in [Section 47.4](appliance_events_and_alerts_events.md#id_a316140d-834d-4343-89fe-9d75d7943427)\). The appliance event from the message payload is contained in the above client event - for details of this payload and the embedded appliance event information, refer to [Section 47.8.3](tscld_aeaa_eventnotificationpayload.md#id_33bccf57-59fb-4e37-a22e-aec54e48ddd1).

**Parent topic:**[Sending Messages](../../appliance_events_alerts_cluster/topics/sending_messages.md)

