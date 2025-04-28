# Description

This function requests the 16-bit network address of the node with a particular 64-bit IEEE \(MAC\) address. The function sends out an NWK\_addr\_req request, which can be either unicast or broadcast, as follows:

-   Unicast to another node, specified through *uDstAddr*, that will ‘know’ the required network address \(this may be the parent of the node of interest or the Coordinator\)
-   Broadcast to the network, in which case *uDstAddr*must be set to the special network address 0xFFFF \(see [Section 9.3](broadcast_addresses.md)\)

The IEEE address of the node of interest must be specified in the request, represented by the structure below \(detailed further in [Section 9.2.2.1](zps_tsaplzdpnwkaddrreq.md)\).

```
typedef struct {
        uint64 u64IeeeAddr;
        uint8 u8RequestType;
        uint8 u8StartIndex;
} ZPS_tsAplZdpNwkAddrReq;
```

The required network address is received in an NWK\_addr\_resp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpNwkAddrRsp`\(detailed in [Section 9.2.3.1](zps_tsaplzdpnwkaddrrsp.md)\). Note that this response can optionally contain the network addresses of the responding node’s neighbors \(this option is selected as part of the request through `u8RequestType`\).

**Parent topic:**[ZPS\_eAplZdpNwkAddrRequest](../topics/zps_eaplzdpnwkaddrrequest.md)

