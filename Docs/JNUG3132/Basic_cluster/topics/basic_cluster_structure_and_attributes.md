# Basic Cluster structure and attributes

The Basic cluster is contained in the following `tsCLD_Basic` structure:

```
typedef struct
{
#ifdef BASIC_SERVER
    zuint8                 u8ZCLVersion;
#ifdef CLD_BAS_ATTR_APPLICATION_VERSION
    zuint8                 u8ApplicationVersion;
#endif
#ifdef CLD_BAS_ATTR_STACK_VERSION
    zuint8                u8StackVersion;
#endif
#ifdef CLD_BAS_ATTR_HARDWARE_VERSION
    zuint8                u8HardwareVersion;
#endif
#ifdef CLD_BAS_ATTR_MANUFACTURER_NAME
    tsZCL_CharacterString sManufacturerName;
uint8                     au8ManufacturerName[32];
#endif
#ifdef CLD_BAS_ATTR_MODEL_IDENTIFIER
    tsZCL_CharacterString sModelIdentifier;
    uint8                 au8ModelIdentifier[32];
#endif
#ifdef CLD_BAS_ATTR_DATE_CODE
    tsZCL_CharacterString sDateCode;
    uint8                 au8DateCode[16];
#endif
    zenum8                ePowerSource;
#ifdef CLD_BAS_ATTR_GENERIC_DEVICE_CLASS
    zenum8                eGenericDeviceClass;
#endif
#ifdef CLD_BAS_ATTR_GENERIC_DEVICE_TYPE
    zenum8                eGenericDeviceType;
#endif
#ifdef CLD_BAS_ATTR_PRODUCT_CODE
    tsZCL_OctetString    sProductCode;
uint8
au8ProductCode[CLD_BASIC_MAX_NUMBER_OF_BYTES_PRODUCT_CODE];
#endif
#ifdef CLD_BAS_ATTR_PRODUCT_URL
    tsZCL_CharacterString  sProductURL;
    uint8
    au8ProductURL[CLD_BASIC_MAX_NUMBER_OF_BYTES_PRODUCT_URL];
#endif
#ifdef CLD_BAS_ATTR_LOCATION_DESCRIPTION
    tsZCL_CharacterString  sLocationDescription;
    uint8                  au8LocationDescription[16];
#endif
#ifdef CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT
    zenum8                 u8PhysicalEnvironment;
#endif
#ifdef CLD_BAS_ATTR_DEVICE_ENABLED
    zbool                 bDeviceEnabled;
#endif
#ifdef CLD_BAS_ATTR_ALARM_MASK
    zbmap8                u8AlarmMask;
#endif
#ifdef CLD_BAS_ATTR_DISABLE_LOCAL_CONFIG
    zbmap8                u8DisableLocalConfig;
#endif
#ifdef CLD_BAS_ATTR_SW_BUILD_ID
    tsZCL_CharacterString sSWBuildID;
    uint8                 au8SWBuildID[16];
#endif
#endif
    zuint16              u16ClusterRevision;
} tsCLD_Basic;
```

where:

-   `u8ZCLVersion` is an 8-bit version number which represents a published set of foundation items, such as global commands and functional descriptions. Currently this should be set to 2.

-   `u8ApplicationVersion` is an optional 8-bit attribute which represents the version of the application \(and is manufacturer-specific\)

-   `u8StackVersion` is an optional 8-bit attribute which represents the version of the ZigBee stack used \(and is manufacturer-specific\)

-   `u8HardwareVersion` is an optional 8-bit attribute which represents the version of the hardware used for the device \(and is manufacturer-specific\)

-   The following optional pair of attributes are used to store the name of the manufacturer of the device:

    -   `sManufacturerName` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 32 characters representing the manufacturer’s name

    -   `au8ManufacturerName[32]` is a byte-array which contains the character data bytes representing the manufacturer’s name

-   The following optional pair of attributes are used to store the identifier for the model of the device:

    -   `sModelIdentifier` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 32 characters representing the model identifier

    -   `au8ModelIdentifier[32]` is a byte-array which contains the character data bytes representing the model identifier

-   The following optional pair of attributes are used to store manufacturing information about the device:

    -   `sDateCode` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters in which the 8 most significant characters contain the date of manufacture in the format YYYYMMDD and the 8 least significant characters contain manufacturer-defined information such as country of manufacture, factory identifier, production line identifier

    -   `au8DateCode[16]` is a byte-array which contains the character data bytes representing the manufacturing information


**Note:** The application device code automatically sets two of the fields of `sDataCode`. The field `sDataCode.pu8Data` is set to point at `au8DateCode`and the field `sDataCode.u8MaxLength`is set to 16 \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b) for details of these fields\).

-   `ePowerSource` is an 8-bit value in which seven bits indicate the primary power source for the device \(e.g. battery\) and one bit indicates whether there is a secondary power source for the device. Enumerations are provided to cover all possibilities - see [Section 8.5.2](tecld_bas_powersource.md#id_a4b93b62-64c9-4f9f-b68c-40e997d39ad5)


**Note:** The power source in the Basic cluster is completely unrelated to the Node Power descriptor in the ZigBee PRO stack. The power source in the ZigBee PRO stack is set using the ZPS Configuration Editor.

-   `eGenericDeviceClass` is an optional attribute that identifies the field of application in which the local device type operates \(see `eGenericDeviceType` below\). Enumerations are provided - see [Section 8.5.3](tecld_bas_genericdeviceclass.md#id_1c4aa542-b89c-43e8-9555-737a0ca1fb9f). Currently, the attribute is used only in lighting applications, for which the value is 0x00 \(all other values are reserved\).

-   `eGenericDeviceType` is an optional attribute that identifies the local device type. Enumerations are provided to cover the different possibilities - see [Section 8.5.4](ecld_bas_genericdevicetype.md#id_d5298bec-1163-42b4-8b8f-7d950400fcc5). Currently, the attribute is used only in lighting applications.

-   The following optional pair of attributes are used to store a code for the product \(this attribute may be used in lighting applications only\):

    -   `sProductCode` is a `tsZCL_OctetString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string representing the product code - the maximum number of characters is defined at compile-time \(see [Section 8.6](compile-time_options.md#id_109edd98-be6b-4f11-b13a-edf11be44178)\) using the macro CLD\_BASIC\_MAX\_NUMBER\_OF\_BYTES\_PRODUCT\_CODE.

    -   `au8ProductCode[``]` is a byte-array which contains the character data bytes representing the product code - the number of array elements, and therefore characters, is determined at compile-time, as indicated above.

-   The following optional pair of attributes are used to store a URL for the product \(this attribute may be used in lighting application only\):

    -   `sProductURL` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a character string representing the product URL - the maximum number of characters is defined at compile-time \(see [Section 8.6](compile-time_options.md#id_109edd98-be6b-4f11-b13a-edf11be44178)\) using the macro CLD\_BASIC\_MAX\_NUMBER\_OF\_BYTES\_PRODUCT\_URL.

    -   `au8ProductURL[``]` is a byte-array which contains the character data bytes representing the product URL - the number of array elements, and therefore characters, is determined at compile-time, as indicated above.

-   The following optional pair of attributes relates to the location of the device:

    -   `sLocationDescription` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 16 characters representing the location of the device

    -   `au8LocationDescription[16]` is a byte-array which contains the character data bytes representing the location of the device

-   `u8PhysicalEnvironment` is an optional 8-bit attribute which indicates the physical environment of the device. Enumerations are provided to cover the different possibilities - see [Section 8.5.5](tecld_bas_physicalenvironment.md#id_487b82e2-fbdd-4d63-8498-d1d3c52dd427).

-   `bDeviceEnabled` is an optional Boolean attribute which indicates whether the device is enabled \(TRUE\) or disabled \(FALSE\). A disabled device cannot send or respond to application level commands other than commands to read or write attributes

-   `u8AlarmMask` is an optional bitmap indicating the general alarms that can be generated \(Bit 0 - general software alarm, Bit 1 - general hardware alarm\)

-   `u8DisableLocalConfig` is an optional bitmap allowing the local user interface of the device to be disabled \(Bit 0 - ‘Reset to factory defaults’ buttons, Bit 1 - ‘Device configuration’ buttons\)

-   The following optional pair of attributes are used to store a manufacturer-specific software build identifier:

    -   `sSWBuildID` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 16 characters representing the software build identifier

    -   `au8SWBuildID[16]` is a byte-array which contains the character data bytes representing the software build identifier.

    -   u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)


The Basic cluster structure contains three mandatory elements: `u``8ZCLVersion`, `e``PowerSource` and `u16ClusterRevision`. The remaining elements are optional, each being enabled/disabled through a corresponding macro defined in the **zcl\_options.h** file - for example, the attribute `u8ApplicationVersion` is enabled/disabled using the enumeration CLD\_BAS\_ATTR\_APPLICATION\_VERSION \(see [Section 8.3](mandatory_attribute_settings.md#id_97b8f5c8-3bfa-4305-afdd-dc811d3ccdf5)\).

The mandatory attribute settings are described further in [Section 8.3](mandatory_attribute_settings.md#id_97b8f5c8-3bfa-4305-afdd-dc811d3ccdf5).

**Parent topic:**[Basic Cluster](../../Basic_cluster/topics/basic_cluster.md)

