# Status Commands from Client to Server

The application on the cluster client can request the current status of the appliance by sending a ‘Signal State’ message to the cluster server on the appliance. This message can be sent by calling the function **eCLD\_ACSignalStateSend\(\)**. This function returns immediately and the requested status information is later returned in an E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_RESPONSE event, which is generated when a response arrives from the server \(Appliance Control events are described in [Section 45.5](appliance_control_events.md#id_cce61421-45c7-4b54-b2ab-fc056f1d6dfa)\).

**Note:** The cluster server handles the ‘Signal State’ message automatically and returns the requested status information in a ‘Signal State Response’ message to the client.

The appliance status information from the message payload is contained in the above event - for details of this payload and the status information, refer to [Section 45.9.3](tscld_ac_signalstateresponseorsignalstatenotificat.md#id_62cbbba6-9e68-43f7-8ffc-b7f9112099d1).

**Parent topic:**[Sending commands](../../appliance_control_cluster/topics/sending_commands.md)

