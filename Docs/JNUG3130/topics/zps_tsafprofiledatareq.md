# ZPS\_tsAfProfileDataReq

This structure is used to specify the transmission details for a data transmission submitted using the function **ZPS\_eAplAfApsdeDataReq\(\)**.

The `ZPS_tsAfProfileDataReq`structure is detailed below.

```
typedef struct {
    ZPS_tuAddress             uDstAddr;
    uint16                    u16ClusterId;
    uint16                    u16ProfileId;
    uint8                     u8SrcEp;
    ZPS_teAplApsdeAddressMode eDstAddrMode;
    uint8                     u8DstEp;
    ZPS_teAplAfSecurityMode   eSecurityMode;
    uint8                     u8Radius;
}ZPS_tsAfProfileDataReq;
```

where:

-   `uDstAddr`is the address of the destination node for the transmission request \(can be 16- or 64-bit, as specified by `eDstAddrMode`\).
-   `u16ClusterId`is the Cluster ID of the destination cluster.
-   `u16ProfileId`is the Profile ID of the destination application profile.
-   `u8SrcEp`is the source endpoint number \(1-240\) on the local node.
-   `eDstAddrMode`is the type of destination address, one of \(also see the table, [Table](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA)\):
    -   ZPS\_E\_ADDR\_MODE\_BOUND \(no address needed for bound nodes\).
    -   ZPS\_E\_ADDR\_MODE\_GROUP \(16-bit group address\).
    -   ZPS\_E\_ADDR\_MODE\_SHORT \(16-bit network address\).
    -   ZPS\_E\_ADDR\_MODE\_IEEE \(64-bit IEEE/MAC address\).

-   `u8DstEp`is the destination endpoint number \(1-240\) on the remote node.
-   `eSecurityMode`is the security mode for the data transfer, one of:
    -   ZPS\_E\_APL\_AF\_UNSECURE \(no security enabled\)
    -   ZPS\_E\_APL\_AF\_SECURE \(Application-level security using link key and network key\)
    -   ZPS\_E\_APL\_AF\_SECURE\_NWK \(Network-level security using network key\)
    -   ZPS\_E\_APL\_AF\_SECURE \| ZPS\_E\_APL\_AF\_EXT\_NONCE \(Application-level security using link key and network key with the extended NONCE included in the frame\)
    -   ZPS\_E\_APL\_AF\_WILD\_PROFILE \(May be combined with the above flags using OR operator. Sends the message using the wildcard profile \(0xFFFF\) instead of the profile in the associated Simple descriptor\).

-   `u8Radius`is the maximum number of hops permitted to the destination node \(zero value specifies that default maximum is to be used\).

**Parent topic:**[Other structures](../topics/other_structures.md)

