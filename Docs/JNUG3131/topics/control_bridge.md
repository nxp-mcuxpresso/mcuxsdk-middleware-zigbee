# Control Bridge

The Control Bridge device is used in nodes that relay control commands issued from another network, for example, in an Internet router with a ZigBee interface.

-   The Device ID is 0x0840.

-   The header file for the device is **control\_bridge.h**.

-   The clusters supported by the device are listed in [Section 3.20.1](supported_clusters.md#ID_391815EB-D725-4C8E-874E-5DBA7079C90F).

-   The device structure, `tsZLO_ControlBridgeDevice`, is listed in [Section 3.20.2](device_structure_020.md#ID_6E476A36-36B5-406E-9DE1-8545311A7BEC).

-   The endpoint registration function for the device, **eZLO\_RegisterControlBridgeEndPoint\(\)**, is detailed in [Section 3.20.3](registration_function_007.md#ID_37305A96-7D6F-47CA-8F91-B29263A9244D).



```{include} ../topics/supported_clusters.md
:heading-offset: 2
```

```{include} ../topics/device_structure_020.md
:heading-offset: 2
```

```{include} ../topics/registration_function_007.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

