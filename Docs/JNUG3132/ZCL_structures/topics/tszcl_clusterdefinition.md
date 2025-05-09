# tsZCL\_ClusterDefinition

This structure defines a cluster used on a device:

```
typedef struct
{
    uint16                      u16ClusterEnum;
    bool_t                      bIsManufacturerSpecificCluster;
    uint8                       u8ClusterControlFlags;
    uint16                      u16NumberOfAttributes;
    tsZCL_AttributeDefinition  *psAttributeDefinition;
    tsZCL_SceneExtensionTable  *psSceneExtensionTable;
#ifdef ZCL_COMMAND_DISCOVERY_SUPPORTED    
    uint8                       u8NumberOfCommands;
    tsZCL_CommandDefinition    *psCommandDefinition;
#endif 
}  tsZCL_ClusterDefinition;

```

Where:

-   `u16ClusterEnum` is the Cluster ID.

-   `bIsManufacturerSpecificCluster` indicates whether the cluster is specific to a manufacturer \(proprietary\):

    -   TRUE - proprietary cluster

    -   FALSE - ZigBee cluster


```

```

u8ClusterControlFlags is a bitmap containing control bits in two parts, as follows:

|**Bits**|**Description**|**Values**|
|--------|---------------|----------|
|0 - 3|Type of security|Indicates the type of security key used via one of the following `teZCL_ZCLSendSecurity` enumerations \(see [Section 7.1.6](../../ZCL_enums_codes/topics/security_level_tezcl_zclsendsecurity.md#id_08a7b679-9310-42d7-a895-85641a70da29)\):

 | Bits  | Description      | Values                                                                                                                                                                                                                                                 |
| ----- | ---------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 0 - 3 | Type of security | Indicates the type of security key used via one of the following teZCL_ZCLSend Security enumerations (see [Section 7.1.6](../../ZCL_enums_codes/topics/security_level_tezcl_zclsendsecurity.md#id_08a7b679-9310-42d7-a895-85641a70da29)\):   E_ZCL_SECURITY_NETWORK, E_ZCL_SECURITY_APPLINK<br>•  E_ZCL_SECURITY_TEMP_APPLINK<br>(this option is for internal use only) |
| 4 - 7 | Cluster mirror   | Used internally to indicate whether the cluster is mirrored, as follows:<br>•  0000b - Not mirrored,1000b - Mirrored, All other values are reserved                                                                                                    |                                                                                                                                                                                                                                                                       |
-   `u16NumberOfAttributes` indicates the number of attributes in the cluster.

-   `psAttributeDefinition` is a pointer to an array of attribute definition structures - see [Section 6.1.3](tszcl_attributedefinition.md#id_8dae1bbb-5a10-4217-90e5-5a58a908f58c).

-   `psSceneExtensionTable` is a pointer to a structure containing a Scene Extension table - see [Section 6.1.20](tszcl_sceneextensiontable.md#id_621389ba-7b40-45e3-a7ea-843aff3ba60e).

-   The following optional pair of fields are related to the Command Discovery feature \(see [Section 2.9](../../ZCL_fundamentals/topics/command_discovery.md#id_49f32120-da2a-4a82-87b4-9f9f8cb1b193)\):

    -   `u8NumberOfCommands` is the number of supported commands in the Command Definition table \(see below\).

    -   `psCommandDefinition` is a pointer to a Command Definition table which contains a list of the commands supported by the cluster - each entry of the table contains the details of a supported command in a `tsZCL_CommandDefinition` structure \(see [Section 6.1.19](tszcl_commanddefinition.md#id_acf0d9f8-9ce3-46e9-b441-9ec894b091ee)\).


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

