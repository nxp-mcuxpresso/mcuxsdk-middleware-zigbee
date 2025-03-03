# BDB\_tuBdbEventData

The following structure is a union containing the data for a ZigBee Base Device event.

```
typedef union
{
BDB_tsZpsAfEvent sZpsAfEvent;
BDB_tsFindAndBindEvent *psFindAndBindEvent;
}BDB_tuBdbEventData
```

where:

-   `sZpsAfEvent` is a structure containing the data for a stack event, indicated by the event type BDB\_EVENT\_ZPSAF - for a description of this structure, refer to [Section 2.7.3](bdb_tszpsafevent.md#ID_88B47CDA-4464-418F-B95F-A2F48DFE4791).

-   `psFindAndBindEvent` is a pointer to a structure containing the data for a ‘Finding and Binding’ event \(see [Section 2.9](events.md#ID_774854A3-F20F-4D45-A0CA-5E90A3F46A92)\) - for a description of this structure, refer to [Section 2.7.4](bdb_tsfindandbindevent.md#ID_3BA20764-40D8-4B2D-B8E5-A4BEDA95411C).


**Parent topic:**[Structures](../topics/structures.md)

