# ZPS\_tsAplZdpReplaceDeviceReq

This structure is used by the function **ZPS\_eAplZdpReplaceDeviceRequest\(\)**. It represents a request to a remote node \(with a primary binding table cache\) to modify its binding table entries by replacing an IEEE address and/or associated endpoint number.

The `ZPS_tsAplZdpReplaceDeviceReq`structure is detailed below.

`typedef struct {`

`uint64 u64OldAddress; uint8 u8OldEndPoint; uint64 u64NewAddress; uint8 u8NewEndPoint;`

`} ZPS_tsAplZdpReplaceDeviceReq;`

where:

-   `u64OldAddress`is the IEEE address to be replaced
-   `u8OldEndPoint`is the endpoint number to be replaced

\(0-240, where 0 indicates that the endpoint number is not to be replaced\)

-   `u64NewAddress`is the replacement IEEE address
-   `u8NewEndPoint`is the replacement endpoint number \(1-240\)

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

