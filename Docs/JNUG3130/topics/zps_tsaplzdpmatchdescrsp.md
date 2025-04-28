# ZPS\_tsAplZdpMatchDescRsp

This structure is used to store Match\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpMatchDescRequest\(\)**. This response contains details of the endpoints on the remote node that matched the criteria specified in the original request.

The `ZPS_tsAplZdpMatchDescRsp`structure is detailed below.

```
typedef struct {
        uint8 u8Status;
        uint16 u16NwkAddrOfInterest;
        uint8 u8MatchLength;
        /* Rest of message is variable length */
        uint8* u8MatchList;
} ZPS_tsAplZdpMatchDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMatchDescRequest\(\)**.
-   `u16NwkAddrOfInterest`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8MatchLength`is the length of the list of matched endpoints, in bytes.
-   `u8MatchList`is a pointer to the list of matched endpoints, where each endpoint is represented by an 8-bit value \(in the range 1-240\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

