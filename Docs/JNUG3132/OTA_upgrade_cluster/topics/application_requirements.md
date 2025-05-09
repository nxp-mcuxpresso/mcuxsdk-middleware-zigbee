# Application Requirements

In order to implement OTA upgrades, the application images for the server and clients must be designed and built according to certain requirements.

These requirements include the following:

-   Inclusion of the header files **zcl\_options.h** and **OTA.h**

-   Inclusion of the relevant \#defines in the file **zcl\_options.h**, as described in [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)

-   Specific application initialization requirements, as outlined in [Section 49.6](initialisation.md#id_bdfa71ee-b367-4124-bef1-518ece2a81a0)

-   Use of the Non-Volatile Memory Manager \(NVM\) to preserve context data, as outlined in [Section 49.8.5](persistent_data_management.md#id_b9fed82b-115f-4f9b-b6b7-0c7d211edfbe)

-   Organization of Flash memory, as outlined in [Section 49.8.6](flash_memory_organisation.md#id_65bef179-543c-4473-a146-88b47fdf7bf7)

-   It is necessary to remove references to the Certicom security certificate, as indicated in [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)


**Note:** Some of above requirements differ between the server image, the first client image and client upgrade images. These differences are pointed out, where relevant, in [Section 49.6](initialisation.md#id_bdfa71ee-b367-4124-bef1-518ece2a81a0) and [Section 49.8](ancillary_features_and_resources_for_ota_upgrade.md#id_1ee6cf32-08d8-4e70-84cd-869e1258ef3d).

In addition, you should increase the CPU stack size from the default value. With OTA Upgrade, the recommended stack size is 6000 bytes. This can be done by including the following line in your application makefile:

```
__stack_size = 6000;

```

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

