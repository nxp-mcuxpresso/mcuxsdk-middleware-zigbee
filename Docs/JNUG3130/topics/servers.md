# Servers

A node can host one or more of the following ‘servers’ in a ZigBee PRO network:

-   Primary Trust Centre
-   Backup Trust Centre
-   Primary Binding Table Cache
-   Backup Binding Table Cache
-   Primary Discovery Cache
-   Backup Discovery Cache
-   Network Manager

The function **zps\_eAplZdpSystemServerDiscoveryRequest\(\)** can be used to discover the servers hosted by other nodes in the network. The function broadcasts a System\_Server\_Discovery\_req request to all nodes. A remote node replies with a System\_Server\_Discovery\_rsp response containing a bitmap indicating the servers hosted by the node.

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

