# tsOTA\_CallBackMessage

For an OTA event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsOTA_CallBackMessage` structure:

```
typedef struct
{
    teOTA_UpgradeClusterEvents     eEventId;
#ifdef OTA_CLIENT
    tsOTA_PersistedData sPersistedData;
    uint8 au8ReadOTAData[OTA_MAX_BLOCK_SIZE];
    uint8 u8NextFreeImageLocation;
    uint8 u8CurrentActiveImageLocation;
#endif
#ifdef OTA_SERVER
    tsCLD_PR_Ota aServerPrams[OTA_MAX_IMAGES_PER_ENDPOINT+OTA_MAX_CO_PROCESSOR_IMAGES];
    tsOTA_AuthorisationStruct               sAuthStruct;
    uint8  u8ServerImageStartSector;
    bool bIsOTAHeaderCopied;
    uint8 au8ServerOTAHeader[OTA_MAX_HEADER_SIZE+OTA_TAG_HEADER_SIZE];
    tsOTA_WaitForDataParams  sWaitForDataParams;
#ifdef OTA_PAGE_REQUEST_SUPPORT
    tsOTA_PageReqServerParams  sPageReqServerParams;
#endif
#endif
    uint8  u8ImageStartSector[OTA_MAX_IMAGES_PER_ENDPOINT];
    uint8 au8CAPublicKey[22];
    uint8 u8MaxNumberOfSectors;
    union
    {
        tsOTA_ImageNotifyCommand              sImageNotifyPayload;
        tsOTA_QueryImageRequest               sQueryImagePayload;
        tsOTA_QueryImageResponse              sQueryImageResponsePayload;
        tsOTA_BlockRequest                    sBlockRequestPayload;
        tsOTA_ImagePageRequest                sImagePageRequestPayload;
        tsOTA_ImageBlockResponsePayload       sImageBlockResponsePayload;
        tsOTA_UpgradeEndRequestPayload        sUpgradeEndRequestPayload;
        tsOTA_UpgradeEndResponsePayload       sUpgradeResponsePayload;
        tsOTA_QuerySpecificFileRequestPayload sQuerySpFileRequestPayload;
        tsOTA_QuerySpecificFileResponsePayload
                sQuerySpFileResponsePayload;
        teZCL_Status                          eQueryNextImgRspErrStatus;
        tsOTA_SignerMacVerify                 sSignerMacVerify;
        tsOTA_ImageVersionVerify              sImageVersionVerify;
        tsOTA_UpgradeDowngradeVerify          sUpgradeDowngradeVerify;
    }uMessage;
}tsOTA_CallBackMessage;

```

where:

-   `eEventId` is the OTA event type \(enumerations are detailed in [Section](teota_upgradeclusterevents.md#id_09ef20c4-d717-495d-913d-13aa91100504)49.12.2\)

-           `sPersistedData` is the structure \(see [Section 49.11.18](tsota_persisteddata.md#id_be27d08c-bdf4-4123-845f-36febbadb28a)\) which contains the persisted data that is stored in Flash memory using the NVM module on the client

-   `au8ReadOTAData` is an array containing the payload data from an Image Block Response

-           `u8NextFreeImageLocation` identifies the next free image location where a new upgrade image can be stored

-           `u8CurrentActiveImageLocation` identifies the location of the currently active image on the client

-           `aServerPrams` is an array containing the server data for each image which can be updated by application

-   `sAuthStruct` is a structure which stores the authorisation state and list of client devices that are authorised for OTA upgrade

-           `u8ServerImageStartSector` identifies the server self-image start-sector

-   `bIsOTAHeaderCopied` specifies whether the new OTA header is copied \(TRUE\) or not \(FALSE\)

-   `au8ServerOTAHeader` specifies the current server OTA header

-   `sWaitForDataParams` is a structure containing time information that may need to be modified by the server for inclusion in an Image Block Response \(for more information, refer to [Section 49.11.15](tsota_waitfordata.md#id_d698b23b-cb16-4ed2-80a0-e56aa8c1061a)\)

-   `sPageReqServerParams` is a structure containing page request information that may need to be modified by the server

-   `u8ImageStartSector` is used to store the image start-sector for each image which is stored or will be stored in the devices internal Flash memory - note that this variable assumes a 32-Kbyte sector size and so, for example, if

    64-Kbyte sectors are used, its value will be twice the actual start-sector value

-   `au8CAPublicKey` specifies the CA public key

-   `u8MaxNumberOfSectors` specifies the maximum number of sectors to be used per image

-   `uMessage` is a union containing the command payload in one of the following forms \(depending on the command specified by `eEventId`\):

    -   `sImageNotifyPayload` is a structure containing the payload of an Image Notify command

    -           `sQueryImagePayload` is a structure containing the payload of a Query Next Image Request

    -           `sQueryImageResponsePayload` is a structure containing the payload of a Query Next Image Response

    -           `sBlockRequestPayload` is a structure containing the payload of an Image Block Request

    -   `sImagePageRequestPayload` is a structure containing the payload of an Image Page Request

    -           `sImageBlockResponsePayload` is a structure containing the payload of an Image Block Response

    -   `sUpgradeEndRequestPayload` is a structure containing the payload of an Upgrade End Request

    -           `sUpgradeResponsePayload` is a structure containing the payload of an Upgrade End Response

    -           `sQuerySpFileRequestPayload` is a structure containing the payload of a Query Specific File Request

    -           `sQuerySpFileResponsePayload` is a structure containing the payload of a Query Specific File Response

    -   `eQueryNextImgRspErrStatus` is the status returned from the query image response command handler and can be passed up to the application when there is an error via the callback event E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE\_

        ERROR. The returned status value will be either E\_ZCL\_ERR\_INVALID\_IMAGE\_SIZE or E\_ZCL\_ERR\_INVALID\_IMAGE\_VERSION

    -   `sSignerMacVerify` is a structure containing the signer’s IEEE/MAC address from a new upgrade image and a status field \(which is set by the application after verifying the signer’s address\)

    -           `sImageVersionVerify` is a structure containing the image version received in the query next image response and status field \(which is set by the application after verifying the image version\)

    -           `sUpgradeDowngradeVerify` is a structure containing the image version received in the upgrade end response and a status field \(which is set by the application after verifying the image version\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

