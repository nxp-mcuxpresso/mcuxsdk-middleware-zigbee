# ZPS\_tsAplZdpMgmtRtgReq

This structure is used by the function **ZPS\_eAplZdpMgmtRtgRequest\(\)**. It represents a request to a remote node to provide the contents of its Routing table.

The `ZPS_tsAplZdpMgmtRtgReq`structure is detailed below.

```
typedef struct {
uint8 u8StartIndex;
} ZPS_tsAplZdpMgmtRtgReq;
```

where `u8StartIndex`is the Routing table index of the first entry to be included in the response to this request.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

