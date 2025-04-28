# eError enumerations

The error enumerations which are part of the `ZPS_tsAfErrorEvent`structure are listed and described below.

**eError Enumerations**

|**eError Enumeration**|**Description**|
|----------------------|---------------|
|ZPS\_ERROR\_APDU\_TOO\_SMALL|Allocated APDU instance is too small to accommodate received message. This error is detailed in the structure `sAfErrorApdu`, which is described below.|
|ZPS\_ERROR\_APDU\_INSTANCES\_EXHAUSTED|The are no APDU instances available to accommodate the received message. This error is detailed in the structure `sAfErrorApdu`, which is described below.|
|ZPS\_ERROR\_NO\_APDU\_CONFIGURED|No APDU has been configured to accommodate the received message. This error is detailed in the structure `sAfErrorApdu`, which is described below.|
|ZPS\_ERROR\_OS\_MESSAGE\_QUEUE\_OVERRUN|A message queue is full and can accept no more messages. This error is detailed in the structure `sAfErrorOsMessageOverrun`, which is described below.|

**sAfErrorApdu**

This structure is used in the following errors:

-   ZPS\_ERROR\_APDU\_TOO\_SMALL, which reports that the allocated APDU instance is too small to store a received message.
-   ZPS\_ERROR\_APDU\_INSTANCES\_EXHAUSTED, which reports that there are no allocated APDU instances left to store a received message.
-   ZPS\_ERROR\_NO\_APDU\_CONFIGURED, which reports that no APDU has been configured to store the received message.

The `sAfErrorApdu`structure is detailed below.

```
struct {
    uint16 u16ProfileId;
    uint16 u16ClusterId;
    uint16 u16SrcAddr;
    uint16 u16DataSize;
    PDUM_thAPdu hAPdu;
    uint8 u8SrcEndpoint;
    uint8 u8DstEndpoint;
}sAfErrorApdu;
```

where:

-   `u16ProfileId`is the identifier of the ZigBee application profile associated with the source and destination endpoints for the message.
-   `u16ClusterId`is the identifier of the cluster associated with the source and destination endpoints for the message.
-   `u16SrcAddr`is the 16-bit network address of the source node of the message.
-   `u16DataSize`is the size of the received message, in bytes.
-   `hAPdu`is the handle of the local APDU pool from which the APDU instance comes.
-   `u8SrcEndpoint`is the number of the source endpoint of the message.
-   `u8DstEndpoint`is the number of the destination endpoint of the message.

**Parent topic:**[ZPS\_tsAfErrorEvent](../topics/zps_tsaferrorevent.md)

