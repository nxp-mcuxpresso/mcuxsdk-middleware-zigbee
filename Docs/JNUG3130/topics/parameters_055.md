# Parameters

-   *__hAPduInst:__* Handle of APDU instance in which request is sent
-   **_uDstAddr:_** Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)
-   **_bExtAddr:_** Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   **\*_pu8SeqNumber:_** Pointer to sequence number of request
-   **\*_psZdpSimpleDescReq:_** Pointer to request \(see above\).

**Parent topic:**[ZPS\_eAplZdpSimpleDescRequest](../topics/zps_eaplzdpsimpledescrequest.md)

