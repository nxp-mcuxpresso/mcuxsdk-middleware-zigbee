# eOTA\_AllocateEndpointOTASpace

```
teZCL_Status eOTA_AllocateEndpointOTASpace(
    uint8 u8Endpoint,
    uint8 *pu8Data,
    uint8 u8NumberOfImages,
    uint8 u8MaxSectorsPerImage,
    bool_t bIsServer,
    uint8 *pu8CAPublicKey);

```

## Description 

This function is used to allocate Flash memory space to store application images as part of the OTA upgrade process for the specified endpoint. The maximum number of images that are held at any one time must be specified as well the Flash memory start sector of every image. The maximum number of sectors used to store an image must also be specified.

The start sectors of the image space allocations are provided in an array. The index of an element of this array will subsequently be used to identify the stored image in other function calls.

Advice about the allocation of internal Flash memory space to OTA upgrade images on the client is provided in [Appendix E.2](../../appendix/topics/adding_manufacturer-specific_commands.md#id_dc585ff5-1df0-44d9-8491-50a361c036c4)

## Parameters 

-   *u8Endpoint*: Number of endpoint for which Flash memory space is to be allocated
-   *pu8Data*: Pointer to array containing the Flash memory start sector of each image \(array index identifies image\)
-   *u8NumberOfImages*: Maximum number of application images that are stored in Flash memory at any one time
-   *u8MaxSectorsPerImage*: Maximum number of sectors to be used to store an individual application image
-   *bIsServer*: Side of cluster implemented on this device:
-   TRUE - Server
-   FALSE - Client
-   *pu8CAPublicKey*: Pointer to Certificate Authority public key \(provided in the security certificate from a company such as Certicom\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[General Functions](../../OTA_upgrade_cluster/topics/general_functions.md)

