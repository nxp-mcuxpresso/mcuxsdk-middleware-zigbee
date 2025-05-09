# Operation

After initialization, the Poll Control cluster server on the End Device begins to operate in normal poll mode and performs the following activities \(while the End Device is awake\):

-   Periodically poll the parent for data packets at a rate determined by the ‘long poll interval’.

-   Periodically check whether any bound cluster clients require the server to enter fast poll mode, with ‘check-ins’ at a rate determined by the ‘check-in interval’.


The server application must provide the cluster with timing prompts for the above periodic activities. These prompts are produced by periodically calling the function **eCLD\_PollControlUpdate\(\)**. The periods of the above activities are defined in terms of quarter-seconds. Therefore, this function must be called every quarter-second and the application must provide a 250 ms software timer to schedule these calls. Any poll or check-in that is due when this function is called is automatically performed by the cluster server.

The End Device operates in normal poll mode until either it puts itself into fast poll mode \(for example, when it is expecting responses to a request\) or the controller \(client\) requests the End Device to enter fast poll mode \(for example, when a data download to the End Device is going to be performed\). As indicated above, such a request from the client is raised as the result of the server performing periodic ‘check-ins’ with the client.

On receiving a ‘check-in’ command, an `E_CLD_POLL_CONTROL_CMD_CHECK_IN` event is generated on the client. The client application must then fill in the `tsCLD_PollControl_CheckinResponsePayload` structure \(see [Section 20.9.2](tscld_pollcontrol_checkinresponsepayload.md#id_00a9d130-1180-415c-8ef5-bfe98d6ea45f)\) of the event, indicating whether fast poll mode is required. A response is then automatically sent back to the server.

After sending the initial Check-in command, the server waits for up to 7.68 seconds for a response \(if no response is received in this time, the server is free to continue in normal poll mode\). If a response is received from a client, the event `E_CLD_POLL_CONTROL_CMD_CHECK_IN` is generated on the server, where this event indicates the processing status of the received response. The server also sends this status back to the responding client in a ZCL default response.

-   If the response was received from a bound client within the timeout period of the initial Check-in command, the status is ZCL\_SUCCESS. In this case, the End Device is automatically put into fast poll mode.

-   If the response is invalid for some reason, an error status is indicated as described below in [Section 20.4.3.2](invalid_check-in_responses.md#id_ec1aba0e-7b6b-475c-a0b0-d1a1ea3d5b52), and fast poll mode is not entered.


When the End Device is in fast poll mode, the client application can request the cluster server to exit fast poll mode immediately \(before the timeout expires\) by calling the function **eCLD\_PollControlFastPollStopSend\(\)**.


```{include} ../../poll_control_cluster/topics/fast_poll_mode_timeout.md
:heading-offset: 3
```

```{include} ../../poll_control_cluster/topics/invalid_check-in_responses.md
:heading-offset: 3
```

**Parent topic:**[Poll Control Operations](../../poll_control_cluster/topics/poll_control_operations.md)

