# ZPS\_tsAplZdpDiscoveryStoreReq

This structure is used by the function **ZPS\_eAplZdpDiscoveryStoreRequest\(\)**. It represents a request to a remote node to reserve memory space to store the local node’s ‘discovery information’.

The `ZPS_tsAplZdpDiscoveryStoreReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`uint8 u8NodeDescSize; uint8 u8PowerDescSize; uint8 u8ActiveEpSize; uint8 u8SimpleDescCount;`

`/* Rest of message is variable length */ uint8* pu8SimpleDescSizeList;`

`} ZPS_tsAplZdpDiscoveryStoreReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `u8NodeDescSize`is the size of the Node descriptor to store
-   `u8PowerDescSize`is the size of the Power descriptor to store
-   `u8ActiveEpSize`is the size of the list of active endpoints to store
-   `u8SimpleDescCount`is the number of Simple descriptors to store
-   `pu8SimpleDescSizeList`is a pointer to a list of sizes of the Simple descriptors

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

