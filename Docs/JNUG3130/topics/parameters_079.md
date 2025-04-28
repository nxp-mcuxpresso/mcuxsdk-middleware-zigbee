# Parameters

-   *hAPduInst* Handle of APDU instance in which request is sent.
-   *uDstAddr* Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)
-   *bExtAddr* Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   **\*** *pu8SeqNumber* Pointer to sequence number of request
-   **\*** *psZdpPowerDescReq* Pointer to request \(see above\)

**Parent topic:**[ZPS\_eAplZdpBindRegisterRequest](../topics/zps_eaplzdpbindregisterrequest.md)

