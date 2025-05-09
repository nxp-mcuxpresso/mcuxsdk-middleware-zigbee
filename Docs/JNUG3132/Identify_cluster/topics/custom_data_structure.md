# Custom Data Structure

        The Identity cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    tsZCL_ReceiveEventAddress                     sReceiveEventAddress;
    tsZCL_CallBackEvent                                   sCustomCallBackEvent;
    tsCLD_IdentifyCallBackMessage         sCallBackMessage;
        } tsCLD_IdentifyCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Identify_cluster/topics/structures.md)

