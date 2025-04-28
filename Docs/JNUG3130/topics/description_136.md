# Description

This function requests a remote node to perform a channel scan in order to discover any other wireless networks that are operating in the neighborhood.

**Note:** This function is provided in the ZDP API for the reason of interoperability with nodes running non-NXP ZigBee PRO stacks that support the generated request. On receiving a request from this function, the NXP ZigBee PRO stack will return the status **ZPS\_ZDP\_NOT\_SUPPORTED**.



This request must specify the requirements for the scan: channels to scan, duration of scan, starting channel. The request is represented by the structure below \(further detailed in [Section 8.2.2.33](zps_tsaplzdpmgmtnwkdiscreq.md)\).

`typedef struct {`

`uint32 u32ScanChannels;`

`uint8 u8ScanDuration;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtNwkDiscReq;`

The remote node replies with a Mgmt\_NWK\_Disc\_rsp response containing the scan results, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtNwkDiscRsp`\(detailed in [Section](zps_tsaplzdpmgmtnwkdiscrsp.md) [8.2.3.33](zps_tsaplzdpmgmtnwkdiscrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtNwkDiscRequest](../topics/zps_eaplzdpmgmtnwkdiscrequest.md)

