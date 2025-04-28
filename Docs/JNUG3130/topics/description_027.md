# Description

This function can be called on an End Device to request a remote node to reserve memory space to store the local node’s ‘discovery information’. To do this, the remote node must contain a primary discovery cache. The ‘discovery information’ includes the local node’s IEEE address, network address, Node descriptor, Power descriptor, Simple descriptor and number of active endpoints. The function sends a Discovery\_store\_req request to the remote node.

This request includes the network and IEEE addresses of the sending node as well as the amount of storage space \(in bytes\) needed to store the information. The request is represented by the structure below \(further detailed in [Section 9.2.2.16](zps_tsaplzdpdiscoverystorereq.md)\).

```
typedef struct {
        uint16 u16NwkAddr;
        uint64 u64IeeeAddr;
        uint8 u8NodeDescSize;
        uint8 u8PowerDescSize;
        uint8 u8ActiveEpSize;
        uint8 u8SimpleDescCount;
        /* Rest of message is variable length */
        uint8* pu8SimpleDescSizeList;
} ZPS_tsAplZdpDiscoveryStoreReq;
```

On receiving this request, the remote node first checks whether it has a primary discovery cache. If this is the case, it checks whether it has storage space in the cache for the new discovery information. If the space is available, it is reserved until the information is later uploaded from the local node.

The node replies with a Discovery\_store\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpDiscoveryStoreRsp`\(detailed in [Section 9.2.3.15](zps_tsaplzdpdiscoverystorersp.md)\).

**Parent topic:**[ZPS\_eAplZdpDiscoveryStoreRequest](../topics/zps_eaplzdpdiscoverystorerequest.md)

