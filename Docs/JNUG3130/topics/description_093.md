# Description

This function requests a remote node to provide the contents of its Binding table. The destination node of this request must be a Router or the Coordinator.

This request must specify the index of the first entry in the Binding table to report. The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtbindreq.md)[8.2.2.36](zps_tsaplzdpmgmtbindreq.md)\).

`typedef struct {`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtBindReq;`

The remote node replies with a Mgmt\_Bind\_rsp response containing the required information, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtBindRsp`\(detailed in [Section](zps_tsaplzdpmgmtbindrsp.md)[8.2.3.36](zps_tsaplzdpmgmtbindrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtBindRequest](../topics/zps_eaplzdpmgmtbindrequest.md)

