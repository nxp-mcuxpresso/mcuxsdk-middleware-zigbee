# On/Off Switch Config Cluster Structure and Attribute

The structure definition for the On/Off Switch Configuration cluster is:

```
typedef struct
{
#ifdef OOSC_SERVER    
    zenum8                  eSwitchType;
    zenum8                  eSwitchActions;
#endif    
    zuint16                 u16ClusterRevision;
} tsCLD_OOSC;

```

where:

-   `eSwitchType` is the type of the switch, one of:

    -   Toggle \(0x00\) - when the switch is physically moved between its two states, it remains in the latest state until it is physically returned to the original state \(for example, a rocker switch\)

    -   Momentary \(0x01\) - when the switch is physically moved between its two states, it returns to the original state as soon as it is released \(for example, a pushbutton which is pressed and then released\)

    -   Multi-function \(0x02\) - when the switch is physically moved between its two states, the command it sends is application-specific and may be dependent on the circumstances.

        -   Enumerations are provided for the above settings \(see [Section 15.5.2](tecld_oosc_switchtype.md#id_691599d1-441d-4a14-af50-dc58a6662a84)\).
-   `eSwitchActions` defines the commands to be generated when the switch moves between state 1 \(S1\) and state 2 \(S2\), one of:

    -   S1 to S2 is ‘switch on’, S2 to S1 is ‘switch off’

    -   S1 to S2 is ‘switch off’, S2 to S1 is ‘switch on’

    -   S1 to S2 is ‘toggle’, S2 to S1 is ‘toggle’

        -   Enumerations are provided for the above settings \(see [Section 15.5.3](tecld_oosc_switchaction.md#id_0f541faf-c471-45e5-86fe-19e4d0493ee4)\).
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[On/Off Switch Configuration Cluster](../../OnOff_Switch_Config_cluster/topics/onoff_switch_configuration_cluster.md)

