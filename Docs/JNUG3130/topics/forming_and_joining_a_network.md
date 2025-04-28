# Forming and joining a network

This section describes how to form a wireless network by first starting the Coordinator and then starting the other nodes, which join the network initiated by the Coordinator.

**Note:** In order to start any network node, certain configuration values must have been pre-set for the

application. This configuration is performed using the steps described in [Chapter 13, ZPS Configuration Editor](zps_configuration_editor.md).

At initialization, the same function calls are needed for all node types. However, once started, the stack performs initialization tasks according to the specific node type, as described in [Section 6.1.1](starting_the_coordinator.md) and [Section 6.1.2](starting_routers_and_end_devices.md). These function calls are listed below, in the required order:

1.  **PDUM\_vInit\(\)** to initialize the JCU Protocol Data Unit Manager \(PDUM\).
2.  **PWR\_Init\(\)** to initialize the Low-Power module in order to facilitate low-power modes such as sleep and doze.
3.  **NvModuleInit\(\)** to initialize the JCU Non-Volatile Memory Manager \(NVM\) in order to save context and application data for retrieval after a power break.
4.  **eZCL\_initialise\(\)** to initialize the ZigBee Cluster Library \(ZCL\).
5.  **eZCL\_Register\(\)** for a custom device type, or the equivalent registration function for a standard ZigBee device type, to register an endpoint for the application.
6.  **zps\_eAplAfInit\(\)** to initialize the Application Framework.
7.  **BDB\_vInit\(\)** to initialize the ZigBee Base Device.
8.  **zps\_eAplZdoStartStack\(\)** to start the ZigBee PRO stack.

**Note:**

-   The ZigBee PRO stack can later be reset to its default state \(deleting context data except NWK frame counters\) using the `zps_vDefaultStack()` function.
-   The IEEE 802.15.4 MAC capabilities of a Router or End Device can be configured by the application using `zps_vAplAfSetMacCapability()` function.


```{include} ../topics/starting_the_coordinator.md
:heading-offset: 2
```

```{include} ../topics/starting_routers_and_end_devices.md
:heading-offset: 2
```

```{include} ../topics/pre-determined_parents.md
:heading-offset: 2
```

**Parent topic:**[Application coding with ZigBee PRO APIs](../topics/application_coding_with_zigbee_pro_apis.md)

