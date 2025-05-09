# tsCLD\_CommissioningCustomDataStructure

The Commissioning cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    tsZCL_ReceiveEventAddress              sReceiveEventAddress;
    tsZCL_CallBackEvent                    sCustomCallBackEvent;
    tsCLD_CommissioningCallBackMessage     sCallBackMessage;
} tsCLD_CommissioningCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Commissioning_cluster/topics/structures.md)

