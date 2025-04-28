# ZPS\_tsAplZdpRemoveNodeCacheReq

This structure is used by the function **ZPS\_eAplZdpActiveEpStoreRequest\(\)**. It represents a request to a remote node to remove from its Primary Discovery Cache all ‘discovery information’ relating to a particular End Device.

The `ZPS_tsAplZdpRemoveNodeCacheReq`structure is detailed below.

```
typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;
} ZPS_tsAplZdpRemoveNodeCacheReq;
```

where:

-   `u16NwkAddr`is the network address of the End Device of interest
-   `u64IeeeAddr`is the IEEE address of the End Device of interest

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

