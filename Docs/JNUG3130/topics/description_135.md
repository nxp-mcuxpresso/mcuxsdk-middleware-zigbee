# Description

This function requests the Node descriptor of the node with a particular network address. The function sends a Node\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.4](zps_tsaplzdpnodedescreq.md)\).

```
typedef struct {
     uint16 u16NwkAddrOfInterest;
} ZPS_tsAplZdpNodeDescReq;
```

The required Node descriptor is received in a Node\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpNodeDescRsp`\(detailed in [Section 9.2.3.3](zps_tsaplzdpnodedescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpNodeDescRequest](../topics/zps_eaplzdpnodedescrequest.md)

