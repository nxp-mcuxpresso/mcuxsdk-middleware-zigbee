# tsZCL\_SceneExtensionTable

This structure contains a Scenes Extension table.

```
typedef struct
{
    tfpZCL_SceneEventHandler    pSceneEventHandler;
    uint16                      u16NumberOfAttributes;
    uint16                      au16Attributes[];
} tsZCL_SceneExtensionTable;

```

Where:

-   `pSceneEventHandler` is a pointer a Scenes event handler function

-   `u16NumberOfAttributes` is the number of attributes in the Scene extension

-   `au16Attributes` is an array of the attribute IDs of the attributes in the Scene extension


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

