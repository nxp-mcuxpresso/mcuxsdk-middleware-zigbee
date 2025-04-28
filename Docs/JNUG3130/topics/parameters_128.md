# Parameters

-   *hAPduInst* Handle of APDU instance in which request is sent

-   *uDstAddr* Network address of destination node of request \(*bExtAddr*must be set to FALSE - see below\)

-   *bExtAddr* Type of destination address: TRUE: 64-bit IEEE \(MAC\) address FALSE: 16-bit network address

    -   **\*** *pu8SeqNumber* Pointer to sequence number of request

    -   **\*** *psZdpIeeeAddrReq* Pointer to request \(see above\)


**Parent topic:**[ZPS\_eAplZdpIEEEAddrRequest](../topics/zps_eaplzdpieeeaddrrequest.md)

