# Forming a network

A network can be formed from a factory-new Coordinator \(Network Steering while not on a network\) as follows:

1.  Enter the `form` on the serial interface. The Coordinator then starts a network.
2.  Using a ZigBee packet sniffer \(running separately on a USB Dongle\), validates the user regarding network status. The periodic "link status" messages must be present on the operational channel. This step is optional.

**Parent topic:**[Coordinator functionality](../topics/coordinator_functionality.md)

