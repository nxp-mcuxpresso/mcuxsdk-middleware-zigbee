# Binding devices

The Router and End Device support the On/Off cluster as a server and implement the "Finding and Binding" process as a target.

To trigger "Finding and Binding" as a target, perform the following steps:

1.  Press the **USER** button on the FRDM-MCXW71 board (or the MCX-W71-EVK / MCX-W72-EVK / FRDM-RW612 / RD-RW612-BGA board) of the target device. The same button is used to start Network Steering, described in [Allowing Other Devices to Join the Network](joining_an_existing_network_using_network_steering.md).
2.  Start "*Finding and Binding*" on the initiator device.

This step causes the End Device or Router to self-identify for 180 seconds. In this duration, the initiator tries to find the identifying devices, queries their capabilities, and creates bindings on the devices with matching operational clusters. As part of this process, the Route or End Device can receive an `Add Group` command and/or a `Binding Request` command.

Reporting is a mandatory feature in ZigBee 3.x. The Router and End Device supports the On/Off cluster as a server and the OnOff attribute of this cluster is a reportable attribute as defined in [ZigBee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf). The Router and End Device hold a default configuration for reporting the state of the OnOff attribute. Once a device wishing to receive these periodic and on-change reports creates a remote binding, the Router starts to send reports to this bound device. The frequency of the reports depends on the default report configuration of the individual target device; 60 seconds in this case. The device receiving the reports can request the change by sending a `Report Configuration` command.

**Parent topic:**[Running the demonstration examples](../topics/running_the_demonstration_examples.md)

