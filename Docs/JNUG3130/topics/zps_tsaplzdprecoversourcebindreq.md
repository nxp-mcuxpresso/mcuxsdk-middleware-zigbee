# ZPS\_tsAplZdpRecoverSourceBindReq

This structure is used by the function **ZPS\_eAplZdpRecoverSourceBindRequest\(\)**. It represents a request to a remote node to recover the back-up of the local node’s source binding table \(whole or in part\).

The `ZPS_tsAplZdpRecoverSourceBindReq`structure is detailed below.

```
typedef struct {
uint16 u16StartIndex;
} ZPS_tsAplZdpRecoverSourceBindReq;
```

where `u16StartIndex`is the binding table index of the first entry to be recovered.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

