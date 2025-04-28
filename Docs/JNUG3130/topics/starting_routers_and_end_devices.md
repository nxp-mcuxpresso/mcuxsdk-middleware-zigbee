# Starting Routers and End Devices

A Router or End Device is pre-configured using the ZPS Configuration Editor. The functions that must be called in a Router or End Device application to initialize the node are listed at the beginning of this section \([Section 6.1](forming_and_joining_a_network.md), [Forming and joining a network](forming_and_joining_a_network.md)\).

**Note:** The start-up and join process described in this section is for a first-time join \(cold start\) only and not for a rejoin \(which is described in [Section 6.6.2](rejoining_the_network.md)\).

Once the stack has been started using **zps\_eAplZdoStartStack\(\)**, a Router or End Device works through the following process to join a network:

1.  Searches for a network to join

2.  Selects a network to join

3.  Submits a join request to network

4.  Records the network's EPID for application use

5.  Router accepts join requests from other devices \(if enabled\)


These processes are described in detail in the following sections.


```{include} ../topics/searches_for_a_network_to_join.md
:heading-offset: 3
```

```{include} ../topics/selects_a_network_to_join.md
:heading-offset: 3
```

```{include} ../topics/submits_a_join_request_to_network.md
:heading-offset: 3
```

```{include} ../topics/records_the_networks_epid_for_application_use.md
:heading-offset: 3
```

```{include} ../topics/router_accepts_join_requests_from_other_devices_if.md
:heading-offset: 3
```

**Parent topic:**[Forming and joining a network](../topics/forming_and_joining_a_network.md)

