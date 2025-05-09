# Initialisation and Operation

The Electrical Measurement cluster must be initialised on both the cluster server and client. This can be done using the function **eCLD\_ElectricalMeasurementCreateElectricalMeasurement\(\)**, which creates an instance of the Electrical Measurement cluster on a local endpoint.

Once the cluster has been initialized, the application on the server should maintain the cluster attributes \(see [Section 30.2](cluster_structure_and_attributes.md#id_ab865248-0ff3-4f63-94bd-dd14a8edf2ac)\) with the electrical measurements made by the local device. The application on a client can remotely read these measured values using the ZCL ‘Read Attribute’ functions, as described in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae).

**Parent topic:**[Electrical Measurement Cluster](../../electrical_measurement_cluster/topics/electrical_measurement_cluster.md)

