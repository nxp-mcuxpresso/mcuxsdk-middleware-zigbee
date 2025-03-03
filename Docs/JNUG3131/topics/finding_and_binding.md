# Finding and Binding

Finding and Binding mode allows a node in the network to pair with another network node - for example, a new lamp may pair with a controller device, to allow control of the lamp. The objective of this commissioning mode is to bind an endpoint on a new node to a compatible endpoint on a remote node in the network \(depending on the supported clusters\). Alternatively, the new node is added to a group of nodes that are collectively controlled.

If it is required on a node, enable Finding and Binding via the attribute *u8bdbCommissioningMode*.

In Finding and Binding, a node have one of two roles:

-   **Initiator:** This node either creates a \(local\) binding with a remote endpoint or requests that the remote endpoint is added to a group.

-   **Target:** This node identifies itself, and receives and responds to requests from the initiator.


The intended outcome is a pairing between the initiator and the target. Usually, the initiator is a controller device. The path followed by the Finding and Binding process depends on whether the local endpoint is an initiator or a target.


```{include} ../topics/initiator_node.md
:heading-offset: 3
```

```{include} ../topics/target_node.md
:heading-offset: 3
```

**Parent topic:**[Network commissioning](../topics/network_commissioning.md)

