# Status Notifications from Server to Client

The cluster server on the appliance can send unsolicited status notifications to the client in ‘Signal State Notification’ messages. A message of this kind can be sent by the application on the server by calling either of the following functions:

-   **eCLD\_ACSignalStateNotificationSend\(\)**

-   **eCLD\_ACSignalStateResponseORSignalStateNotificationSend\(\)**


**Note:** The latter function is also used internally by the cluster server to send a ‘Signal State Response’ message - see [Section 45.4.2](status_commands_from_client_to_server.md#id_7d9bcfdd-2613-4f5b-a199-ccabe4ea5bb6).

The appliance status information from the ‘Signal State Notification’ message is reported to the application on the cluster client through the event E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_NOTIFICATION, which is generated when the notification arrives from the server \(Appliance Control events are described in [Section 45.5](appliance_control_events.md#id_cce61421-45c7-4b54-b2ab-fc056f1d6dfa)\). The appliance status information from the message payload is contained in the above event - for details of this payload and the status information, refer to [Section 45.9.3](tscld_ac_signalstateresponseorsignalstatenotificat.md#id_62cbbba6-9e68-43f7-8ffc-b7f9112099d1).

**Parent topic:**[Sending commands](../../appliance_control_cluster/topics/sending_commands.md)

