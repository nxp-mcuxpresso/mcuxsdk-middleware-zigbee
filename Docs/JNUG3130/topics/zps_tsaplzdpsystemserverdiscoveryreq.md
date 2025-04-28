# ZPS\_tsAplZdpSystemServerDiscoveryReq

This structure is used by the **ZPS\_eAplZdpSystemServerDiscoveryRequest\(\)** function. It represents a request for information on the available services of a remote node.

The `ZPS_tsAplZdpSystemServerDiscoveryReq`structure is detailed below.

```
typedef struct {
uint16 u16ServerMask;
} ZPS_tsAplZdpSystemServerDiscoveryReq;
```

where `u16ServerMask`is a bitmask representing the required services \(1 for ‘required’, 0 for ‘not required’\). This bitmask is detailed in the table below.

**Services Bitmask**

|**Bit**|**Service**|
|--|--|
|0|Primary Trust Centre|
|1|Backup Trust Centre|
|2|Primary Binding Table Cache|
|3|Backup Binding Table Cache|
|4|Primary Discovery Cache|
|5|Back-up Discovery Cache|
|6|Network Manager|
|7-15|Reserved|

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

