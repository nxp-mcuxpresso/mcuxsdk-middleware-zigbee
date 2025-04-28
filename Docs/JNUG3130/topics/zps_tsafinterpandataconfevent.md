# ZPS\_tsAfInterPanDataConfEvent

This structure is used in the ZPS\_EVENT\_APS\_INTERPAN\_DATA\_CONFIRM event, which indicates that an inter-PAN communication has been sent by the local node and an acknowledgment has been received from the first hop node \(this acknowledgment is not generated in the case of a broadcast\).

The `ZPS_tsAfInterPanDataConfEvent`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint8 u8Handle;
} ZPS_tsAfInterPanDataConfEvent;
```

where

-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `u8Handle`is a handle for internal use.

**Parent topic:**[Event structures](../topics/event_structures.md)

