# ‘Log Request’ messages from client to server

The application on the cluster client can request the log with a particular log ID from the appliance by sending a ‘Log Request’ message to the server. This message is sent by calling the function **eCLD\_ASCLogRequestSend\(\)**. This function returns immediately and the requested log information is later returned in an E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_RESPONSE event, which is generated when a response arrives from the server \(Appliance Statistics events are described in [Section 48.5](appliance_statistics_events.md#id_15b6edae-0ed9-4acc-911d-748358a083e6)\).

**Note:**

1.  This function should normally be called after a ‘Log Queue Response’ or ‘Statistics Available’ message has been received by the client, indicating that logs are available on the server.
2.  The cluster server handles the ‘Log Request’ message automatically and returns the requested log information in a ‘Log Response’ message to the client.

The log information from the message payload is contained in the above event - for details of this payload and the supplied log information, refer to [Section 48.9.3](tscld_asc_lognotificationorlogresponsepayload.md#id_5db27449-4b3a-4b18-a4d1-a8f63b7b0d61).

**Parent topic:**[Sending messages](../../appliance_statistics_cluster/topics/sending_messages.md)

