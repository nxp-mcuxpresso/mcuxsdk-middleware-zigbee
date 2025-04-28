# ZPS\_tsAplZdpActiveEpStoreRsp

This structure is used to store Active\_EP\_store\_rsp message data - a response to a call to the function **ZPS\_eAplZdpActiveEpStoreRequest\(\)**. This response indicates whether the sending node has successfully stored the received list of active endpoints in its primary discovery cache.

The `ZPS_tsAplZdpActiveEpStoreRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpActiveEpStoreRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpActiveEpStoreRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

