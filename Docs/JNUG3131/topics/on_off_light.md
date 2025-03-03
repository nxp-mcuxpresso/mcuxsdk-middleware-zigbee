# On/Off light

The On/Off Light device is simply a light that can be switched on and off \(two states only and no intermediate levels\).

-   The Device ID is 0x0100.

-   The header file for the device is **on\_off\_light.h**.

-   The clusters supported by the device are listed in [Section 3.1.1](supported_clusters_019.md#ID_C5E22FF7-1A48-4C7A-9502-05C095F2AB23).

-   The device structure, `tsZLO_OnOffLightDevice`, is listed in [Section 3.1.2](device_structure_005.md#ID_C33ADD97-4873-4F63-9C9B-1206A917D2BF).

-   The endpoint registration function for the device, **eZLO\_RegisterOnOffLightEndPoint\(\)**, is detailed in [Section 3.1.3](registration_function_019.md#ID_237F0D37-C5DC-4DB0-824F-A37711075163).



```{include} ../topics/supported_clusters_019.md
:heading-offset: 2
```

```{include} ../topics/device_structure_005.md
:heading-offset: 2
```

```{include} ../topics/registration_function_019.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

