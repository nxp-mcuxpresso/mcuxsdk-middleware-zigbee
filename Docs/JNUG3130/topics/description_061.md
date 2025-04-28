# Description

This function can be used to search for nodes in the network that hold ‘discovery information’ about a particular node. The function broadcasts a *Find\_node\_cache\_req*request to the network.

This request includes the network and IEEE addresses of the node of interest. The request is represented by the structure below \(further detailed in [Section 8.2.2.21](zps_tsaplzdpfindnodecachereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
} ZPS_tsAplZdpFindNodeCacheReq;
```

On receiving the request, a remote node first checks whether it has a primary discovery cache, or is the specified node itself. If either is the case, it checks whether it holds the required information and, if this is the case, replies with a *Find\_node\_cache\_rsp*response. This response should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpFindNodeCacheRsp`\(detailed in [Section 8.2.3.20](zps_tsaplzdpfindnodecachersp.md)\).

Only nodes that hold the required information respond to the request.

**Parent topic:**[ZPS\_eAplZdpFindNodeCacheRequest](../topics/zps_eaplzdpfindnodecacherequest.md)

