# Description

This function can be called on an End Device to upload a Simple descriptor from the local node for storage in the primary discovery cache on the specified remote node. The Simple descriptor for each endpoint on the local node must be uploaded separately using this function. The function sends a *Simple\_Desc\_store\_req* request to the remote node.

This request includes the network and IEEE addresses of the sending node as well as the Simple descriptor to store. The request is represented by the structure below \(further detailed in [Section 9.2.2.19](zps_tsaplzdpsimpledescstorereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
    uint8 u8Length;
    /* Rest of message is variable length */
    ZPS_tsAplZdpSimpleDescType sSimpleDescriptor;
} ZPS_tsAplZdpSimpleDescStoreReq;
```

On receiving the request, the remote node first checks whether it has a primary discovery cache. If this is the case, it checks whether it has previously reserved storage space in its cache for the local node. If it has, it stores the Simple descriptor in its cache.

The node replies with a *Simple\_Desc\_store\_rsp* response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpSimpleDescStoreRsp`\(detailed in [Section 9.2.3.18](zps_tsaplzdpsimpledescstorersp.md)\).

**Note:** This function should only be called if storage space for the local node’s ‘discovery information’ has previously been reserved on the remote node following a call to **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**.

**Parent topic:**[ZPS\_eAplZdpSimpleDescStoreRequest](../topics/zps_eaplzdpsimpledescstorerequest.md)

