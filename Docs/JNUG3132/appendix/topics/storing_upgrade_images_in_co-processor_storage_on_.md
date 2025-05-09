# Appendix F.2: Storing Upgrade Images in Co-processor Storage on Server

When the co-processor on the OTA server node receives a new OTA upgrade image from an external source \(such as a utility company\), if the image is not for the co-processor itself then it is normally passed to the Wireless Microcontroller device for storage in the attached Flash memory device. However, if there is insufficient storage space in Flash memory then the new image will need to be stored in the storage device of the co-processor:

-   When the co-processor application notifies the Wireless Microcontroller application of the arrival of a new image, the Wireless Microcontroller application must check whether there is sufficient Flash memory space for the image.

-   If there is insufficient Flash memory space, the Wireless Microcontroller application must inform the co-processor that it should store the image in its own storage device.


The maximum number of images that can be stored in the co-processor’s storage device on the OTA server node must be specified as a compile-time option in the **zcl\_options.h** file through the macro OTA\_MAX\_CO\_PROCESSOR\_IMAGES.

The OTA Upgrade cluster server will require knowledge of any OTA upgrade images stored in the co-processor’s storage device - the cluster server must be able to advertise the availability of the image to cluster clients and be able to process requests for the image from clients. To facilitate this role, once the image has been saved, the co-processor must provide the OTA image header information to the Wireless Microcontroller application. The latter application can then register this header information with the cluster server by calling the function **eOTA\_NewImageLoaded\(\)**.

When an Image Block Request from a cluster client is received by the cluster server for an image stored in the co-processor’s storage device, the event E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PRECOSSOR\_IMAGE\_BLOCK\_REQUEST is generated on the Wireless Microcontroller. After requesting and receiving the required image block from the co-processor, the application must send the block to the relevant client by calling the function **eOTA\_ServerImageBlockResponse\(\)** to issue an Image Block Response.

**Parent topic:**[Appendix F: OTA extension for dual-processor nodes](../../appendix/topics/ota_extension_for_dual-processor_nodes.md)

