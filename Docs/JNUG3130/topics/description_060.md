# Description

This function submits a request to send data to a remote node, with no restrictions on the type of transmission, destination address, destination application profile, destination cluster and destination endpoint number - these destination parameters do not need to be known to the stack or defined in the ZPS configuration. In this sense, this is most general of the Data Transfer functions.

The destination details and type of transmission are specified in the function call in a `ZPS_tsAfProfileDataReq`structure \(see [Section 8.2.3.4](zps_tsafprofiledatareq.md)\).

The data is sent in an Application Protocol Data Unit \(APDU\) instance. This instance can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, this function call fails \(and returns `ZPS_E_ADSU_TOO_LONG`\). To send large APDUs, use the function **ZPS\_eAplAfUnicastAckDataReq\(\)**, which automatically implements data fragmentation \(if required\).

Once the sent data has reached the first hop node in the route to its destination, a `ZPS_EVENT_APS_DATA_CONFIRM` event is generated on the local node.

**Parent topic:**[ZPS\_eAplAfApsdeDataReq](../topics/zps_eaplafapsdedatareq.md)

