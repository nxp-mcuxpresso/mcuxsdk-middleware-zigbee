# Custom Command Responses

The Scenes cluster generates responses to certain custom commands. The responses which contain payloads are detailed below:

## Add Scene Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesAddSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the Add Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the added scene is associated

-   `u8SceneId` is the scene ID of the added scene


## View Scene Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
    uint8                       u8SceneId;
    uint16                      u16TransitionTime;
    tsZCL_CharacterString       sSceneName;
    tsCLD_ScenesExtensionField  sExtensionField;
} tsCLD_ScenesViewSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the View Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the viewed scene is associated

-   `u8SceneId` is the scene ID of the viewed scene

-   `u16TransitionTime` is the amount of time, in seconds, that the device takes to switch to the viewed scene

-   `sSceneName` is an optional character string \(of up to 16 characters\) representing the name of the viewed scene

-   `sExtensionField` is a structure containing the attribute values of the clusters to which the viewed scene relates


## Remove Scene Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesRemoveSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the Remove Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the removed scene is associated

-   `u8SceneId` is the scene ID of the removed scene


## Remove All Scenes Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
} tsCLD_ScenesRemoveAllScenesResponsePayload;

```

where:

-   `eStatus` is the outcome of the Remove All Scenes command \(success or invalid\)

-   `u16GroupId` is the group ID with which the removed scenes are associated


## Store Scene Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
    uint8                       u8SceneId;
} tsCLD_ScenesStoreSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the Store Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the stored scene is associated

-   `u8SceneId` is the scene ID of the stored scene


## Get Scene Membership Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint8                       u8Capacity;
    uint16                      u16GroupId;
    uint8                       u8SceneCount;
    uint8                       *pu8SceneList;
} tsCLD_ScenesGetSceneMembershipResponsePayload;

```

where:

-   `eStatus` is the outcome of the Get Scene Membership command \(success or invalid\)

-   `u8Capacity` is the capacity of the Scene table of the device to receive more scenes - that is, the number of scenes that may be added \(special values: 0xFE means that at least one more scene may be added, a higher value means that the remaining capacity of the table is unknown\)

-   `u16GroupId` is the group ID to which the query relates

-   `u8SceneCount` is the number of scenes in the list of the next field

-   `pu8SceneList` is a pointer to the returned list of scenes from those queried that exist on the device, where each scene is represented by its scene ID


## Enhanced Add Scene Response Payload 

```
typedef struct
{
    zenum8     eStatus;
    uint16     u16GroupId;
    uint8      u8SceneId;
} tsCLD_ScenesEnhancedAddSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the Enhanced Add Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the added scene is associated

-   `u8SceneId` is the scene ID of the added scene


## Enhanced View Scene Response Payload 

```
typedef struct
{
    zenum8                      eStatus;
    uint16                      u16GroupId;
    uint8                       u8SceneId;
    uint16                      u16TransitionTime;
    tsZCL_CharacterString       sSceneName;
    tsCLD_ScenesExtensionField  sExtensionField;
} tsCLD_ScenesEnhancedViewSceneResponsePayload;

```

where:

-   `eStatus` is the outcome of the Enhanced View Scene command \(success or invalid\)

-   `u16GroupId` is the group ID with which the viewed scene is associated

-   `u8SceneId` is the scene ID of the viewed scene

-   `u16TransitionTime` is the amount of time, in seconds, that the device takes to switch to the viewed scene

-   `sSceneName` is an optional character string \(of up to 16 characters\) representing the name of the viewed scene

-   `sExtensionField` is a structure containing the attribute values of the clusters to which the viewed scene relates


## Copy Scene Response Payload 

```
typedef struct
{
    uint8       u8Status;
    uint16      u16FromGroupId;
    uint8       u8FromSceneId;
} tsCLD_ScenesCopySceneResponsePayload;

```

where:

-   `u8Status` is the outcome of the Copy Scene command \(success, invalid scene, or insufficient space for new scene\)

-   `u16FromGroupId` is the source group ID for the copy

-   `u8FromSceneId` is the source scene ID for the copy


**Parent topic:**[Structures](../../Scenes_cluster/topics/structures.md)

