# ZPS\_tsAplZdpSimpleDescStoreReq

This structure is used by the function **ZPS\_eAplZdpSimpleDescStoreRequest\(\)**. It represents a request to a remote node to store the Simple descriptor of one of the local node’s endpoints.

The `ZPS_tsAplZdpSimpleDescStoreReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr; uint8 u8Length;`

`/* Rest of message is variable length */ ZPS_tsAplZdpSimpleDescType sSimpleDescriptor;`

`} ZPS_tsAplZdpSimpleDescStoreReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `u8Length`is the length of the Simple descriptor to store
-   `sSimpleDescriptor`is a pointer to the Simple descriptor to store \(this is itself a structure of the type `ZPS_tsAplZdpSimpleDescType`, detailed in [Section](zps_tsaplzdpsimpledesctype.md)[8.2.1.3](zps_tsaplzdpsimpledesctype.md)\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

