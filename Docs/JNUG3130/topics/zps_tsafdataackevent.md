# ZPS\_tsAfDataAckEvent

This structure is used in the `ZPS_EVENT_APS_DATA_ACK` event, which is generated when an end-to-end acknowledgment is received from the destination node during a data transfer in which an acknowledgment was requested.

```
typedef struct {
  uint8 u8Status;
  uint8 u8SrcEndpoint;
  uint8 u8DstEndpoint;
  uint8 u8DstAddrMode;
  uint16 u16DstAddr;
  uint8 u8SequenceNum;
  uint16 u16ProfileId;
  uint16 u16ClusterId;
} ZPS_tsAfDataAckEvent;
```

where:

-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `u8SrcEndpoint`is the number of the \(local\) source endpoint for the data transfer \(in range 1-240\).
-   `u8DstEndpoint`is the number of the destination endpoint for the data transfer \(in range 1-240\).
-   `u8DstAddrMode`indicates the type of destination address specified through the element `u16DstAddr`\(see [Table](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA)\) - only values 0x01 \(group address\) and 0x02 \(network address\) are valid in this structure.
-   `u16DstAddr`is the 16-bit address of the destination node for the data transfer and therefore of the node that sent the acknowledgment \(the type of address is specified using the element `u8DstAddrMode`above\).
-   `u8SequenceNum`is the sequence number of the request that initiated the data transfer.
-   `u16ProfileId`is the identifier of the ZigBee device profile of the device for which the data transfer was intended.
-   `u16ClusterId`is the identifier of the cluster \(which belongs to the device profile specified in `u16ProfileId`\) for which the data transfer was intended.

**Parent topic:**[Event structures](../topics/event_structures.md)

