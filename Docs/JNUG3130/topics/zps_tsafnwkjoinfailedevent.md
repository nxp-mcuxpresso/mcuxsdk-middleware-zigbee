# ZPS\_tsAfNwkJoinFailedEvent

This structure is used in the event ZPS\_EVENT\_NWK\_FAILED\_TO\_JOIN, which indicates that the local device has failed to join a network.

The `ZPS_tsAfNwkJoinFailedEvent`structure is detailed below.

```
typedef struct
{
    uint8 u8Status;
    bool_t bRejoin;
} ZPS_tsAfNwkJoinFailedEvent;
```

where:

-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `bRejoin`indicates whether the join attempt was a rejoin \(TRUE\) or a new association \(FALSE\).

**Parent topic:**[Event structures](../topics/event_structures.md)

