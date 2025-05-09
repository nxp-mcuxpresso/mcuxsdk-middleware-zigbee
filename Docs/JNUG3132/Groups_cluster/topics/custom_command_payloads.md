# Custom Command Payloads

The following structures contain the payloads for the Groups cluster custom commands.

## Add Group Request Payload 

```
typedef struct
{
    zuint16                 u16GroupId;
    tsZCL_CharacterString   sGroupName;
} tsCLD_Groups_AddGroupRequestPayload;

```

where:

-   `u16GroupId` is the ID/address of the group to which the endpoints must be added.

-   `sGroupName` is the name of the group to which the endpoints must be added.


## View Group Request Payload 

```
typedef struct
{
    zuint16             u16GroupId;
} tsCLD_Groups_ViewGroupRequestPayload;

```

where `u16GroupId` is the ID/address of the group whose name is required

## Get Group Membership Request Payload 

```
typedef struct
{
    zuint8             u8GroupCount;
    zint16             *pi16GroupList;
} tsCLD_Groups_GetGroupMembershipRequestPayload;

```

where:

-   `u8GroupCount` is the number of groups in the list of the next field.

-   `pi16GroupList` is a pointer to a list of groups whose memberships are being queried, where each group is represented by its group ID/address.


## Remove Group Request Payload 

```
typedef struct
{
    zuint16            u16GroupId;
} tsCLD_Groups_RemoveGroupRequestPayload;

```

where `u16GroupId` is the ID/address of the group from which the endpoints must be removed.

**Parent topic:**[Structures](../../Groups_cluster/topics/structures.md)

