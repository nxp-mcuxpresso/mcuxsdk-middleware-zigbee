# ZPS\_tsAplZdpMgmtNwkDiscRsp

This structure is used to store Mgmt\_NWK\_Disc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtNwkDiscRequest\(\)**. This response reports the networks discovered in a network discovery \(all the networks or a subset\).

The `ZPS_tsAplZdpMgmtNwkDiscRsp`structure is detailed below.

```
typedef struct {
  uint8 u8Status;
  uint8 u8NetworkCount;
  uint8 u8StartIndex;
  uint8 u8NetworkListCount;
  /* Rest of the message is variable length */
  ZPS_tsAplZdpNetworkDescr* psNetworkDescrList;
} ZPS_tsAplZdpMgmtNwkDiscRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtNwkDiscRequest\(\)**
-   `u8NetworkCount`is the total number of networks discovered
-   `u8StartIndex`is the index, in the complete list of discovered networks, of the first network reported in this response \(through `psNetworkDescrList`\)
-   `u8NetworkListCount`is the number of discovered networks reported in this response \(through `psNetworkDescrList`\)
-   `psNetworkDescrList`is a pointer to the first entry in a list of network descriptors for the discovered networks. Each entry is of the type `ZPS_tsAplZdpNetworkDescr`detailed below.

    **ZPS\_tsAplZdpNetworkDescr**

    ```
    
    typedef struct
    {
        uint64 u64ExtPanId;
        uint8 u8LogicalChan;
        uint8 u8StackProfile;
        uint8 u8ZigBeeVersion;
        uint8 u8PermitJoining;
        uint8 u8RouterCapacity;
        uint8 u8EndDeviceCapacity;
    } ZPS_tsAplZdpNetworkDescr;
    ```

    where:

    -   `u64ExtPanId`is the 64-bit extended PAN ID of the discovered network.
    -   `u8LogicalChan`is the radio channel in which the discovered network operates \(value in range 0 to 26, but only channels 11 to 26 relevant to 2400-MHz band\).
    -   `u8StackProfile`is the 4-bit identifier of the ZigBee stack profile used by the discovered network \(0 - manufacturer-specific, 1 - ZigBee, 2 - ZigBee PRO, other values reserved\) and is fixed at 2 for the NXP stack.
    -   `u8ZigBeeVersion`is the 4-bit version of the ZigBee protocol used by the discovered network.
    -   `u8PermitJoining`indicates whether the discovered network is currently allowing joinings - that is, at least one node \(a Router or the Coordinator\) of the network is allowing other nodes to join it:
        -   0x01: Joinings allowed.
        -   0x00: Joinings not allowed.
        -   All other values reserved.
    -   `u8RouterCapacity`indicates whether the device is capable of accepting join requests from Routers - set to TRUE if capable, FALSE otherwise.
    -   `u8EndDeviceCapacity`indicates whether the device is capable of accepting join requests from End Devices - set to TRUE capable, FALSE otherwise.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

