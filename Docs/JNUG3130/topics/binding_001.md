# Binding

For the purpose of data communication between applications running on different nodes, it may be useful to ‘bind’ the relevant source and destination endpoints. When data is subsequently sent from the source endpoint, it is automatically routed to the bound destination endpoint\(s\) without the need to specify a destination address. For example, a binding could be created between the temperature sensor endpoint on a thermostat node and the switch endpoint on a heating controller node. Details of a binding are held in a Binding table on the source node. Binding is introduced more fully in [Section 3.6.2](binding.md), where bindings are one-to-one, one-to-many or many-to-one.

This section describes setting up a Bind Request Server and how to bind together two nodes, as well as how to unbind them. Access to the Binding tables is also described.

**Note:** Where 64-bit IEEE/MAC addresses are used to identify remote nodes, the corresponding 16-bit network addresses must be available in the local Address Map - see Section 5.2.3.


```{include} ../topics/setting_up_bind_request_server.md
:heading-offset: 2
```

```{include} ../topics/binding_endpoints.md
:heading-offset: 2
```

```{include} ../topics/unbinding_endpoints.md
:heading-offset: 2
```

```{include} ../topics/accessing_binding_tables.md
:heading-offset: 2
```

**Parent topic:**[Application coding with ZigBee PRO APIs](../topics/application_coding_with_zigbee_pro_apis.md)

