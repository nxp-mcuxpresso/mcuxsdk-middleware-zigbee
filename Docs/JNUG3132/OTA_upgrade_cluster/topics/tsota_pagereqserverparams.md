# tsOTA\_PageReqServerParams

The following structure is used in the `tsOTA_CallBackMessage` structure \(see [Section 49.11.21](tsota_callbackmessage.md#id_312a27a2-f182-4f8b-a4e0-93a3d75ce9b5)\) on an OTA Upgrade server. It contains the data from an Image Page Request received from a client.

```
typedef struct
{
    uint8                      u8TransactionNumber;
    bool_t                     bPageReqRespSpacing;
    uint16                     u16DataSent;
    tsOTA_ImagePageRequest     sPageReq;
    tsZCL_ReceiveEventAddress  sReceiveEventAddress;
}tsOTA_PageReqServerParams;

```

where:

-   `u8TransactionNumber` is the Transaction Sequence Number \(TSN\) which is used in the Image Page Request

-   `bPageReqRespSpacing` is a boolean used to request a spacing between consecutive Image Block Responses:

    -   TRUE - Implement spacing
    -           FALSE - Otherwise
-   `u16DataSent` indicates the number of data bytes contained in the Image Page Request

-   `sPageReq` is a structure containing the payload data from the Image Page Request \(see [Section 49.11.9](tsota_imagepagerequest.md#id_70400234-ce69-45a1-b422-a7464d5aa3f0)\)

-   `sReceiveEventAddress` contains the address of the OTA Upgrade client that made the page request


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

