# Description

This function can be called on an End Device to upload the local node’s Node descriptor for storage in the primary discovery cache on a remote node. The function sends a Node\_Desc\_store\_req command to the remote node.

This request includes the network and IEEE addresses of the sending node as well as the Node descriptor to store. The request is represented by the structure below \(further detailed in [Section 9.2.2.17](zps_tsaplzdpnodedescstorereq.md)\).

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`/* Rest of message is variable length */ ZPS_tsAplZdpNodeDescriptor sNodeDescriptor;`

`} ZPS_tsAplZdpNodeDescStoreReq;`

On receiving the request, the remote node will first check whether it has a primary discovery cache. If this is the case, it will check whether it has previously reserved storage space in its cache for the local node. If it has, it will store the Node descriptor in its cache.

The node replies with a Node\_Desc\_store\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpNodeDescStoreRsp`\(detailed in [Section 9.2.3.16](zps_tsaplzdpnodedescstorersp.md)\).

**Note:** This function should only be called if storage space for the local node’s ‘discovery information’ has previously been reserved on the remote node following a call to **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**.

**Parent topic:**[ZPS\_eAplZdpNodeDescStoreRequest](../topics/zps_eaplzdpnodedescstorerequest.md)

