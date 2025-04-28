# ZPS\_tsAplZdpDiscoveryCacheRsp

This structure is used to store Discovery\_Cache\_rsp message data - a response to a call to the function **ZPS\_eAplZdpDiscoveryCacheRequest\(\)**. This response indicates that the sending node has a primary discovery cache.

The `ZPS_tsAplZdpDiscoveryCacheRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpDiscoveryCacheRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpDiscoveryCacheRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

