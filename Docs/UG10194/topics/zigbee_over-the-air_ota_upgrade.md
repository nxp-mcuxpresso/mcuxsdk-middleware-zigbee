# ZigBee over-the-air upgrade

An over-the-air \(OTA\) upgrade involves transferring a new firmware image to a device already installed and operational within a ZigBee network. This functionality is provided by the OTA upgrade cluster. To upgrade the devices on a network, two functional elements are required as follows:

-   **OTA Server:** First, the network must host an OTA server, which receives new OTA images from manufacturers and advertise the OTA image details to the network. Then, it must deliver the new image to the requested devices.
-   **OTA Clients:** The second requirement is for OTA clients, which are on the network devices that can be updated. These devices periodically interrogate the OTA server for details of the firmware images available. If a client finds a suitable upgrade image on the server, it starts to request this image, storing each part as it is received. Once the full image has been received, it validates, and the device boots to run the new image.

The clients pull down the new images, requesting each block in turn and filling in the gaps. The server never pushes the images onto the network.

## OTA for RW612 platform

For information about the over-the-air upgrade process for RW612 platforms, refer to the section [Zigbee Over The Air Upgrade (OTA) for RW612 platforms](https://bitbucket.sw.nxp.com/projects/CONNINT/repos/zigbee_public/browse/platform/RW612/docs/README.md#over-the-air-upgrade-ota).<br>
```{include} ../topics/overview_001.md
:heading-offset: 1
```

```{include} ../topics/ota_upgrade_operation.md
:heading-offset: 1
```

```{include} ../topics/image_credentials.md
:heading-offset: 1
```

```{include} ../topics/upgrade_and_downgrade.md
:heading-offset: 1
```

