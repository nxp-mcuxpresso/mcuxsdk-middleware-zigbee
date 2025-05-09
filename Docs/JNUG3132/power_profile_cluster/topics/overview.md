# Overview

The Power Profile cluster allows an appliance, the cluster server, to provide its expected power usage data to a controller, the cluster client. This ‘power profile’ represents the predicted ‘energy footprint’ of the appliance, and may be used by the controller to schedule and control the operation of the appliance. It may be requested by the client or provided unsolicited by the server.

The cluster is enabled by defining CLD\_PP in the **zcl\_options.h** file. Further compile-time options for the Power Profile cluster are detailed in [Section 21.11](compile-time_options.md#id_b8a93293-b412-43d1-a3e6-4800989d0691).

**Note:** The Power Profile cluster requires the Appliance Control cluster for the implementation of status notifications and power management commands. The Appliance Control cluster is described in [Chapter 45](../../appliance_control_cluster/topics/appliance_control_cluster.md#id_de2e147c-a77e-440d-a30d-837ca20be885).

**Parent topic:**[Power Profile Cluster](../../power_profile_cluster/topics/power_profile_cluster.md)

