# tszQueue

The ZigBee queue structure `tszQueue`is shown below.

```
typedef struct
{
uint32 u32Length;
uint32 u32ItemSize;
uint32 u32MessageWaiting;
void *pvHead;
void *pvWriteTo;
void *pvReadFrom;
}tszQueue;
```

where:

-   `u32Length`is the size of the queue in terms of the number of messages that it can hold
-   `u32ItemSize`is the size of a message, in bytes
-   `u32MessageWaiting`is the number of messages currently in the queue
-   `pvHead`is a pointer to the beginning of the queue storage area
-   `pvWriteTo`is a pointer to the next free place in the storage area where a new message can be written
-   `pvReadFrom`is a pointer to the next message to be read from the storage area

**Parent topic:**[ZigBee queue structures](../topics/zigbee_queue_structures.md)

