# Maintaining a primary discovery cache

Some routing nodes of a ZigBee PRO network may be capable of hosting a primary discovery cache, which contains ‘discovery information’ relating to other nodes in the network - see [Primary Discovery Cache](primary_discovery_cache.md).

**Note:** NXP nodes do not have the capability to hold a primary discovery cache, but functions are provided to interface with a primary discovery cache held on a node from another manufacturer.

Functions are provided for storing the local node’s ‘discovery information’ in another node’s primary discovery cache \(normally in the parent or another ascendant node\). First of all, **zps\_eAplZdpDiscoveryStoreRequest\(\)** must be called to allocate memory space for this information in the remote node’s cache. This function sends a Discovery\_store\_req request to the remote node, which replies with a Discovery\_store\_rsp response. The local node’s information can then be stored in the remote node’s primary discovery cache using the following functions \(which all operate on a request/response basis\):

-   **Node descriptor:** Stored using **zps\_eAplZdpNodeDescStoreRequest\(\)**
-   Power descriptor: Stored using **zps\_eAplZdpPowerDescStoreRequest\(\)**
-   **Simple descriptor:** Stored using **zps\_eAplZdpSimpleDescStoreRequest\(\)**
-   **Active endpoints list:** Stored using **zps\_eAplZdpActiveEpStoreRequest\(\)**

A node’s information can be removed from a primary discovery cache using the function **zps\_eAplZdpRemoveNodeCacheRequest\(\)**. This function can be called on the local node to remove a third node’s information from the primary discovery cache of a remote node.

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

