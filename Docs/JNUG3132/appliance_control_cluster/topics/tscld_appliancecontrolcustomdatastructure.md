# tsCLD\_ApplianceControlCustomDataStructure

The Appliance Control cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    tsZCL_ReceiveEventAddress                 sReceiveEventAddress;
    tsZCL_CallBackEvent                       sCustomCallBackEvent;
    tsCLD_ApplianceControlCallBackMessage     sCallBackMessage;
} tsCLD_ApplianceControlCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../appliance_control_cluster/topics/structures.md)

