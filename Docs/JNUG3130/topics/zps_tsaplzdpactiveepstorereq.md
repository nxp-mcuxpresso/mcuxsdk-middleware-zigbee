# ZPS\_tsAplZdpActiveEpStoreReq

This structure is used by the function **ZPS\_eAplZdpActiveEpStoreRequest\(\)**. It represents a request to a remote node to store the list of active endpoints of the local node.

The `ZPS_tsAplZdpActiveEpStoreReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`uint8 u8ActiveEPCount;`

`/* Rest of message is variable length */ uint8* pu8ActiveEpList;`

`} ZPS_tsAplZdpActiveEpStoreReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `u8ActiveEPCount`is the number of active endpoints in the list to store
-   `pu8ActiveEpList`is a pointer to the list of active endpoints to store

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

