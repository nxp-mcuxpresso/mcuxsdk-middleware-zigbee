# Build Process

Special build requirements must be implemented when building applications that are to participate in OTA upgrades:

1. Certain lines must be included in the makefiles for the applications - see [Section 49.14.1](modifying_makefiles.md#id_a3c9ef6c-b9c0-472d-affb-4d79934c84ba)

2. The server and client applications must then be built - see [Section 49.14.2](building_applications.md#id_7fc48c1d-41d2-4a3d-a82f-5675093fa564)

3. The \(initial\) client application must now be prepared and loaded into Flash memory of the client device - see [Section 49.14.3](preparing_and_downloading_initial_client_image.md#id_8cb4b3cf-8a14-4f1a-8ec8-686d28c9ce98)

4. The server application must now be prepared and loaded into Flash memory of the server device - see [Section 49.14.4](preparing_and_downloading_server_image.md#id_295a7e46-69de-4abe-9956-737e9d9a41f1)


```{include} ../../OTA_upgrade_cluster/topics/modifying_makefiles.md
:heading-offset: 2
```

```{include} ../../OTA_upgrade_cluster/topics/building_applications.md
:heading-offset: 2
```

```{include} ../../OTA_upgrade_cluster/topics/preparing_and_downloading_initial_client_image.md
:heading-offset: 2
```

```{include} ../../OTA_upgrade_cluster/topics/preparing_and_downloading_server_image.md
:heading-offset: 2
```

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

