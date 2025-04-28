# ZPS\_tsAplZdpBindRegisterReq

This structure is used by the function **ZPS\_eAplZdpBindRegisterRequest\(\)**. It represents a request to inform a remote node with a primary binding table cache that the local node will hold its own Binding table entries.

The `ZPS_tsAplZdpBindRegisterReq`structure is detailed below.

`typedef struct {`

`uint64 u64NodeAddress;`

`} ZPS_tsAplZdpBindRegisterReq;`

where `u64NodeAddress`is the IEEE address of the local node.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

