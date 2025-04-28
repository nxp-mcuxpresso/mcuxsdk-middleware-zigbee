# Filtering packets on LQI Value/Link cost

This section describes the operation and configuration of the filtering of received data packets based on LQI value \(detected signal strength\). Packet filtering results in some received packets with low LQI values being discarded.

In practice, the measured LQI values of packets are translated into ‘link cost’ values for filtering, as detailed in [Section 6.10.3.1](link_cost.md).

Packet filtering is optional and can be beneficial during:

-   network joining
-   route discovery
-   normal network operation

The operation and benefits of packet filtering are described in [Section 6.10.3.2](packet_filtering_in_operation.md). Packet filtering can be enabled using the function **zps\_vAplAfEnableMcpsFilter\(\)** and modified as described in [Section 6.10.3.3](packet_filtering_configuration.md).


```{include} ../topics/link_cost.md
:heading-offset: 3
```

```{include} ../topics/packet_filtering_in_operation.md
:heading-offset: 3
```

```{include} ../topics/packet_filtering_configuration.md
:heading-offset: 3
```

**Parent topic:**[Advanced features](../topics/advanced_features.md)

