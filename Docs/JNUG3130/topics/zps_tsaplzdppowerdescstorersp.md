# ZPS\_tsAplZdpPowerDescStoreRsp

This structure is used to store `Power_Desc_store_rsp` message data - a response to a call to the function **ZPS\_eAplZdpPowerDescStoreRequest\(\)**. This response indicates whether the sending node has successfully stored the received Power descriptor in its primary discovery cache.

The `ZPS_tsAplZdpPowerDescStoreRsp`structure is detailed below.

```
typedef struct {
        uint8 u8Status;
        uint64 u64IeeeAddr;
        /* Rest of message is variable length */
        ZPS_tsAplZdpNodePowerDescriptor sPowerDescriptor;
} ZPS_tsAplZdpPowerDescStoreRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpPowerDescStoreRequest\(\)**.
-   `u64IeeeAddr`is the IEEE/MAC address of the device whose Power descriptor has been stored in the primary discovery cache.
-   `sPowerDescriptor`is the Power descriptor stored \(see [Section 9.2.1.1](zps_tsaplzdpnodedescriptor.md)\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

