# Appendix D: Custom endpoints

A ZigBee device and its associated clusters can be registered on an endpoint using the relevant device registration function, from those listed and described in the *ZigBee Devices User Guide \(JNUG3131\)*. However, it is also possible to set up a custom endpoint which supports selected clusters \(rather than a whole ZigBee device and all of its associated clusters\). Custom endpoints are particularly useful when using multiple endpoints on a single node - for example, the first endpoint may support a complete ZigBee device \(such as a Light Sensor\) while one or more custom endpoints are used to support selected clusters.


```{include} ../../appendix/topics/devices_and_endpoints.md
:heading-offset: 1
```

```{include} ../../appendix/topics/cluster_creation_functions.md
:heading-offset: 1
```

```{include} ../../appendix/topics/custom_endpoint_set-up.md
:heading-offset: 1
```

