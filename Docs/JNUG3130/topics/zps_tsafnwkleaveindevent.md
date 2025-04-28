# ZPS\_tsAfNwkLeaveIndEvent

This structure is used in the ZPS\_EVENT\_LEAVE\_INDICATION event, which indicates that a neighboring node has left the network or a remote node has requested the local node to leave.

The `ZPS_tsAfNwkLeaveIndEvent`structure is detailed below.

```
typedef struct {
    uint64 u64ExtAddr;
    uint8 u8Rejoin;
} ZPS_tsAfNwkLeaveIndEvent;
```

where:

-   `u64ExtAddr`is the 64-bit IEEE \(MAC\) address of the node that has left the network, or is zero if the local node has been requested to leave the network
-   `u8Rejoin`indicates whether the leaving node was requested to attempt a subsequent rejoin of the network:
    -   zero represents FALSE
    -   a non-zero value represents TRUE.

**Parent topic:**[Event structures](../topics/event_structures.md)

