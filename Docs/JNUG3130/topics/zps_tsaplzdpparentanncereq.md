# ZPS\_tsAplZdpParentAnnceReq

This structure is used by the function **ZPS\_eAplZdpParentAnnceReq\(\)**, which sends out a Parent Announcement message. The structure specifies the nodes that are the children of the local node which called the function.

The `ZPS_tsAplZdpParentAnnceReq`structure is detailed below.

`typedef struct {`

`uint8 u8NumberOfChildren; uint64* pu64ChildList;`

`} ZPS_tsAplZdpParentAnnceReq;`

where:

-   `u8NumberOfChildren`is the number of child nodes
-   `pu64ChildList`is a pointer to a list of the 64-bit IEEE/MAC addresses of the child nodes

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

