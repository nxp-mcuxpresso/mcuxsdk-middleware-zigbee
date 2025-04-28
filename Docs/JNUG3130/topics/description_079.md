# Description

This function requests a remote node to provide a list of the End Devices registered in its primary discovery cache. Therefore, the destination node must contain a primary discovery cache.

**Note:** This function is provided in the ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status **ZPS\_ZDP\_NOT\_SUPPORTED**.

The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtcachereq.md)[9.2.2.40](zps_tsaplzdpmgmtcachereq.md)\).

`typedef struct {`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtCacheReq;`

The remote node replies with a Mgmt\_Cache\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtCacheRsp`\(detailed in [Section 9.2.3.40](zps_tsaplzdpmgmtcachersp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtCacheRequest](../topics/zps_eaplzdpmgmtcacherequest.md)

