# End Device functionality

The End Device is not capable of either forming a network or being a parent to other devices joining the network.

Two types of End Device are as follows:

-   "RX On" End Devices, which are always ready to communicate in the network
-   Sleepy "RX Off when Idle" End Devices, which can sleep for periods of time during which it cannot communicate

The End Device supports the mandatory clusters and features of the Base Device as defined in [ZigBee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf).

For demonstrating the "Finding and Binding" functionality, the End Device also supports the On/Off cluster as a client.

All communications to/from the End Device are passed through its parent Coordinator or Router. For an RX Off with the Idle End Device, communication is initiated from the End Device through Poll Requests. The parent device then buffers data for the child End Device for some time. During this period, the End Device must send periodic Poll Requests to its parent to receive any messages that are waiting for it.

For the RX On device, no poll is required and messages are sent directly from the parent. However, regular messages must be sent. Otherwise, the device can be timed out.


```{include} ../topics/joining_an_existing_network_using_network_steering_001.md
:heading-offset: 2
```

```{include} ../topics/operating_the_device_001.md
:heading-offset: 2
```

```{include} ../topics/rejoining_a_network.md
:heading-offset: 2
```

```{include} ../topics/performing_a_factory_reset.md
:heading-offset: 2
```

**Parent topic:**[Running the demonstration examples](../topics/running_the_demonstration_examples.md)

