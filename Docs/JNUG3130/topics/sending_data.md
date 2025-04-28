# Sending data

Data is sent across the wireless network in an Application Protocol Data Unit \(APDU\). Before calling the function to send the data, an APDU instance must first be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then populated with data using the PDUM function **PDUM\_u16APduInstanceWriteNBO\(\)**.

There are five ways to send data to one or more remote nodes:

-   **Unicast:** Sending data to a single destination endpoint
-   **Broadcast:** Sending data to \(potentially\) all endpoints
-   **Group Multicast:** Sending data to a group of endpoints
-   **Bound Transfer:** Sending data to bound endpoints
-   **Inter-PAN Transfer:** Sending data to another ZigBee PRO network

These methods are described in the sub-sections below. However, in all cases except the inter-PAN transfer, a general function **zps\_eAplAfApsdeDataReq\(\)** can be used which imposes no restrictions on the destination address, destination cluster and destination endpoint number - these destination parameters do not need to be known to the stack or defined in the ZPS configuration.

**Note:**

1.  In all cases, once the data packet has been successfully sent, a ‘DATA\_CONFIRM’ stack event is generated. When sending data to one or more individual nodes \(not broadcasting\), this event is generated after a MAC-level acknowledgment has been received from the ‘next hop’ node.
2.  Where 64-bit IEEE/MAC addresses are used to identify remote nodes, the corresponding 16-bit network addresses must be available in the local Address Map - see Section 5.2.3.


```{include} ../topics/unicast.md
:heading-offset: 3
```

```{include} ../topics/broadcast.md
:heading-offset: 3
```

```{include} ../topics/group_multicast.md
:heading-offset: 3
```

```{include} ../topics/bound_transfer.md
:heading-offset: 3
```

```{include} ../topics/inter-pan_transfer.md
:heading-offset: 3
```

**Parent topic:**[Transferring data](../topics/transferring_data.md)

