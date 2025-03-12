# Allowing other devices to join the network \(Router\)

Once the Router joins a network, the network is immediately opened for 180 seconds to allow other devices to join \(Network Steering while on a network\). During this time, new devices can join the network using either the Coordinator or the Router as the parent, with no additional steps required. After this time expires, no new nodes can ever join the network. If rejoining other nodes is necessary after this time expires, perform the following steps:

1.  Press the **USER** button on the (K32W148-EVK / FRDM-MCXW71 / MCX-W72-EVK / FRDM-RW612 / RD-RW612-BGA board). The same button is also used to start "*Finding and Binding*", described in [Binding devices](binding_devices.md).
2.  Then, the Router broadcasts a Management Permit Join Request to the network to open the "permit join" window for 180 seconds. The Network Steering process \(for devices not on a network\) can now be triggered on the devices that are to join the network.

**Parent topic:**[Router functionality](../topics/router_functionality.md)

