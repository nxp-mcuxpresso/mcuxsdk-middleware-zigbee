# Commissioning Cluster structure and attributes

The Commissioning cluster has only server attributes that are contained in the following `tsCLD_Commissioning` structure, organised as a set of structures containing the Commissioning cluster attribute sets:

```
typedef struct
{
#ifdef COMMISSIONING_SERVER    
/* Start- attribute setup Parameters attribute set */
    tsCLD_StartupParameters         sStartupParameters;
/* Join Parameters attribute set */
    tsCLD_JoinParameters            sJoinParameters;
/* End Device Parameters attribute set */
    tsCLD_EndDeviceParameters       sEndDeviceParameters;
/* Concentrator Parameters attribute set */
    tsCLD_ConcentratorParameters    sConcentratorParameters;
#endif
    zuint16       u16ClusterRevision;
} tsCLD_Commissioning;

```

where:

```
sStartupParameters is a structure containing the attributes of the Start-up Parameters attribute set - this structure and the associated attributes are detailed in [Section 43.2.1](start-up_parameters_tscld_startupparameters.md#id_d22b5600-7fda-403a-90c7-d433548a4983)
sJoinParameters is a structure containing the attributes of the Join Parameters attribute set - this structure and the associated attributes are detailed in [Section 43.2.2](join_parameters_tscld_joinparameters.md#id_02f93815-3ce8-498e-a271-cd3675dc7015) 
sEndDeviceParameters is a structure containing the attributes of the End Device Parameters attribute set - this structure and the associated attributes are detailed in [Section 43.2.3](end_device_parameters_tscld_enddeviceparameters.md#id_a29fedbf-ef44-458b-88af-f134a455d4c0)    
sConcentratorParameters is a structure containing the attributes of the Concentrator Parameters attribute set - this structure and the associated attributes are detailed in [Section 43.2.4](concentrator_parameters_tscld_concentratorparamete.md#id_3713b9e8-5da6-4db8-b678-617069de5091)
u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

```

**Note:** Memory is allocated at compile-time for all the Commissioning cluster attributes.


```{include} ../../Commissioning_cluster/topics/start-up_parameters_tscld_startupparameters.md
:heading-offset: 2
```

```{include} ../../Commissioning_cluster/topics/join_parameters_tscld_joinparameters.md
:heading-offset: 2
```

```{include} ../../Commissioning_cluster/topics/end_device_parameters_tscld_enddeviceparameters.md
:heading-offset: 2
```

```{include} ../../Commissioning_cluster/topics/concentrator_parameters_tscld_concentratorparamete.md
:heading-offset: 2
```

**Parent topic:**[Commissioning Cluster](../../Commissioning_cluster/topics/commissioning_cluster.md)

