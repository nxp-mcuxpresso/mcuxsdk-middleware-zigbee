# Attribute Settings

The Commissioning cluster structure contains only optional attributes. Each attribute is enabled/disabled through a corresponding macro defined in the **zcl\_options.h** file \(see [Section 43.10](compile-time_options.md#id_ff1e5475-70c7-41e3-8ab8-1188b0c7ab78)\) - for example, `u16ShortAddress` is enabled/disabled through the macro CLD\_COMM\_ATTR\_SHORT\_ADDRESS.

The function **eCLD\_CommissioningSetAttribute\(\)** can be used on the cluster server to write values to any one of the four attribute sets of the Commissioning cluster.

**Parent topic:**[Commissioning Cluster](../../Commissioning_cluster/topics/commissioning_cluster.md)

