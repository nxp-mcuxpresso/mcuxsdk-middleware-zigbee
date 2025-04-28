# ZPS\_tsAplZdpFindNodeCacheRsp

This structure is used to store Find\_node\_cache\_rsp message data - a response to a call to the function **ZPS\_eAplZdpFindNodeCacheRequest\(\)**. This response indicates that the sending node holds ‘discovery information’ about a given network node in its primary discovery cache.

The `ZPS_tsAplZdpFindNodeCacheRsp`structure is detailed below.

```
typedef struct {
    uint16 u16CacheNwkAddr;
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
} ZPS_tsAplZdpFindNodeCacheRsp;
```

where:

-   `u16CacheNwkAddr`is the network address of the remote node that sent the response.
-   `u16NwkAddr`is the network address of the node of interest \(this is the network address that was specified in the request\).
-   `u64IeeeAddr`is the IEEE address of the node of interest \(this is the IEEE address that was specified in the request\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

