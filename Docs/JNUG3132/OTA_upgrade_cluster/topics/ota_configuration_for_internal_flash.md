# OTA Configuration for Internal Flash

OTA cluster is enabled through the **ZCL\_options.h** file.

The OTA cluster requires initialization of the location where the upgrade image can be stored. The application provides this through **_eOTA\_AllocateEndpointOTASpace_** API.

Each page on the device is 512 bytes. The usable flash size is 632 K, with 32 K typically reserved for NVM \(start page 1152\) and 24 K for customer data. This leaves a usable flash size for image at 576 K.

If we split it into two sections to support OTA. It means 288 K becomes maximum image size. Each 288 K section would be 576 flash pages.

This could be represented as 32 K sectors to keep in line with legacy devices.

So, for allocation to the OTA cluster:

```
uint8 u8MaxSectorPerImage = 0; 
uint8 u8StartSector[1] = {9}; /* So next image starts at 9*32*1024 = 288K offset*/ 
u8MaxSectorPerImage = 9 ; /* 9 *32* 1024 = 288K is the maximum size of the image */ 
sNvmDefs.u32SectorSize = 512; /* Sector Size = 512 bytes*/ 

```

The OTA checks for the presence of the well-known Zigbee09 key at a fixed location within the image.

This provides a convenient mechanism to test the decryption of an encrypted image and an additional sanity check to make sure the image is a valid image to progress downloading.

**Note:** This is not the mechanism for a full image validation. For a better validation of an OTA image, it is recommended that for OTA an encrypted image with the CRC check is used.

Each application note has an OTA\_BUILD folder which holds the OTA compatible images.

**LinkKey\_3.txt** is required for creation of the OTA image. It holds the Key which can be used for validation purpose as described above.

The **config OTA\_JN518x\_Cer\_Keys\_HA\_Light.txt**and **config OTA\_JN518x\_Cer\_Keys\_HA\_Light\_Generic.txt**files provide the OTA image generator with the offset for the key.

Prior to this release the values were **LinkKey\_3.txt,02c0,16**, which should now be **LinkKey\_3.txt,01b0,16**.


```{include} ../../OTA_upgrade_cluster/topics/switching_to_a_new_image.md
:heading-offset: 2
```

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

