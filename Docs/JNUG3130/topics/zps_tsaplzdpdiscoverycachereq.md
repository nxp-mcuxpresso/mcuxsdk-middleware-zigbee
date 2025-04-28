# ZPS\_tsAplZdpDiscoveryCacheReq

This structure is used by the function **ZPS\_eAplZdpDiscoveryCacheRequest\(\)**. It represents a request to find the nodes in the network which have a primary discovery cache.

The `ZPS_tsAplZdpDiscoveryCacheReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`} ZPS_tsAplZdpDiscoveryCacheReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

