# Standard stack queues

Three standard queues must be created by the application for use by the stack:

-   Queue with handle zps\_msgMlmeDcfmInd to receive IEEE 802.15.4 MAC command packets from other nodes
-   Queue with handle zps\_msgMcpsDcfmInd to receive IEEE 802.15.4 MAC data packets from other nodes
-   Queue with handle zps\_TimeEvents to receive internal software timer events \(such as a timer expiry event\)

Example code for the creation of these queues is provided below:

`ZQ_vZQueueCreate(&zps_msgMlmeDcfmInd, MLME_QUEUE_SIZE, sizeof(MAC_tsMlmeVsDcfmInd),(uint8*)asMacMlmeVsDcfmInd);`

`ZQ_vZQueueCreate(&zps_msgMcpsDcfmInd, MCPS_QUEUE_SIZE, sizeof(MAC_tsMcpsVsDcfmInd),(uint8*)asMacMcpsDcfmInd);`

`ZQ_vQueueCreate(&zps_TimeEvents,TIMER_QUEUE_SIZE,sizeof(zps_tsTimeEvent), (uint8*)asTimeEvent);`

You simply need to include the above code in your application. You do not need to process these queues in your code.

More information on the receive queues is provided in [Received message queues](received_message_queues.md).

**Parent topic:**[Message queues](../topics/message_queues.md)

