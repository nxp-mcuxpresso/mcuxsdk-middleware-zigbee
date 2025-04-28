# Parameters

-   *hAPdu* Handle of APDU in which request is sent.
-   *uDstAddr* Address of destination node of request \(can be 16- or 64-bit, as specified by *bExtAddr*\)
-   *bExtAddr* Type of destination address:
    -   TRUE: 64-bit IEEE \(MAC\) address
    -   FALSE: 16-bit network address
-   **\*** *pu8SeqNumber* Pointer to sequence number of request
-   *u16ProfileId* Application profile ID
-   **\*** *psZdpStoreBkupBindEntryReq* Pointer to request \(see above\)

**Parent topic:**[ZPS\_eAplZdpStoreBkupBindEntryRequest](../topics/zps_eaplzdpstorebkupbindentryrequest.md)

