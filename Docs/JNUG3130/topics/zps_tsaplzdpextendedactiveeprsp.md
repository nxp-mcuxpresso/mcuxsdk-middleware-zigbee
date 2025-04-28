# ZPS\_tsAplZdpExtendedActiveEpRsp

This structure is used to store Extended\_Active\_EP\_rsp message data - a response to a call to the function **ZPS\_eAplZdpExtendedActiveEpRequest\(\)**. This response contains a list of the active endpoints on the node with a given network address.

The `ZPS_tsAplZdpExtendedActiveEpRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddr;
    uint8 u8ActiveEpCount;
    uint8 u8StartIndex;
    /* Rest of the message is variable Length */
    uint8* pActiveEpList;
} ZPS_tsAplZdpExtendedActiveEpRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpExtendedActiveEpRequest\(\)**.
-   `16NwkAddr`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\).
-   `u8ActiveEpCount`is the total number of active endpoints on the node.
-   `u8StartIndex`is the index, in the node’s list of active endpoints, of the first endpoint reported in this response.
-   `pActiveEpList`is a pointer to the reported list of active endpoints \(starting with the endpoint with index `u8StartIndex`\).

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

