# Inter-PAN transfer

A data packet can be sent to nodes in other IEEE 802.15.4 networks - this is referred to as an inter-PAN transfer or transmission. Typically, this mechanism could be used to send information to optional low-cost devices that are not part of the local network. Note that no security \(encyption/decryption\) can be applied to inter-PAN transfers and only one application on a device can perform inter-PAN transmissions. The inter-PAN messages are not forwarded and so will only be received by nodes within direct radio range of the transmitter.

The inter-PAN feature is enabled via the ZPS Configuration Editor. The *Inter PAN*value is set to true in the APS Layer Configuration section of the Advanced Properties for the device.

The function **zps\_eAplAfInterPanDataReq\(\)** is used to request an inter-PAN transmission. This function requires the destination\(s\) for the transfer to specified:

-   Single destination node in a specific network \(PAN ID and node address must be specified\)
-   Multiple destination nodes in a specific network

\(PAN ID and a group address for the nodes must be specified\)

-   All nodes in a specific network

\(PAN ID and broadcast address of 0xFFFF must be specified\)

-   All nodes in all reachable networks

\(broadcast PAN ID and broadcast address, both of 0xFFFF, must be specified\)

After successfully sending the data packet, the stack will generate the event zps\_EVENT\_APS\_INTERPAN\_DATA\_CONFIRM \(for a single destination, this event is generated once the ‘next hop’ acknowledgment has been received\).

A destination endpoint is not specified for this type of data transfer but a cluster must be specified for the destination. On receiving the data packet, the recipient node will automatically pass the packet to the endpoint which supports the given cluster \(see [Section 5.5.2](receiving_data.md)\).

**Note:**

1.  In the case of a data packet received from another network by means of an inter-PAN transfer, the **zps\_EVENT\_APS\_INTERPAN\_DATA\_INDICATION** stack event will be generated. The data packet will be passed to the endpoint which supports the specified cluster. The application must always handle these inter-PAN packets and release the APDU instances \(see below\). The event will only be generated if the inter-PAN feature has been enabled via the ZPS Configuration Editor. If an application transmits inter-PAN messages but does not need to receive them, the application must enable inter-PAN in the ZPS Configuration Editor and handle any **zps\_EVENT\_APS\_INTERPAN\_DATA\_INDICATION** events by releasing the APDU instances.
2.  In the case of the arrival of a response packet which is destined for the ZDO, a **zps\_EVENT\_AF\_DATA\_INDICATION** stack event will be generated with a destination endpoint of 0. It will be necessary for the application to call the function **zps\_bAplZdpUnpackResponse\(\)** to extract the response data from the event.

**Parent topic:**[Sending data](../topics/sending_data.md)

