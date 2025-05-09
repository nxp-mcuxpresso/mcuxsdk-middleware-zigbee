# tsCLD\_ASC\_LogNotificationORLogResponsePayload

This structure contains the payload for the ‘Log Notification’ and ‘Log Response’ messages.

```
typedef struct
{
    zutctime    utctTime;
    zuint32     u32LogId;
    zuint32     u32LogLength;
    uint8      *pu8LogData;
} tsCLD_ASC_LogNotificationORLogResponsePayload;

```

where:

-   `utctTime` is the UTC time at which the reported log was produced

-   `u32LogId` is the identifier of the reported log

-   `u32LogLength` is the length, in bytes, of the reported log

-   `pu8LogData` is a pointer to an area of memory to receive the data of the reported log


**Parent topic:**[Structures](../../appliance_statistics_cluster/topics/structures.md)

