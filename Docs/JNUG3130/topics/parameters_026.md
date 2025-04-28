# Parameters

-   *__hAPduInst:__* Handle of APDU instance in which request is sent

-   *__uDstAddr__:* Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)

-   *__bExtAddr:__* Type of destination address:

    -   TRUE: 64-bit IEEE \(MAC\) address

    -   FALSE: 16-bit network address

-   **\*_pu8SeqNumber:_** Pointer to sequence number of request

-   **\*_psZdpMatchDescReq:_** Pointer to request \(see above\).


**Parent topic:**[ZPS\_eAplZdpMatchDescRequest](../topics/zps_eaplzdpmatchdescrequest.md)

