# Cluster structure and attributes

The structure definition for the Appliance Identification cluster \(server\) is:

```
typedef struct
{
#ifdef APPLIANCE_IDENTIFICATION_SERVER    
    zbmap56   u64BasicIdentification;
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_COMPANY_NAME
tsZCL_CharacterString   sCompanyName;
uint8   au8CompanyName[16];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_COMPANY_ID
    zuint16  u16CompanyId;
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_BRAND_NAME
    tsZCL_CharacterString  sBrandName;
    uint8    au8BrandName[16];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_BRAND_ID
    zuint16   u16BrandId;
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_MODEL
    tsZCL_OctetStrings   Model;
    uint8 au8Model[16];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_PART_NUMBER
    tsZCL_OctetString  sPartNumber;
    uint8   au8PartNumber[16];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_REVISION
    tsZCL_OctetString    sProductRevision;
    uint8     au8ProductRevision[6];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_SOFTWARE_REVISION
    tsZCL_OctetString    sSoftwareRevision;
    uint8     au8SoftwareRevision[6];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_TYPE_NAME
    tsZCL_OctetString    sProductTypeName;
    uint8     au8ProductTypeName[2];
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_TYPE_ID
    zuint16   u16ProductTypeId;
#endif
#ifdef CLD_APPLIANCE_IDENTIFICATION_ATTR_CECED_SPEC_VERSION
    zuint8   u8CECEDSpecificationVersion;
#endif
#endif
    zuint16   u16ClusterRevision;
} tsCLD_ApplianceIdentification;

```

where:

## ‘Basic Appliance Identification’ Attribute Set 

-   `u64BasicIdentification` is a mandatory attribute which is a 56-bit bitmap containing the following information about the appliance:


|**Bits**|**Information**|
|--------|---------------|
|0-15|Company \(manufacturer\) ID|
|16-31|Brand ID|
|32-47|Product Type ID, one of:

 -   0x0000: White Goods

-   0x5601: Dishwasher

-   0x5602: Tumble Dryer

-   0x5603: Washer Dryer

-   0x5604: Washing Machine

-   0x5E03: Hob

-   0x5E09: Induction Hob

-   0x5E01: Oven

-   0x5E06: Electrical Oven

-   0x6601: Refrigerator/Freezer


 For enumerations, see [Section 46.5.2](product_type_id_enumerations.md#id_80728e19-6a3b-489f-8116-c2f57a3e096f).

|
|48-55|Specification Version|

## ‘Extended Appliance Identification’ Attribute Set 

-   The following optional pair of attributes are used to store human readable versions of the company \(manufacturer\) name:

    -   `sCompanyName` is a `tsZCL_OctetString` structure which contains a character string representing the company name of up to 16 characters

    -   `au8CompanyName[16]` is a byte-array which contains the character data bytes representing the company name

-   `u16CompanyId` is an optional attribute which contains the company ID

-   The following optional pair of attributes are used to store human readable versions of the brand name:

    -   `sBrandName` is a `tsZCL_OctetString` structure which contains a character string representing the brand name of up to 16 characters

    -   `au8BrandName[16]` is a byte-array which contains the character data bytes representing the brand name

-   `u16BrandId` is an optional attribute which contains the brand ID

-   The following optional pair of attributes are used to store human readable versions of the manufacturer-defined model name:

    -   `sModel` is a `tsZCL_OctetString` structure which contains a character string representing the model name of up to 16 characters

    -   `au8Model[16]` is a byte-array which contains the character data bytes representing the model name

-   The following optional pair of attributes are used to store human readable versions of the manufacturer-defined part number/code:

    -   `sPartNumber` is a `tsZCL_OctetString` structure which contains a character string representing the part number/code of up to 16 characters

    -   `au8PartNumber[16]` is a byte-array which contains the character data bytes representing the part number/code

-   The following optional pair of attributes are used to store human readable versions of the manufacturer-defined product revision number:

    -   `sProductRevision` is a `tsZCL_OctetString` structure which contains a character string representing the product revision number of up to 6 characters

    -   `au8ProductRevision[6]` is a byte-array which contains the character data bytes representing the product revision number

-   The following optional pair of attributes are used to store human readable versions of the manufacturer-defined software revision number:

    -   `sSoftwareRevision` is a `tsZCL_OctetString` structure which contains a character string representing the software revision number of up to 6 characters

    -   `au8SoftwareRevision[6]` is a byte-array which contains the character data bytes representing the software revision number

-   The following optional pair of attributes are used to store human readable versions of the 2-character product type name \(e.g. "WM" for washing machine\):

    -   `sProductTypeName` is a `tsZCL_OctetString` structure which contains a character string representing the product type name of up to 2 characters

    -   `au8ProductTypeName[2]` is a byte-array which contains the character data bytes representing the product type name

-   `u16ProductTypeId` is an optional attribute containing the product type ID \(from those listed above in the description of `u64BasicIdentification`\)

-   `u8CECEDSpecificationVersion` is an optional attribute which indicates the version of the CECED specification to which the appliance conforms, from the following:


|**Value**|**Specification**|
|---------|-----------------|
|0x10|Compliant with v1.0, not certified|
|0x1A|Compliant with v1.0, certified|
|0xX0|Compliant with vX.0, not certified|
|0xXA|Compliant with vX.0, certified|

## Global Attributes 

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Appliance Identification Cluster](../../appliance_identification_cluster/topics/appliance_identification_cluster.md)

