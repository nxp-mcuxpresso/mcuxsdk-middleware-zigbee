# Description

This function requests a remote node to allow a particular device \(identified through its IEEE address\) to join the network as a child of the node. Thus, joining should be enabled on the remote node just for the nominated device. The destination node of this request must be a Router or the Coordinator.

**Note:** This function is provided in the ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status **ZPS\_ZDP\_NOT\_SUPPORTED**.

The IEEE address of the nominated device as well as its capabilities must be included in the request. The request is represented by the structure below \(further detailed in [Section 8.2.2.38](zps_tsaplzdpmgmtdirectjoinreq.md)\).

`typedef struct {`

`uint64 u64DeviceAddress; uint8 u8Capability;`

`} ZPS_tsAplZdpMgmtDirectJoinReq;`

The remote node replies with a Mgmt\_Direct\_Join\_req response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtDirectJoinRsp`\(detailed in [Section 8.2.3.38](zps_tsaplzdpmgmtdirectjoinrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtDirectJoinRequest](../topics/zps_eaplzdpmgmtdirectjoinrequest.md)

