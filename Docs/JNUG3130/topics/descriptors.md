# Descriptors

An application may need to obtain information about the nodes of the network in which it runs, as described in [Section 3.4.6](discovery.md). For this, it uses information stored in descriptors in the nodes.

There are three mandatory descriptors and two optional descriptors stored in a node. The mandatory descriptors are the Node, Node Power and Simple descriptors, while the optional descriptors are called the Complex and User descriptors

For each node, there is only one Node and Node Power descriptor, but there is a Simple descriptor for each endpoint. There may also be Complex and User descriptors in the device.

The Node, Node Power and Simple descriptors are outlined below. For full details of the descriptors, refer to [Section 9.2.1](descriptor_structures_001.md).


```{include} ../topics/simple_descriptor.md
:heading-offset: 3
```

```{include} ../topics/node_descriptor.md
:heading-offset: 3
```

```{include} ../topics/node_power_descriptor_001.md
:heading-offset: 3
```

**Parent topic:**[Application level concepts](../topics/application_level_concepts.md)

