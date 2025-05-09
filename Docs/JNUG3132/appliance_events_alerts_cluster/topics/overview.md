# Overview

The Appliance Events and Alerts cluster provides an interface for sending notifications of appliance events \(for example, target temperature reached\) and alerts \(for example, alarms\).

The cluster is enabled by defining CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS in the **zcl\_options.h** file. Further compile-time options for the Appliance Events and Alerts cluster are detailed in [Section 47.9](compile-time_options.md#id_dbbc6ea3-cb47-44cb-b943-75805b4cfe02).

Events are notified in terms of header and event identifier fields \(an event may occur when the appliance reaches a certain state, such as the end of its operational cycle\).

Alerts are notified in terms of the following fields:

-   Alert identification value

-   Alert category, one of: Warning, Danger, Failure

-   Presence/recovery flag \(indicating alert has been either detected or recovered\)


**Parent topic:**[Appliance Events and Alerts Cluster](../../appliance_events_alerts_cluster/topics/appliance_events_and_alerts_cluster.md)

