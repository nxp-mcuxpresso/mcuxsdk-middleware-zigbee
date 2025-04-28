# Description

This function can be called on an End Device to upload the local node’s Power descriptor for storage in the primary discovery cache on a remote node. The function sends a `Power_Desc_store_req` request to the remote node.

This request includes the network and IEEE addresses of the sending node as well as the Power descriptor to store. The request is represented by the structure below \(further detailed in [Section 9.2.2.18](zps_tsaplzdppowerdescstorereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
    /* Rest of message is variable length */
    ZPS_tsAplZdpNodePowerDescriptor sPowerDescriptor;
} ZPS_tsAplZdpPowerDescStoreReq;
```

On receiving the request, the remote node first checks whether it has a primary discovery cache. If this is the case, it checks whether it has previously reserved storage space in its cache for the local node. If it has, it stores the Power descriptor in its cache.

The node replies with a Power\_Desc\_store\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpPowerDescStoreRsp`\(detailed in [Section 9.2.3.17](zps_tsaplzdppowerdescstorersp.md)\).

**Note:** This function should only be called if storage space for the local node’s ‘discovery information’ has previously been reserved on the remote node following a call to **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**.

**Parent topic:**[ZPS\_eAplZdpPowerDescStoreRequest](../topics/zps_eaplzdppowerdescstorerequest.md)

