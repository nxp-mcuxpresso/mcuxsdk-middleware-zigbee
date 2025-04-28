# Description

This function submits a request to send data to all nodes/endpoints to which the source node/endpoint has been previously bound \(using the binding functions, described in [Section 9.1.3](binding_functions.md)\) and requires an acknowledgment to be returned by the remote node\(s\) once the data reaches its destination\(s\). You must specify the local endpoint and output cluster from which the data originates \(the cluster must be in the Simple descriptor for the endpoint\).

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, the APDU can be broken up into fragments \(NPDUs\) for transmission. To enable this fragmentation, set the ZigBee network parameter *Maximum Number of Transmitted Simultaneous Fragmented Messages* to a non-zero value.

Once the sent data reaches its final destination node\(s\), a ZPS\_EVENT\_BIND\_REQUEST\_SERVER event is generated on the local node. This event reports the status of the bound transmission, including the number of bound endpoints for which the transmission has failed.

Security \(encyption/decryption\) can be applied to the APDU, where this security can be implemented at the Application layer or the network \(ZigBee\) layer, or both.

**Parent topic:**[ZPS\_eAplAfBoundAckDataReq](../topics/zps_eaplafboundackdatareq.md)

