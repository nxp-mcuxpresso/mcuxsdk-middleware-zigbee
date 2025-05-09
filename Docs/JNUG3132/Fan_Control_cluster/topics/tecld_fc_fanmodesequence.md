# teCLD\_FC\_FanModeSequence

The following structure contains the enumerations used to set the value of the `e8FanModeSequence` attribute in the `tsCLD_FanControl` structure \(see [Section](fan_control_structure_and_attributes.md#id_95fa5518-d4e8-4fd1-a158-1bfabf89b67f)34.2\).

```
typedef enum 
{
    E_CLD_FC_FAN_MODE_SEQUENCE_LOW_MED_HIGH         = 0x00,
    E_CLD_FC_FAN_MODE_SEQUENCE_LOW_HIGH,            //0x01
    E_CLD_FC_FAN_MODE_SEQUENCE_LOW_MED_HIGH_AUTO,   //0x02
    E_CLD_FC_FAN_MODE_SEQUENCE_LOW_HIGH_AUTO,       //0x03
    E_CLD_FC_FAN_MODE_SEQUENCE_ON_AUTO,             //0x04
} teCLD_FC_FanModeSequence;

```

The above enumerations are described in the table below \(the fan speeds/states refer to those listed in [Section 34.5.2](tecld_fc_fanmode.md#id_adea5c8f-da59-4f2f-ad8c-9920b5b8d498)\).

|**Enumeration**|**Description \(Set of Fan Speeds/States\)**|
|---------------|--------------------------------------------|
|E\_CLD\_FC\_FAN\_MODE\_SEQUENCE\_LOW\_MED\_HIGH|Low/Med/High|
|E\_CLD\_FC\_FAN\_MODE\_SEQUENCE\_LOW\_HIGH|Low/High|
|E\_CLD\_FC\_FAN\_MODE\_SEQUENCE\_LOW\_MED\_HIGH\_AUTO|Low/Med/High/Auto|
|E\_CLD\_FC\_FAN\_MODE\_SEQUENCE\_LOW\_HIGH\_AUTO|Low/High/Auto|
|E\_CLD\_FC\_FAN\_MODE\_SEQUENCE\_ON\_AUTO|On/Auto|

**Parent topic:**[Enumerations](../../Fan_Control_cluster/topics/enumerations.md)

