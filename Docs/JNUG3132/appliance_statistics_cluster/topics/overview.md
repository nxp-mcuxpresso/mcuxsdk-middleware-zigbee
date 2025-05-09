# Overview

The Appliance Statistics cluster provides an interface for sending appliance statistics in the form of data logs to a collector node, which may be a gateway.

The cluster is enabled by defining CLD\_APPLIANCE\_STATISTICS in the **zcl\_options.h** file. Further compile-time options for the Appliance Statistics cluster are detailed in [Section 48.10](compile-time_options.md#id_a476548a-7858-48c6-8a37-1bf42072cb00).

The cluster client may obtain logs from the server \(appliance\) in any of the following ways:

-   Unsolicited log notifications sent by the server

-   Solicited responses obtained by:

    -   Client sending ‘Log Queue Request’ to enquire whether logs are available

    -   Client sending ‘Log Request’ for each log available

-   Semi-solicited responses obtained by:

    -   Server sending ‘Statistics Available’ notification to indicate that logs are available

    -   Client sending ‘Log Request’ for each log available


**Parent topic:**[Appliance Statistics Cluster](../../appliance_statistics_cluster/topics/appliance_statistics_cluster.md)

