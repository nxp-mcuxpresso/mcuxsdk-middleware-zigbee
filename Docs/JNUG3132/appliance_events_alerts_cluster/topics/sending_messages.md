# Sending Messages

The Appliance Events and Alerts cluster server resides on the appliance \(for example, a washing machine\) and the cluster client resides on a controlling device \(normally a remote control unit\).

Messages can be sent between the client and the server in the following ways:

-   Alerts that are active on the appliance can be requested by the client by sending a ‘Get Alerts’ message to the server \(which replies with a ‘Get Alerts Response’ message\).

-   Alerts that are active on the appliance can be sent unsolicited from the server to the client in an ‘Alerts Notification’ message.

-   The server can notify the client of an appliance event by sending an unsolicited ‘Event Notification’ message to the client


Sending the above messages is described in the sub-sections below.


```{include} ../../appliance_events_alerts_cluster/topics/get_alerts_messages_from_client_to_server.md
:heading-offset: 2
```

```{include} ../../appliance_events_alerts_cluster/topics/alerts_notification_messages_from_server_to_client.md
:heading-offset: 2
```

```{include} ../../appliance_events_alerts_cluster/topics/event_notification_messages_from_server_to_client.md
:heading-offset: 2
```

**Parent topic:**[Appliance Events and Alerts Cluster](../../appliance_events_alerts_cluster/topics/appliance_events_and_alerts_cluster.md)

