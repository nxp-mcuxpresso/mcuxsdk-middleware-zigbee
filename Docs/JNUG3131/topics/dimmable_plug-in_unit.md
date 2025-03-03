# Dimmable Plug-in Unit

The Dimmable Plug-in Unit device is typically used in nodes that contain a controllable mains plug or adaptor which includes an adjustable output \(to a lamp\). It may be controlled from a controller device such as a Dimmer Switch or a Non-colour Controller.

-   The Device ID is 0x010B.

-   The header file for the device is **dimmable\_plug.h**.

-   The clusters supported by the device are listed in [Section 3.12.1](supported_clusters_015.md#ID_58531E04-E68A-4E18-A49A-02476BB34AC5).

-   The device structure, `tsZLO_DimmablePlugDevice`, is listed in [Section 3.12.2](device_structure_003.md#ID_9934418E-45FA-4EAB-A457-64616F9A4625).

-   The endpoint registration function for the device, **eZLO\_RegisterDimmablePlugEndPoint\(\)**, is detailed in [Section 3.12.3](registration_function_016.md#ID_14268145-80AD-4849-8613-CD4569FE7DFB).



```{include} ../topics/supported_clusters_015.md
:heading-offset: 2
```

```{include} ../topics/device_structure_003.md
:heading-offset: 2
```

```{include} ../topics/registration_function_016.md
:heading-offset: 2
```

**Parent topic:**[Lighting and Occupancy Device Types](../topics/lighting_and_occupancy_device_types.md)

