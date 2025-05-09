# Concentrator Parameters \(tsCLD\_ConcentratorParameters\)

The `sCLD_ConcentratorParameters` structure below contains the attributes of the Concentrator Parameters attribute set:

```
typedef struct
{
#ifdef     CLD_COMMISSIONING_ATTR_CONCENTRATOR_FLAG
    bool_t         bConcentratorFlag;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_CONCENTRATOR_RADIUS
    uint8         u8ConcentratorRadius;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_CONCENTRATOR_DISCVRY_TIME
    uint8         u8ConcentratorDiscoveryTime;
#endif
} tsCLD_ConcentratorParameters;

```

where:

-   `bConcentratorFlag` is a Boolean flag which, when set to TRUE, enables the device as a concentrator for many-to-one routing. The default value is FALSE.

-   `u8ConcentratorRadius` is the hop-count radius for concentrator route discoveries. The default value is 0x0F.

-   `u8ConcentratorDiscoveryTime` is the time-interval, in seconds, between consecutive discoveries of inbound routes initiated by the concentrator. The default value is 0x0000, indicating that this time-interval is unknown and the discoveries must be triggered by the application.


**Parent topic:**[Commissioning Cluster structure and attributes](../../Commissioning_cluster/topics/commissioning_cluster_structure_and_attributes.md)

