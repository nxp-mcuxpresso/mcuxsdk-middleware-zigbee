# Custom Command Responses

The Groups cluster generates responses to certain custom commands. The responses which contain payloads are detailed below:

## Add Group Response Payload 

```
typedef struct
{
    zenum8            eStatus;
    zuint16            u16GroupId;
} tsCLD_Groups_AddGroupResponsePayload;

```

where:

-   `eStatus` is the status \(success or failure\) of the requested group addition.

-   `u16GroupId` is the ID/address of the group to which endpoints were added.


## View Group Response Payload 

```
typedef struct
{
    zenum8                  eStatus;
    zuint16                 u16GroupId;
    tsZCL_CharacterString   sGroupName;
} tsCLD_Groups_ViewGroupResponsePayload;

```

where:

-   `eStatus` is the status \(success or failure\) of the requested operation.

-   `u16GroupId` is the ID/address of the group whose name was requested.

-   `sGroupName` is the returned name of the specified group.


## Get Group Membership Response Payload 

```
typedef struct
{
    zuint8                  u8Capacity;
    zuint8                  u8GroupCount;
    zint16                 *pi16GroupList;
} tsCLD_Groups_GetGroupMembershipResponsePayload;

```

where:

-   `u8Capacity` is the capacity of the Group table of the device to receive more groups - that is, the number of groups that may be added \(special values: 0xFE means that at least one additional group may be added, a higher value means that the remaining capacity of the table is unknown\).

-   `u8GroupCount` is the number of groups in the list of the next field.

-   `pi16GroupList` is a pointer to the returned list of groups from those queried that exist on the device, where each group is represented by its group ID/address.


## Remove Group Response Payload 

```
typedef struct
{
    zenum8               eStatus;
    zuint16              u16GroupId;
} tsCLD_Groups_RemoveGroupResponsePayload;

```

where:

-   `eStatus` is the status \(success or failure\) of the requested group modification.

-   `u16GroupId` is the ID/address of the group from which endpoints were removed.


**Parent topic:**[Structures](../../Groups_cluster/topics/structures.md)

