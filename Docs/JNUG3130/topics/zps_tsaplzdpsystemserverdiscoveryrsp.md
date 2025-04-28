# ZPS\_tsAplZdpSystemServerDiscoveryRsp

This structure is used to store System\_Server\_Discovery\_rsp message data - a response to a call to the function **ZPS\_eAplZdpSystemServerDiscoveryRequest\(\)**. This response indicates which of the requested services are supported by a given network node.

The `ZPS_tsAplZdpSystemServerDiscoveryRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16ServerMask;
} ZPS_tsAplZdpSystemServerDiscoveryRsp;
```

where:

-   `u8Status`is the return status for the function **ZPS\_eAplZdpSystemServerDiscoveryRequest\(\)**.
-   `u16ServerMask`is the returned bitmask that summarizes the requested services supported by the node \(1 for ‘supported’, 0 for ‘not supported’ or ‘not requested’\). This bitmask is detailed in the table below.

**Services Bitmask**

| **Bit** | **Service** |
|-----|-----------|
|0|Primary Trust Centre|
|1|Backup Trust Centre|
|2|Primary Binding Table Cache|
|3|Backup Binding Table Cache|
|4|Primary Discovery Cache|
|5|Back-up Discovery Cache|
|6|Network Manager|
|7-15|Reserved|


**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

