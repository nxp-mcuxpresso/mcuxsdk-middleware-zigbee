# teCLD\_BallastConfiguration\_ClusterID

The following structure contains the enumerations used to identify the attributes of the Ballast Configuration cluster.

```
typedef enum 
{
    /* Ballast Information attribute set attribute IDs */
    E_CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MIN_LEVEL      = 0x0000,
    E_CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MAX_LEVEL,
    E_CLD_BALLASTCONFIGURATION_ATTR_BALLAST_STATUS,
    /* Ballast Settings attribute set attribute IDs */
    E_CLD_BALLASTCONFIGURATION_ATTR_MIN_LEVEL               = 0x0010,
    E_CLD_BALLASTCONFIGURATION_ATTR_MAX_LEVEL,
    E_CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_LEVEL,
    E_CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_FADE_TIME,
    E_CLD_BALLASTCONFIGURATION_ATTR_INTRINSIC_BALLAST_FACTOR,
    E_CLD_BALLASTCONFIGURATION_ATTR_BALLAST_FACTOR_ADJUSTMENT,
    /* Lamp Information attribute set attribute IDs */
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_QUANTITY           = 0x0020,
    /* Lamp Settings attribute set attribute IDs */
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_TYPE               = 0x0030,
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_MANUFACTURER,
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_RATED_HOURS,
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS,
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_ALARM_MODE,
    E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS_TRIP_POINT,
} teCLD_BallastConfiguration_ClusterID;

```

**Parent topic:**[Enumerations](../../Ballast_Configuration_cluster/topics/enumerations.md)

