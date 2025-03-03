# Non-Colour Scene Controller

The Non-Colour Scene Controller device is used in nodes that support ‘scenes’ and issues control commands which are not related to colour - for example, to control a Dimmable Light.

-   The Device ID is 0x0830.

-   The header file for the device is **non\_colour\_scene\_controller.h**.

-   The clusters supported by the device are listed in [Supported clusters](supported_clusters_020.md#ID_87AB4AB0-9D2E-4732-A8E9-5EC5F376489E).

-   The device structure, `tsZLO_NonColourSceneRemoteDevice`, is listed in [Device Structure](device_structure_015.md#ID_488CC64B-2F8A-48CA-A2AF-2F8E1D7DCC2B).

-   The endpoint registration function for the device, **eZLO\_RegisterNonColourSceneControllerEndPoint\(\)**, is detailed in [Registration Function](registration_function.md#ID_9DBDC6D8-2EE7-4B51-9D85-5812CE185E72).



```{include} ../topics/supported_clusters_020.md
:heading-offset: 2
```

```{include} ../topics/device_structure_015.md
:heading-offset: 2
```

```{include} ../topics/registration_function.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

