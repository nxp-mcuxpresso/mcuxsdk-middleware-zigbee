# Scenes Table Entry

The following structure contains the data for a Scenes table entry \(containing a saved scene\):

```
typedef struct
{
    DNODE          dllScenesNode;
    bool           bActive;
    bool           bInTransit;
    uint16         u16GroupId;
    uint8          u8SceneId;
    uint16         u16TransitionTime;
    uint32         u32TransitionTimer;
    uint8          u8SceneNameLength;
    uint8          au8SceneName[CLD_SCENES_MAX_SCENE_NAME_LENGTH + 1];
    uint16         u16SceneDataLength;
    uint8          au8SceneData[CLD_SCENES_MAX_SCENE_STORAGE_BYTES];
#ifdef  CLD_SCENES_TABLE_SUPPORT_TRANSITION_TIME_IN_MS
    uint8          u8TransitionTime100ms;
#endif
} tsCLD_ScenesTableEntry;

```

where:

-   `bActive` is a boolean value indicating whether the scene is active \(TRUE\) or inactive \(FALSE\).
-   `bInTransit` is a boolean value indicating whether the scene is in a transitional state \(TRUE\) or a constant active/inactive state \(FALSE\).
-   `u16GroupId` is the identifier of the group to which the scene applies \(the value 0x0000 is used to indicate that the scene is not associated with a group\).
-   `u8SceneId` is the identifier of the scene and must be a unique value within the group with which the scene is associated.
-   `u16TransitionTime` is the length of time, in seconds, that the device takes to move from its current state to the scene state.
-   `u32TransitionTimer` is the elapsed time, in milliseconds, since the start of a currently active transition to the scene.
-   `u8SceneNameLength` is the number of characters in the name of the scene \(and therefore the size of the array `au8SceneName[]` below\). The value must not be greater than CLD\_SCENES\_MAX\_SCENE\_NAME\_LENGTH, which is set in the compile-time options \(see [Section 13.9](compile-time_options.md)\).
-   `au8SceneName[]` is an array containing the name of the scene, with one ASCII character in each array element. The number of elements in the array must be set in `u8SceneNameLength` above.
-   `u16SceneDataLength` is the number of items of data for the scene \(and therefore the size of the array `au8SceneData[]` below\). The value must not be greater than CLD\_SCENES\_MAX\_SCENE\_STORAGE\_BYTES, which is set in the compile-time options \(see [Section 13.9](compile-time_options.md)\).
-   `au8SceneData[]` is an array containing the data for the scene, with one data item in each array element. The data stored is dependent on the cluster to which the scene data applies. The number of elements in the array must be set in `u16SceneDataLength` above.
-   `u8TransitionTime` 100 ms is an optional that allows a fractional part to be added to the transition time \(`u16TransitionTime`\) of the scene. This value represents the number of tenths of a second in the range 0x00 to 0x09.

**Parent topic:**[Structures](../../Scenes_cluster/topics/structures.md)

