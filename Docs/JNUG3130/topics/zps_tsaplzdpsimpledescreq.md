# ZPS\_tsAplZdpSimpleDescReq

This structure is used by the function **ZPS\_eAplZdpSimpleDescRequest\(\)**. It represents a request for the Simple descriptor of an endpoint on the node with a given network address.

The `ZPS_tsAplZdpSimpleDescReq`structure is detailed below.

```
typedef struct {
    uint16 u16NwkAddrOfInterest;
    uint8 u8EndPoint;
} ZPS_tsAplZdpSimpleDescReq;
```

where:

-   `u16NwkAddrOfInterest`is the network address of the node of interest.
-   `u8EndPoint`is the number of the relevant endpoint on the node \(1-240\).

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

