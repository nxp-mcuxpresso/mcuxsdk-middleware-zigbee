# ZPS\_tsAplZdpIEEEAddrReq

This structure is used by the function **ZPS\_eAplZdpIEEEAddrRequest\(\)**. It represents a request for the IEEE address of a node with a given network address.

The `ZPS_tsAplZdpIEEEAddrReq`structure is detailed below.

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint8 u8RequestType;`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpIEEEAddrReq;`

where:

-   `u16NwkAddrOfInterest`is the network address of the node of interest
-   `u8RequestType`is the type of response required:
    -   0x00: Single device response, which will contain only the IEEE address of the target node
    -   0x01: Extended response, which will also include the IEEE addresses of neighboring nodes
    -   All other values are reserved
-   `u8StartIndex`is the Neighbor table index of the first neighboring node to be included in the response, if an extended response has been selected

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

