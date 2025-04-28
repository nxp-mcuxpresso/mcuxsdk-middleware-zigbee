# ZQ\_vQueueCreate

```
void ZQ_vQueueCreate(tszQueue *psQueueHandle,
                    const uint32 uiQueueLength,
                    const uint32 uiItemSize,
                    uint8 *pu8StartQueue);
```

**Description**

This function creates a message queue for use by the application or stack \(message queues are described in [Section 6.9.1](message_queues.md)\). The size of the queue and the size of a message in the queue must be specified, as well as the location in memory where the queue should start. A unique handle must also be given to the queue, where this handle is a pointer to a `tszQueue`structure that contains up-to-date information about the queue.


```{include} ../topics/parameters_003.md
:heading-offset: 4
```

```{include} ../topics/returns_084.md
:heading-offset: 4
```

**Parent topic:**[ZigBee queue functions](../topics/zigbee_queue_functions.md)

