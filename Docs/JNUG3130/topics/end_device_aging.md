# End device aging

A Router that is a parent needs to maintain its Neighbor table. This involves discarding inactive children \(that may have left the network\) in order to make way for potential new children. An End Device Aging mechanism is available to support this maintenance.

In this mechanism, a timeout is applied to every child entry in the Router’s Neighbor table. If a packet, called a ‘keep-alive’ packet, is not received from an End Device child before its timeout expires, the child is assumed to be no longer active and is removed from the table \(and therefore from the Router’s children\).


```{include} ../topics/timeout_period.md
:heading-offset: 3
```

```{include} ../topics/keep-alive_packets.md
:heading-offset: 3
```

**Parent topic:**[Advanced features](../topics/advanced_features.md)

