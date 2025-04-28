# Parameters

-   *__hAPduInst__* Handle of APDU instance in which request is sent

-   **_uDstAddr_** Address of destination node of request \(can be 16-bit or 64-bit, as specified by *bExtAddr*\)

-   **_bExtAddr:_** Type of destination address:

    -   TRUE: 64-bit IEEE \(MAC\) address

    -   FALSE: 16-bit network address

-   **\*_pu8SeqNumber:_** Pointer to sequence number of request

-   **\*_psZdpUserDescSetReq_***:* Pointer to request \(see above\)


**Parent topic:**[ZPS\_eAplZdpUserDescSetRequest](../topics/zps_eaplzdpuserdescsetrequest.md)

