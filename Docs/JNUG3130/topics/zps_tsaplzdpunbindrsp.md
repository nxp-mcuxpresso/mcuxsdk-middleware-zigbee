# ZPS\_tsAplZdpUnbindRsp

This structure is used to store Unbind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpBindUnbindRequest\(\)**. This response indicates the status of an unbinding request \(a request to modify of a binding table\).

The `ZPS_tsAplZdpUnbindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpUnbindRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpBindUnbindRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

