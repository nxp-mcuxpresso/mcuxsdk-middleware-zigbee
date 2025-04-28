# ZPS\_tsAplZdpSimpleDescRsp

This structure is used to store Simple\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpSimpleDescRequest\(\)**. This response contains the Simple descriptor of a given endpoint on the node with a given network address.

The `ZPS_tsAplZdpSimpleDescRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddrOfInterest;
    uint8 u8Length;
    /* Rest of the message is variable length */
    ZPS_tsAplZdpSimpleDescType sSimpleDescriptor;
} ZPS_tsAplZdpSimpleDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpSimpleDescRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8Length`is the length of the returned Simple descriptor, in bytes \(depends on the number of clusters supported by the endpoint\).
-   `sSimpleDescriptor`is the returned Simple descriptor, a structure of type `ZPS_tsAplZdpSimpleDescType`\(detailed in [Section 9.2.1.3](zps_tsaplzdpsimpledesctype.md)\). This is only included if `u8Status`reports success.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

