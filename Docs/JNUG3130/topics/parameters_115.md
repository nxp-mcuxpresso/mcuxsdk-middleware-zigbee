# Parameters

-   *__hAPduInst__:* Handle of APDU instance to be sent

-   *__u16ClusterId__:* Identifier of relevant output cluster on source endpoint

-   *__u8SrcEndpoint__:* Source endpoint number \(1-240\) on local node

-   **_u8DstEndpoint_:** Destination endpoint number \(1-240\) on remote node

-   **_u64DestAddr:_** IEEE \(MAC\) address of destination node

-   *__eSecurityMode__:* Security mode for data transfer:

    -   ZPS\_E\_APL\_AF\_UNSECURE \(no security enabled\)

    -   ZPS\_E\_APL\_AF\_SECURE \(Application-level security using link key and network key\)

    -   ZPS\_E\_APL\_AF\_SECURE\_NWK \(Network-level security using network key\)

    -   ZPS\_E\_APL\_AF\_SECURE \| ZPS\_E\_APL\_AF\_EXT\_NONCE \(Application-level security using link key and network key with the extended NONCE included in the frame\)

    -   ZPS\_E\_APL\_AF\_WILD\_PROFILE \(May be combined with above flags using OR operator. Sends the message using the wildcard profile \(0xFFFF\) instead of the profile in the associated Simple descriptor\)

-   *__u8Radius__:* Maximum number of hops permitted to destination node \(zero value specifies that default maximum is to be used\)

-   **\*_pu8SeqNum:_** Pointer to location to receive sequence number assigned to data transfer request. If not required, set to NULL


**Parent topic:**[ZPS\_eAplAfUnicastIeeeDataReq](../topics/zps_eaplafunicastieeedatareq.md)

