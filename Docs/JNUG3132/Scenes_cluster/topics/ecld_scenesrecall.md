# eCLD\_ScenesRecall

```
teZCL_Status eCLD_ScenesRecall(
    uint8 u8SourceEndPointId,
    uint16 u16GroupId,
    uint8 u8SceneId);

```

## Description 

This function obtains the attribute values \(from the extension fields\) of the scene with the specified Scene ID and Group ID on the specified \(local\) endpoint, and sets the corresponding cluster attributes on the device to these values. Thus, the function reads the stored attribute values for a scene and implements them on the device.

Note that the values of any cluster attributes that are not included in the scene remains unchanged.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint containing Scene table to be read.
-   *u16GroupId*: 16-bit group ID/address of associated group \(or 0x0000 if no group\)
-   *u8SceneId*: 8-bit scene ID of scene to be read.

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[Functions](../../Scenes_cluster/topics/functions.md)

