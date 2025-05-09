# Functions

The following Occupancy Sensing cluster function is provided in the NXP implementation of the ZCL:

-   [eCLD\_OccupancySensingCreateOccupancySensing](ecld_occupancysensingcreateoccupancysensing.md#id_e21a9162-e52c-458b-b9ec-75e875b0984e)

The cluster attributes can be accessed using the general attribute read/write functions, as described in [Section 2.3](../../ZCL_fundamentals/topics/accessing_attributes.md#id_9f17ffc2-9472-40fa-9365-07ad9a0f505b). The state of the occupancy sensor can be obtained by reading the `u8Occupancy` attribute in the `tsCLD_OccupancySensing` structure on the cluster server \(see [Section 29.2](occupancy_sensing_structure_and_attributes.md#id_92bbe49c-e6f9-4fd5-8de5-f8e2e59efb11)\).


```{include} ../../Occupancy_Sensing_cluster/topics/ecld_occupancysensingcreateoccupancysensing.md
:heading-offset: 2
```

**Parent topic:**[Occupancy Sensing Cluster](../../Occupancy_Sensing_cluster/topics/occupancy_sensing_cluster.md)

