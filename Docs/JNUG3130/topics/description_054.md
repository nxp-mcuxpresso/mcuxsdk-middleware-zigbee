# Description

This function requests responses from network nodes with endpoints that match specified criteria in their Simple descriptors. More specifically, these criteria include: application profile, number of input clusters, number of output clusters, list of input clusters, and list of output clusters. The function sends out a Match\_Desc\_req command, as a broadcast to all network nodes. It might also be sent as a unicast to either a specific node of interest or to another node that may hold the required information in its primary discovery cache. The wildcard profile \(0xFFFF\) can be used to match any profile ID.

The request is represented by the structure below \(further detailed in [Section 9](zps_tsaplzdpmatchdescreq.md)[.2.2.10](zps_tsaplzdpmatchdescreq.md)\).

```
typedef struct {
    uint16 u16NwkAddrOfInterest;
    uint16 u16ProfileId;
    /* rest of message is variable length */
    uint8 u8NumInClusters;
    uint16* pu16InClusterList;
    uint8 u8NumOutClusters;
    uint16* pu16OutClusterList;
} ZPS_tsAplZdpMatchDescReq;
```

A node with matching endpoint criteria responds with a Match\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMatchDescRsp`\(detailed in [Section](zps_tsaplzdpmatchdescrsp.md)[9.2.3.9](zps_tsaplzdpmatchdescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMatchDescRequest](../topics/zps_eaplzdpmatchdescrequest.md)

