# BDB\_tsBdbEvent

The following structure contains ZigBee Base Device event information that is passed to the **APP\_vBdbCallback\(\)** callback function \(see [Events](events.md#ID_774854A3-F20F-4D45-A0CA-5E90A3F46A92)\).

```
typedef struct
{
    BDB_teBdbEventTypee EventType;
    BDB_tuBdbEventData uEventData;
}BDB_tsBdbEvent;

```

where:

-   `eEventType` is an enumeration indicating the event type - for the possible enumerations, refer to [Section 2.9](events.md#ID_774854A3-F20F-4D45-A0CA-5E90A3F46A92).

-   `uEventData` is a union structure containing the event information \(if any\) - for a description of this structure, refer to [Section 2.7.2](bdb_tubdbeventdata.md#ID_3674B210-6ECF-44DB-BE25-413567AA4204).


**Parent topic:**[Structures](../topics/structures.md)

