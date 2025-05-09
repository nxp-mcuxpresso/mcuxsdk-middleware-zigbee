# Flash Memory Organization

Flash memory should be organized such that the application images are stored from Sector 0 and, if required, persistent data is stored in the final sectors.

The storage of applications and persistent data in Flash memory is described further below. Guidance on the organization of OTA upgrade applications in the devices internal Flash memory is also provided Appendix.

## Application Images 

As part of application initialization \(see [Section 49.6](initialisation.md#id_bdfa71ee-b367-4124-bef1-518ece2a81a0)\), the OTA Upgrade cluster must be informed of the storage arrangements for application images in Flash memory. This is done through the function **eOTA\_AllocateEndpointOTASpace\(\)**, which applies to a specified endpoint \(normally the endpoint of the application which calls the function\). The information provided via this function includes:

-   Start sector for each image that can be stored \(specified through an array with one element per image\). s

-   Number of images for the endpoint \(the maximum number of images per endpoint is specified in the **zcl\_options.h** file - see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\)

-   Maximum number of sectors per image

-   Type of node \(server or client\)

-   Public key for signed images


## Persistent Data 

The storage of persistent data is handled by the NVM module \(see [Section 49.8.5](persistent_data_management.md#id_b9fed82b-115f-4f9b-b6b7-0c7d211edfbe)\) and the sector used is specified as part of the NVM initialization through **NvModuleInit\(\)** - the final sector of Flash memory should be specified.

**Parent topic:**[Ancillary Features and Resources for OTA Upgrade](../../OTA_upgrade_cluster/topics/ancillary_features_and_resources_for_ota_upgrade.md)

