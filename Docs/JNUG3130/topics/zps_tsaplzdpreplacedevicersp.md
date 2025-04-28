# ZPS\_tsAplZdpReplaceDeviceRsp

This structure is used to store Replace\_Device\_rsp message data - a response to a call to the function **ZPS\_eAplZdpReplaceDeviceRequest\(\)**. This response indicates the status of the replace request.

The `ZPS_tsAplZdpReplaceDeviceRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpReplaceDeviceRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpReplaceDeviceRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

