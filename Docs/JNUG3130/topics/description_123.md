# Description

This function requests a remote node to provide a list of neighboring nodes, from its Neighbor table, including LQI \(link quality\) values for radio transmissions from each of these nodes. The destination node of this request must be a Router or the Co- ordinator.

This request must specify the index of the first node in the Neighbor table to report. The request is represented by the structure below \(further detailed in [Section](zps_tsaplzdpmgmtlqireq.md) [8.2.2.34](zps_tsaplzdpmgmtlqireq.md)\).

`typedef struct {`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtLqiReq;`

The remote node replies with a Mgmt\_Lqi\_rsp response containing the required information, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpMgmtLqiRsp`\(detailed in [Section](zps_tsaplzdpmgmtlqirsp.md) [8.2.3.34](zps_tsaplzdpmgmtlqirsp.md)\).

**Parent topic:**[ZPS\_eAplZdpMgmtLqiRequest](../topics/zps_eaplzdpmgmtlqirequest.md)

