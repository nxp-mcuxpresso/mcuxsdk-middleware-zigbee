# Description

This function requests the User descriptor of the node with a particular network address. The function sends a User\_Desc\_req request either to the relevant node or to another node that may hold the required information in its primary discovery cache.

**Note:** This function can only be used to access the User descriptor of a non-NXP device \(which supports this descriptor\), since the storage of a User descriptor on an NXP remove device is not supported.

The network address of the node of interest must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.9](zps_tsaplzdpuserdescreq.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest;`

`} ZPS_tsAplZdpUserDescReq;`

The required User descriptor will be received in a User\_Desc\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpUserDescRsp`\(detailed in [Section 9.2.3.8](zps_tsaplzdpuserdescrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpUserDescRequest](../topics/zps_eaplzdpuserdescrequest.md)

