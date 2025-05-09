# Step Command Payload

```
typedef struct
{
    uint8                   u8StepMode;
    uint8                   u8StepSize;
    uint16                  u16TransitionTime;
    zbmap8                  u8OptionsMask;
    zbmap8                  u8OptionsOverride;    
} tsCLD_LevelControl_StepCommandPayload;

```

where:

-   `u8StepMode` indicates the direction of the required level change, up \(0x00\) or down \(0x01\)

-   `u8StepSize` is the size for the required level change

-   `u16TransitionTime` is the time taken, in units of tenths of a second, to reach the target level \(0xFFFF means move to the level as fast as possible\)

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


**Parent topic:**[Custom Command Payloads](../../Level_Control_cluster/topics/custom_command_payloads.md)

