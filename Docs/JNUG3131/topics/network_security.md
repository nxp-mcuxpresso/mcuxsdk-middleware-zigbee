# Network security

The ZigBee Base Device supports the following network security modes:

-   Centralized security

-   Distributed security


These security modes are described in the subsections below:

All Router and End Device nodes should support both centralized security and distributed security by adapting to the security scheme employed by the network that they join. A Co-ordinator supports only centralized security.

When the application calls **BDB\_vInit\(\)**, this function internally calls the function **BDB\_vSetKeys\(\)**. This function loads the appropriate pre-configured link key, depending on whether the node type supports centralized and/or distributed security. The pre-configured link keys are defined in the file **bdb\_link\_keys.c**.


```{include} ../topics/centralised_security_networks.md
:heading-offset: 2
```

```{include} ../topics/distributed_security_networks.md
:heading-offset: 2
```

**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

