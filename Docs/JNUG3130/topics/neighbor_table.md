# Neighbor table

The Neighbor table on a routing node \(Router or Coordinator\) holds information about the node’s immediate neighbors:

-   The first entry in the table contains information about the node’s parent.
-   Part of the table holds information about child nodes which have joined the network through the local device.
-   The rest of the table holds information about nodes which are neither children nor the parent \(these ‘other’ nodes are only relevant to Mesh networks\).

The Neighbor table size is, by default, set to 26 - this is the minimum size required for a ZigBee-Compliant Platform. The table size may be increased through the parameter *Active Neighbor Table Size*to reflect the density of the network. However, increasing the table size uses more RAM. Increasing the Neighbor table size beyond 26 also results in an extra link status packet since one of these packets can accommodate a maximum of 26 neighbors. Thus it doubles the traffic for these periodic packets.

The first two parts of the Neighbor table, for the device’s parent and children, form a sub-table that is persisted in Flash. This sub-table must not occupy more than two-thirds of the Neighbor table. Since this sub-table contains child entries, the size of the sub-table determines the number of children that the device is allowed to have - the maximum number of children is one less than the sub-table size.

The default size for the sub-table is 5, allowing up to 4 child nodes, but the size can be changed through the parameter *Child Table Size* \(which corresponds to the total number of sub-table entries including the parent’s entry, not just the child entries\).

**Note:** Increasing the sub-table size uses more Flash for persisted data.

**Parent topic:**[Table configuration guidelines](../topics/table_configuration_guidelines.md)

