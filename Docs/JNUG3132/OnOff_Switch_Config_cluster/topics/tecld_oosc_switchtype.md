# teCLD\_OOSC\_SwitchType

The following structure contains the enumerations used to specify the switch type in the `eSwitchType` attribute.

```
typedef enum
{
    E_CLD_OOSC_TYPE_TOGGLE,
    E_CLD_OOSC_TYPE_MOMENTARY,
    E_CLD_OOSC_TYPE_MULTI_FUNCTION
} teCLD_OOSC_SwitchType;

```

The above enumerations are detailed in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_OOSC\_TYPE\_TOGGLE|Toggle - when the switch is physically moved between its two states, it remains in the latest state until it is physically returned to the original state \(for example, a rocker switch\).|
|E\_CLD\_OOSC\_TYPE\_MOMENTARY|Momentary - when the switch is physically moved between its two states, it returns to the original state as soon as it is released \(for example, a pushbutton which is pressed and then released\).|
|E\_CLD\_OOSC\_TYPE\_MULTI\_FUNCTION|Multi-function - when the switch is physically moved between its two states, the command it sends is application-specific and may be dependent on the circumstances.|

**Parent topic:**[Enumerations](../../OnOff_Switch_Config_cluster/topics/enumerations.md)

