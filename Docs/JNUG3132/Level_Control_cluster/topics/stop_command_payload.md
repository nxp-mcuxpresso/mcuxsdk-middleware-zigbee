# Stop Command Payload

```
typedef struct
{
    zbmap8                  u8OptionsMask;
    zbmap8                  u8OptionsOverride;    
} tsCLD_LevelControl_StopCommandPayload;

```

where `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.

**Parent topic:**[Custom Command Payloads](../../Level_Control_cluster/topics/custom_command_payloads.md)

