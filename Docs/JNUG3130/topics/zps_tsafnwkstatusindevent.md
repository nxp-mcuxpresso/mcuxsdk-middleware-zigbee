# ZPS\_tsAfNwkStatusIndEvent

This structure is used in the ZPS\_EVENT\_NWK\_STATUS\_INDICATION event, which reports status information from the NWK layer of the stack.

The `ZPS_tsAfNwkStatusIndEvent`structure is detailed below.

```
typedef struct {
    uint16 u16NwkAddr;
    uint8 u8Status;
} ZPS_tsAfNwkStatusIndEvent;
```

where:

-   `u16NwkAddr`is the 16-bit network address of the node associated with the event.
-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).

**Parent topic:**[Event structures](../topics/event_structures.md)

