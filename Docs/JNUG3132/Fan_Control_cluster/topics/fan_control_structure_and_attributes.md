# Fan Control Structure and Attributes

The structure definition for the Fan Control cluster is shown below.

```
typedef struct
{
    #ifdef FAN_CONTROL_SERVER    
        zenum8  e8FanMode;
        zenum8  e8FanModeSequence;
    #endif
    zuint16 u16ClusterRevision;
} tsCLD_FanControl;

```

where:

-   `e8FanMode` is a server attribute that represents the current speed/state of the fan. The attribute can be set to one of the enumerated values listed in [Section](tecld_fc_fanmode.md#id_adea5c8f-da59-4f2f-ad8c-9920b5b8d498)34.5.2, representing off, low, medium, high, on, auto or smart.

-   `e8FanModeSequence` is a server attribute that specifies the possible fan speeds/states that a thermostat can set. The attribute can be set to one of the enumerated values listed in [Section 34.5.3](tecld_fc_fanmodesequence.md#id_ab838f20-ec0d-487f-964d-711818aa746f), each representing a set of possible fan speeds/states.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. For cluster specifications that pre-date the ZCL r6, this attribute is set to 0.


**Parent topic:**[Fan Control Cluster](../../Fan_Control_cluster/topics/fan_control_cluster.md)

