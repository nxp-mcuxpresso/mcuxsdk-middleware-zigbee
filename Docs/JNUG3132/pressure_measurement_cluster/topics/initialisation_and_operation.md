# Initialization and Operation

The Pressure Measurement cluster must be initialized on both the cluster server and client. This can be done using the function **eCLD\_PressureMeasurementCreatePressureMeasurement\(\)**, which creates an instance of the Pressure Measurement cluster on a local endpoint.

Once the cluster has been initialized, the application on the server should maintain the cluster attributes \(see [Section 26.2](cluster_structure_and_attributes.md#id_54d80c28-6623-4cbe-b5ea-57983a64cd1b)\) with the pressure measurements made by the local device. The application on a client can remotely read these measured values using the ZCL ‘Read Attribute’ functions, as described in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae).

**Parent topic:**[Pressure Measurement Cluster](../../pressure_measurement_cluster/topics/pressure_measurement_cluster.md)

