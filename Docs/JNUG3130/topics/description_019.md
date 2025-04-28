# Description

This function requests that a back-up of the locally held primary binding table cache is recovered from a remote node. The destination node of the request must hold the back-up binding table cache which is associated with the primary cache on the local node.

**Note:** This function is provided in the NXP ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status `ZPS_ZDP_NOT_SUPPORTED`.

This request must indicate the starting index in the binding table for the recovery. The request is represented by the structure below \(further detailed in [Section 9.2.2.30](zps_tsaplzdprecoverbindtablereq.md)\).

`typedef struct {`

`uint16 u16StartIndex;`

`} ZPS_tsAplZdpRecoverBindTableReq;`

The remote node replies with a Recover\_Bind\_Table\_rsp response containing the required binding table entries, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpRecoverBindTableRsp`\(detailed in [Section 9.2.3.30](zps_tsaplzdprecoverbindtablersp.md)\). As many binding entries as possible are included in this response. If the returned binding table is incomplete, this is indicated in the response and this function must be called again, with the appropriate starting index, to recover the rest of the table.

**Parent topic:**[ZPS\_eAplZdpRecoverBindTableRequest](../topics/zps_eaplzdprecoverbindtablerequest.md)

