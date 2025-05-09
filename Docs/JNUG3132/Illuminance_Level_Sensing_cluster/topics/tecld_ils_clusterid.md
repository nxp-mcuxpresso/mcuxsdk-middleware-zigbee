# teCLD\_ILS\_ClusterID

The following structure contains the enumerations used to identify the attributes of the Illuminance Level Sensing cluster \(see [Section 24.2](cluster_structure_and_attributes.md#id_8e6fab80-4831-4a3e-9f11-10f8776011af)\).

```
typedef enum 
{
  E_CLD_ILS_ATTR_ID_LEVEL_STATUS = 0x0000, /* Mandatory */
  E_CLD_ILS_ATTR_ID_LIGHT_SENSOR_TYPE,
  E_CLD_ILS_ATTR_ID_ILLUMINANCE_TARGET_LEVEL = 0x0010, /* Mandatory */
} teCLD_ILS_ClusterID;

```

**Parent topic:**[Enumerations](../../Illuminance_Level_Sensing_cluster/topics/enumerations.md)

