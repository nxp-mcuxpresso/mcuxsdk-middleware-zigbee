# Custom Data Structure

The IAS WD cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
 tsCLD_IASWD_SquawkReqPayload sSquawk;
 tsCLD_IASWD_StartWarningReqPayload sWarning;
 uint32   u32WarningDurationRemainingIn100MS;
 tsZCL_ReceiveEventAddress  sReceiveEventAddress;
 tsZCL_CallBackEvent  sCustomCallBackEvent;
 tsCLD_IASWDCallBackMessage sCallBackMessage;   
} tsCLD_IASWD_CustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../IAS_WD_cluster/topics/structures.md)

