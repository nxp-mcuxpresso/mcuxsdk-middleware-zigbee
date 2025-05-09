# ‘Get Alerts’ Messages from Client to Server

The application on the cluster client can request the alerts that are currently active on the appliance by sending a ‘Get Alerts’ message to the server - this message is sent by calling the function **eCLD\_AEAAGetAlertsSend\(\)**. This function returns immediately and the requested alerts are later returned in an E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS event, which is generated when a response arrives from the server \(Appliance Events and Alerts events are described in [Section 47.4](appliance_events_and_alerts_events.md#id_a316140d-834d-4343-89fe-9d75d7943427)\).

**Note:** The cluster server handles the ‘Get Alerts’ message automatically and returns the requested alerts in a ‘Get Alerts Response’ message to the client.

The appliance alerts from the message payload are contained in the above event - for details of this payload and the alert information, refer to [Section 47.8.2](tscld_aeaa_getalertsresponseoralertsnotificationpa.md#id_4aa90637-5913-4ddd-a5e2-4c731b6406ce). Up to 15 alerts can be reported in a single response.

**Parent topic:**[Sending Messages](../../appliance_events_alerts_cluster/topics/sending_messages.md)

