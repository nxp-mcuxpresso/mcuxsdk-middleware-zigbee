# Route Record table

The Route Record table is only relevant to a device, which will be the concentrator in a network, if many-to-one routing is implemented. This table replaces the Routing table in the node.

-   The size of the Route Record table can be set through the parameter *Route Record Table Size*.
-   In the concentrator node, this table size should be set to the size of the network. Since this table then replaces the Routing table in the node, the Routing table size should be set to 1 \(see [Appendix B.5.4](routing_table.md)\).
-   In all other network nodes, the size of the Route Record table should be set to 1.

**Parent topic:**[Table configuration guidelines](../topics/table_configuration_guidelines.md)

