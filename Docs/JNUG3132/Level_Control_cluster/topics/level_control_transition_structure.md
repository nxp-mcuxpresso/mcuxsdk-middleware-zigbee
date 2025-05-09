# Level Control Transition Structure

The following structure is used to store information about an ongoing level transition.

```
typedef struct
{
    teCLD_LevelControl_Transition   eTransition;
    teCLD_LevelControl_MoveMode     eMode;
    bool bWithOnOff;
    int  iCurrentLevel;
    int  iTargetLevel;
    int  iPreviousLevel;
    int  iStepSize;
    uint32     u32Time;
} tsCLD_LevelControl_Transition;

```

where:

-   `eTransition` is an enumeration indicating the type of level transition implemented - for the enumerations, see [Section 16.9.2](tecld_levelcontrol_transition.md#id_3f424014-285f-4a0f-a584-82a334b72c0e).
-   `eMode` is an enumeration indicating the direction in which the level is moved during the transition - for the enumerations, see [Section 16.9.3](tecld_levelcontrol_movemode.md#id_2c2bcf2b-e0cd-4f07-ada7-7b0471c693dc)
-   `bWithOnOff` is a boolean which is set to TRUE if the transition is implemented with the On/Off cluster \(or FALSE otherwise\). When enabled:
    -   If the transition is to increase the level, the OnOff attribute of the On/Off cluster is set to ‘on’.
    -   If the transition decreases the level to the minimum permissible level for the device, the OnOff attribute of the On/Off cluster is set to ‘off’.
-   `iCurrentLevel` is the current level \(0x01-0xFE\) during the transition.
-   `iTargetLevel` is the target level \(0x01-0xFE\) of the transition.
-   `iPreviousLevel` is the previous level \(0x01-0xFE\) during the transition.
-   `iStepSize` is the size of a single step of the transition.
-   `u32Time` is the total time for the transition, in tenths of a second.

**Parent topic:**[Structures](../../Level_Control_cluster/topics/structures.md)

