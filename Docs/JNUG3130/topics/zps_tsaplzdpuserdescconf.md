# ZPS\_tsAplZdpUserDescConf

This structure is used to store User\_Desc\_conf message data - a response to a call to the function **ZPS\_eAplZdpUserDescSetRequest\(\)**. This response contains a confirmation of the requested configuration of the User descriptor on a given network node.

The `ZPS_tsAplZdpUserDescConf`structure is detailed below.

```
typedef struct {
        uint8 u8Status;
        uint16 u16NwkAddrOfInterest;
} ZPS_tsAplZdpUserDescConf;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpUserDescSetRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

