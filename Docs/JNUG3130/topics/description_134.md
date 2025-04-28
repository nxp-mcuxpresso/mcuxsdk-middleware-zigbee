# Description

This function submits a request to send data to a group of endpoints located on one or more nodes \(group multicast\). Users must specify the local endpoint and output cluster from which the data originates \(the cluster must be in the Simple descriptor for the endpoint\) as well as the ‘group address’ of the group of destination endpoints. A group is set up using the function **ZPS\_eAplZdoGroupEndpointAdd\(\)**. The data is actually broadcast to all network nodes and each recipient node assesses whether it has endpoints in the specified group.

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, this function call fails \(and returns ZPS\_E\_ADSU\_TOO\_LONG\). Once the data is transmitted, a ZPS\_EVENT\_APS\_DATA\_CONFIRM event is generated on the local node.

Security \(encyption/decryption\) can be applied to the APDU, where this security can be implemented at the Application layer or the network \(ZigBee\) layer, or both.

**Parent topic:**[ZPS\_eAplAfGroupDataReq](../topics/zps_eaplafgroupdatareq.md)

