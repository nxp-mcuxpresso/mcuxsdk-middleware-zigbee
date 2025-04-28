# Description

This function requests the Power descriptor of the node with a particular network address. The function sends a Power\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.5](zps_tsaplzdppowerdescreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest;`

`} ZPS_tsAplZdpPowerDescReq;`

The required Power descriptor is received in a Power\_Desc\_rsp response. The descriptor should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpPowerDescRsp`\(detailed in [Section 9.2.3.4](zps_tsaplzdppowerdescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpPowerDescRequest](../topics/zps_eaplzdppowerdescrequest.md)

