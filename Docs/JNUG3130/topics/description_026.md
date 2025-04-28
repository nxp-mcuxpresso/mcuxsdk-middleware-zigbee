# Description

This function is used to discover which nodes in the network have a primary discovery cache - that is, a bank of information about other nodes in the network. The function broadcasts a Discovery\_Cache\_req request to the network.

The request includes the network and IEEE addresses of the sending device, and is represented by the structure below \(further detailed in [Section 9.2.2.15](zps_tsaplzdpdiscoverycachereq.md)\).

`typedef struct {`

`uint16 u16NwkAddr;`

`uint64 u64IeeeAddr;`

`} ZPS_tsAplZdpDiscoveryCacheReq;`

A node with a primary discovery cache replies with a Discovery\_Cache\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpDiscoveryCacheRsp`\(detailed in [Section 9.2.3.14](zps_tsaplzdpdiscoverycachersp.md)\).

**Parent topic:**[ZPS\_eAplZdpDiscoveryCacheRequest](../topics/zps_eaplzdpdiscoverycacherequest.md)

