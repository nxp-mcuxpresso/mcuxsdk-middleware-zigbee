# Appendix F.3: Use of Image Indices

Each OTA upgrade image that is stored in non-volatile memory in a node is identified by an index number. This image index number is actually associated with the memory space allocated to a single image, rather than with a particular image. For example, the image index number `1` may correspond to sectors 3 and 4 of the Flash memory attached to the device.

**Note:** In the case of external Flash memory, an image index number is linked with the start sector of the memory allocated to a single image when the function **eOTA\_AllocateEndpointOTASpace\(\)** is called.

-   The maximum number of images that can be stored in the external Flash memory is set at compile-time by defining a value for `OTA_MAX_IMAGES_PER_ENDPOINT` in the **zcl\_options.h** file. The minimum value that can be used is 1, since the active image is held in the internal Flash memory and does not need to be included.

-   Since the image indices are numbered from zero, they can take values in the range:
    -   0 to \(`OTA_MAX_IMAGES_PER_ENDPOINT` - 1\)

In the case of a dual-processor node, OTA upgrade images may also be stored in the co-processor’s external storage device. The maximum number images that can be stored in this device is set at compile-time by defining a value for `OTA_MAX_CO_PROCESSOR_IMAGES` in the **zcl\_options.h** file.

-   The maximum number of images that can be stored across the two storage devices is:

    -   `OTA_MAX_IMAGES_PER_ENDPOINT` + `OTA_MAX_CO_PROCESSOR_IMAGES`

-   The image indices can take values in the range:
    -   0 to \(`OTA_MAX_IMAGES_PER_ENDPOINT` + `OTA_MAX_CO_PROCESSOR_IMAGES` - 1\)
-   The indices of the images stored in the external Flash memory still take values in the range:
    -   0 to \(`OTA_MAX_IMAGES_PER_ENDPOINT` - 1\)

-   The indices of the images stored in co-processor external storage take values in the range:
    -   `OTA_MAX_IMAGES_PER_ENDPOINT` to \(`OTA_MAX_IMAGES_PER_ENDPOINT` + `OTA_MAX_CO_PROCESSOR_IMAGES` - 1\)


**Parent topic:**[Appendix F: OTA extension for dual-processor nodes](../../appendix/topics/ota_extension_for_dual-processor_nodes.md)

