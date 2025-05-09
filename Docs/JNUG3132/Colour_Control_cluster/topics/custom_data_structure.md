# Custom Data Structure

The Colour Control cluster requires extra storage space to be allocated for use by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
    teCLD_ColourControl_ColourMode     eColourMode;
    uint16                             u16CurrentHue;
    tsCLD_ColourControl_Transition     sTransition;
    /* Matrices for XYZ <> RGB conversions */
    float                              afXYZ2RGB[3][3];
    float                              afRGB2XYZ[3][3];
    tsZCL_ReceiveEventAddress          sReceiveEventAddress;
    tsZCL_CallBackEvent                sCustomCallBackEvent;
    tsCLD_ColourControlCallBackMessage sCallBackMessage;
} tsCLD_ColourControlCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../Colour_Control_cluster/topics/structures.md)

