# Receiving data

When a data packet \(sent using one of the methods described in [Section 6.5.1](sending_data.md)\) is received by the destination node, it is put into a message queue. A zps\_EVENT\_AF\_DATA\_INDICATION stack event is generated on the destination node to indicate that a data packet has arrived \(the destination endpoint is indicated in this event\). The packet must then be collected from the message queue using the function **ZQ\_bZQueueReceive\(\)**.

**Note:**

-   **Note 1**: In case a data packet is received from another network by means of an inter-PAN transfer, the `zps_EVENT_APS_INTERPAN_DATA_INDICATION` stack event is generated. The data packet is passed to the endpoint that supports the specified cluster. The application must always handle these inter-PAN packets and release the APDU instances \(see below\). The event will only be generated if the inter-PAN feature has been enabled via the ZPS Configuration Editor. If an application transmits inter-PAN messages but does not need to receive them, the application must enable inter-PAN in the ZPS Configuration Editor and handle any `zps_EVENT_APS_INTERPAN_DATA_INDICATION` events by releasing the APDU instances.
-   **Note 2**: In the case of the arrival of a response packet which is destined for the ZDO, a `zps_EVENT_AF_DATA_INDICATION` stack event is generated with a destination endpoint of 0. It is necessary for the application to call the function `zps_bAplZdpUnpackResponse()` to extract the response data from the event.

An End Device that is asleep would be unable to receive a data packet directly, so the data is buffered by its parent for collection later. The End Device must explicitly request this data, once awake. This method of receiving data is called data polling and is described in [Section 6.5.3](polling_for_data.md).

Once a data packet has been collected from a message queue, the data can be extracted from the APDU instance using the PDUM function **PDUM\_u16APduInstanceReadNBO\(\)**. The APDU instance must then be released using the PDUM function **PDUM\_eAPduFreeAPduInstance\(\)**.

**Parent topic:**[Transferring data](../topics/transferring_data.md)

