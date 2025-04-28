# ZPS\_tsAplZdpIeeeAddrRsp

This structure is used to store IEEE\_addr\_rsp message data - a response to a call to the function **ZPS\_eAplZdpIeeeAddrRequest\(\)**. This response contains the IEEE address of the node with a given network address.

The `ZPS_tsAplZdpIeeeAddrRsp`structure is detailed below.

```
typedef struct
    { uint8 u8Status;
     uint64 u64IeeeAddrRemoteDev;
     uint16 u16NwkAddrRemoteDev;
     uint8 u8NumAssocDev;
     uint8 u8StartIndex;
    /* Rest of the message is variable Length */
     uint16* pNwkAddrAssocDevList;
} ZPS_tsAplZdpIeeeAddrRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpIeeeAddrRequest\(\)**.
-   `u64IeeeAddrRemoteDev`is the IEEE address of the remote node that sent the response \(this is the IEEE address that was requested\).
-   `u16NwkAddrRemoteDev`is the network address of the remote node that sent the response \(this is the network address specified in the original request\).
-   `u8NumAssocDev`is the number of neighboring nodes for which network addresses are also being reported \(in the remainder of the structure\).
-   `u8StartIndex`is the index in the remote node’s Neighbor table of the first entry to be included in this report. This element should be ignored if the element `u8NumAssocDev`is 0.
-   `pNwkAddrAssocDevList`is a pointer to a list of 16-bit network addresses of the remote node’s neighbors \(this is a variable-length list with four bytes per node\). This element should be ignored if the element `u8NumAssocDev`is 0.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

