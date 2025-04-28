# ZPS\_tsAfPollConfEvent

This structure is used in the ZPS\_EVENT\_NWK\_POLL\_CONFIRM event, which reports the completion of a poll request sent from the \(local\) End Device to its parent.

The `ZPS_tsAfPollConfEvent`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAfPollConfEvent;
```

where `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).

**Parent topic:**[Event structures](../topics/event_structures.md)

