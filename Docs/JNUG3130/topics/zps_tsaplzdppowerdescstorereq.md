# ZPS\_tsAplZdpPowerDescStoreReq

This structure is used by the function **ZPS\_eAplZdpPowerDescStoreRequest\(\)**. It represents a request to a remote node to store the Power descriptor of the local node.

The `ZPS_tsAplZdpPowerDescStoreReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint64 u64IeeeAddr;`

`/* Rest of message is variable length */ ZPS_tsAplZdpNodePowerDescriptor sPowerDescriptor;`

`} ZPS_tsAplZdpPowerDescStoreReq;`

where:

-   `u16NwkAddr`is the network address of the sending node
-   `u64IeeeAddr`is the IEEE address of the sending node
-   `sPowerDescriptor`is a pointer to the Power descriptor to store \(this is itself a structure of the type `ZPS_tsAplZdpNodePowerDescriptor`, detailed in [Section](zps_tsaplzdpnodepowerdescriptor.md)[8.2.1.2](zps_tsaplzdpnodepowerdescriptor.md)\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

