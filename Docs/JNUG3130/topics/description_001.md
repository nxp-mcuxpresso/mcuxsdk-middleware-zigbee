# Description

This function is used to notify other nodes that the local node has joined or rejoined the network. The function broadcasts a Device\_annce announcement to the network and is normally automatically called by the ZDO when the local node joins or rejoins the network.

The IEEE \(MAC\) and allocated network addresses as well as the capabilities of the sending node must be specified in the announcement, represented by the structure below \(detailed further in [Section 9.2.2.3](zps_tsaplzdpdeviceanncereq.md)\).

```
typedef struct {
    uint16 u16NwkAddr;
    uint64 u64IeeeAddr;
    uint8 u8Capability;
} ZPS_tsAplZdpDeviceAnnceReq;
```

On receiving this announcement, a network node updates any information it holds that relates to the supplied IEEE and network addresses:

-   If it already holds the supplied IEEE address, it updates the corresponding network address with the supplied one \(if necessary\).
-   If it already holds the supplied network address but with a different corresponding IEEE address, the latter is marked as not having a valid corresponding network address.

**Parent topic:**[ZPS\_eAplZdpDeviceAnnceRequest](../topics/zps_eaplzdpdeviceanncerequest.md)

