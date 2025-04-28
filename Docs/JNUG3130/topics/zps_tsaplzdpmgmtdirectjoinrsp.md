# ZPS\_tsAplZdpMgmtDirectJoinRsp

This structure is used to store Mgmt\_Direct\_Join\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMgmtDirectJoinRequest\(\)**. This response is issued by a remote node \(Router or Coordinator\) that has been requested to allow a particular device to join the network as a child of the node.

The `ZPS_tsAplZdpMgmtDirectJoinRsp`structure is detailed below.

```
typedef struct {
        uint8 u8Status;
} ZPS_tsAplZdpMgmtDirectJoinRsp;
```

where `u8Status`is the return status for **ZPS\_eAplZdpMgmtDirectJoinRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

