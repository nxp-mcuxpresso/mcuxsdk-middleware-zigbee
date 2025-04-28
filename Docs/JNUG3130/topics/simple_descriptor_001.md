# Simple descriptor

There is a Simple descriptor for each endpoint on a node. The information in this descriptor includes the ZigBee device type supported by the endpoint as well as details of its input and output clusters. The following functions can be used to obtain a Simple descriptor:

-   **zps\_eAplAfGetSimpleDescriptor\(\)** obtains the Simple descriptor of a particular endpoint on the local node. The result is stored in a structure of type `zps_tsAplAfSimpleDescriptor`.
-   **zps\_eAplZdpSimpleDescRequest\(\)** requests the Simple descriptor of a particular endpoint on a remote node. The result is stored in a structure of type `zps_tsAplZdpSimpleDescReq`.

The returned Simple descriptor includes a list of input clusters and a list of output clusters of the endpoint.

When requesting a Simple descriptor from a remote node, if the cluster lists are long, the Simple descriptor may not fit into the APDU of the response. In this case, the returned Simple descriptor will contain incomplete cluster lists, but the remainder of the lists can be recovered using **zps\_eAplZdpExtendedSimpleDescRequest\(\)**.

It is also possible to search for nodes on the basis of certain criteria in the Simple descriptors of their endpoints - for example, search for endpoints which have a particular list of input clusters and/or output clusters. Such a search can be performed using the function **zps\_eAplZdpMatchDescRequest\(\)**. Use of this function is described in [Section 6.2.2](finding_compatible_endpoints.md).

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

