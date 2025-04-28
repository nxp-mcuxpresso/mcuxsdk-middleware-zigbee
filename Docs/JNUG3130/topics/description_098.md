# Description

This function can be called on an End Device to upload a list of its active endpoints for storage in the primary discovery cache on a remote node. The function sends an *Active\_EP\_store\_req* command to the remote node.

This request includes the network and IEEE addresses of the sending node as well as the list of active endpoints to store. The request is represented by the structure below \(further detailed in [Section 9.2.2.20](zps_tsaplzdpactiveepstorereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
    uint8 u8ActiveEPCount;
    /* Rest of message is variable length */
    uint8* pu8ActiveEpList;
} ZPS_tsAplZdpActiveEpStoreReq;
```

On receiving the request, the remote node first checks whether it has a primary discovery cache. If this is the case, it checks whether it has previously reserved storage space in its cache for the local node. If it has, it stores the list of active endpoints in its cache.

The node replies with an *Active\_EP\_store\_rsp* response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpActiveEpStoreRsp`\(detailed in [Section 9.2.3.19](zps_tsaplzdpactiveepstorersp.md)\).

**Note:** This function should only be called if storage space for the local node’s ‘discovery information’ has previously been reserved on the remote node following a call to **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**.

**Parent topic:**[ZPS\_eAplZdpActiveEpStoreRequest](../topics/zps_eaplzdpactiveepstorerequest.md)

