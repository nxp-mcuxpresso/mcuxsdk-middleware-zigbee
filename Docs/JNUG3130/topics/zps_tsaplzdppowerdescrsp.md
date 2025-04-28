# ZPS\_tsAplZdpPowerDescRsp

This structure is used to store Power\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpPowerDescRequest\(\)**. This response contains the Power descriptor of the node with a given network address.

The `ZPS_tsAplZdpPowerDescRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddrOfInterest;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpNodePowerDescriptor sPowerDescriptor;
} ZPS_tsAplZdpPowerDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpPowerDescRequest\(\)**
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\)
-   `sPowerDescriptor`is the returned Power descriptor, a structure of type `ZPS_tsAplZdpNodePowerDescriptor`\(detailed in [Section 9.2.1.2](zps_tsaplzdpnodepowerdescriptor.md)\). This is only included if `u8Status`reports success

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

