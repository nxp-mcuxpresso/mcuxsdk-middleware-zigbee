# Initialization and Operation

The Flow Measurement cluster must be initialized on both the cluster server and client. Initialization can be done using the **eCLD\_FlowMeasurementCreateFlowMeasurement\(\)** function, which creates an instance of the Flow Measurement cluster on a local endpoint.

Once the cluster has been initialized, the application on the server should maintain the cluster attributes \(see [Section 27.2](cluster_structure_and_attributes.md#id_223c19f6-65aa-4cae-9253-7850fea2f993)\) with the flow measurements made by the local device. The application on a client can remotely read these measured values using the ZCL ‘Read Attribute’ functions, as described in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae).

**Parent topic:**[Flow Measurement Cluster](../../flow_measurement_cluster/topics/flow_measurement_cluster.md)

