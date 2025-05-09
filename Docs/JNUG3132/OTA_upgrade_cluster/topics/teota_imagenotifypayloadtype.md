# teOTA\_ImageNotifyPayloadType

The following enumerations represent the payload options for an Image Notify message issued by the server:

```
typedef enum 
{
    E_CLD_OTA_QUERY_JITTER,
    E_CLD_OTA_MANUFACTURER_ID_AND_JITTER,
    E_CLD_OTA_ITYPE_MDID_JITTER,
    E_CLD_OTA_ITYPE_MDID_FVERSION_JITTER
}teOTA_ImageNotifyPayloadType;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_OTA\_QUERY\_JITTER|Include only ‘Query Jitter’ in payload|
|E\_CLD\_OTA\_MANUFACTURER\_ID\_AND\_JITTER|Include ‘Manufacturer Code’ and ‘Query Jitter’ in payload|
|E\_CLD\_OTA\_ITYPE\_MDID\_JITTER|Include ‘Image Type’, ‘Manufacturer Code’ and ‘Query Jit-ter’ in payload|
|E\_CLD\_OTA\_ITYPE\_MDID\_FVERSION\_JITTER|Include ‘Image Type’, ‘Manufacturer Code’, ‘File Version’ and ‘Query Jitter’ in payload|

**Parent topic:**[Enumerations](../../OTA_upgrade_cluster/topics/enumerations.md)

