# ‘Log Notification’ messages from server to client

The cluster server can supply the client with an individual data log by sending an unsolicited ‘Log Notification’ message to the client. This message is sent by the application on the server by calling either of the following functions:

-   **eCLD\_ASCLogNotificationSend\(\)**

-   **eCLD\_ASCLogNotificationORLogResponseSend\(\)**


**Note:**

1.  The latter function is also used internally by the cluster server to send a ‘Log Response’ message - see [Section 48.3.1](log_queue_request_messages_from_client_to_server.md#id_325f1910-013a-4826-945d-098c47bc7f47).
2.  Before calling either function, the relevant log should be in the local log queue \(see [Section 48.4.1](adding_and_removing_logs.md#id_427bc004-1b06-48f8-880a-7adb4f8a5f06)\). This is because the log needs to be in the queue to allow the server to perform further actions on it - for example, to process a ‘Log Request’.
3.  The function **eCLD\_ASCAddLog\(\)** used to add a log to the local log queue \(see [Section 48.4.1](adding_and_removing_logs.md#id_427bc004-1b06-48f8-880a-7adb4f8a5f06)\) automatically sends a ‘Log Notification’ message to all bound Appliance Statistics cluster clients.

The log information from the ‘Log Notification’ message is reported to the application on the cluster client through the event E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_NOTIFICATION, which is generated when the message arrives from the server \(Appliance Statistics events are described in [Section 48.5](appliance_statistics_events.md#id_15b6edae-0ed9-4acc-911d-748358a083e6)\). The log information from the message payload is contained in the above event - for details of this payload and the supplied log information, refer to [Section 48.9.3](tscld_asc_lognotificationorlogresponsepayload.md#id_5db27449-4b3a-4b18-a4d1-a8f63b7b0d61).

**Parent topic:**[Sending messages](../../appliance_statistics_cluster/topics/sending_messages.md)

