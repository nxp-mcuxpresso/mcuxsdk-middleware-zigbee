# Image Block Size and Fragmentation

An OTA Upgrade image is normally requested by the OTA Upgrade client one block at a time. The ZigBee frame for the OTA transfer contains various header data as well as payload data and, for this reason, the payload data is limited to about 48 bytes. Therefore, to transfer one image block per frame, the block size must be restricted to 48 bytes or less. The maximum block size can be configured at compile-time through the OTA\_MAX\_BLOCK\_SIZE define in the **zcl\_options.h** file \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\).

A block size of greater than 48 bytes can be used but the image block will need to be transferred across two or more ZigBee frames. In this case, fragmentation must be enabled in which the image block data that is assembled in an APDU \(Application Protocol Data Unit\) on the server is fragmented into multiple NPDUs \(Network Protocol Data Unit\) for OTA transfer, where one NPDU is transferred in a single ZigBee frame. Fragmentation is enabled on the OTA Upgrade server and client using network parameters of the ZigBee PRO stack, as follows:

-   **On the server:** Set the parameter *Maximum Number of Transmitted Simultaneous Fragmented Messages* to a non-zero value to allow transmitted messages to be fragmented.

-   **On the client:** Set the parameter *Maximum Number of Received Simultaneous Fragmented Messages* to a non-zero value to allow received fragmented messages to be re-assembled.


The network parameter values are set using the ZPS Configuration Editor and are described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

**Note:** **Note:**The 48-byte limit on the payload data in a ZigBee frame is also applicable when image data is requested and transferred one page at a time \(see [Section 49.8.4](page_requests.md#id_a01735d1-0ceb-4b41-a26b-9b9050f56309)\). In this case, fragmentation may need to be enabled.

The maximum APDU size must always be greater than the size of an Image Block Response. It is set through the APDU *Size* parameter of the PDU Manager, where this parameter is amongst the Advanced Device Parameters that can be configured using the ZPS Configuration Editor.

Depending on the image block size, fragmentation is not always an efficient way of transferring image blocks, as the payload of the final NPDU fragment may contain little data and be mostly empty. For example, if the image block size is set to 64 bytes and fragmentation is enabled, each block is transferred in two ZigBee frames, the first may contain 48 bytes of data and the second may contain only 16 bytes of data, leaving 32 empty bytes in the payload. In contrast, if the block size is set to 48 bytes without fragmentation, two consecutive frames would carry 96 bytes of data, and the image transfer would require fewer frames. This is particularly important when transferring an application image to a battery-powered End Device that needs to conserve energy.

**Parent topic:**[Ancillary Features and Resources for OTA Upgrade](../../OTA_upgrade_cluster/topics/ancillary_features_and_resources_for_ota_upgrade.md)

