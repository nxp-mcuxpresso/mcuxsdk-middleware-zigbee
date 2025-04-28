# Description

This function can be used to request information on the available servers hosted by remote nodes \(Primary or Backup Trust Centre, Primary or Backup Binding Table Cache, Primary or Backup Discovery Cache, Network Manager\). The function broadcasts a System\_Server\_Discovery\_req request to all network nodes.

The required servers must be specified by means of a bitmask in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.14](zps_tsaplzdpsystemserverdiscoveryreq.md)\).

`typedef struct {`

`uint16 u16ServerMask;`

`} ZPS_tsAplZdpSystemServerDiscoveryReq;`

A remote node replies with a System\_Server\_Discovery\_rsp response, indicating which of the requested servers are implemented. This response should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpSystemServerDiscoveryRsp`\(detailed in [Section 9.2.3.13](zps_tsaplzdpsystemserverdiscoveryrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpSystemServerDiscoveryRequest](../topics/zps_eaplzdpsystemserverdiscoveryrequest.md)

