# teCLD\_FC\_FanMode

The following structure contains the enumerations used to set the value of the `e8FanMode` attribute in the `tsCLD_FanControl` structure \(see [Section 34.2](fan_control_structure_and_attributes.md#id_95fa5518-d4e8-4fd1-a158-1bfabf89b67f)\).

```
typedef enum 
{
    E_CLD_FC_FAN_MODE_OFF       = 0x00,
    E_CLD_FC_FAN_MODE_LOW,      //0x01
    E_CLD_FC_FAN_MODE_MEDIUM,   //0x02
    E_CLD_FC_FAN_MODE_HIGH,     //0x03
    E_CLD_FC_FAN_MODE_ON,       //0x04
    E_CLD_FC_FAN_MODE_AUTO,     //0x05
    E_CLD_FC_FAN_MODE_SMART,    //0x06
} teCLD_FC_FanMode;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description \(Fan State/Speed\)**|
|---------------|-----------------------------------|
|E\_CLD\_FC\_FAN\_MODE\_OFF|Off|
|E\_CLD\_FC\_FAN\_MODE\_LOW|Low|
|E\_CLD\_FC\_FAN\_MODE\_MEDIUM|Medium|
|E\_CLD\_FC\_FAN\_MODE\_HIGH|High|
|E\_CLD\_FC\_FAN\_MODE\_ON|On|
|E\_CLD\_FC\_FAN\_MODE\_AUTO|Auto \(fan speed is self-regulated\)|
|E\_CLD\_FC\_FAN\_MODE\_SMART|Smart \(when the space is occupied, the fan is always on\)|

**Parent topic:**[Enumerations](../../Fan_Control_cluster/topics/enumerations.md)

