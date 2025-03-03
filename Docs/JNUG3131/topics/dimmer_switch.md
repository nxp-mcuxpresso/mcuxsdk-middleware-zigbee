# Dimmer Switch

The Dimmer Switch device is used to control a characteristic of a light \(for example, luminance\) and to switch the light device on and off.

-   The Device ID is 0x0104.

-   The header file for the device is **dimmer\_switch.h**.

-   The clusters supported by the device are listed in [Section 3.5.1](supported_clusters_010.md#ID_2341FD36-B878-4B16-AB89-E4C11B8524C6).

-   The device structure, `tsZLO_DimmerSwitchDevice`, is listed in [Section 3.5.2](device_structure_012.md#ID_F572E56C-880C-4981-A498-05DA0DA18D9A).

-   The endpoint registration function for the device, **eZLO\_RegisterDimmerSwitchEndPoint\(\)**, is detailed in [Section 3.5.3](registration_function_005.md#ID_C62EAA4E-670C-4D69-8144-A9E80C85E2BB).



```{include} ../topics/supported_clusters_010.md
:heading-offset: 2
```

```{include} ../topics/device_structure_012.md
:heading-offset: 2
```

```{include} ../topics/registration_function_005.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

