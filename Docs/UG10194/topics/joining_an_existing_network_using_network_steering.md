# Joining an existing network using network steering \(Router\)

A factory-new Router can join an existing ZigBee only when the network is opened to accept new joiners \(Network Steering for a device on a network\).

Joining an existing network using Network Steering is achieved as follows:

1.  Trigger Network Steering on one of the devices already on the network \(Coordinator or another Router in the same ZigBee network\).
2.  Then reset using the **RESET** button or power on the joining Router device.
3.  As a result, the Router starts a network discovery and the associate process. Association is followed by an exchange of security materials and an update of the Trust center link key \(if joining a Centralized Trust center network\).
4.  By power cycling, the join can be retried if it fails.

**Parent topic:**[Router functionality](../topics/router_functionality.md)

