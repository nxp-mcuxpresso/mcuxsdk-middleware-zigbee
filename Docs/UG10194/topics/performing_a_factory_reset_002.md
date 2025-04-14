# Performing a factory reset \(router\)

The Router can be returned to its factory-new state \(erasing all persistent data except the outgoing network frame counter\) as follows:

-   Hold down the **USER** button and press the **RESET** button on the board (FRDM-MCXW71 / MCX-W71-EVK / MCX-W72-EVK / FRDM-RW612 / RD-RW612-BGA).

The Router then broadcasts a Leave Indication on the old network. It also deletes all persistent data \(except the outgoing network frame counter\) and performs a software reset.

The two supported over-the-air commands for removing a device from the network are as follows:

-   Network Leave Request without rejoin
-   ZDO Management Network Leave Request without rejoin

The Reset command of the Basic cluster causes the ZCL to be reset to its factory-new defaults, resetting all attributes and configured reports. It does not remove the device from the network. Therefore, all network parameters, groups, and bindings remain in place.

**Parent topic:**[Router functionality](../topics/router_functionality.md)

