# ZPS\_tsAplZdpExtendedActiveEpReq

This structure is used by the function **ZPS\_eAplZdpExtendedActiveEpRequest\(\)**. It represents a request for a list of the active endpoints on the node with a given network address. This request is required when the node has more active endpoints than the usual **ZPS\_eAplZdpActiveEpRequest\(\)** function can deal with.

The `ZPS_tsAplZdpExtendedActiveEpReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpExtendedActiveEpReq;`

where:

-   `u16NwkAddr`is the network address of the node of interest
-   `u8StartIndex`is the index of the first endpoint of interest in the list of active endpoints \(this and subsequent endpoints will be reported in the response\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

