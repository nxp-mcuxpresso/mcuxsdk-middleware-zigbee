# Appendix B: Attribute reporting

Attribute reporting involves sending attribute values unsolicited from the cluster server to a client - that is, pushing values from server to client without the client needing to request the values. This mechanism reduces network traffic compared with the client polling the server for attribute values. It also allows a sleeping server to report its attribute values while it is awake.

The server sends an ‘attribute report’ to the client, where this report can be issued in one of the following ways:

-   by a function call in the user application \(on the server device\)

-   automatically by the ZCL \(triggered by a change in the attribute value or periodically\)


The rules for automatic reporting \(see [Appendix B.1](automatic_attribute_reporting.md#id_ff57abcc-c007-4561-ad92-72e73d561f70)\) can be configured by a remote client by sending a ‘configure reporting’ command to the server. The same rules apply to ‘default reporting’ \(see [Appendix B.2](default_reporting.md#id_acce1fe2-421f-4f0b-81f4-89c1cd3d81b1)\), but are configured locally on the server. The configuration of attribute reporting is described in [Appendix B.3](configuring_attribute_reporting.md#id_8f4a2099-2cfd-4173-ae40-941bc28e2989). Remote devices can also query the attribute reporting configuration of the server, as described in [Appendix B.6.](querying_attribute_reporting_configuration.md#id_d747e079-b30d-427f-becf-4bc6c140e3af)

Sending and receiving attribute reports are described in [Appendix B.4](sending_attribute_reports.md#id_42d44dc8-5502-479c-a256-c8cc7a4b7807) and [Appendix B.5](receiving_attribute_reports.md#id_7d67801f-7339-466c-afe7-d946f508aeb1).

**Attention:** Attribute reporting is an optional feature and is not supported by all devices.


```{include} ../../appendix/topics/automatic_attribute_reporting.md
:heading-offset: 3
```

```{include} ../../appendix/topics/default_reporting.md
:heading-offset: 3
```

```{include} ../../appendix/topics/configuring_attribute_reporting.md
:heading-offset: 3
```

```{include} ../../appendix/topics/sending_attribute_reports.md
:heading-offset: 3
```

```{include} ../../appendix/topics/receiving_attribute_reports.md
:heading-offset: 3
```

```{include} ../../appendix/topics/querying_attribute_reporting_configuration.md
:heading-offset: 3
```

```{include} ../../appendix/topics/storing_an_attribute_reporting_configuration.md
:heading-offset: 3
```

