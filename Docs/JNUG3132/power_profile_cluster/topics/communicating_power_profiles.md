# Communicating power profiles

In order to control the power consumption of the appliance \(by scheduling the energy phases of the power profile\), the controller \(cluster client\) must ‘learn’ the power profiles supported by the appliance \(server\). This may be done through requests or notifications, as described in the sub-sections below.

**Note:** In order remotely control the appliance from a controller for energy management, the attribute `bEnergyRemote` of the Power Profile cluster on the server device must be set to TRUE \(see [Section 21.2](cluster_structure_and_attributes.md#id_a7a109d5-ed4c-4f67-8b31-21f7a4c482c3)\).


```{include} ../../power_profile_cluster/topics/requesting_a_power_profile_by_client.md
:heading-offset: 3
```

```{include} ../../power_profile_cluster/topics/notification_of_a_power_profile_by_server.md
:heading-offset: 3
```

**Parent topic:**[Power profile operations](../../power_profile_cluster/topics/power_profile_operations.md)

