# Parameters

-   *u8DstAddrMode* Type of destination address:
    -   ZPS\_E\_ADDR\_MODE\_SHORT - 16-bit network address.
    -   ZPS\_E\_ADDR\_MODE\_IEEE - 64-bit IEEE/MAC address.
    -   All other values are reserved.

-   *uDstAddress:* Destination address \(address type as specified through *u8DstAddrMode*\) - special broadcast addresses are detailed in [Section 9.3](broadcast_addresses.md)
-   *au8Key\[\]:* Array containing the network key to be transported. This array has a length equal to ZPS\_SEC\_KEY\_LENGTH
-   *u8KeySeqNum:* Sequence number of the specified key
-   *bUseParent:* Indicates whether to send key to parent of target node:
    -   TRUE - send to parent
    -   FALSE - do not send to parent
-   *u64ParentAddr:* 64-bit IEEE/MAC address of parent \(if used\).

**Parent topic:**[ZPS\_eAplZdoTransportNwkKey](../topics/zps_eaplzdotransportnwkkey.md)

