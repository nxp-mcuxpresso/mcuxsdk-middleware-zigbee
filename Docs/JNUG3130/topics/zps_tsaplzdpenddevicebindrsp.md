# ZPS\_tsAplZdpEndDeviceBindRsp

This structure is used to store End\_Device\_Bind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpEndDeviceBindRequest\(\)**. This response is issued by the Coordinator to indicate the status of an End Device binding request.

The `ZPS_tsAplZdpEndDeviceBindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpEndDeviceBindRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpEndDeviceBindRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

