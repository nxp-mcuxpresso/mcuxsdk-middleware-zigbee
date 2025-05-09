# Move To Level Command Payload

```
typedef struct
{
    uint8                   u8Level;
    uint16                  u16TransitionTime;
    zbmap8                  u8OptionsMask;
    zbmap8                  u8OptionsOverride;
} tsCLD_LevelControl_MoveToLevelCommandPayload;

```

where:

-   `u8Level` is the target level within the range 0x01 to 0xFE or within a more restricted range \(see [Section 16.5.1](changing_level.md#id_82d61a0b-7d29-492d-b406-ed9f96a5728f)\)

-   `u16TransitionTime` is the time taken, in units of tenths of a second, to reach the target level \(0xFFFF means use the `u16OnOffTransitionTime` attribute instead - if this optional attribute is not present, the device changes the level as fast as possible\).

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


**Parent topic:**[Custom Command Payloads](../../Level_Control_cluster/topics/custom_command_payloads.md)

