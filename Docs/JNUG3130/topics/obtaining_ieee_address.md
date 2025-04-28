# Obtaining IEEE address

You may wish to obtain the IEEE address of the node with a given network address - for example, in order to know which physical node corresponds to a particular dynamically allocated network address.

The IEEE address of the local node can be obtained simply by calling the function **zps\_u64AplZdoGetIeeeAddr\(\)**

The IEEE address of a remote node can be obtained in either of two ways, depending on whether an entry for the node exists in the local Address Map table:

-   The function **zps\_u64AplZdoLookupIeeeAddr\(\)** can be used to search the local Address Map table for the IEEE address which corresponds to a given network address.
-   The required IEEE address can be obtained directly from the remote node by using the function **zps\_eAplZdpIeeeAddrRequest\(\)** to submit a request for the IEEE address of the node with a particular network address. This request, of type IEEE\_addr\_req, is sent in an APDU \(Application Protocol Data Unit\) which must first be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)**. The request details are specified through the structure `zps_tsAplZdpIeeeAddrReq`, which includes an option to also request the IEEE addresses of all the target node’s children \(if any\). The results are reported in an IEEE\_addr\_resp response.

**Parent topic:**[Obtaining and maintaining node addresses](../topics/obtaining_and_maintaining_node_addresses.md)

