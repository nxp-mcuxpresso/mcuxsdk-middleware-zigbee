# ZPS\_tsAplZdpNodeDescStoreReq

This structure is used by the function **ZPS\_eAplZdpNodeDescStoreRequest\(\)**. It represents a request to a remote node to store the Node descriptor of the local node.

The `ZPS_tsAplZdpNodeDescStoreReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`/* Rest of message is variable length */ ZPS_tsAplZdpNodeDescriptor sNodeDescriptor;`

`} ZPS_tsAplZdpNodeDescStoreReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `sNodeDescriptor`is a pointer to the Node descriptor to store \(this is itself a structure of the type `ZPS_tsAplZdpNodeDescriptor`, detailed in [Section](zps_tsaplzdpnodedescriptor.md)[8.2.1.1](zps_tsaplzdpnodedescriptor.md)\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

