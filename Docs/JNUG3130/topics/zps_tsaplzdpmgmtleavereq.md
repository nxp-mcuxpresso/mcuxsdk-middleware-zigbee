# ZPS\_tsAplZdpMgmtLeaveReq

This structure is used by the function **ZPS\_eAplZdpMgmtLeaveRequest\(\)**. It requests a remote node to leave the network.

The `ZPS_tsAplZdpMgmtLeaveReq`structure is detailed below.

```
typedef struct {
    uint64 u64DeviceAddress;
    uint8 u8Flags;
} ZPS_tsAplZdpMgmtLeaveReq;
```

where:

-   `u64DeviceAddress`is the IEEE address of the device being asked to leave the network.
-   `u8Flags`is an 8-bit bitmap containing the following flags:
    -   Rejoin flag \(bit 0\): Set to 1 if the node requested to leave the network should immediately try to rejoin the network, otherwise set to 0.
    -   Remove Children flag \(bit 1\): Set to 1 if the node requested to leave the network should also request its own children \(if any\) to leave the network, otherwise set to 0.
    -   Reserved \(bits 7-2\).

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

