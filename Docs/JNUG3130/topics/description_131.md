# Description

This function requests a list of the active endpoints on a remote node. The function should be called if the node has more active endpoints than could be included in a response to **ZPS\_eAplZdpActiveEpRequest\(\)**. The function sends an Extended\_Active\_EP\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.12](zps_tsaplzdpextendedactiveepreq.md)\).

`typedef struct { uint16 u16NwkAddr;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpExtendedActiveEpReq;`

This structure allows you to specify the first endpoint of interest for the request.

The endpoint list is received in an Extended\_Active\_EP\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpExtendedActiveEpRsp`\(detailed in [Section](zps_tsaplzdpextendedactiveeprsp.md)[9.2.3.11](zps_tsaplzdpextendedactiveeprsp.md)\).

**Parent topic:**[ZPS\_eAplZdpExtendedActiveEpRequest](../topics/zps_eaplzdpextendedactiveeprequest.md)

