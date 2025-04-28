# Description

This function requests that the specified endpoint \(on the local node\) is added to the group with the specified group address. This means that this endpoint will become one of the destinations for messages sent to the given group address.

To form a group comprising endpoints from different nodes, it is necessary to call this function for each endpoint individually, on the endpoint’s local node.

An endpoint can belong to more than one group.

Information on the endpoints in a group can be obtained from the Group Address table in the AIB \(which can be accessed using the function **ZPS\_psAplAibGetAib\(\)**\).

**Note:** In order to add an endpoint to a group using this function, a Group Address table must exist on the local node. This table is created using the ZPS Configuration Editor.

**Parent topic:**[ZPS\_eAplZdoGroupEndpointAdd](../topics/zps_eaplzdogroupendpointadd.md)

