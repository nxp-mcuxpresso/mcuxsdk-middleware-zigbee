# Mandatory Attribute Settings

The application must set the values of the mandatory `u8ZCLVersion`, `ePowerSource` and `u16ClusterRevision` fields of the Basic cluster structure so that other devices can read them. This should be done immediately after calling the endpoint registration function for the device - for example, **eZLO\_RegisterDimmableLightEndPoint\(\)**.

These values can be set by calling the **eZCL\_WriteLocalAttributeValue\(\)** function with the appropriate input values. Alternatively, they can be set by writing to the relevant members of the shared structure of the device, as illustrated below, where `sLight` or `sSwitch` is the device that is registered using the registration function.

On a Dimmable Light:

```
sLight.sBasicCluster.u8ZCLVersion = 0x01;
sLight.sBasicCluster.ePowerSource = E_CLD_BAS_PS_SINGLE_PHASE_MAINS;
sLight.sBasicClusteru.16ClusterRevision = CLD_BAS_CLUSTER_REVISION;

```

On a battery-powered Dimmer Switch:

```
sSwitch.sLocalBasicCluster.u8ZCLVersion = 0x01;
sSwitch.sLocalBasicCluster.ePowerSource = E_CLD_BAS_PS_BATTERY;
sLight.sBasicClusteru.16ClusterRevision = CLD_BAS_CLUSTER_REVISION;

```

**Parent topic:**[Basic Cluster](../../Basic_cluster/topics/basic_cluster.md)

