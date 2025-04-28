# Description

This function requests a list of the active endpoints on a remote node. The function sends an Active\_EP\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.11](zps_tsaplzdpactiveepreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest;`

`} ZPS_tsAplZdpActiveEpReq;`

The endpoint list is received in an Active\_EP\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpActiveEpRsp`\(detailed in [Section 9.2.3.10](zps_tsaplzdpactiveeprsp.md)\).

**Parent topic:**[ZPS\_eAplZdpActiveEpRequest](../topics/zps_eaplzdpactiveeprequest.md)

