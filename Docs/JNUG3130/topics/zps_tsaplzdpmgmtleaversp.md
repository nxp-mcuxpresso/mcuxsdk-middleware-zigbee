# ZPS\_tsAplZdpMgmtLeaveRsp

This structure is used to store Mgmt\_Leave\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtLeaveRequest\(\)**. This response is issued by a remote node that has been requested to leave the network.

The `ZPS_tsAplZdpMgmtLeaveRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpMgmtLeaveRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpMgmtLeaveRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

