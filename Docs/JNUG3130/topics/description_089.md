# Description

This function requests a remote node to enable or disable joining for a specified amount of time. The destination node of this request must be a Router or the Co- ordinator. The request can be unicast to a particular node or broadcast to all routing nodes \(for which the destination address must be set to the 16-bit network address 0xFFFC\).

**Note:** This function is provided in the ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status **ZPS\_ZDP\_NOT\_SUPPORTED**.

The duration of the enable or disable joining state must be specified in the request. The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtpermitjoiningreq.md)[8.2.2.39](zps_tsaplzdpmgmtpermitjoiningreq.md)\).

`typedef struct {`

`uint8 u8PermitDuration; bool_t bTcSignificance;`

`} ZPS_tsAplZdpMgmtPermitJoiningReq;`

If the request was unicast, the remote node replies with a Mgmt\_Permit\_Joining\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtPermitJoiningRsp`\(detailed in [Section 8.2.3.39](zps_tsaplzdpmgmtpermitjoiningrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtPermitJoiningRequest](../topics/zps_eaplzdpmgmtpermitjoiningrequest.md)

