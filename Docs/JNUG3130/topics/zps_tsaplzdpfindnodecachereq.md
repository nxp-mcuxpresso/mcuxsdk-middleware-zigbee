# ZPS\_tsAplZdpFindNodeCacheReq

This structure is used by the function **ZPS\_eAplZdpActiveEpStoreRequest\(\)**. It represents a request to search for nodes in the network that hold ‘discovery information’ about a particular node.

The `ZPS_tsAplZdpFindNodeCacheReq`structure is detailed below.

```
typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;
} ZPS_tsAplZdpFindNodeCacheReq;
```

where:

-   `u16NwkAddr`is the network address of the node of interest
-   `u64IeeeAddr`is the IEEE address of the node of interest

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

