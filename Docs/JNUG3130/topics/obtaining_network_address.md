# Obtaining network address

You may wish to obtain the network address of the node with a given IEEE address - for example, in order to know the network address that has been dynamically allocated to a particular physical node.

The network address of the local node can be obtained simply by calling the function**zps\_u16AplZdoGetNwkAddr\(\)**.

The network address of a remote node can be obtained in either of two ways, depending on whether an entry for the node exists in the local Address Map table:

-   **zps\_u16AplZdoLookupAddr\(\)** can be used to search the local Address Map table for the network address which corresponds to a given IEEE address.
-   The required network address can be obtained directly from within the network by using the function **zps\_eAplZdpNwkAddrRequest\(\)** to submit a request for the network address of the node with a particular IEEE address. This request can be either unicast or broadcast, as follows:
    -   Unicast to another node that will ‘know’ the required network address \(this may be the parent of the node of interest or the Coordinator\)
    -   Broadcast to the network

This request, of type NWK\_addr\_req, is sent in an APDU \(Application Protocol Data Unit\) which must first be allocated using the PDUM function **PDUM\_hAPduAllocateAPduInstance\(\)**. The request details are specified through the structure `zps_tsAplZdpNwkAddrReq`, which includes an option to also request the network addresses of all the target node’s children \(if any\). The results are reported in a NWK\_addr\_resp response.

**Parent topic:**[Obtaining and maintaining node addresses](../topics/obtaining_and_maintaining_node_addresses.md)

