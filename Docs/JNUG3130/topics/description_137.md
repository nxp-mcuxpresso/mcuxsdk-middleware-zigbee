# Description

This function requests a remote node to provide the contents of its Routing table. The destination node of this request must be a Router or the Coordinator.

This request must specify the index of the first entry in the Routing table to report. The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtrtgreq.md) [8.2.2.35](zps_tsaplzdpmgmtrtgreq.md)\).

`typedef struct {`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtRtgReq;`

The remote node replies with a Mgmt\_Rtg\_rsp response containing the required information, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtRtgRsp`\(detailed in [Section](zps_tsaplzdpmgmtrtgrsp.md) [8.2.3.35](zps_tsaplzdpmgmtrtgrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtRtgRequest](../topics/zps_eaplzdpmgmtrtgrequest.md)

