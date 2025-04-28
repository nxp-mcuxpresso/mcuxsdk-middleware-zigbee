# Description

This function submits a request to send data to a remote node \(unicast\), using the remote node’s IEEE \(MAC\) address. The function also requires an acknowledgment to be returned by the remote node once the data reaches its destination. You must specify the local endpoint and output cluster from which the data originates \(the cluster must be in the Simple descriptor for the endpoint\), as well as the IEEE address of the remote node and the destination endpoint on the node.

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, the APDU can be broken up into fragments \(NPDUs\) for transmission. To enable this fragmentation, users should set the ZigBee network parameter *Maximum Number of Transmitted Simultaneous Fragmented Messages*to a non-zero value.

If data is sent using this function to a destination for which a route has not already been established, the data is not sent and a route discovery is performed instead. In this case, the function returns ZPS\_NWK\_ENUM\_ROUTE\_ERROR and must later be re-called to send the data \(see Note under [Section 6.5.1.1, "Unicast”](unicast.md)\).

Once the sent data has reached the first hop node in the route to its destination, a ZPS\_EVENT\_APS\_DATA\_CONFIRM event will be generated on the local node. Then, once an acknowledgment has been received from the destination node, a ZPS\_EVENT\_APS\_DATA\_ACK is generated on the sending node.

Security \(encyption/decryption\) can be applied to the APDU, where this security can be implemented at the Application layer or the network \(ZigBee\) layer, or both.

**Parent topic:**[ZPS\_eAplAfUnicastIeeeAckDataReq](../topics/zps_eaplafunicastieeeackdatareq.md)

