# Remotely Reading Simple Metering Attributes

Dedicated functions are provided for remotely reading the Simple Metering attributes:

1. The application must first call **eSE\_ReadMeterAttributes\(\)** to submit a ‘read attributes’ request to the relevant remote endpoint. The resulting read process is as described for **eZCL\_SendReadAttributesRequest\(\)** in [Section 2.3.2](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae).

2. On receiving the ‘read attributes’ response, the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE is generated, which causes the callback function for the local endpoint to be invoked. This callback function should include a call to **eSE\_HandleReadAttributesResponse\(\)** which checks whether all the Simple Metering attributes are included in the response. If the response is not complete, the function re-sends ‘read attributes’ requests until all attribute values are obtained.

Note that read access to cluster attributes must be explicitly enabled at compile-time as described in [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987).

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

