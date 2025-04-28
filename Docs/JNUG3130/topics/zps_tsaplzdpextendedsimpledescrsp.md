# ZPS\_tsAplZdpExtendedSimpleDescRsp

This structure is used to store Extended\_Simple\_Desc\_rsp message data - a response to a call to the function **ZPS\_eAplZdpExtendedSimpleDescRequest\(\)**. This response contains a cluster list \(combined input and output\) for a given endpoint on the node with a given network address.

The `ZPS_tsAplZdpExtendedSimpleDescRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16NwkAddr;
    uint8 u8EndPoint;
    uint8 u8AppInputClusterCount;
    uint8 u8AppOutputClusterCount;
    uint8 u8StartIndex;
    /* Rest of the message is variable length */
    uint16* pAppClusterList;
} ZPS_tsAplZdpExtendedSimpleDescRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpExtendedSimpleDescRequest\(\)**

-   `u16NwkAddr`is the network address of the remote node that sent the response \(this is the network address that was specified in the request\)
-   `u8EndPoint`is the number of the endpoint for which the response was sent \(this is the endpoint number that was specified in the request\)
-   `u8AppInputClusterCount`is the total number of input clusters in the endpoint’s complete input cluster list
-   `u8AppOutputClusterCount`is the total number of output clusters in the endpoint’s complete output cluster list
-   `u8StartIndex`is the index, in the endpoint’s complete input or output cluster list, of the first cluster reported in this response
-   `pAppClusterList`is a pointer to the reported cluster list, input clusters first then output clusters. This is only included if `u8Status`reports success

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

