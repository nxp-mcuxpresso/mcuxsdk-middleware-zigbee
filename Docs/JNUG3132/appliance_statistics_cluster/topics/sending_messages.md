# Sending messages

The Appliance Statistics cluster server resides on the appliance \(e.g. a washing machine\) and the cluster client resides on a controlling device \(normally a remote control unit\).

Messages can be sent between the client and the server in the following ways:

-   The client can enquire whether any data logs are available on the appliance \(server\) by sending a ‘Log Queue Request’ to the server \(which will reply with a ‘Log Queue Response’ message\)

-   The server can notify the client that data logs are available by sending an unsolicited ‘Statistics Available’ message to the client

-   The client can request a current data log from the appliance \(server\) by sending a ‘Log Request’ message to the server \(which will reply with a ‘Log Response’ message\)

-   The server can send an unsolicited data log to the client in a ‘Log Notification’ message


Sending the above messages is described in the sub-sections below.


```{include} ../../appliance_statistics_cluster/topics/log_queue_request_messages_from_client_to_server.md
:heading-offset: 2
```

```{include} ../../appliance_statistics_cluster/topics/statistics_available_messages_from_server_to_clien.md
:heading-offset: 2
```

```{include} ../../appliance_statistics_cluster/topics/log_request_messages_from_client_to_server.md
:heading-offset: 2
```

```{include} ../../appliance_statistics_cluster/topics/log_notification_messages_from_server_to_client.md
:heading-offset: 2
```

**Parent topic:**[Appliance Statistics Cluster](../../appliance_statistics_cluster/topics/appliance_statistics_cluster.md)

