# ZPS\_tsAfInterPanDataIndEvent

This structure is used in the ZPS\_EVENT\_APS\_INTERPAN\_DATA\_INDICATION event, which indicates that an inter-PAN data packet has arrived.

The `ZPS_tsAfInterPanDataIndEvent`structure is detailed below.

```
typedef struct
{
    ZPS_tsInterPanAddress sDstAddr;
    uint8   u8SrcAddrMode;
    uint16   u16SrcPan;
    uint64   u64SrcAddress;
    uint16   u16ProfileId;
    uint16   u16ClusterId;
    PDUM_thAPduInstance hAPduInst;
    uint8   eStatus;
    uint8   u8DstEndpoint;
    uint8   u8LinkQuality;
} ZPS_tsAfInterPanDataIndEvent;
```

where

-   `sDstAddr`is a structure of the type `ZPS_tsInterPanAddress`\(see [Section](zps_tsinterpanaddress.md)[8.2.3.3](zps_tsinterpanaddress.md)\) which contains the PAN ID and address for the destination node\(s\) of the inter-PAN data packet.
-   `u8SrcAddrMode`indicates the type of address specified through the element `u64SrcAddress` \(see [Table](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA)\).

-   `u16SrcPan`is the PAN ID of the network from which the data packet originates.
-   `u64SrcAddress`is the address of the node which sent the data packet \(the type of address is specified using the element `u8SrcAddrMode`above\).
-   `u16ProfileId`is the identifier of the application profile for which the data packet is intended.
-   `u16ClusterId`is the identifier of the cluster for which the data packet is intended.
-   `hAPduInst`is the handle of the APDU instance for the data packet.
-   `eStatus`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `u8DstEndpoint`is the number of the destination endpoint for the data packet \(in range 1-240\).
-   `u8LinkQuality`is an LQI value indicating the perceived strength of the radio signal which carried the received data packet.

**Parent topic:**[Event structures](../topics/event_structures.md)

