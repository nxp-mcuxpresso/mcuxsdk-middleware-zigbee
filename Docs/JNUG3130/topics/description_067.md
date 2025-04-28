# Description

This function submits a request to send data to one or more nodes in another ZigBee PRO network - that is, to implement an inter-PAN transmission. The destination for the data is specified in a structure \(detailed in [Section 8.2.3.3](zps_tsinterpanaddress.md)\) which contains:

-   PAN ID of destination network \(a broadcast to all reachable ZigBee PRO networks can also be configured\)
-   Address of destination node \(this can be an IEEE/MAC or network address for a single node, a group address for multiple nodes or a broadcast address for all nodes\).

The data is sent in an Application Protocol Data Unit \(APDU\) instance, which can be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)** and then written to using **PDUM\_u16APduInstanceWriteNBO\(\)**.

If the APDU size is larger than the maximum packet size allowed on the local network, this function call fails \(and returns ZPS\_E\_ADSU\_TOO\_LONG\).

Once the sent data reaches the first hop node in the route to its destination, a ZPS\_EVENT\_APS\_INTERPAN\_DATA\_CONFIRM event is generated on the local node. In case of a broadcast or group multicast, this event is simply generated once the data has been sent from the local node.

Security \(encyption/decryption\) cannot be applied to inter-PAN transmissions.

**Parent topic:**[ZPS\_eAplAfInterPanDataReq](../topics/zps_eaplafinterpandatareq.md)

