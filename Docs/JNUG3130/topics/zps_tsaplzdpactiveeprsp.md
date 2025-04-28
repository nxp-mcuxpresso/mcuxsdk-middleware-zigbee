# ZPS\_tsAplZdpActiveEpRsp

This structure is used to store Active\_EP\_rsp message data - a response to a call to the function **ZPS\_eAplZdpActiveEpRequest\(\)**. This response contains a list of the active endpoints on a given network node.

The `ZPS_tsAplZdpActiveEpRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddrOfInterest;
    uint8 u8ActiveEpCount;
    /* Rest of the message is variable */
    uint8* pActiveEpList;
} ZPS_tsAplZdpActiveEpRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpActiveEpRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8ActiveEpCount`is the number of active endpoints on the node.
-   `pActiveEpList`is a pointer to the list of active endpoints, where each endpoint is represented by an 8-bit value \(in the range 1-240\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

