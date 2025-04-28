# Active endpoints

An endpoint on the local node can be configured as enabled or disabled using the function **zps\_eAplAfSetEndpointState\(\)**. An enabled endpoint is described as ‘active’. The current state of a local endpoint can be obtained using the function **zps\_eAplAfGetEndpointState\(\)**.

It is also possible to configure whether a local endpoint will be included in the results of network discovery operations, for example, when **zps\_eAplZdpMatchDescRequest\(\)**is called. The ‘discoverable’ state of a local endpoint can be set using the function **zps\_eAplAfSetEndpointDiscovery\(\)**, while this state can be obtained using the function **zps\_eAplAfGetEndpointDiscovery\(\)**.

A list of the active endpoints on a remote can be obtain using the function **zps\_eAplZdpActiveEpRequest\(\)**. This functions submits an Active\_EP\_req request to the target node, which replies with an Active\_EP\_rsp response. If the active endpoint list is too long to fit into the APDU of the response, the returned list will be incomplete. However, the remainder of the list can be recovered using the function **zps\_eAplZdpExtendedActiveEpRequest\(\)**. Note that an endpoint is included in the list only if it is active and discoverable.

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

