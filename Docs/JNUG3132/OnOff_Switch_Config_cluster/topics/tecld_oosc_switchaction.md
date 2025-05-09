# teCLD\_OOSC\_SwitchAction

The following structure contains the enumerations used to specify the switch action in the `eSwitchActions` attribute.

```
typedef enum 
{
    E_CLD_OOSC_ACTION_S2ON_S1OFF,
    E_CLD_OOSC_ACTION_S2OFF_S1ON,
    E_CLD_OOSC_ACTION_TOGGLE
} teCLD_OOSC_SwitchAction;

```

The above enumerations are detailed in the .

|**Enumeration**|**Description**

 When the switch moves between state 1 \(S1\) and state 2 \(S2\)...

|
|---------------|--------------------------------------------------------------------------------------|
|E\_CLD\_OOSC\_ACTION\_S2ON\_S1OFF|S1 to S2 is ‘switch on’, S2 to S1 is ‘switch off’|
|E\_CLD\_OOSC\_ACTION\_S2OFF\_S1ON|S1 to S2 is ‘switch off’, S2 to S1 is ‘switch on’|
|E\_CLD\_OOSC\_ACTION\_TOGGLE|S1 to S2 is ‘toggle’, S2 to S1 is ‘toggle’|

**Parent topic:**[Enumerations](../../OnOff_Switch_Config_cluster/topics/enumerations.md)

