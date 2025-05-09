# tsCLD\_ASC\_LogQueueResponseORStatisticsAvailablePayload

This structure contains the payload for the ‘Log Queue Response’ and ‘Statistics Available’ messages.

```
typedef struct
{
    zuint8     u8LogQueueSize;
    zuint32   *pu32LogId;
} tsCLD_ASC_LogQueueResponseORStatisticsAvailablePayload;

```

where:

-   `u8LogQueueSize` indicates the number of logs currently in the log queue

-   `pu32LogId` is a pointer to an area of memory to receive the sequence of 32-bit log IDs of the logs in the queue


**Parent topic:**[Structures](../../appliance_statistics_cluster/topics/structures.md)

