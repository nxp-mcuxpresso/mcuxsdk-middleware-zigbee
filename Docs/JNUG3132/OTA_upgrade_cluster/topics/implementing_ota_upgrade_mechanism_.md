# Implementing OTA Upgrade Mechanism

The OTA upgrade mechanism is implemented in code as described below.

**Note:** The stack automatically handles part of an OTA upgrade and calls some of the OTA functions. However, if preferred, the application can handle all aspects of an OTA upgrade and filter all OTA data indications. In this case, the application must call all the relevant OTA functions \(these are indicated below\).

1. On the server, when a new client image is available for download, the function **eOTA\_NewImageLoaded\(\)** should be called to request the OTA Upgrade cluster to validate the image.

-   Then, optionally, the function **eOTA\_SetServerParams\(\)** can be called to set the server parameter values for the new image. Otherwise, the default parameter values will be used.

2. The server must then notify the relevant client\(s\) of the availability of the new image. The notification method depends on the ZigBee node type of the client:

-   **Coordinator or Router client:** The server can notify the Coordinator or a Router client directly by sending an Image Notify message to the client through a call to the function **eOTA\_ServerImageNotify\(\)**. This message can be unicast, multicast or broadcast. On arrival at a client, this message will trigger an Image Notify event. If the new software is required, the client can request the upgrade image by sending a Query Next Image Request to the server through a call to **eOTA\_ClientQueryNextImageRequest\(\)**.

-   **All clients:** The server cannot notify an End Device client directly, since the End Device may be asleep when a notification message is sent. Therefore, an End Device client must poll the server periodically \(during wake periods\) in order to establish whether new software is available. In fact, any client can implement polling of the server. The client does this by sending a Query Next Image Request to the server through a call to the function **eOTA\_ClientQueryNextImageRequest\(\)**.

    -   On arrival at the server, the Query Next Image Request message triggers a Query Next Image Request event.

3. The server automatically replies to the request with a Query Next Image Response \(the application can also send this response by calling the function **eOTA\_ServerQueryNextImageResponse\(\)**\). The contents of this response message depend on whether the client is using notifications or polling:

-   **Coordinator or Router client \(notifications\):** The response contains details of the upgrade image, such as manufacturer, image type, image size, and file version.

-   **All clients \(polling\):** If upgrade software is available, the response reports success and the message contains details of the upgrade image, as indicated above. If no upgrade software is available, the response simply reports failure \(the client must then poll again later\).

    -   On arrival at the client, the Query Next Image Response message triggers a Query Next Image Response event.

4. The OTA Upgrade cluster on the client now automatically requests the upgrade image one block at a time by sending an Image Block Request to the server \(this request can also be sent by the application through a call to the function **eOTA\_ClientImageBlockRequest\(\)**\). The maximum size of a block and the time interval between requests can both be configured in the header file **zcl**-**\_options.h** - see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31).

-   On arrival at the server, the Image Block Request message triggers an Image Block Request event.

5. The server automatically responds to each block request with an Image Block Response containing a block of data \(the application can also send this response by calling the function **eOTA\_ServerImageBlockResponse\(\)**\).

-   On arrival at the client, the Image Block Response message triggers an Image Block Response event.

6. The client determines when the entire image has been received \(by referring to the image size that was quoted in the Query Next Image Response before the download started\). Once the final block of image data has been received, the client application should transmit an Upgrade End Request to the server \(that is, by calling **eOTA\_HandleImageVerification\(\)**\).

-   This Upgrade End Request may report success or an invalid image. In the case of an invalid image, the image will be discarded by the client, which may initiate a new download of the image by sending a Query Next Image Request to the server.
-   On arrival at the server, the Upgrade End Request message triggers an Upgrade End Request event.

**Note:** An Upgrade End Request may also be sent to the server during a download in order to abort the download.

7. The server replies to the request with an Upgrade End Response containing an instruction of when the client should use the downloaded image to upgrade the running software on the node \(the message contains both the current time and the upgrade time, and hence an implied delay\).

-   On arrival at the client, the Upgrade End Response message triggers an Upgrade End Response event.

8. The client will then count down to the upgrade time \(in the Upgrade End Response\) and on reaching it, start the upgrade. If the upgrade time has been set to an indefinite value \(represented by 0xFFFFFFFF\), the client should poll the server for an Upgrade Command at least once per minute and start the upgrade once this command has been received.

9. Once triggered on the client, the upgrade process proceeds as follows \(although the details will be manufacturer-specific\):

a\) A reboot of the device is initiated causing the default bootloader to run.

b\) The bootloader scans through Flash looking for various image headers, including the running one and the one received via OTA. If the OTA image in newer, indicated by version number in the header, this is selected as the new running image.

**Note:** The client automatically invalidates the existing image and validates the new upgrade image once the allotted upgrade time is reached.

c\) The new software image is then executed.

## Query Jitter 

The 'query jitter' mechanism can be used to prevent a flood of replies to an Image Notify broadcast or multicast \(Step 2 above\). The server includes a number, n, in the range 1-100 in the notification. If interested in the image, the receiving client generates a random number in the range 1-100. If this number is greater than n, the client discards the notification, otherwise it responds with a Query Next Image Request. This results in only a fraction of interested clients responding to each broadcast/multicast and therefore helps to avoid traffic congestion.

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

