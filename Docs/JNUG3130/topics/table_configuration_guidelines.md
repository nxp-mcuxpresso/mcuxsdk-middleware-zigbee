# Table configuration guidelines

This section provides guidelines on configuring various tables used by the ZigBee PRO stack. These tables can be configured through ZigBee network parameters in the ZPS Configuration Editor. The tables are sized, by default, to support a network of up to 250 nodes. The table sizes can be increased to support more nodes, but this will be at the expense of RAM and/or Flash usage.

The tables and their configuration are individually described in the sections below, which reference to the ZigBee network parameters used to configure the table sizes \(the network parameters are detailed in [Chapter 12](zigbee_network_parameters.md)\).


```{include} ../topics/neighbor_table.md
:heading-offset: 2
```

```{include} ../topics/address_map_table.md
:heading-offset: 2
```

```{include} ../topics/mac_address_table.md
:heading-offset: 2
```

```{include} ../topics/routing_table.md
:heading-offset: 2
```

```{include} ../topics/broadcast_transaction_table.md
:heading-offset: 2
```

```{include} ../topics/route_discovery_table.md
:heading-offset: 2
```

```{include} ../topics/discovery_table.md
:heading-offset: 2
```

```{include} ../topics/route_record_table.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

