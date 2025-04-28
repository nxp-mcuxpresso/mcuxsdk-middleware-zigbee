# ZPS\_tsAfNwkFormationEvent

This structure is used in the event ZPS\_EVENT\_NWK\_STARTED, which indicates whether the network has been started \(on the Coordinator\).

The `ZPS_tsAfNwkFormationEvent`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAfNwkFormationEvent;
```

where is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).

**Parent topic:**[Event structures](../topics/event_structures.md)

