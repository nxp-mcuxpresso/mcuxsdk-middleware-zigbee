# ZPS\_tsAfNwkLeaveConfEvent

This structure is used in the event ZPS\_EVENT\_NWK\_LEAVE\_CONFIRM, which reports the results of a node leave request issued by the local node.

The `ZPS_tsAfNwkLeaveConfEvent`structure is detailed below.

```
typedef struct {
    uint64 u64ExtAddr;
    uint8 eStatus;
} ZPS_tsAfNwkLeaveConfEvent;
```

where:

-   `u64ExtAddr`is the 64-bit IEEE \(MAC\) address of the leaving node. This value is zero if the local node itself is leaving.
-   `eStatus`is the leave status returned by the lower layers - ZPS\_NWK\_ENUM\_SUCCESS, if the leave request has been successful.

**Parent topic:**[Event structures](../topics/event_structures.md)

