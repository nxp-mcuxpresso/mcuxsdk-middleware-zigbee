# ZPS\_tsAplZdpNodeDescRsp

This structure is used to store Node\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpNodeDescRequest\(\)**. This response contains the Node descriptor of the node with a given network address.

The `ZPS_tsAplZdpNodeDescRsp`structure is detailed below.

```
typedef struct {
    uint8     u8Status;
    uint16    u16NwkAddrOfInterest;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpNodeDescriptor tsNodeDescriptor;
} ZPS_tsAplZdpNodeDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpNodeDescRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `tsNodeDescriptor`is the returned Node descriptor, a structure of type `ZPS_tsAplZdpNodeDescriptor`\(detailed in [Section 9.2.1.1](zps_tsaplzdpnodedescriptor.md)\). This is only included if `u8Status`reports success.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

