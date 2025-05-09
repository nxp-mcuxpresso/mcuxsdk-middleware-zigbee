# tsSE\_Mirror

Details of the mirror endpoints on the ESP are kept in an array of structures of the type `tsSE_Mirror` \(one structure per endpoint\) within the `tsSE_EspMeterDevice` structure. The `tsSE_Mirror` structure is shown and described below.

**Note:** This structure is only for use by the ZCL and should not be modified by the application.

```
typedef struct
{
            /*Mirrored EndPoint*/
    tsZCL_EndPointDefinition sEndPoint;
    /*Mirror Requester address*/
    uint64        u64SourceAddress;
    /*Mirror cluster instances*/
    tsSE_MirrorClusterInstances         sSEMirrorClusterInstances;
    /*Event Address, Custom callback event, Custom callback message*/
    tsSM_CustomStruct sSMMirrorCustomDataStruct;
}tsSE_Mirror;

```

where:

-   `sEndPoint` is a `tsZCL_EndPointDefinition` structure which contains details of the endpoint corresponding to the mirror \(for details of this structure, refer to [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\)

-   `u64SourceAddress` is the 64-bit IEEE address of the Metering Device to which the mirror endpoint is assigned - a zero value indicates that the mirror endpoint is not currently assigned to a device

-   `sSEMirrorClusterInstances` is a `tsSE_MirrorClusterInstances` structure \(see [Section 42.11.3](tsse_mirrorclusterinstances.md#id_b3a727c0-c704-4b28-8b65-25e38b772051)\) which contains information on the Basic and Simple Metering cluster instances that are associated with the mirror endpoint

-   `sSMMirrorCustomDataStruct` is a `tsSM_CustomStruct` structure \(see [Section 42.11.4](tssm_customstruct.md#id_3df88a4b-a4a8-4aa3-b41f-f4983c605936)\) which contains data relating to a received command/message for the mirror endpoint


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

