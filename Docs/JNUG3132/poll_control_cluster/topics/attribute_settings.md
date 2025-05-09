# Attribute Settings

In assigning user-defined values to the mandatory attributes, the following inequality should be obeyed:

`u32CheckinInterval` ≥ `u32LongPollInterval` ≥ `u16ShortPollInterval`

In addition, the mandatory attribute `u16FastPollTimeout` should not be set to an excessive value for self-powered nodes, as fast poll mode can rapidly drain the stored energy of a node \(for example, the battery\).

The three optional attributes can be used to ensure that the values of the corresponding mandatory attributes are kept within reasonable limits, to prevent the rapid depletion of the energy resources of the node. If required, the optional attributes must be enabled and initialized in the compile-time options \(see [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

Minimum and maximum values for all the mandatory attributes can alternatively be set using the compile-time options \(again, refer to [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed)\).

**Parent topic:**[Poll Control Cluster](../../poll_control_cluster/topics/poll_control_cluster.md)

