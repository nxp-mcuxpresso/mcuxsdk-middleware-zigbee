# ZPS\_tsAplZdpComplexDescRsp

This structure is used to store Complex\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpComplexDescRequest\(\)**. This response contains the Complex descriptor of the node with a given network address.

The `ZPS_tsAplZdpComplexDescRsp`structure is detailed below.

```
typedef struct {
        uint8 u8Status;
        uint16 u16NwkAddrOfInterest;
        uint8 u8Length;
        /* Rest of the message is variable Length */
        ZPS_tsAplZdpComplexDescElement sComplexDescriptor;
} ZPS_tsAplZdpComplexDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpComplexDescRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8Length`is the length of the returned Complex descriptor, in bytes.
-   `sComplexDescriptor`is the returned Complex descriptor, a structure of type. `ZPS_tsAplZdpComplexDescRsp`\(described below\). This is only included if `u8Status`reports success .


```{include} ../topics/zps_tsaplzdpcomplexdescelement.md
:heading-offset: 4
```

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

