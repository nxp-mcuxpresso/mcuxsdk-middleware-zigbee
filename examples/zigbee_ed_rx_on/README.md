# Table of Content

- [Table of Content](#table-of-content)
- [Zigbee End Device demo example](#zigbee-end-device-demo-example)
  - [Joining a network](#joining-a-network)
  - [Operating the device](#operating-the-device)
  - [Rejoining a network](#rejoining-a-network)
  - [Performing a factory reset](#performing-a-factory-reset)
  - [Binding devices](#binding-devices)
  - [LED Indicator table](#led-indicator-table)
  - [Available CLI commands](#available-cli-commands)

# Zigbee End Device demo example

The End Device is not capable of either forming a network nor being a parent to other devices joining the network.

There are two types of End Devices:
- "RX On" End Devices, which are always ready to communicate in the network
- "RX Off" Sleepy End Devices, which can sleep for periods of time during which it cannot communicate

The Zigbee End Device demo example demonstrates the "RX On" End Device device type and the "Find and Binding"
functionality. To do so, it supports the On/Off Cluster as a server.

The End Device supports the mandatory clusters and features of the Base Device as defined in
[ZigBee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf)

All communications to/from the End Device are passed through its parent Coordinator or End Device. For the RX On device,
no poll is required and messages are sent directly from the parent. However, regular messages must be sent. Otherwise,
the device can be timed out.

A CLI similar to the Coordinator's one can be enabled by defining the preprocessor flag `APP_ROUTER_NODE_CLI`. By
default, this flag is not set, only the board button will be available to operate the device.
Refer to the [Available CLI commands](#available-cli-commands) chapter for more information on the available commands.

## Joining a network

A factory-new End Device can join an existing network once the network has been opened to accept new joiners (Network
Steering for a device on a network).

Joining an existing network using Network Steering is achieved as follows:
1. Trigger Network Steering on one of the devices already on the network.
2. Then, reset using the RESET button or power on the End device.

## Operating the device

The operational functionality of this device in this demonstration is provided by the On/Off cluster. Since the
device supports the On/Off cluster server, its operation is passive, and it responds to commands sent by bound
devices. It responds to an OnOff Toggle command from a bound controller device by toggling the LED1 on the board if
there's one available. On boards where no LEDs are available, only an internal boolean state will be toggled.

## Rejoining a network

An End Device can be restarted in a state, which is not factory-new. In such a case, it automatically sends
a Network Rejoin Request to re-establish contact with its previous parent. If this fails, it then tries to join any
Router on the network that can host it. The End Device attempts to rejoin when powered on and after it wakes
from the deep sleep state. All the application, binding, group, and network parameters are preserved in nonvolatile
memory.

## Performing a factory reset

The End Device can be returned to its factory-new state (erasing all persistent data except the outgoing network
frame counter) as follows:
- Hold down the USER button and press the RESET button on the board.
- Alternatively, use the command `factory reset`

The End Device then unicast a Leave Indication to its parent. The parent then broadcasts this message again to
the old network. The End Device deletes all persistent data (other than the outgoing network frame counter) and
performs a software reset.

There are two supported over-the-air commands for removing a device from the network. These commands are listed below:
- Network Leave Request without rejoin
- ZDO Management Network Leave Request without rejoin

The Reset command of the Basic cluster causes the ZCL to be reset to its factory-new defaults, resetting
all attributes and configured reports. This does not remove the device from the network and all network
parameters, groups, and bindings remain in place.

## Binding devices

The End Device supports the On/Off cluster as a server and implement the "Finding and Binding" process as a
target. To trigger "Finding and Binding" as a target, perform the following steps:
1. Press the USER button on the board of the target device. Alternatively, use the `find` command.
2. Start "Finding and Binding" on the initiator device.

This step causes the End Device to self-identify for 180 seconds. In this duration, the initiator tries
to find the identifying devices, queries their capabilities, and creates bindings on the devices with matching
operational clusters. As part of this process, the or End Device can receive an `Add Group` command and/or a `Binding Request command`.

Reporting is a mandatory feature in ZigBee 3.x. The End Device supports the On/Off cluster as a server and the OnOff
attribute of this cluster is a reportable attribute as defined in
[ZigBee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf)
The End Device holds a default configuration for reporting the state of the `OnOff` attribute. Once a device wishing to receive
these periodic and on-change reports creates a remote binding, the End Device starts to send reports to this bound device.
The frequency of the reports depends on the default report configuration of the individual target device; 60 seconds in
this case. The device receiving the reports can request the change by sending a `Report Configuration` command.

## LED Indicator table

| LED1 | LED2 | Description |
| - | - | - |
| OFF | OFF | The device is not on the network |
| ON/OFF (Current On/Off cluster status) or Blinking (Identifying) | Blinking every 250ms | Find&Bind active |

## Available CLI commands

| Command | Description |
| - | - |
| `find` | Starts a Find&Bind procedure |
| `factory reset` | Sends a Leave Indication, deletes all persistent data and performs a software reset |
| `soft reset` | Performs a software reset |
