# Description

This function can be used to configure the User descriptor on a remote node. The function sends a User\_Desc\_set request either to the remote node or to another node that may hold the relevant User descriptor in its primary discovery cache.

**Note:** This function can only be used to access the User descriptor of a non-NXP device \(which supports this descriptor\), since the storage of a User descriptor on an NXP device is not supported.

The network address of the node of interest as well as the required modifications must be specified in the request, which is represented by the structure below \(further detailed in [Section 9.2.2.13](zps_tsaplzdpuserdescset.md)\).

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint8 u8Length;`

`char szUserDescriptor[ZPS_ZDP_LENGTH_OF_USER_DESC];`

`} ZPS_tsAplZdpUserDescSet;`

If the specified User descriptor was successfully modified, a User\_Desc\_conf response is received. This response should be collected by the application task using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpUserDescConf`\(detailed in [Section 9.2.3.12](zps_tsaplzdpuserdescconf.md)\).

**Parent topic:**[ZPS\_eAplZdpUserDescSetRequest](../topics/zps_eaplzdpuserdescsetrequest.md)

