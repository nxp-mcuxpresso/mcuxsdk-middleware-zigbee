# ZPS\_tsAplZdpDiscoveryStoreRsp

This structure is used to store Discovery\_Store\_rsp message data - a response to a call to the function **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**. This response indicates whether the sending node has successfully reserved space in its primary discovery cache.

The `ZPS_tsAplZdpDiscoveryStoreRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpDiscoveryStoreRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

