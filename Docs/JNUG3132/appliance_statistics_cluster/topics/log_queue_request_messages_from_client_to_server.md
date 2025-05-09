# ‘Log Queue Request’ messages from client to server

The application on the cluster client can enquire about the availability of data logs on the appliance by sending a ‘Log Queue Request’ message to the server. This message is sent by calling the function **eCLD\_ASCLogQueueRequestSend\(\)**. This function returns immediately and the log availability is later returned in an E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_RESPONSE event, which is generated when a response arrives from the server \(Appliance Statistics events are described in [Section 48.5](appliance_statistics_events.md#id_15b6edae-0ed9-4acc-911d-748358a083e6)\).

**Note:** The cluster server handles the ‘Log Queue Request’ message automatically and returns the requested information in a ‘Log Queue Response’ message to the client.

The log availability information from the message payload is contained in the above event, and comprises the number of logs currently in the log queue and their log IDs - for details of this payload and the availability information, refer to [Section 48.9.4](tscld_asc_logqueueresponseorstatisticsavailablepay.md#id_4cfb8571-5604-4991-b2c3-0c78359ecaf8).

**Parent topic:**[Sending messages](../../appliance_statistics_cluster/topics/sending_messages.md)

