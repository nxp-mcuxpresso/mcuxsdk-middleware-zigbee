# Starting the Coordinator

The Coordinator must be the first node to be started. This node is pre-configured using the ZPS Configuration Editor. The functions that must be called in the Coordinator application to initialize the node are those listed at the start of this \([Section 6.1](forming_and_joining_a_network.md)\).

Once the stack has been started using **zps\_eAplZdoStartStack\(\)**, the Coordinator works through the following process to establish a network:


```{include} ../topics/setting_the_radio_channel_for_the_network.md
:heading-offset: 3
```

```{include} ../topics/setting_the_extended_pan_id_for_the_network.md
:heading-offset: 3
```

```{include} ../topics/accepting_join_requests_from_other_devices_if_enab.md
:heading-offset: 3
```

**Parent topic:**[Forming and joining a network](../topics/forming_and_joining_a_network.md)

