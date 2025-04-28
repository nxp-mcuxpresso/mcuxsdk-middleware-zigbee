# ZPS\_tsAfErrorEvent

This structure is used in the ZPS\_EVENT\_ERROR event, which reports error situations concerning the storage of received messages in APDU instances.

The `ZPS_tsAfErrorEvent`structure is detailed below.

```
typedef struct {
    enum {
        ZPS_ERROR_APDU_TOO_SMALL,
        ZPS_ERROR_APDU_INSTANCES_EXHAUSTED,
        ZPS_ERROR_NO_APDU_CONFIGURED,
        ZPS_ERROR_OS_MESSAGE_QUEUE_OVERRUN
    } eError;
   union {
         struct {
            uint16 u16ProfileId;
            uint16 u16ClusterId;
            uint16 u16SrcAddr;
            uint16 u16DataSize;
            PDUM_thAPdu hAPdu;
            uint8 u8SrcEndpoint;
            uint8 u8DstEndpoint;
        }sAfErrorApdu;
        struct {
            OS_thMessage hMessage;
        } sAfErrorOsMessageOverrun;
    } uErrorData;
} ZPS_tsAfErrorEvent;
```

The member enumerations and structures of the above structure are detailed below.


```{include} ../topics/eerror_enumerations.md
:heading-offset: 4
```

```{include} ../topics/saferrorosmessageoverrun.md
:heading-offset: 4
```

**Parent topic:**[Event structures](../topics/event_structures.md)

