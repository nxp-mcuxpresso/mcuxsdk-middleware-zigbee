# Setting up ZigBee security

This section describes how to set up ZigBee security in your application code. Note that if security is enabled in a ZigBee network then network-level security is always used, while application-level security is optional.

Security is enabled on a node via the device parameter *Security Enabled*in the ZPS Configuration Editor. Enabling security also enables many-to-one routing toward the Trust Centre, which becomes a network concentrator \(see [Section 3.5.3](many-to-one_routing.md)\).

A Trust Centre must be nominated \(see [Section 2.8](secure_operating_environment.md)\) using the ZPS Configuration Editor. The Coordinator is normally chosen as the Trust Centre. The maximum number of nodes that will require the services of the Trust Centre must be set on the nominated node using the network parameter *Route Record Table Size*in the ZPS Configuration Editor \(the default number is 4\).

Security can be set up in the application code using the function **zps\_vAplSecSetInitialSecurityState\(\)**, which must be called before **zps\_eAplAfInit\(\)** and **zps\_eAplZdoStartStack\(\)** - see [Section 6.1](forming_and_joining_a_network.md).

**Note:** As an alternative to using the function **zps\_vAplSecSetInitialSecurityState\(\)** in the application code, ZigBee security can be set up in the ZPS Configuration Editor \(see [Section 6.8.3.1](network-level_security_set-up.md)\).

Once **zps\_vAplSecSetInitialSecurityState\(\)** has been called and the stack has been started, the stack will automatically manage the subsequent network-level security set-up and implementation.

Network-level security set-up and application-level security set-up are further described in [Section 6.8.3.1](network-level_security_set-up.md) and [Section 6.8.3.2](application-level_security_set-up.md) respectively.

**Note:** Certain functionality on the Trust Centre can be disabled using the **zps\_vSetTCLockDownOverride\(\)** function. For more information, refer to the function [description](description_069.md).


```{include} ../topics/network-level_security_set-up.md
:heading-offset: 3
```

```{include} ../topics/application-level_security_set-up.md
:heading-offset: 3
```

**Parent topic:**[Implementing ZigBee security](../topics/implementing_zigbee_security.md)

