# Primary discovery cache

A ZigBee routing node \(Router or the Coordinator\) may be able to host a ‘primary discovery cache’. This is a database, held in memory, containing ‘discovery information’ about a set of network nodes, normally children and possibly other descendant nodes. The information held about a node includes the node’s addresses, descriptors \(Node, Node Power, Simple\) and its list of active endpoints. Remote nodes can then interrogate the primary discovery cache to obtain information about other nodes in the network.

**Note:** NXP nodes do not have the capability to hold a primary discovery cache, but functions are provided to interface with a primary discovery cache held on a node from another manufacturer.

The function **zps\_eAplZdpDiscoveryCacheRequest\(\)** allows nodes which hold a primary discovery cache to be detected. This function submits a Discovery\_Cache\_req request to the network. Nodes with a primary discovery cache reply with a Discovery\_Cache\_rsp response.

In addition, the function **zps\_eAplZdpFindNodeCacheRequest\(\)** can be used to search for nodes with a primary discovery cache that holds information about a particular node. This function submits a Find\_node\_cache\_req request to the network. Nodes with the required node information in their caches reply with a Find\_node\_cache\_rsp response.

Functions for storing node information in a primary discovery cache are described in [Section 6.2.5](maintaining_a_primary_discovery_cache.md).

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

