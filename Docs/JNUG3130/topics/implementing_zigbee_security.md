# Implementing ZigBee security

The NXP ZigBee PRO APIs allow ZigBee security to be implemented, which applies key-based encryption to communications between network nodes. The message frame content generated at the NWK layer and higher is encrypted using 128-bit AES-based encryption \(see [Section 2.10](secure_operating_environment.md)\). The NWK payload of the frame is encrypted, and the NWK header and payload are integrity-protected with a 32-bit Message Integrity Code \(MIC\).

This section describes security in a network with centralized security that is managed by a single Trust Centre, which is usually the Coordinator node. A distributed security scheme can alternatively be used and this is described in [Section 6.10.2](distributed_security_networks.md).

The sub-sections below deal with the following topics:

-   Security levels - see [Section 6.8.1](security_levels.md)
-   Security keys - see [Section 6.8.2](security_key_types.md)
-   Security set-up - see [Section 6.8.3](setting_up_zigbee_security.md)
-   Security key modification - see [Section 6.8.4](security_key_modification.md)


```{include} ../topics/security_levels.md
:heading-offset: 2
```

```{include} ../topics/security_key_types.md
:heading-offset: 2
```

```{include} ../topics/setting_up_zigbee_security.md
:heading-offset: 2
```

```{include} ../topics/security_key_modification.md
:heading-offset: 2
```

**Parent topic:**[Application coding with ZigBee PRO APIs](../topics/application_coding_with_zigbee_pro_apis.md)

