# teCLD\_DEVTEMPCFG\_AttributeId

The following structure contains the enumerations used to identify the attributes of the Device Temperature Configuration cluster.

```
typedef enum 
{
    /* Device Temperature Information attribute set attribute IDs  */
    E_CLD_DEVTEMPCFG_ATTR_ID_CURRENT_TEMPERATURE      = 0x0000, 
    E_CLD_DEVTEMPCFG_ATTR_ID_MIN_TEMP_EXPERIENCED,
    E_CLD_DEVTEMPCFG_ATTR_ID_MAX_TEMP_EXPERIENCED,
    E_CLD_DEVTEMPCFG_ATTR_ID_OVER_TEMP_TOTAL_DWELL,
    /* Device Temperature Settings attribute set attribute IDs */
    E_CLD_DEVTEMPCFG_ATTR_ID_DEVICE_TEMP_ALARM_MASK   = 0x0010,
    E_CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_THRESHOLD,
    E_CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_THRESHOLD,
    E_CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_DWELL_TRIP_POINT,
    E_CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_DWELL_TRIP_POINT,
} teCLD_DEVTEMPCFG_AttributeId;

```

**Parent topic:**[Enumerations and Defines](../../Device_Temp_Configuration_cluster/topics/enumerations_and_defines.md)

