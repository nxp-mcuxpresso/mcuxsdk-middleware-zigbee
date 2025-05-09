# teCLD\_ILS\_LightLevelStatus

The following structure contains the enumerations used to represent the light-level status in the `u8LevelStatus` attribute of the cluster \(see [Section 24.2](cluster_structure_and_attributes.md#id_8e6fab80-4831-4a3e-9f11-10f8776011af)\).

```
typedef enum 
{
  E_CLD_ILS_LLS_ON_TARGET,
  E_CLD_ILS_LLS_BELOW_TARGET,
  E_CLD_ILS_LLS_ABOVE_TARGET,
} teCLD_ILS_LightLevelStatus;

```

**Parent topic:**[Enumerations](../../Illuminance_Level_Sensing_cluster/topics/enumerations.md)

