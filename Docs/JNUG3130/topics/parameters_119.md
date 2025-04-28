# Parameters

-   *hAPduInst* Handle of APDU instance in which request is sent.
-   *uDstAddr* Address of destination node of request \(can be 16-bit or 64-bit, as specified by *bExtAddr*\)
-   *bExtAddr* Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   **\*** *pu8SeqNumber* Pointer to sequence number of request
-   **\*** *psZdpMgmtRtgReq* Pointer to request \(see above\)

**Parent topic:**[ZPS\_eAplZdpMgmtRtgRequest](../topics/zps_eaplzdpmgmtrtgrequest.md)

