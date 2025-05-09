# tsOTA\_ImageBlockResponsePayload

The following structure contains payload data for an Image Block Response issued by the server \(as the result of an Image Block Request from a client\):

```
typedef struct
{
            uint8 u8Status;
            union
            {
                         tsOTA_WaitForData                   sWaitForData;
         tsOTA_SuccessBlockResponsePayload   sBlockPayloadSuccess;
            }uMessage;
}tsOTA_ImageBlockResponsePayload;

```

where:

-                   `u8Status` indicates whether a data block is included in the response:

    -   OTA\_STATUS\_SUCCESS: A data block is included

    -   OTA\_STATUS\_WAIT\_FOR\_DATA: No data block is included - client should re-request a data block after a waiting time

-   The element used from the union depends on the status reported above:

    -   `sWaitForData` is a structure containing information used to instruct the requesting client to wait for a time before requesting the data block again or requesting the next data block \(see [Section 49.11.15](tsota_waitfordata.md#id_d698b23b-cb16-4ed2-80a0-e56aa8c1061a)\) - this information is only provided in the case of the status OTA\_STATUS\_WAIT\_FOR\_DATA

    -   `sBlockPayloadSuccess` is a structure containing a requested data block and associated information \(see [Section 49.11.13](tsota_successblockresponsepayload.md#id_695eaf9c-84f6-4191-9f6d-50413e62a4de)\) - this data is only provided in the case of the status OTA\_STATUS\_SUCCESS


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

