# ZPS\_tsAplZdpUserDescRsp

This structure is used to store User\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpUserDescRequest\(\)**. This response contains the User descriptor of the node with a given network address.

The `ZPS_tsAplZdpUserDescRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddrOfInterest;
    uint8 u8Length;
    /* Rest of the message is variable Length */
    char szUserDescriptor[ZPS_ZDP_LENGTH_OF_USER_DESC];
} ZPS_tsAplZdpUserDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpUserDescRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8Length`is the length of the returned User descriptor, in bytes \(maximum: 16\).
-   `szUserDescriptor`is the returned User descriptor as a character array. This is only included if `u8Status`reports success.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

