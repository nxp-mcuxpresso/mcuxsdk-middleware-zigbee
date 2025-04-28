# ZPS\_tsAplZdpMgmtCacheRsp

This structure is used to store Mgmt\_Cache\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtCacheRequest\(\)**. This response reports a list of the End Devices registered in the node’s primary discovery cache.

The `ZPS_tsAplZdpMgmtCacheRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint8 u8DiscoveryCacheEntries;
    uint8 u8StartIndex;
    uint8 u8DiscoveryCacheListCount;
   /* Rest of the message is variable length */
   ZPS_tsAplDiscoveryCache* pDiscoveryCacheList;
} ZPS_tsAplZdpMgmtCacheRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtCacheRequest\(\)**
-   `u8DiscoveryCacheEntries`is the total number of discovery cache entries on the remote node.
-   `u8StartIndex`is the discovery cache index of the first entry reported in this response \(through `pDiscoveryCacheList`\).
-   `u8DiscoveryCacheListCount`is the number of discovery cache entries reported in this response \(through `pDiscoveryCacheList`\).
-   `pRoutingTableList`is a pointer to the first entry in the list of reported discovery cache entries. Each entry is of the type `ZPS_tsAplDiscoveryCache`detailed below.


```{include} ../topics/zps_tsapldiscoverycache.md
:heading-offset: 4
```

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

