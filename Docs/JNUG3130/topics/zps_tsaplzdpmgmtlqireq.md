# ZPS\_tsAplZdpMgmtLqiReq

This structure is used by the function **ZPS\_eAplZdpMgmtLqiRequest\(\)**. It represents a request to a remote node to provide a list of neighboring nodes, from its Neighbor table, including a radio signal strength \(LQI\) value for each of these nodes.

The `ZPS_tsAplZdpMgmtLqiReq`structure is detailed below.

```
typedef struct {
uint8 u8StartIndex;
} ZPS_tsAplZdpMgmtLqiReq;
```

where `u8StartIndex`is the Neighbor table index of the first entry to be included in the response to this request.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

