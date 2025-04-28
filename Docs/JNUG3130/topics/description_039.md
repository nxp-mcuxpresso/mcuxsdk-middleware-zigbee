# Description

This function requests a cluster list for a specific endpoint on the node with a particular network address. The function should be called if the endpoint has more input or output clusters than could be included in the response to **ZPS\_eAplZdpSimpleDescRequest\(\)**. The function sends an Extended\_Simple\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest and the relevant endpoint on the node must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.7](zps_tsaplzdpextendedsimpledescreq.md)\).

`typedef struct { uint16 u16NwkAddr; uint8 u8EndPoint;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpExtendedSimpleDescReq;`

This structure allows you to specify the first input/output cluster of interest in the endpoint’s input and output cluster lists. Thus, this should normally be the cluster after the last one reported following a call to **ZPS\_eAplZdpSimpleDescRequest\(\)**.

The required cluster information is received in a Extended\_Simple\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpExtendedSimpleDescRsp`\(detailed in [Section 9.2.3.6](zps_tsaplzdpextendedsimpledescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpExtendedSimpleDescRequest](../topics/zps_eaplzdpextendedsimpledescrequest.md)

