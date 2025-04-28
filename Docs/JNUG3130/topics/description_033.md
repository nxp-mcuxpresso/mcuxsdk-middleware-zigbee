# Description

This function requests a Primary Discovery Cache node to remove from its cache all ‘discovery information’ relating to a particular End Device. The function sends a *Remove\_node\_cache\_req* request to the Primary Discovery Cache node.

The effect of a successful request is to remove the relevant ‘discovery information’ and free the corresponding storage space in the cache previously reserved by **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**\ (which may have been called from another node in the network\).

This request includes the network and IEEE addresses of the End Device whose ‘discovery information’ is to be removed. The request is represented by the structure below \(further detailed in [Section 9.2.2.22](zps_tsaplzdpremovenodecachereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
} ZPS_tsAplZdpRemoveNodeCacheReq;
```

On receiving the request, the remote node first checks whether it has a primary discovery cache. If this is the case, it checks whether it has previously received and implemented a *Discovery\_store\_req*request for the specified End Device, resulting from a call to **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**. If it has, it deletes the relevant data and unreserve the corresponding part of the cache.

The node replies with a *Remove\_node\_cache\_rsp* response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpRemoveNodeCacheRsp`\(detailed in [Section 9.2.3.21](zps_tsaplzdpremovenodecachersp.md)\).

**Parent topic:**[ZPS\_eAplZdpRemoveNodeCacheRequest](../topics/zps_eaplzdpremovenodecacherequest.md)

