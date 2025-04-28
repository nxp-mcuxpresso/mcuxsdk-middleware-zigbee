# ZPS\_tsAplZdpMgmtBindReq

This structure is used by the function **ZPS\_eAplZdpMgmtBindRequest\(\)**. It represents a request to a remote node to provide the contents of its Binding table.

The `ZPS_tsAplZdpMgmtBindReq`structure is detailed below.

```
typedef struct {
    uint8 u8StartIndex;
} ZPS_tsAplZdpMgmtBindReq;
```

where `u8StartIndex`is the Binding table index of the first entry to be included in the response to this request.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

