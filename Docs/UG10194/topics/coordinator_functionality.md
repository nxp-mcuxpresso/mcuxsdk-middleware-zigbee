# Coordinator functionality

The functionality of the Coordinator application is described as follows:

-   The Coordinator is responsible for initially forming the network. It manages other devices that can join the network via the Trust center functionality. It distributes security materials to those devices that are allowed to join. The Coordinator supports the mandatory clusters and features of the Base Device as defined in the *ZigBee Base Device Behavior Specification*.
-   The Coordinator also supports the On/Off Cluster as a client for demonstrating the "Finding and Binding" functionality.
-   The serial commands issued from a terminal program control the Coordinator. The terminal program runs on a PC connected to the Zigbee device through a USB connection. The Coordinator application is configured to communicate with the following configuration:

    -   Baud rate = 115200
    -   Data = 8 bits
    -   Stop = 1 bit
    -   Parity = None
    -   Flow control = None
    The serial interface is not case-sensitive. For a summary of the serial interface, refer to [Summary of Serial Interface Commands](summary_of_serial_interface_commands.md).



```{include} ../topics/forming_a_network.md
:heading-offset: 2
```

```{include} ../topics/allowing_other_nodes_to_join_network_steering.md
:heading-offset: 2
```

```{include} ../topics/operating_the_device_002.md
:heading-offset: 2
```

```{include} ../topics/rejoining_a_network_000.md
:heading-offset: 2
```

```{include} ../topics/performing_a_factory_reset_001.md
:heading-offset: 2
```

```{include} ../topics/summary_of_serial_interface_commands.md
:heading-offset: 2
```

**Parent topic:**[Running the demonstration examples](../topics/running_the_demonstration_examples.md)

