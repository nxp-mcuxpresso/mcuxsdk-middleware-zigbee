# Description

This function obtains the discoverable state of the specified cluster of the specified endpoint on the local node - that is, whether the cluster/endpoint will be included in ‘device discoveries’ initiated on the network.

If the cluster/endpoint is discoverable, it appears in the Simple descriptor of the local node and is also included in match results requested using the function **ZPS\_eAplZdpMatchDescRequest\(\)**.

The initial discoverable state of the cluster/endpoint is pre-set using the ZPS Configuration Editor \(see [Chapter 13](zps_configuration_editor.md)\). The state can subsequently be changed at runtime using the function **ZPS\_eAplAfSetEndpointDiscovery\(\)**.

**Parent topic:**[ZPS\_eAplAfGetEndpointDiscovery](../topics/zps_eaplafgetendpointdiscovery.md)

