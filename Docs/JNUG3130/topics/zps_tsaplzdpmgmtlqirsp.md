# ZPS\_tsAplZdpMgmtLqiRsp

This structure is used to store Mgmt\_Lqi\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtLqiRequest\(\)**. This response reports a list of neighboring nodes along with their LQI \(link quality\) values.

The `ZPS_tsAplZdpMgmtLqiRsp`structure is detailed below.

```
typedef struct {
  uint8 u8Status;
  uint8 u8NeighborTableEntries;
  uint8 u8StartIndex;
  uint8 u8NeighborTableListCount;
  /* Rest of the message is variable length */
  ZPS_tsAplZdpNtListEntry* pNetworkTableList;
} ZPS_tsAplZdpMgmtLqiRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtLqiRequest\(\)**
-   `u8NeighborTableEntries`is the total number of Neighbor table entries on the remote node
-   `u8StartIndex`is the Neighbor table index of the first entry reported in this response \(through `pNetworkTableList`\)
-   `u8NetworkListCount`is the number of Neighbor table entries reported in this response \(through `pNetworkTableList`\)
-   `pNetworkTableList`is a pointer to the first entry in the list of reported Neighbor table entries. Each entry is of the type `ZPS_tsAplZdpNtListEntry`detailed below.

    **ZPS\_tsAplZdpNtListEntry**

    ```
    typedef struct
    {
        uint64 u64ExtPanId;
        uint64 u64ExtendedAddress;
        uint16 u16NwkAddr;
        uint8 u8LinkQuality;
        uint8 u8Depth;
        /*
        * Bitfields are used for syntactic neatness and space saving.
        * May need to assess whether these are suitable for embedded
        environment and may need to watch endianness on u8Assignment
        */
      union
        {
          struct
          {
            unsigned u1Reserved1:1;
            unsigned u2Relationship:3;
            unsigned u2RxOnWhenIdle:2;
            unsigned u2DeviceType:2;
            unsigned u6Reserved2:6;
            unsigned u2PermitJoining:2;
          } ;
          uint8 au8Field[2];
      } uAncAttrs;
    } ZPS_tsAplZdpNtListEntry;
    ```

    where:

    -   `u64ExtPanId`is the 64-bit extended PAN ID of the network .
    -   `u64ExtendedAddress`is the IEEE address of the neighboring node.
    -   `u16NwkAddr`is the network address of the neighboring node.
    -   `u8LinkQuality`is the estimated LQI \(link quality\) value for radio transmissions from the neighboring node.
    -   `u8Depth`is the tree depth of the neighboring node \(where the Coordinator is at depth zero\).
    -   `u1Reserved1:1`is a 1-bit reserved value and should be set zero.
    -   `u2Relationship:3`is a 3-bit value representing the neighboring node’s relationship to the local node:
        -   0: Neighbor is the parent.
        -   1: Neighbor is a child.
        -   2: Neighbor is a sibling \(has same parent\).
        -   3: None of the above.
        -   4: Neighbor is a former child.
    -   `u2RxOnWhenIdle:2`is a 2-bit value indicating whether the neighboring node’s receiver is enable during idle periods:
        -   0: Receiver off when idle \(sleeping device\)
        -   1: Receiver on when idle \(non-sleeping device\)
        -   2: Unknown
    -   `u2DeviceType:2`is a 2-bit value representing the ZigBee device type of the neighboring node:
        -   0: Coordinator
        -   1: Router
        -   2: End Device
        -   3: Unknown
    -   `u6Reserved2:6`is a 6-bit reserved value and should be set zero.
    -   `u2PermitJoining:2`is a 2-bit value indicating whether the neighboring node is accepting joining requests:
        -   0: Not accepting join requests
        -   1: Accepting join requests
        -   2: Unknown
    -   `au8Field[2]`is the allocation of two bytes for the union.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

