# Description

This function requests a remote node to leave the network. The request also indicates whether the children of the leaving node should also be requested to leave and whether the leaving node\(s\) should subsequently attempt to rejoin the network.

**Note:** This function is provided in the ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status **ZPS\_ZDP\_NOT\_SUPPORTED**.

The IEEE address of the node to leave the network must be included in the request, as well as flags indicating the children and rejoin choices \(see above\). The request is represented by the structure below \(further detailed in [Section 8.2.2.37](zps_tsaplzdpmgmtleavereq.md)\).

`typedef struct {`

`uint64 u64DeviceAddress;`

`uint8 u8Flags;`

`} ZPS_tsAplZdpMgmtLeaveReq;`

The remote node replies with a Mgmt\_Leave\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtLeaveRsp`\(detailed in [Section 8.2.3.37](zps_tsaplzdpmgmtleaversp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtLeaveRequest](../topics/zps_eaplzdpmgmtleaverequest.md)

