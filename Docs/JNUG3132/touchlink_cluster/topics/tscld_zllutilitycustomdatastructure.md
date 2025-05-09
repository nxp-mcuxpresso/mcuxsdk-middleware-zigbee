# tsCLD\_ZllUtilityCustomDataStructure

This structure is used to hold custom data for a Commissioning Utility instance of the Touchlink Commissioning cluster.

```
typedef struct
{
 tsZCL_ReceiveEventAddress sRxAddr;
 tsZCL_CallBackEvent sCustomCallBackEvent;
 tsCLD_ZllUtilityCallBackMessage sCallBackMessage;
} tsCLD_ZllUtilityCustomDataStructure;

```

where:

-   `sRxAddr` is a ZCL structure containing the destination address of the command.

-   `sCustomCallBackEvent` is the ZCL event structure for the command.

-   `sCallBackMessage` is a structure containing the command ID and payload \(see [Section 44.8.19](tscld_zllutilitycallbackmessage.md#id_93fed3ac-1151-469c-82cc-1416571b0420)\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

