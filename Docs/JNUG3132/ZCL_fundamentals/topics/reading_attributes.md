# Reading Attributes

A ZigBee 3.0 application might require to read attribute values from a remote device. Attributes are read by sending a ‘read attributes’ request, normally from a client cluster to a server cluster. This request can be sent using a general ZCL function \(see below\) or using a function which is specific to the target cluster. The cluster-specific functions for reading attributes are covered in the chapters of this manual that describe the supported clusters.

**Note:** Users should enable read access to cluster attributes explicitly at compile-time as described in [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987).

A ZCL function is provided for reading a set of attributes of a remote cluster instance, as described in [Section 2.3.2.1](reading_a_set_of_attributes_of_a_remote_cluster.md#id_9fdd1d77-833a-40cd-957e-f0ca0880dc90). A function is also provided for reading a local cluster attribute value, as described in [Section 2.3.2.2](reading_an_attribute_of_a_local_cluster.md#id_6fa9efc2-e6e6-4c65-8c9e-f17f4fd1e954).


```{include} ../../ZCL_fundamentals/topics/reading_a_set_of_attributes_of_a_remote_cluster.md
:heading-offset: 3
```

```{include} ../../ZCL_fundamentals/topics/reading_an_attribute_of_a_local_cluster.md
:heading-offset: 3
```

**Parent topic:**[Accessing Attributes](../../ZCL_fundamentals/topics/accessing_attributes.md)

