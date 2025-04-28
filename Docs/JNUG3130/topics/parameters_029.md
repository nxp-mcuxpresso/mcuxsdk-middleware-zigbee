# Parameters

-   *__hAPduInst:__* Handle of APDU instance to be sent
-   *__u16ClusterId__:* Identifier of relevant output cluster on source endpoint
-   *__u8SrcEndpoint__:* Source endpoint number \(1-240\) on local node
-   *__u16DstGroupAddr__:* Group address of destination endpoints
-   *__eSecurityMode:__* Security mode for data transfer, one of:
    -   ZPS\_E\_APL\_AF\_UNSECURE \(no security enabled\)
    -   ZPS\_E\_APL\_AF\_SECURE\_NWK \(Network-level security using network key\)
    -   ZPS\_E\_APL\_AF\_WILD\_PROFILE \(May be combined with above flags using OR operator. Sends the message using the wildcard profile \(0xFFFF\) instead of the profile in the associated Simple descriptor\)

-   *__u8Radius__:* Maximum number of hops permitted to destination node \(zero value specifies that default maximum is to be used\)
-   **\*_pu8SeqNum:_** Pointer to location to receive sequence number assigned to data transfer request. If not required, set to NULL.

**Parent topic:**[ZPS\_eAplAfGroupDataReq](../topics/zps_eaplafgroupdatareq.md)

