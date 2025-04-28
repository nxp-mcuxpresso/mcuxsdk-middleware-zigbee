# Description

This function submits a request to send data to a remote node \(unicast\), using the remote node’s IEEE \(MAC\) address. You must specify the local endpoint and output cluster from which the data originates \(the cluster must be in the Simple descriptor for the endpoint\), as well as the IEEE address of the remote node and the destination endpoint on the node.

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the network, this function call will fail \(and return ZPS\_E\_ADSU\_TOO\_LONG\). To send large APDUs, use the function **ZPS\_eAplAfUnicastIeeeAckDataReq\(\)**, which automatically implements data fragmentation \(if required\).

Once the sent data has reached the first hop node in the route to its destination, a ZPS\_EVENT\_APS\_DATA\_CONFIRM event is generated on the local node.

If users try to send data using this function to a destination for which a route has not already been established, the data is not sent. Instead, a route discovery is performed. In this case, the function returns ZPS\_NWK\_ENUM\_ROUTE\_ERROR and must later be re-called to send the data \(see Note under [Section 6.5.1.1, "Unicast”](unicast.md)\).

Security \(encryption/decryption\) can be applied to the APDU, where this security can be implemented at the Application layer or the network \(ZigBee\) layer, or both.

**Parent topic:**[ZPS\_eAplAfUnicastIeeeDataReq](../topics/zps_eaplafunicastieeedatareq.md)

