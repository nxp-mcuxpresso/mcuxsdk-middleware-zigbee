# tsCLD\_PollControlCustomDataStructure

The Poll Control cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
#ifdef POLL_CONTROL_SERVER 
    tsCLD_PollControlParameters         sControlParameters;
#endif    
    tsZCL_ReceiveEventAddress           sReceiveEventAddress;
    tsZCL_CallBackEvent                 sCustomCallBackEvent;
    tsCLD_PollControlCallBackMessage    sCallBackMessage;
} tsCLD_PollControlCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../poll_control_cluster/topics/structures.md)

