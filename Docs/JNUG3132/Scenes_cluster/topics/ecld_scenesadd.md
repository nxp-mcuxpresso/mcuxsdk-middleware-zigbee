# eCLD\_ScenesAdd

```
teZCL_Status eCLD_ScenesAdd(
    uint8 u8SourceEndPointId,
    uint16 u16GroupId,
    uint8 u8SceneId);   

```

## Description 

This function adds a new scene on the specified local endpoint - that is, adds an entry to the Scenes table on the endpoint. The group ID associated with the scene must also be specified \(or set to 0x0000 if there is no associated group\).

If a scene with the specified scene ID and group ID exists in the table, the existing entry is overwritten \(that is, all previous scene data in this entry is lost\).

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which Scene table entry is to be added.
-   *u16GroupId*: 16-bit group ID/address of associated group \(or 0x0000 if no group\).
-   *u8SceneId*: 8-bit scene ID of new scene.

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[Functions](../../Scenes_cluster/topics/functions.md)

