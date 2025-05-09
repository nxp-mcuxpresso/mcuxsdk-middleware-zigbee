# Move Command Payload

```
typedef struct
{
    uint8                   u8MoveMode;
    uint8                   u8Rate;
    zbmap8                  u8OptionsMask;
    zbmap8                  u8OptionsOverride;    
} tsCLD_LevelControl_MoveCommandPayload;

```

where:

-   `u8MoveMode` indicates the direction of the required level change, up \(0x00\) or down \(0x01\)

-   `u8Rate` represents the required rate of change in units per second \(0xFF means use the `u``8DefaultMoveRate` attribute instead - if this optional attribute is not present, the device changes the level as fast as possible\)

-   `OptionsMask` and `OptionsOverride` must be either both present or both not present. These fields are used in creating a temporary Options bitmap from the `u8Options` attribute. Each bit of the `u8Options` attribute is carried across to the temporary Options bitmap unless the corresponding bit of `OptionsMask` is set \(to 1\). In this case, the corresponding bit of `OptionsOverride` is used in the temporary Options bitmap instead.


**Parent topic:**[Custom Command Payloads](../../Level_Control_cluster/topics/custom_command_payloads.md)

