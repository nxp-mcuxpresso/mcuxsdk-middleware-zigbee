# Description

This function requests the Simple descriptor for a specific endpoint on the node with a particular network address. The function sends a Simple\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest and the relevant endpoint on the node must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.6](zps_tsaplzdpsimpledescreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint8 u8EndPoint;`

`} ZPS_tsAplZdpSimpleDescReq;`

The required Simple descriptor is received in a Simple\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpSimpleDescRsp`\(detailed in [Section 9.2.3.5](zps_tsaplzdpsimpledescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpSimpleDescRequest](../topics/zps_eaplzdpsimpledescrequest.md)

