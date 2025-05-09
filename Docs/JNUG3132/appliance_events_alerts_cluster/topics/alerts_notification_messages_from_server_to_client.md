# ‘Alerts Notification’ Messages from Server to Client

The cluster server on the appliance can send unsolicited alert notifications to the client in ‘Alerts Notification’ messages. The application on the server can send a message of this kind by calling either of the following functions:

-   **eCLD\_AEAAAlertsNotificationSend\(\)**

-   **eCLD\_AEAAGetAlertsResponseORAlertsNotificationSend\(\)**


**Note:** The latter function is also used internally by the cluster server to send a ‘Get Alerts Response’ message - see [Section 47.3.1](get_alerts_messages_from_client_to_server.md#id_dda7debe-0281-45d5-8543-e24c1c8061f0).

The appliance status information from the ‘Alerts Notification’ message is reported to the application on the cluster client through the event E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION, which is generated when the notification arrives from the server \(Appliance Events and Alerts events are described in [Section 47.4](appliance_events_and_alerts_events.md#id_a316140d-834d-4343-89fe-9d75d7943427)\). The appliance alerts from the message payload are contained in the above event - for details of this payload and the alert information, refer to [Section 47.8.2](tscld_aeaa_getalertsresponseoralertsnotificationpa.md#id_4aa90637-5913-4ddd-a5e2-4c731b6406ce). Up to 15 alerts can be reported in a single notification.

**Parent topic:**[Sending Messages](../../appliance_events_alerts_cluster/topics/sending_messages.md)

