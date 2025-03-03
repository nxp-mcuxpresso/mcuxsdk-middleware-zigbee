# ZigBee Base Device

The **ZigBee Base Device** \(ZBD\) is a mandatory device on all nodes of a ZigBee 3.0 network. It exists alongside one or more other ZigBee device types on a node, but does not require an endpoint. The ZigBee Base Device provides a framework for the use of ZigBee device types. It implements basic functionality that all nodes require and ensures consistent behavior across all nodes, particularly regarding network creation, joining, and security.

The network commissioning and security functionality of the ZigBee Base Device is described in this chapter. The chapter also describes the NXP resources required to implement these features in ZigBee 3.0 applications on the **NXP hardware platforms**: **K32W148-EVK, FRDM-MCXW71, FRDM-MCXW72, MCX-W71-EVK, and MCX-W72-EVK, FRDM-RW612, and RD-RW612-BGA**.<br>
These boards (hardware platforms) belong to NXP provided **K32W041, K32W061, K32W1, MCXW71, MCXW72, RW612, and JN518x family of wireless microcontrollers**.

Detailed information about the ZigBee Base Device is provided in the *ZigBee Base Device Behavior Specification \(13-0402\)*, available from the ZigBee Alliance.


```{include} ../topics/initialising_and_starting_the_zigbee_base_device.md
:heading-offset: 1
```

```{include} ../topics/network_commissioning.md
:heading-offset: 1
```

```{include} ../topics/network_security.md
:heading-offset: 1
```

```{include} ../topics/zigbee_base_device_rejoin_handling.md
:heading-offset: 1
```

```{include} ../topics/attributes_and_constants.md
:heading-offset: 1
```

```{include} ../topics/functions.md
:heading-offset: 1
```

```{include} ../topics/structures.md
:heading-offset: 1
```

```{include} ../topics/enumerations.md
:heading-offset: 1
```

```{include} ../topics/events.md
:heading-offset: 1
```

```{include} ../topics/compile-time_options_001.md
:heading-offset: 1
```

