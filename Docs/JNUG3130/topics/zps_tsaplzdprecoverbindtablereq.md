# ZPS\_tsAplZdpRecoverBindTableReq

This structure is used by the function **ZPS\_eAplZdpRecoverBindTableRequest\(\)**. It represents a request to a remote node to recover a back-up of the local primary binding table cache.

The `ZPS_tsAplZdpRecoverBindTableReq`structure is detailed below.

```
typedef struct {
uint16 u16StartIndex;
} ZPS_tsAplZdpRecoverBindTableReq;
```

where `u16StartIndex`is the binding table index of the first entry to be recovered.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

