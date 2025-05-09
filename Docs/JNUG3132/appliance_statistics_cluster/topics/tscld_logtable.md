# tsCLD\_LogTable

This structure is used to store the details of a data log.

```
typedef struct
{
    zutctime    utctTime;
    uint32      u32LogID;
    uint8       u8LogLength;
    uint8      *pu8LogData;
} tsCLD_LogTable;

```

where:

-   `utctTime` is the UTC time at which the log was produced

-   `u32LogId` is the identifier of the log

-   `u32LogLength` is the length, in bytes, of the log

-   `pu8LogData` is a pointer to an area of memory to receive the data of the log


**Parent topic:**[Structures](../../appliance_statistics_cluster/topics/structures.md)

