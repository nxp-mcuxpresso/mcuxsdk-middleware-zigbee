# Parameters

-   *__hAPduInst:__* Handle of APDU instance in which request is sent
-   *__uDstAddr:__* Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)
-   *__bExtAddr:__* Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   \**pu8SeqNumber:* Pointer to sequence number of request
-   \**psZdpNwkAddrReq:* Pointer to request \(see above\).

**Parent topic:**[ZPS\_eAplZdpNwkAddrRequest](../topics/zps_eaplzdpnwkaddrrequest.md)

