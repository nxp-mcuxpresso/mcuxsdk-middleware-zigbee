# teOTA\_UpgradeClusterEvents

The following enumerations represent the OTA Upgrade cluster events:

```
typedef enum 
{
    E_CLD_OTA_COMMAND_IMAGE_NOTIFY,
    E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_REQUEST,
    E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_RESPONSE,
    E_CLD_OTA_COMMAND_BLOCK_REQUEST,
    E_CLD_OTA_COMMAND_PAGE_REQUEST,
    E_CLD_OTA_COMMAND_BLOCK_RESPONSE,
    E_CLD_OTA_COMMAND_UPGRADE_END_REQUEST,
    E_CLD_OTA_COMMAND_UPGRADE_END_RESPONSE,
    E_CLD_OTA_COMMAND_QUERY_SPECIFIC_FILE_REQUEST,
    E_CLD_OTA_COMMAND_QUERY_SPECIFIC_FILE_RESPONSE,
    E_CLD_OTA_INTERNAL_COMMAND_TIMER_EXPIRED,
    E_CLD_OTA_INTERNAL_COMMAND_SAVE_CONTEXT,
    E_CLD_OTA_INTERNAL_COMMAND_OTA_DL_ABORTED,
    E_CLD_OTA_INTERNAL_COMMAND_POLL_REQUIRED,
    E_CLD_OTA_INTERNAL_COMMAND_RESET_TO_UPGRADE,
    E_CLD_OTA_INTERNAL_COMMAND_LOCK_FLASH_MUTEX,
    E_CLD_OTA_INTERNAL_COMMAND_FREE_FLASH_MUTEX,
    E_CLD_OTA_INTERNAL_COMMAND_SEND_UPGRADE_END_RESPONSE,
    E_CLD_OTA_INTERNAL_COMMAND_CO_PROCESSOR_BLOCK_RESPONSE,
    E_CLD_OTA_INTERNAL_COMMAND_CO_PROCESSOR_DL_ABORT,
    E_CLD_OTA_INTERNAL_COMMAND_CO_PROCESSOR_IMAGE_DL_COMPLETE,
    E_CLD_OTA_INTERNAL_COMMAND_CO_PROCESSOR_SWITCH_TO_NEW_IMAGE,
    E_CLD_OTA_INTERNAL_COMMAND_CO_PROCESSOR_IMAGE_BLOCK_REQUEST,
    E_CLD_OTA_INTERNAL_COMMAND_SPECIFIC_FILE_BLOCK_RESPONSE,
    E_CLD_OTA_INTERNAL_COMMAND_SPECIFIC_FILE_DL_ABORT,
    E_CLD_OTA_INTERNAL_COMMAND_SPECIFIC_FILE_DL_COMPLETE,
    E_CLD_OTA_INTERNAL_COMMAND_SPECIFIC_FILE_USE_NEW_FILE,
    E_CLD_OTA_INTERNAL_COMMAND_SPECIFIC_FILE_NO_UPGRADE_END_RESPONSE,
    E_CLD_OTA_COMMAND_QUERY_NEXT_IMAGE_RESPONSE_ERROR,
    E_CLD_OTA_INTERNAL_COMMAND_VERIFY_SIGNER_ADDRESS,
    E_CLD_OTA_INTERNAL_COMMAND_RCVD_DEFAULT_RESPONSE,
    E_CLD_OTA_INTERNAL_COMMAND_VERIFY_IMAGE_VERSION,
    E_CLD_OTA_INTERNAL_COMMAND_SWITCH_TO_UPGRADE_DOWNGRADE,
    E_CLD_OTA_INTERNAL_COMMAND_REQUEST_QUERY_NEXT_IMAGES,
    E_CLD_OTA_INTERNAL_COMMAND_OTA_START_IMAGE_VERIFICATION_IN_LOW_PRIORITY,
    E_CLD_OTA_INTERNAL_COMMAND_FAILED_VALIDATING_UPGRADE_IMAGE,
    E_CLD_OTA_INTERNAL_COMMAND_FAILED_COPYING_SERIALIZATION_DATA
}teOTA_UpgradeClusterEvents;

```

The above enumerations are described in the table below.

|**Enumeration**|**Event Description**|
|---------------|---------------------|
|E\_CLD\_OTA\_COMMAND\_IMAGE\_NOTIFY|Generated on client when an Image Notify message is received from the server to indicate that a new application image is available for download|
|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_REQUEST|Generated on server when a Query Next Image Request is received from a client to enquire whether a new application image is available for download|
|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE|Generated on client when a Query Next Image Response is received from the server \(in response to a Query Next Image Request\) to indicate whether a new application image is available for download|
|E\_CLD\_OTA\_COMMAND\_BLOCK\_REQUEST|Generated on server when an Image Block Request is received from a client to request a block of image data as part of a download|
|E\_CLD\_OTA\_COMMAND\_PAGE\_REQUEST|Generated on server when an Image Page Request is received from a client to request a page of image data as part of a download|
|E\_CLD\_OTA\_COMMAND\_BLOCK\_RESPONSE|Generated on client when an Image Block Response is received from the server \(in response to an Image Block Request\) and contains a block of image data which is part of a download|
|E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_REQUEST|Generated on server when an Upgrade End Request is received from a client to indicate that the complete image has been downloaded and verified|
|E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_RESPONSE|Generated on client when an Upgrade End Response is received from the server \(in response to an Upgrade End Request\) to confirm the end of a download|
|E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_REQUEST|Generated on server when a Query Specific File Request is received from a client to request a particular application image|
|E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_RESPONSE|Generated on client when a Query Specific File Response is received from the server \(in response to a Query Specific File Request\) to indicate whether the requested application image is available for download|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_TIMER\_EXPIRED|Generated on client to notify the application that the local one-second timer has expired|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SAVE\_CONTEXT|Generated on server or client to prompt the application to store context data in Flash memory|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_DL\_ABORTED|Generated on a client if the received image is invalid or the client has aborted the image download \(allowing the application to request the new image again\)|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_POLL\_REQUIRED|Generated on client to prompt the application to poll the server for a new application image|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_RESET\_TO\_UPGRADE|Generated on client to notify the application that the stack is going to reset the device|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_LOCK\_-FLASH\_MUTEX|Generated on server or client to prompt the application to lock the mutex used for accesses to external Flash

 memory

|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_FREE\_-FLASH\_MUTEX|Generated on server or client to prompt the application to unlock the mutex used for accesses to external Flash memory|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SEND\_UPGRADE\_END\_RESPONSE|Generated on server to notify the application that the stack is going to send an Upgrade End Response to a client|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_BLOCK\_RESPONSE|Generated on client to notify the application that Image Block Response has been received for co-processor image|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_DL\_ABORT|Generated on client to notify the application that download of co-processor image from the server has been aborted|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_IMAGE\_DL\_COMPLETE|Generated on client to notify the application that download of co-processor image from the server has completed|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_SWITCH\_TO\_NEW\_IMAGE|Generated on client to notify the application that the upgrade time for a previously downloaded co-processor image has been reached \(this event is generated after receiving the Upgrade End Response which contains the upgrade time\)|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_IMAGE\_BLOCK\_REQUEST|Generated on server when an Image Block Request is

 received from a client to request a block of image data

 as part of a download and the server finds that the required image is stored in the co-processor’s external storage device

|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_BLOCK\_RESPONSE|Generated on client when an Image Block Response is received from server as part of a device-specific file download - the event contains a block of file data which the client stores in an appropriate location|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_ABORT|Generated on client when the final Image Block Response of a device-specific file download has been received from the server|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_COMPLETE|Generated on client following a device-specific file download to indicate that the upgrade time has been reached and the file can now be used by the client|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_USE\_NEW\_FILE|Generated to indicate that a device-specific file download is being aborted and any received data must be discarded by the application|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_NO\_UPGRADE\_END\_RESPONSE|Generated to indicate that no Upgrade End Response has been received for a device-specific file download \(after three attempts to obtain one\)|
|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE\_ERROR|This event is generated on the client when a Query Next Image Response message is received from the server, in response to a Query Next Image Request with a status of Invalid Image Size.|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_SIGNER\_ADDRESS|This event is generated to prompt the application to verify the signer address received in a new OTA upgrade image. This event gives control to the application to verify that the new upgrade image came from a trusted source. After checking the signer address, the application should set the status field of the event to E\_ZCL\_SUCCESS \(valid source\) or E\_ZCL\_FAIL \(invalid source\).|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_RCVD\_DEFAULT\_RESPONSE|This event is generated on the client when a default response message is received from the server, in response to a Query Next Image Request, Image Block Request or Upgrade End Request. This is an internal ZCL event that results in an OTA download being aborted, thus activating the callback function for the event E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_DL\_ABORTED.|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_IMAGE\_VERSION|This event is generated to prompt the application to verify the image version received in a Query Next Image Response. This event allows the application to verify that the new upgrade image has a valid image version. After checking the image version, the application should set the status field of the event to E\_ZCL\_SUCCESS \(valid version\) or E\_ZCL\_FAIL \(invalid version\).|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SWITCH\_TO\_UPGRADE\_DOWNGRADE|This event is generated to prompt the application to verify the image version received in an upgrade end response. This event allows the application to verify that the new upgrade image has a valid image version.

 After checking the image version, the application should set the status field of the event to E\_ZCL\_SUCCESS \(valid version\) or E\_ZCL\_FAIL \(invalid version\).

|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_REQUEST\_QUERY\_NEXT\_IMAGES|This event is generated on the client when a co-processor image also requires the client to update its own image. After the first file is downloaded \(co-processor image\) this event notifies the application to allow it to send a Query Next Image command for its own upgrade image, using the function **eOTA\_ClientQueryNextImageRequest\(\)**.|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_START\_IMAGE\_VERIFICATION\_IN\_LOW\_PRIORITY|This event is generated to prompt the application to verify the downloaded JN516x client image from a low priority task. Once the low priority task is running, the application should call **eOTA\_VerifyImage\(\)** to start image verification.|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_VALIDATING\_UPGRADE\_IMAGE|This event is generated on the client when the validation of a new upgrade image fails. This validation takes place when the upgrade time is reached.|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_COPYING\_SERIALIZATION\_DATA|This event is generated on the client when the copying of serialization data from the active image to the new upgrade image fails. This process takes place after image validation \(if applicable\) are completed successfully.|

The above events are described in more detail in [Section 49.9](ota_upgrade_events.md#id_ca6373a3-106d-49cb-a744-7eebb68e1999).

**Parent topic:**[Enumerations](../../OTA_upgrade_cluster/topics/enumerations.md)

