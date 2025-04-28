# ZPS\_tsAplZdpBindRsp

This structure is used to store Bind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpBindUnbindRequest\(\)**. This response indicates the status of a binding request \(a request to modify of a binding table\).

The `ZPS_tsAplZdpBindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpBindRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpBindUnbindRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

