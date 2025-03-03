# Network commissioning

Network commissioning covers the following activities:

-   Creating a network

-   Allowing devices to join the network \(through the local node\)

-   Joining a network

-   Binding a local endpoint to an endpoint on a remote node

-   Adding a remote node to a group


The commissioning activities performed by an individual node depend on the ZigBee node type \(Coordinator, Router, End Device\) and the commissioning modes that are enabled for the node. A number of different commissioning modes are available through the ZigBee Base Device. These modes are listed in the table below along with the commissioning activities that they support. <br>
**Functionality of Commissioning Modes**
| Commissioning mode  | Functionality                                                                                                                        |
| ------------------- | ------------------------------------------------------------------------------------------------------------------------------------ |
| Touchlink           | •  Creating a new network<br>•  Allowing other devices to join an existing network<br>•  Joining local device to an existing network |
| Network steering    | •  Allowing other devices to join an existing network<br>•  Joining local device to an existing network                              |
| Network formation   | •  Creating a new network                                                                                                            |
| Finding and binding | •  Binding a local endpoint to an endpoint on a remote node<br>•  Adding a remote node to a group                                    |



The commissioning modes are individually enabled/disabled via the attribute *u8bdbCommissioningMode*, as indicated in the table below. This attribute is a bitmap with a bit for each of four commissioning mode - a bit is to ‘1’ to enable or ‘0’ to disable the corresponding commissioning mode. Enumerations are available to enable the individual modes \(set their bits to ‘1’\).<br>

**Commissioning Modes (configured via bdbCommissioningMode)**

| Bit | Commissioning mode  | Enumeration                              |
| --- | ------------------- | ---------------------------------------- |
| 0   | Touchlink           | BDB_COMMISSIONING_MODE_TOUCHLINK         |
| 1   | Network steering    | BDB_COMMISSIONING_MODE_NWK_STEERING      |
| 2   | Network formation   | BDB_COMMISSIONING_MODE_NWK_FORMATION     |
| 3   | Finding and binding | BDB_COMMISSIONING_MODE_FINDING_N_BINDING |

The current commissioning state on a node is reflected in the attribute *ebdbCommissioningStatus*.

In the NXP implementation of the ZigBee Base Device, the individual commissioning modes are initiated under application control using supplied API functions. A commissioning mode is invoked by the application if the mode is enabled and the node type is relevant to the mode \(for example, an End Device cannot perform Network Formation\).

The commissioning modes are outlined in the subsections below. For detailed information on these modes, refer to the *ZigBee Base Device Behavior Specification \(13-0402-08\)*.

**Note:** A node is normally be prompted to enter commissioning by a user action, such as pressing a button on the node. This action may be on behalf of the node as a whole or a single endpoint on the node.


```{include} ../topics/touchlink.md
:heading-offset: 2
```

```{include} ../topics/network_steering.md
:heading-offset: 2
```

```{include} ../topics/network_formation.md
:heading-offset: 2
```

```{include} ../topics/finding_and_binding.md
:heading-offset: 2
```

```{include} ../topics/out-of-band_commissioning.md
:heading-offset: 2
```

**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

