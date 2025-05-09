# Custom Data Structure

The Scenes cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    DLIST   lScenesAllocList;
    DLIST   lScenesDeAllocList;
    tsZCL_ReceiveEventAddress       sReceiveEventAddress;
    tsZCL_CallBackEvent             sCustomCallBackEvent;
    tsCLD_ScenesCallBackMessage     sCallBackMessage;
    tsCLD_ScenesTableEntry
           asScenesTableEntry[CLD_SCENES_MAX_NUMBER_OF_SCENES];
} tsCLD_ScenesCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Scenes_cluster/topics/structures.md)

