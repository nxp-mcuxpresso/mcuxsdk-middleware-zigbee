# ZPS\_tsAfBindRequestServerEvent

This structure is used in the ZPS\_EVENT\_BIND\_REQUEST\_SERVER event, which reports the status of a data transmission sent from the \(local\) node to a set of bound endpoints.

The `ZPS_tsAfBindRequestServerEvent`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint8 u8SrcEndpoint;
    uint32 u32FailureCount;
} ZPS_tsAfBindRequestServerEvent;
```

where:

-   `u8Status`is the overall status of the bound data transmission:
    -   Success \(0\) indicates that the data packet was successfully transmitted to all bound endpoints
    -   Failure \(non-zero value\) indicates that the data packet was not successfully sent to at least one bound endpoint \(see `u32FailureCount`below\).
-   `u8SrcEndpoint`is the number of the local endpoint from which the data packet was sent.
-   `u32FailureCount`is the number of bound endpoints for which the transmission failed.

**Parent topic:**[Event structures](../topics/event_structures.md)

