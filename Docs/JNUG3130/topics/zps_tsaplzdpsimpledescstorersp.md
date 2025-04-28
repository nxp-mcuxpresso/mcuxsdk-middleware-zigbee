# ZPS\_tsAplZdpSimpleDescStoreRsp

This structure is used to store Power\_Desc\_store\_rsp message data - a response to a call to the function **ZPS\_eAplZdpSimpleDescStoreRequest\(\)**. This response indicates whether the sending node has successfully stored the received Simple descriptor in its primary discovery cache.

The `ZPS_tsAplZdpSimpleDescStoreRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpSimpleDescStoreRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpSimpleDescStoreRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

