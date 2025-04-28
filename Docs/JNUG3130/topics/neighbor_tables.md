# Neighbor tables

A routing node \(Router or Coordinator\) holds information about its neighboring nodes. This information is stored in a Neighbor table containing entries for the node’s immediate children, for its own parent and, in a Mesh network, for all peer Routers with which the node has direct radio communication.

It is possible to define the maximum number of entries in a Neighbor table. If this parameter is set to a low value, it will result in a ‘long, thin network’.

The structure and configuration of a Neighbor table are described in [Appendix B.5.1](neighbor_table.md).

**Parent topic:**[Network level concepts](../topics/network_level_concepts.md)

