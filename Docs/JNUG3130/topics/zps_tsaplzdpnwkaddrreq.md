# ZPS\_tsAplZdpNwkAddrReq

This structure is used by the function **ZPS\_eAplZdpNwkAddrRequest\(\)**. It represents a request for the network address of the node with a given IEEE address.

The `ZPS_tsAplZdpNwkAddrReq`structure is detailed below.

```
typedef struct {
  uint64 u64IeeeAddr;
  uint8 u8RequestType;
  uint8 u8StartIndex;
} ZPS_tsAplZdpNwkAddrReq;
```

where:

-   `u64IeeeAddr` is the IEEE address of the node of interest.
-   `u8RequestType` is the type of response required:
    -   0x00: Single device response, which contains only the network address of the target node.
    -   0x01: Extended response, which also includes the network addresses of neighboring nodes.
    -   All other values are reserved.
-   `u8StartIndex` is the Neighbor table index of the first neighboring node to be included in the response, if an extended response has been selected.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

