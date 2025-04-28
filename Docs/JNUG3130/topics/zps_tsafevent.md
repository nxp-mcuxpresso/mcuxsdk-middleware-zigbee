# ZPS\_tsAfEvent

This structure contains the details of an event. The `ZPS_tsAfEvent`structure is detailed below.

```
typedef struct {
    ZPS_teAfEventType eType;
    ZPS_tuAfEventData uEvent;
} ZPS_tsAfEvent;
```

where

-   `eType`indicates the event type, using the enumerations listed and described in [Section 11.1](events.md).
-   `uEvent`is a structure containing the event data from the union of structures detailed in [Section 8.2.2.2](zps_tuafeventdata.md).

**Parent topic:**[Event structures](../topics/event_structures.md)

