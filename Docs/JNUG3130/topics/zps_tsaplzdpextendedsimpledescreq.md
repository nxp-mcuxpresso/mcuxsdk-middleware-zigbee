# ZPS\_tsAplZdpExtendedSimpleDescReq

This structure is used by the **ZPS\_eAplZdpExtendedSimpleDescRequest\(\)**function. It represents a request for the Simple descriptor of an endpoint on the node with a given network address. This request is required when the endpoint has more input/output clusters than the usual **ZPS\_eAplZdpSimpleDescRequest\(\)** function can deal with.

The `ZPS_tsAplZdpExtendedSimpleDescReq`structure is detailed below.

`typedef struct { uint16 u16NwkAddr; uint8 u8EndPoint;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpExtendedSimpleDescReq;`

where:

-   `u16NwkAddrOfInterest`is the network address of the node of interest
-   `u8EndPoint`is the number of the relevant endpoint on the node \(1-240\)
-   `u8StartIndex`is the index of the first cluster of interest in the input and output cluster lists for the endpoint \(this and subsequent clusters will be reported in the response\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

