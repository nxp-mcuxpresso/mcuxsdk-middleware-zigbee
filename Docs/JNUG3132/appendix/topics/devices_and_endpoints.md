# Appendix D.1: Devices and Endpoints

When using custom endpoints, it is important to note the difference between the following ‘devices’:

-   **Physical device:** This is the physical entity which is the network node

-   **Logical device:** This is a software entity which implements a specific set of functionality on the node, e.g. On/Off Switch device


A ZigBee network node may contain multiple endpoints, where one endpoint is used to represent the ‘physical device’ and other endpoints are used to support ‘logical devices’. The following rules apply to cluster instances on endpoints:

-   All cluster instances relating to a single ‘logical device’ must reside on a single endpoint.

-   The Basic cluster relates to the ‘physical device’ rather than a ‘logical device’ instance. There can be only one Basic cluster server for the entire node, which can be implemented in either of the following ways:

    -   A single cluster instance on a dedicated ‘physical device’ endpoint

    -   A separate cluster instance on each ‘logical device’ endpoint, but each cluster instance must use the same `tsZCL_ClusterInstance` structure \(and the same attribute values\)


**Parent topic:**[Appendix D: Custom endpoints](../../appendix/topics/custom_endpoints.md)

