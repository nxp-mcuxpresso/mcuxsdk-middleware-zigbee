# ZPS\_tsAfZdoBindEvent

This structure is used in the ZPS\_EVENT\_ZDO\_BIND event, which indicates that the local node has been successfully bound to one or more remote nodes.

The `ZPS_tsAfZdoBindEvent`structure is detailed below.

```
typedef struct { ZPS_tuAddress uDstAddr; uint8 u8DstAddrMode; uint8 u8SrcEp; uint8 u8DstEp; } ZPS_tsAfZdoBindEvent;
```

where

-   `uDstAddr`is the address of the remote node for the binding \(the type of address is specified using the element `u8DstAddrMode`above\).
-   `u8DstAddrMode`indicates the type of address specified through the element `uDstAddr`\(see [Table 1](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA)\).

-   `u8SrcEp`is the number of the source endpoint for the binding \(in range 1-240\).
-   `u8DstEp`is the number of the destination endpoint for the binding \(in range 1-240\).

**Parent topic:**[Event structures](../topics/event_structures.md)

