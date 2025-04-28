# Accessing binding tables

Information about established bindings is held in Binding tables on the relevant nodes. Normally, a Binding table is held on a node which contains at least one source endpoint for a binding - thus, the table includes entries for all bindings which involve source endpoints on the local node. Alternatively, the Binding table entries for a particular source node can be held in a primary Binding table cache on the node’s parent or another ascendant node. However, if a primary Binding table cache exists on an ascendant node, a source node can opt out of membership of this table by calling the function **zps\_eAplZdpBindRegisterRequest\(\)** to indicate that the source node will store its own Binding table entries locally.

Functions are provided which allow Binding tables to be remotely accessed and modified. These functions are particularly useful in implementing a commissioning tool application.

A binding can be remotely created or removed by requesting a modification to the relevant Binding table on a remote node. The remote Binding table may be a primary Binding table cache or the source node’s local Binding table, which is relevant for the particular binding.

-   The function **zps\_eAplZdpBindUnbindRequest\(\)** can be used to request that a new binding is added to a remote Binding table. The addition of this binding is signaled by a zps\_EVENT\_ZDO\_BIND event on the remote node.
-   The function **zps\_eAplZdpBindUnbindRequest\(\)** can also be used to request that an existing binding is removed from a remote Binding table. The removal of this binding is signaled by a zps\_EVENT\_ZDO\_UNBIND event on the remote node. A Binding table entry can also be removed locally using the function **zps\_eAplAibRemoveBindTableEntryForMacAddress\(\)**, which requests that the entry containing a particular IEEE/MAC address is deleted.

In addition, binding entries in a remote primary Binding table cache can be modified using the function **zps\_eAplZdpReplaceDeviceRequest\(\)**, to replace an IEEE/MAC address and/or endpoint number. This operation works on a ‘search and replace’ basis in the Binding table, and the address/endpoint number to be replaced could occur in the source or destination of one or more table entries.

The function **zps\_eAplZdpMgmtBindRequest\(\)** is also provided, which can be used to request the Binding table of a remote node.

**Parent topic:**[Binding](../topics/binding_001.md)

