# Enrollment

An IAS Zone device hosting the IAS Zone cluster server must be paired with a CIE device hosting the cluster client. This pairing is implemented by the process of ‘enrollment’ which, for extra security, provides a layer of pairing in addition to ZigBee PRO binding - if required, binding is implemented as part of the enrollment process.

During enrollment, the CIE device sends its IEEE/MAC address to the Zone device as well as a Zone ID, which is a unique 8-bit identifier that the CIE device assigns to the Zone device. These values are stored in the `u64IASCIEAddress` and `u8ZoneId` attributes on the Zone device \(cluster server\) - see [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1). In addition, once enrollment has completed, the `e8ZoneState` attribute is set to ‘enrolled’. Subsequently, the Zone device will only communicate with the paired CIE device.

Enrollment begins just after the Zone device joins the network. This device must then periodically poll for data \(from the CIE device\), ideally once every 2 seconds \(or faster\) but no slower than once every 7 seconds. This polling must continue until the `e8ZoneState` attribute has been updated to ‘enrolled’. However, if the IAS Zone device supports the Poll Control cluster, polling at the above rate should continue until the Poll Control cluster configuration is changed.

Three methods of enrollment are available:

-   Trip-to-Pair, described in [Section 37.3.1](trip-to-pair.md#id_548f7b6a-fe8a-49aa-ba44-6bc8ea5e5db9)

-   Auto-Enroll-Response, described in [Section 37.3.2](auto-enroll-response.md#id_f832d5a1-1468-45f8-a95a-bae52e661cbb)

-   Auto-Enroll-Request, described in [Section 37.3.3](auto-enroll-request.md#id_b1335587-eb60-46be-b9f8-5da156e61c7f)


A cluster server and client can each implement both Trip-to-Pair and Auto-Enroll-Response or just Auto-Enroll-Request.


```{include} ../../IAS_Zone_cluster/topics/trip-to-pair.md
:heading-offset: 2
```

```{include} ../../IAS_Zone_cluster/topics/auto-enroll-response.md
:heading-offset: 2
```

```{include} ../../IAS_Zone_cluster/topics/auto-enroll-request.md
:heading-offset: 2
```

**Parent topic:**[IAS Zone Cluster](../../IAS_Zone_cluster/topics/ias_zone_cluster.md)

