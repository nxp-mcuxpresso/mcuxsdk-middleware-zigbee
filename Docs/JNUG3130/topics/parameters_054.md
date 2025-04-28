# Parameters

-   *__hAPduInst:__* Handle of APDU instance in which request is sent
-   *__uDstAddr__:* Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)
-   *__bExtAddr__:* Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   **\*_pu8SeqNumber_:** Pointer to sequence number of request
-   **\*_psZdpPowerDescReq_***:* Pointer to request \(see above\)

**Parent topic:**[ZPS\_eAplZdpPowerDescRequest](../topics/zps_eaplzdppowerdescrequest.md)

