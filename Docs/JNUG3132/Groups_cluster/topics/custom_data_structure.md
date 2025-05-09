# Custom Data Structure

The Groups cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    DLIST                    lGroupsAllocList;
    DLIST                    lGroupsDeAllocList;
    bool                    bIdentifying;
    tsZCL_ReceiveEventAddress    sReceiveEventAddress;
    tsZCL_CallBackEvent          sCustomCallBackEvent;
    tsCLD_GroupsCallBackMessage  sCallBackMessage;
#if (defined CLD_GROUPS) && (defined GROUPS_SERVER)
    tsCLD_GroupTableEntry 
          asGroupTableEntry[CLD_GROUPS_MAX_NUMBER_OF_GROUPS];
#endif
} tsCLD_GroupsCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

However, the structure `tsCLD_GroupTableEntry` used for the Group table entries is shown in [Section 12.6.2](group_table_entry.md#id_9b9808be-18ff-4066-95f1-4f01a074cede).

**Parent topic:**[Structures](../../Groups_cluster/topics/structures.md)

