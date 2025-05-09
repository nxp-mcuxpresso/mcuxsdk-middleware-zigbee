# Group Table Entry

The following structure contains a Group table entry.

```
typedef struct
{
    DNODE   dllGroupNode;
    uint16  u16GroupId;
    uint8   au8GroupName[CLD_GROUPS_MAX_GROUP_NAME_LENGTH + 1];
} tsCLD_GroupTableEntry;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Groups_cluster/topics/structures.md)

