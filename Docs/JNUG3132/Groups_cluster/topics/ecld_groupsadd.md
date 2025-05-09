# eCLD\_GroupsAdd

```
teZCL_Status eCLD_GroupsAdd(uint8 u8SourceEndPointId,
    uint16 u16GroupId,
    uint8 *pu8GroupName);

```

## Description 

This function adds the specified endpoint on the local node to the group with the specified group ID/address and specified group name. The relevant entry is modified in the Group table on the local endpoint \(of the calling application\). If the group does not currently exist, it is created by adding a new entry for the group to the Group table.

Note that the number of entries in the Group table must not exceed the value of CLD\_GROUPS\_MAX\_NUMBER\_OF\_GROUPS defined at compile time \(see [Section 12.8](compile-time_options.md#id_fefc101c-dbca-44f4-8450-a52e943b55e9)\).

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint to be added to group.
-   *u16GroupId*: 16-bit group ID/address of group.
-   *pu8GroupName*: Pointer to character string representing name of group.

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Groups_cluster/topics/functions.md)

