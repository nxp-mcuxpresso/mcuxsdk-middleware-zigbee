# Server-side Events

-   **E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_REQUEST**

    -   This event is generated on the server when a Query Next Image Request is received from a client to enquire whether a new application image is available for download. The event may result from a poll request from the client or may be a consequence of an Image Notify message previously sent by the server. The server reacts to this event by returning a Query Next Image Response.
-   **E\_CLD\_OTA\_COMMAND\_BLOCK\_REQUEST**

    -   This event is generated on the server when an Image Block Request is received from a client to request a block of image data as part of a download. The application reacts to this event by returning an Image Block Response containing a data block.
-   **E\_CLD\_OTA\_COMMAND\_PAGE\_REQUEST**

    -   This event is generated on the server when an Image Page Request is received from a client to request a page of image data as part of a download.
-   **E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_REQUEST**

    -   This event is generated on the server when an Upgrade End Request is received from a client to indicate that the complete image has been downloaded and verified. The application reacts to this event by returning an Upgrade End Response.
-   **E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_REQUEST**

    -   This event is generated on the server when a Query Specific File Request is received from a client to request a particular application image. The server reacts to this event by returning a Query Specific File Response.
-   **E\_CLD\_OTA\_INTERNAL\_COMMAND\_SEND\_UPGRADE\_END\_RESPONSE**

    -   This event is generated on the server to notify the application that the stack is going to send an Upgrade End Response to a client. No specific action is required by the application on the server.

**Parent topic:**[OTA Upgrade events](../../OTA_upgrade_cluster/topics/ota_upgrade_events.md)

