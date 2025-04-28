# ZPS\_tsAfNwkJoinedEvent

This structure is used in the events ZPS\_EVENT\_NWK\_JOINED\_AS\_ROUTER and ZPS\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE, which confirm that the local device \(Router or End Device\) has successfully joined a network.

The `ZPS_tsAfNwkJoinedEvent`structure reports the network address that the parent has assigned to the new node and is detailed below.

```
typedef struct
{
    uint16 u16Addr;
    bool_t bRejoin;
} ZPS_tsAfNwkJoinedEvent;
```

where:

-   `u16Addr`is the 16-bit network address allocated to the joining node.
-   `bRejoin`indicates whether the join was a rejoin \(TRUE\) or a new association \(FALSE\).

**Parent topic:**[Event structures](../topics/event_structures.md)

