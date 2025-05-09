# Preparing and Downloading Server Image

The server device is programmed by loading a binary image into Flash memory using a Flash programming tool such as the Flash Programmer within MCUXpresso \(normally only used in a development environment\) or the *DK6 Production Flash Programmer \(JN-SW-4407\)*.

When a new client image becomes available for the server to distribute, this image must be loaded into the server.

-   In a deployed and running system, this image may be supplied via a backhaul network.

-   In a development environment, it may be loaded into Flash memory using the Flash Programmer within MCUXpresso.

    -   However, this Flash Programmer only allows programming from the start of Flash memory. Therefore, the server application must be re-programmed into the Flash memory as well as the new client image. The server application binary and client application binary must be combined into a single binary image using the DK6 Encryption Tool \(JET\) before being loaded into the server. This tool is provided in the SDK and is described in the *JET User Guide \(JNUG3135\)*.

**Note:** If desired, the initial server image can also include the initial client application. Although there is no need for the server to download this first client application to the client\(s\), it may be stored in the server in case there is any subsequent need to re-load it into a client.

**Parent topic:**[Build Process](../../OTA_upgrade_cluster/topics/build_process.md)

