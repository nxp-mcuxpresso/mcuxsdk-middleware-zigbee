# ZPS\_tsAplZdpMgmtPermitJoiningRsp

This structure is used to store Mgmt\_Permit\_Joining\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtPermitJoiningRequest\(\)**. This response is issued by a remote node \(Router or Coordinator\) that has been requested to enable or disable joining for a specified amount of time. The response is only sent if the original request was unicast \(and not if it was broadcast\).

The `ZPS_tsAplZdpMgmtPermitJoiningRsp`structure is detailed below.

```
typedef struct {
     uint8 u8Status;
} ZPS_tsAplZdpMgmtPermitJoiningRsp;
```

where `u8Status`is the return status for the function **ZPS\_eAplZdpMgmtPermitJoiningRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

