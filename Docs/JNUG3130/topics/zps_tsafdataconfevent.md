# ZPS\_tsAfDataConfEvent

This structure is used in the ZPS\_EVENT\_APS\_DATA\_CONFIRM event, which confirms that a data packet sent by the local node has been successfully passed down the stack to the MAC layer and has made its first hop toward its destination \(an acknowledgment has been received from the next hop node\).

The `ZPS_tsAfDataConfEvent`structure is detailed below.

```
typedef struct {
uint8         u8Status;
uint8         u8SrcEndpoint;
uint8         u8DstEndpoint;
uint8         u8DstAddrMode;
ZPS_tuAddress uDstAddr;
uint8         u8SequenceNum;
} ZPS_tsAfDataConfEvent;
```

where:

-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `u8SrcEndpoint`is the number of the \(local\) source endpoint for the data transfer \(in range 1-240\).
-   `u8DstEndpoint`is the number of the destination endpoint for the data transfer \(in range 1-240\).
-   `u8DstAddrMode`indicates the type of destination address specified through the element `uDstAddr`\(see [Table](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA)\) - only values 0x02 \(group address\) and 0x03 \(network address\) are valid in this structure.
-   `uDstAddr`is the address of the destination node for the data packet \(the type of address is specified using the element `u8DstAddrMode`above\).
-   `u8SequenceNum`is the sequence number of the request that initiated the data transfer.

**Parent topic:**[Event structures](../topics/event_structures.md)

