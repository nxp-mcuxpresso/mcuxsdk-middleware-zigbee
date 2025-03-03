# BDB\_tsZpsAfEvent

The following structure contains the data for a ZigBee stack event \(see the BDB\_EVENT\_ZPSAF event in [Section 2.9](events.md)\).

```
typedef struct
{
    uint8 u8EndPoint;
    ZPS_tsAfEvent sStackEvent;
}BDB_tsZpsAfEvent;

```

where:

-   `u8EndPoint` is the number of the endpoint on which the event occurred.

-   `sStackEvent` is a ZPS structure containing the stack event type and data - this structure is detailed in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.


**Parent topic:**[Structures](../topics/structures.md)

