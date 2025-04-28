# Description

This function informs a remote node with a primary binding table cache that the local node will hold its own binding table entries \(and therefore the remote node does not need to hold these entries\). The function sends a Bind\_Register\_req request to the remote node.

The IEEE address of the local node must be specified in the request, which is represented by the structure below \(further detailed in [Section 8.2.2.25](zps_tsaplzdpbindregisterreq.md)\).

`typedef struct {`

`uint64 u64NodeAddress;`

`} ZPS_tsAplZdpBindRegisterReq;`

The remote node replies with a Bind\_Register\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpBindRegisterRsp`\(detailed in [Section 9.2.3.25](zps_tsaplzdpbindregisterrsp.md)\). This response contains any information stored about the binding on the remote.

**Parent topic:**[ZPS\_eAplZdpBindRegisterRequest](../topics/zps_eaplzdpbindregisterrequest.md)

