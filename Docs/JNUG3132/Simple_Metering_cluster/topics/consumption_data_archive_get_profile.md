# Consumption Data Archive \(‘Get Profile’\)

Devices that support the Simple Metering cluster can maintain and exchange historical consumption \(profiling\) data using the ‘Get Profile’ feature. A consumption data archive, which is distinct from the data of the Simple Metering cluster attributes, is maintained in a circular buffer on the cluster server. A cluster client can make a ‘Get Profile’ request to the server to obtain data from this archive. Normally, the cluster server is implemented on a Metering Device and the cluster client is implemented on an IPD. Typically, the IPD requests a consumption history from the Metering Device in order to display this information to the consumer.

The consumption data in the archive corresponds to a series of consecutive time intervals with their corresponding consumption values. Thus, the archive consists of the last few consumption measurements - it is the responsibility of the application running on the server device to update the archive \(see [Section 42.6.1](updating_consumption_data_on_server.md#id_11566dd9-de95-4802-a999-1d80c3a6abd6)\).

If the ‘Get Profile’ feature is required, it must be enabled in the compile-time options as described in [Section 42.12](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1). These options include the maximum number of consumption intervals that can be archived on the server \(and therefore requested\).


```{include} ../../Simple_Metering_cluster/topics/updating_consumption_data_on_server.md
:heading-offset: 2
```

```{include} ../../Simple_Metering_cluster/topics/sending_and_handling_a_get_profile_request.md
:heading-offset: 2
```

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

