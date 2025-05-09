# ‘Statistics Available’ messages from server to client

The cluster server can notify the client when data logs are available by sending an unsolicited ‘Statistics Available’ message to the client. This message contains the number of logs in the log queue and the log IDs. A message of this kind can be sent by the application on the server by calling either of the following functions:

-   **eCLD\_ASCStatisticsAvailableSend\(\)**

-   **eCLD\_ASCLogQueueResponseORStatisticsAvailableSend\(\)**


**Note:**

1.  The latter function is also used internally by the cluster server to send a ‘Log Queue Response’ message - see [Section 48.3.1](log_queue_request_messages_from_client_to_server.md#id_325f1910-013a-4826-945d-098c47bc7f47).
2.  Before calling either function, the relevant log\(s\) should be added to the local log queue as described in [Section 48.4.1](adding_and_removing_logs.md#id_427bc004-1b06-48f8-880a-7adb4f8a5f06). This is because the logs need to be in the queue to allow the server to perform further actions on them - for example, to process a ‘Log Request’.

The log availability information from the ‘Statistics Available’ message is reported to the application on the cluster client through the event E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_STATISTICS\_AVAILABLE, which is generated when the message arrives from the server \(Appliance Statistics events are described in [Section 48.5](appliance_statistics_events.md#id_15b6edae-0ed9-4acc-911d-748358a083e6)\). The availability information from the message payload is contained in the above event - for details of this payload and the availability information, refer to [Section 48.9.4](tscld_asc_logqueueresponseorstatisticsavailablepay.md#id_4cfb8571-5604-4991-b2c3-0c78359ecaf8).

**Parent topic:**[Sending messages](../../appliance_statistics_cluster/topics/sending_messages.md)

