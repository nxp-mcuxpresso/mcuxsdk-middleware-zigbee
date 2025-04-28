# ZPS\_tsAplZdpMgmtRtgRsp

This structure is used to store Mgmt\_Rtg\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtRtgRequest\(\)**. This response reports the contents of the remote node’s Routing table

The `ZPS_tsAplZdpMgmtRtgRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint8 u8RoutingTableEntries;
    uint8 u8StartIndex;
    uint8 u8RoutingTableCount;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpRtEntry* pRoutingTableList;
} ZPS_tsAplZdpMgmtRtgRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtRtgRequest\(\)**
-   `u8RoutingTableEntries`is the total number of Routing table entries on the remote node
-   `u8StartIndex`is the Routing table index of the first entry reported in this response \(through `pRoutingTableList`\)
-   `u8RoutingTableCount`is the number of Routing table entries reported in this response \(through `pRoutingTableList`\)
-   `pRoutingTableList`is a pointer to the first entry in the list of reported Routing table entries. Each entry is of the type `ZPS_tsAplZdpRtEntry`detailed below

    ```
    
    typedef struct
    {
        uint16 u16NwkDstAddr; /**< Destination Network address */
        uint16 u16NwkNxtHopAddr; /**< Next hop Network address */
      union
        {
        struct
           {
            unsigned u3Status:3;
            unsigned u1MemConst:1;
            unsigned u1ManyToOne:1;
            unsigned u1RouteRecordReqd:1;
            unsigned u1Reserved:2;
            } bfBitfields;
            uint8 u8Field;
      } uAncAttrs;
    } ZPS_tsAplZdpRtEntry;
    ```

    where:

    -   `u16NwkDstAddr`is the destination network address of the route.
    -   `u16NwkNxtHopAddr`is the ‘next hop’ network address of the route.
    -   `u3Status:3`is the 3-bit status for the route:
        -   000 = ACTIVE
        -   001 = DISCOVERY\_UNDERWAY
        -   010 = DISCOVERY\_FAILED
        -   011 = INACTIVE
        -   100 = VALIDATION\_UNDERWAY
        -   101-111 = Reserved.
    -   `u1MemConst:1`is a bit indicating whether the device is a memory-constrained concentrator.
    -   `u1ManyToOne:1`is a bit indicating whether the destination node is a concentrator that issued a many-to-one request.
    -   `u1RouteRecordReqd:1`is a bit indicating whether a route record command frame. should be sent to the destination before the next data packet.
    -   `u1Reserved:2`are reserved bits.
    -   `u8Field`contains the full set of flags of the `bfBitfields`sub-structure, with `u3Status:3`occupying the most significant bits and `u1Reserved:2`occupying the least significant bits \(for a big-endian device\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

