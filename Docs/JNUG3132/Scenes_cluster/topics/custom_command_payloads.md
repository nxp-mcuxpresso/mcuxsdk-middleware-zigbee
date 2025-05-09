# Custom Command Payloads

The following structures contain the payloads for the Scenes cluster custom commands.

## Add Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
    uint16                      u16TransitionTime;
    tsZCL_CharacterString       sSceneName;
    tsCLD_ScenesExtensionField  sExtensionField;
} tsCLD_ScenesAddSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the scene is associated \(0x0000 if there is no association with a group\)

-   `u8SceneId` is the ID of the scene to be added to the Scene table \(the Scene ID must be unique within the group associated with the scene\)

-   `u16TransitionTime` is the amount of time, in seconds, that the device takes to switch to this scene

-   `sSceneName` is an optional character string \(of up to 16 characters\) representing the name of the scene

-   `sExtensionField` is a structure containing the attribute values of the clusters to which the scene relates


## View Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesViewSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the desired scene is associated

-   `u8SceneId` is the scene ID of the scene to be viewed


## Remove Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesRemoveSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the relevant scene is associated

-   `u8SceneId` is the scene ID of the scene to be deleted from the Scene table


## Remove All Scenes Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
} tsCLD_ScenesRemoveAllScenesRequestPayload;

```

where `u16GroupId` is the group ID for which all scenes are to be deleted.

## Store Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesStoreSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the relevant scene is associated

-   `u8SceneId` is the scene ID of the scene in which the captured cluster settings are to be stored


## Recall Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesRecallSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the relevant scene is associated

-   `u8SceneId` is the scene ID of the scene from which cluster settings are to be retrieved and applied


## Get Scene Membership Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
} tsCLD_ScenesGetSceneMembershipRequestPayload;

```

where `u16GroupId` is the group ID for which associated scenes are required.

## Enhanced Add Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
    uint16                      u16TransitionTime100ms;
    tsZCL_CharacterString       sSceneName;
    tsCLD_ScenesExtensionField  sExtensionField;
} tsCLD_ScenesEnhancedAddSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the scene is associated \(0x0000 if there is no association with a group\)

-   `u8SceneId` is the ID of the scene to be added to the Scene table \(the Scene ID must be unique within the group associated with the scene\)

-   `u16TransitionTime100ms` is the amount of time, in tenths of a second, that the device takes to switch to this scene

-   `sSceneName` is an optional character string \(of up to 16 characters\) representing the name of the scene

-   `sExtensionField` is a structure containing the attribute values of the clusters to which the scene relates


## View Scene Request Payload 

```
typedef struct
{
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesEnhancedViewSceneRequestPayload;

```

where:

-   `u16GroupId` is the group ID with which the desired scene is associated

-   `u8SceneId` is the scene ID of the scene to be viewed


## Copy Scene Request Payload 

```
typedef struct
{
    uint8       u8Mode;
    uint16      u16FromGroupId;
    uint8       u8FromSceneId;
    uint16      u16ToGroupId;
    uint8       u8ToSceneId;
} tsCLD_ScenesCopySceneRequestPayload;

```

where:

-   `u8Mode` is a bitmap indicating the required copying mode \(only bit 0 is used\):

    -   If bit 0 is set to ‘1’, then ‘copy all scenes’ mode is used, in which all scenes associated with the source group are duplicated for the destination group \(and the scene ID fields are ignored\)

    -   If bit 0 is set to ‘0’, then a single scene is copied

-   `u16FromGroupId` is the source group ID

-   `u8FromSceneId` is the source scene ID \(ignored for ‘copy all scenes’ mode\)

-   `u16ToGroupId` is the destination group ID

-   `u8ToSceneId` is the destination scene ID \(ignored for ‘copy all scenes’ mode\)


**Parent topic:**[Structures](../../Scenes_cluster/topics/structures.md)

