# ZPS\_tsAplZdpNodeDescStoreRsp

This structure is used to store `Node_Desc_store_rsp` message data - a response to a call to the function **ZPS\_eAplZdpNodeDescStoreRequest\(\)**. This response indicates whether the sending node has successfully stored the received Node descriptor in its primary discovery cache.

The `ZPS_tsAplZdpNodeDescStoreRsp`structure is detailed below.

```
typedef struct {
     uint8 u8Status;
} ZPS_tsAplZdpNodeDescStoreRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpNodeDescStoreRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

