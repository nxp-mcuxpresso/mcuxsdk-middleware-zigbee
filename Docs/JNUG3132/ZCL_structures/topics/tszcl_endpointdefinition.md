# tsZCL\_EndPointDefinition

This structure defines the endpoint for an application:

```
struct tsZCL_EndPointDefinition
{
    uint8                       u8EndPointNumber;
    uint16                      u16ManufacturerCode;
    uint16                      u16ProfileEnum;
    bool_t                      bIsManufacturerSpecificProfile;
    uint16                      u16NumberOfClusters;
    tsZCL_ClusterInstance      *psClusterInstance;
    bool_t                      bDisableDefaultResponse;
    tfpZCL_ZCLCallBackFunction  pCallBackFunctions;
};

```

Where:

-   `u8EndPointNumber` is the endpoint number between 1 and 240 \(0 is reserved\)

-   `u16ManufacturerCode` is the manufacturer code \(only valid when `bIsManufacturerSpecificProfile` is set to TRUE\)

-   `u16ProfileEnum` is the ZigBee application profile ID

-   `bIsManufacturerSpecificProfile` indicates whether the application profile is proprietary \(TRUE\) or from the ZigBee Alliance \(FALSE\)

-   `u16NumberOfClusters` is the number of clusters on the endpoint

-   `psClusterInstance` is a pointer to an array of cluster instance structures

-   `bDisableDefaultResponse` can be used to disable the requirement for default responses to be returned for commands sent from the endpoint \(TRUE=disable, FALSE=enable\)

-   `pCallBackFunctions` is a pointer to the callback functions for the endpoint


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

