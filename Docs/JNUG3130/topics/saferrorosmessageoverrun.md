# sAfErrorOsMessageOverrun

This structure is used in the ZPS\_ERROR\_OS\_MESSAGE\_QUEUE\_OVERRUN error, which indicates that a message queue is full and can accept no more messages.

The `sAfErrorOsMessageOverrun`structure is detailed below.

```
struct {
    OS_thMessage hMessage;
} sAfErrorOsMessageOverrun;
```

where `hMessage`is the handle of the message type for the queue which is full.

**Parent topic:**[ZPS\_tsAfErrorEvent](../topics/zps_tsaferrorevent.md)

