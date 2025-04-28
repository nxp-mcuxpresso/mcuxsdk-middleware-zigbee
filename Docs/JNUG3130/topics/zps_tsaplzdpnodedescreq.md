# ZPS\_tsAplZdpNodeDescReq

This structure is used by the function **ZPS\_eAplZdpNodeDescRequest\(\)**. It represents a request for the Node descriptor of the node with a given network address.

The `ZPS_tsAplZdpNodeDescReq`structure is detailed below.

`typedef struct {`

`uint16 u16NwkAddrOfInterest;`

`} ZPS_tsAplZdpNodeDescReq;`

where `u16NwkAddrOfInterest`is the network address of the node of interest.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

