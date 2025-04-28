# Description

This function requests the Complex descriptor of the node with a particular network address. The function sends a Complex\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.8](zps_tsaplzdpcomplexdescreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest;`

`} ZPS_tsAplZdpComplexDescReq;`

The required Complex descriptor will be received in a Complex\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpComplexDescRsp`\(detailed in [Section 9.2.3.7](zps_tsaplzdpcomplexdescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpComplexDescRequest](../topics/zps_eaplzdpcomplexdescrequest.md)

