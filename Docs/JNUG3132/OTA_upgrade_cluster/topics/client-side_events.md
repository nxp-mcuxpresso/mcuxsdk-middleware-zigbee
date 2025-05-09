# Client-side Events

-   **E\_CLD\_OTA\_COMMAND\_IMAGE\_NOTIFY**

    -   This event is generated on the client when an Image Notify message is received from the server to indicate that a new application image is available for download. If the client decides to download the image, the application should react to this event by sending a Query Next Image Request to the server using the function **eOTA\_ClientQueryNextImageRequest\(\)**.
-   **E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE**

    -   This event is generated on the client when a Query Next Image Response is received from the server \(in response to a Query Next Image Request\) to indicate whether a new application image is available for download. If a suitable image is reported, the client initiates a download by sending an Image Block Request to the server.
-   **E\_CLD\_OTA\_COMMAND\_BLOCK\_RESPONSE**

    -   This event is generated on the client when an Image Block Response is received from the server \(in response to an Image Block Request\) and contains a block of image data which is part of a download. Following this event, the client can request the next block of image data by sending an Image Block Request to the server or, if the entire image has been received and verified, the client can close the download by sending an Upgrade End Request to the server.
-   **E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_RESPONSE**

    -   This event is generated on the client when an Upgrade End Response is received from the server \(in response to an Upgrade End Request\) to confirm the end of a download. This event contains the time delay before the upgrade of the running application must be performed.
-   **E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_RESPONSE**

    -   This event is generated on the client when a Query Specific File Response is received from the server \(in response to a Query Specific File Request\) to indicate whether the requested application image is available for download.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_TIMER\_EXPIRED**

    -   This event is generated on the client when the local one-second timer has expired. It is an internal event and is not passed to the application.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_POLL\_REQUIRED**

    -   This event is generated on the client to prompt the application to poll the server for a new application image by calling the function **eOTA\_ClientQueryNextImageRequest\(\)**.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_RESET\_TO\_UPGRADE**

    -   This event is generated on the client to notify the application that the stack is going to reset the device. No specific action is required by the application.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SAVE\_CONTEXT**

    -   This event prompts the client application to store context data in Flash memory. The data to be stored is passed to the application within this event.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_DL\_ABORTED**

    -   This event is generated on a client if the received image is invalid or the client has aborted the image download. This allows the application to request the new image again.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_BLOCK\_RESPONSE**

    -   This event is generated on the client when an Image Block Response is received from the server in response to an Image Block Request for a device-specific file. The event contains a block of file data which is part of a download. Following this event, the client stores the data block in an appropriate location and can request the next block of file data by sending an Image Block Request to the server \(if the complete image has not yet been received and verified\).
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_COMPLETE**

    -   This event is generated on the client when the final Image Block Response of a device-specific file download has been received from the server - the event indicates that all the data blocks that make up the file have been received.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_USE\_NEW\_FILE**

    -   This event is generated on the client following a device-specific file download to indicate that the file can now be used by the client. At the end of the download, the server sends an Upgrade End Response that may include an ‘upgrade time’ - this is the UTC time at which the new file can be applied. Thus, on receiving this response, the client starts a timer and, on reaching the upgrade time, generates this event.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_ABORT**

    -   This event is generated to indicate that the OTA Upgrade cluster needs to abort a device-specific file download. Following this event, the application should discard data that has already been received as part of the aborted download.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_NO\_UPGRADE\_**

    **END\_RESPONSE**

    -   This event is generated when no Upgrade End Response has been received for a device-specific file download. The client makes three attempts to obtain an Upgrade End Response. If no response is received, the client raises this event.

**Note:** For a device-specific file download, it is not mandatory for the server to send an Upgrade End Response. The decision of whether to send the Upgrade End Response is manufacturer-specific.

-   **E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE\_ERROR**

    -   This event is generated on the client when a Query Next Image Response message is received from the server, in response to a Query Next Image Request with a status of Invalid Image Size.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_RCVD\_DEFAULT\_RESPONSE**

    -   This event is generated on the client when a default response message is received from the server, in response to a Query Next Image Request, Image Block Request or Upgrade End Request. This is an internal ZCL event that results in an OTA download being aborted, thus activating the callback function for the E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_DL\_ABORTED event.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_IMAGE\_VERSION**

    -   This event is generated to prompt the application to verify the image version received in a Query Next Image Response. This event allows the application to verify that the new upgrade image has a valid image version. After checking the image version, the application should set the status field of the event to E\_ZCL\_SUCCESS \(valid version\) or E\_ZCL\_FAIL \(invalid version\).
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SWITCH\_TO\_UPGRADE\_**

    **DOWNGRADE**

    -   This event is generated to prompt the application to verify the image version received in an upgrade end response. This event allows the application to verify that the new upgrade image has a valid image version.
    -   After checking the image version, the application should set the status field of the event to E\_ZCL\_SUCCESS \(valid version\) or E\_ZCL\_FAIL \(invalid version\).
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_VALIDATING\_UPGRADE\_**

    **IMAGE**

    -   This event is generated on the client when the validation of a new upgrade image fails. This validation takes place when the upgrade time is reached.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_COPYING\_SERIALIZATION\_DATA**

    -   This event is generated on the client when the copying of serialisation data from the active image to the new upgrade image fails. This process takes place after image validation \(if applicable\) is completed successfully.
-   **E\_CLD\_OTA\_BLOCK\_RESPONSE\_TAG\_OTHER\_THAN\_UPGRADE\_**

    **IMAGE**

    -   This event is generated on the client when an Image Block Response is received from the server but the response contains a block of data that is not upgrade image data \(it may contain tags such as an integrity code or ECDA signature\).Thus, this event can help the application to process tags or data other than upgrade image data.

**Parent topic:**[OTA Upgrade events](../../OTA_upgrade_cluster/topics/ota_upgrade_events.md)

