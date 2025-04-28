# Description

This function can be used to extract data received in a response packet which is destined for the ZDO \(at endpoint 0\). When such a packet is received, the event ZPS\_EVENT\_APS\_DATA\_INDICATION is generated. The application must then check whether the destination endpoint number is 0 in the event and, if this is the case, call this function to extract the response data from the event.

A pointer to a `ZPS_tsAfZdpEvent`structure must be provided, which the function will populate with the extracted data.

**Parent topic:**[ZPS\_bAplZdpUnpackResponse](../topics/zps_baplzdpunpackresponse.md)

