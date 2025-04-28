# Description

This function submits a request to send data to all network nodes that conform to the specified broadcast mode. You must specify the local endpoint and output cluster from which the data originates \(the cluster must be in the Simple descriptor for the endpoint\), as well as the destination endpoint\(s\) on the remote nodes.

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, this function call fails \(and return ZPS\_E\_ADSU\_TOO\_LONG\).

Following this function call, the APDU may be broadcast up to four times by the source node \(in addition, the APDU may be subsequently re-broadcast up to four times by each intermediate routing node\). If the transmission is successful, the event ZPS\_EVENT\_APS\_DATA\_CONFIRM is generated on the local node.

Security \(encyption/decryption\) can be applied to the APDU, where this security can be implemented at the Application layer or the network \(ZigBee\) layer, or both.

**Parent topic:**[ZPS\_eAplAfBroadcastDataReq](../topics/zps_eaplafbroadcastdatareq.md)

