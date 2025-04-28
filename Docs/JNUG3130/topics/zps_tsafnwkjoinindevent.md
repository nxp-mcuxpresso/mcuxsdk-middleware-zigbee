# ZPS\_tsAfNwkJoinIndEvent

This structure is used in the event ZPS\_EVENT\_NWK\_NEW\_NODE\_HAS\_JOINED, which notifies a Router or the Coordinator that a new child node has joined the network.

The `ZPS_tsAfNwkJoinIndEvent`structure contains information about the new node and is detailed below.

```
typedef struct
{
  uint64 u64ExtAddr;
  uint16 u16NwkAddr;
  uint8 u8Capability;
  uint8 u8Rejoin;
  uint8 u8SecureRejoin;
} ZPS_tsAfNwkJoinIndEvent;
```

where:

-   `u64ExtAddr`is the 64-bit IEEE \(MAC\) address of the joining node.
-   `u16NwkAddr`is the 16-bit network address assigned to the joining node.
-   `u8Capability`is a bitmap indicating the operational capabilities of the joining node. This bitmap is detailed in [Table](zps_tsafnwkjoinindevent.md#TABLE_026A2BDC-B736-4A72-8700-BD9FF0F39F3E) below.
-   `u8Rejoin`indicates the method used to join the network:
    -   `0x00` if joined through association.
    -   `0x01` if joined directly or used orphaning.
    -   `0x02` if was network rejoin.
-   `u8SecureRejoin`indicates whether the join was performed in a secure manner.
    -   zero represents FALSE.
    -   a non-zero value represents TRUE.

**Node capabilities bitmap**

|**Bits**|**Description**|
|--------|---------------|
|0|Coordinator capability:<br>-   `1`: Node able to act as Coordinator<br>-   `0`: Node not able to act as Coordinator|
|1|Device type:<br>-   `1`: Full-Function Device \(FFD\)<br>-   `0`: Reduced-Function Device \(RFD\)<br>An FFD can act as any node type while an RFD cannot act as the network Coordinator.|
|2|Power source:<br>-   `1`:Node is mains-powered <br>-   `0`: Node is not mains-powered|
|3|Receiver on when idle:<br>-   `1`: Receiver enabled during idle periods<br>-   `0`: Receiver disabled during idle periods to conserve power|
|4-5|Reserved|
|6|Security capability:<br>-   `1`: High security<br>-   `0`: Standard security|
|7|Allocate address:<br>-   `1`: Network address should be allocated to node<br>-   `0`: Network address need not be allocated to node|

**Parent topic:**[Event structures](../topics/event_structures.md)

