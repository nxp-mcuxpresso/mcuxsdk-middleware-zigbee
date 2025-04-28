# Description

This function is used on a Router or the Coordinator to send a Parent Announcement message to one or more other nodes. In this announcement, the originating node declares which nodes it has as children. These child nodes are specified using their IEEE/MAC addresses.

The message contains the above data in following structure \(further detailed in [Section 8.2.2.42](zps_tsaplzdpparentanncereq.md)\):

`typedef struct {`

`uint8 u8NumberOfChildren;`

`uint64* pu64ChildList;`

`} ZPS_tsAplZdpParentAnnceReq;`

If a node which receives this message also has one of the specified nodes as its child \(so there is a conflict\), the receiving node broadcasts a response to indicate this. The response data is contained in the structure below \(further detailed in [Section](zps_tsaplzdpparentanncersp.md) [8.2.3.42](zps_tsaplzdpparentanncersp.md)\):

`typedef struct {`

`uint64* pu64ChildList; uint8 u8NumberOfChildren; uint8 u8Status;`

`} ZPS_tsAplZdpParentAnnceRsp;`

**Parent topic:**[ZPS\_eAplZdpParentAnnceReq](../topics/zps_eaplzdpparentanncereq.md)

