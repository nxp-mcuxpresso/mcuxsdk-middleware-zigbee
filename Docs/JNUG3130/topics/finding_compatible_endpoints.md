# Finding compatible endpoints

An endpoint on a newly joined node must find compatible endpoints on remote nodes with which to communicate. The decision of whether a remote endpoint is compatible is based on the endpoint properties stored in its Simple descriptor, notably the input/ output clusters supported.

The endpoint application can discover compatible nodes by sending out a Match\_Desc\_req request identifying the required clusters. This request is submitted by calling the function **zps\_eAplZdpMatchDescRequest\(\)**, which allows the request to be sent as a broadcast to all nodes or as a unicast to a particular node \(the sending node may already have a record of the network nodes and their addresses, as each node automatically announces itself in a broadcast when it joins the network\). The

request is sent in an APDU \(Application Protocol Data Unit\) which must first be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)**.

A receiving endpoint which satisfies the supplied criteria replies to the request with a Match\_Desc\_rsp response which, when received, must be collected on the requesting node using the function **ZQ\_bZQueueReceive\(\)**. The requesting application may bind to a compatible endpoint \(see [Section 5.4](binding_001.md)\) and communicate with the endpoint using binding or addressing \(see [Section 5.5](transferring_data.md)\).

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

