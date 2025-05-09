# Command Discovery

The ZCL provides the facility to discover the commands that a cluster instance on a remote device can receive and generate. This is useful since an individual cluster instance may not be able to receive or generate all of the commands that are theoretically supported by the cluster.

The commands that are supported by a cluster \(and that can therefore potentially be discovered\) are defined in a Command Definition table which is enabled in the cluster definition when Command Discovery is enabled \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\).

Two ZCL functions are provided to implement the Command Discovery feature \(as indicated in [Section 2.9.1](discovering_command_sets.md#id_9cb486e8-2ca1-48f1-81ff-ca8d75d0eeb4) below and fully described in [Section 5.3](../../Core_functions/topics/command_discovery_functions.md#id_6ceaec5d-cba9-40fe-aada-a237a99761cf)\).


```{include} ../../ZCL_fundamentals/topics/discovering_command_sets.md
:heading-offset: 2
```

```{include} ../../ZCL_fundamentals/topics/compile-time_options.md
:heading-offset: 2
```

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

