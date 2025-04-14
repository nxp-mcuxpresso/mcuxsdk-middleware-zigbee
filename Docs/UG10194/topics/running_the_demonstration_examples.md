# Running the demonstration examples

This section describes how to use the supplied pre-built binaries to run the example applications on a ZigBee device. All the applications run on the FRDM-MCXW71 board (or the MCX-W71-EVK / MCX-W72-EVK / FRDM-RW612 / RD-RW612-BGA boards). The examples do not run on other development kits. All the ZigBee wireless demo applications are configured to use a default channel 12. The pre-processor configuration uses the setting `SINGLE_CHANNEL=12`, which can be overwritten to change it to a different channel.

The ZigBee examples work in the Centralized \(Trust center\) network only, and all devices are expected to join with the ZigBee09 key. Once joined, the devices then automatically negotiate a new TCLK key.

For details of the differences between a Centralized \(Trust center\) network and a Distributed network, see the *ZigBee Devices User Guide* \(document JNUG3131\).


```{include} ../topics/loading_the_applications.md
:heading-offset: 1
```

```{include} ../topics/coordinator_functionality.md
:heading-offset: 1
```

```{include} ../topics/router_functionality.md
:heading-offset: 1
```

```{include} ../topics/end_device_functionality.md
:heading-offset: 1
```

```{include} ../topics/binding_devices.md
:heading-offset: 1
```

