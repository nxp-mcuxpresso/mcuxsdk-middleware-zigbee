# Description

This function requests the 64-bit IEEE \(MAC\) address of the node with a particular 16-bit network address. The function sends an IEEE\_addr\_req request to the relevant node, specified through *uDstAddr*.

The network address of the node of interest must also be specified in the request, represented by the structure below \(detailed further in [Section 9.2.2.2](zps_tsaplzdpieeeaddrreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint8 u8RequestType;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpIeeeAddrReq;`

The required IEEE address is received in an IEEE\_addr\_resp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpIeeeAddrRsp`\(detailed in [Section 9.2.3.2](zps_tsaplzdpieeeaddrrsp.md)\). Note that this response can optionally contain the IEEE addresses of the responding node’s neighbors \(this option is selected as part of the request through `u8RequestType`\).

**Parent topic:**[ZPS\_eAplZdpIEEEAddrRequest](../topics/zps_eaplzdpieeeaddrrequest.md)

