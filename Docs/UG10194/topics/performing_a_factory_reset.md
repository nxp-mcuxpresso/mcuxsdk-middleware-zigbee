# Performing a factory reset \(ED\)

The End Device can be returned to its factory-new state \(erasing all persistent data except the outgoing network frame counter\) as follows:

-   Hold down the **USER** button and press the **RESET** button on the FRDM-MCXW71 board or MCX-W71-EVK board, or MCX-W72-EVK board.

The End Device then unicasts a Leave Indication to its parent. The parent then broadcasts this message again to the old network. The End Device deletes all persistent data \(other than the outgoing network frame counter\) and performs a software reset.

There are two supported over-the-air commands for removing a device from the network as follows:

-   Network Leave Request without rejoin
-   ZDO Management Network Leave Request without rejoin

The Reset command of the Basic cluster causes the ZCL to be reset to its factory-state defaults. It also resets all attributes and configured reports. This step does not remove the device from the network and all network parameters, groups, and bindings remain in place.

**Parent topic:**[End Device functionality](../topics/end_device_functionality.md)

