# Table of Content

- [Table of Content](#table-of-content)
- [Zigbee Router demo example](#zigbee-router-demo-example)
  - [Joining a network](#joining-a-network)
  - [Allowing other devices to join the network](#allowing-other-devices-to-join-the-network)
  - [Operating the device](#operating-the-device)
  - [Rejoining a network](#rejoining-a-network)
  - [Performing a factory reset](#performing-a-factory-reset)
  - [Binding devices](#binding-devices)
  - [LED Indicator table](#led-indicator-table)
  - [Available CLI commands](#available-cli-commands)

# Zigbee Router demo example

The Zigbee Router demo example demonstrates the Router device type and the "Find and Binding" functionality.
To do so, it supports the On/Off Cluster as a server.

A CLI similar to the Coordinator's one can be enabled by defining the preprocessor flag `APP_ROUTER_NODE_CLI`. By default,
this flag is not set, only the board button will be available to operate the device. Refer to the [Available CLI commands](#available-cli-commands) chapter for
more information on the available commands.

## Joining a network

The Router can only join an existing network. If it does not find one, it continues discovering the network until it
can find one to join.

A factory-new Router can join an existing ZigBee network only when the network has been opened to accept new joiners
(Network Steering for a device on a network). Joining an existing network using Network Steering is achieved as follow:
- Trigger Network Steering on one of the devices already on the network (Coordinator or another Router in the same network)
- Then reset using the RESET button or power on the joining Router device

As a result, the Router starts a network discovery and the associate process. Association is followed by an exchange
of security materials and an update of the Trust Center link key (if joining a Centralized Trust Center network).

## Allowing other devices to join the network

Once the Router is part of a network, it can open the network to allow other devices to join (Network Sterring while on
a network). To allow other devices to join, press the USER button. The same button is used to start "Finding and Binding".
Alternatively, the command `find` can be used.

The Router then broadcasts a Management Permit Join Request to the network to open the "permit join" window for 180 seconds.
The Network Steering process (for devices not on the network) can now be triggered on the devices that are to join the
network.

## Operating the device

The operational functionality of this device in this demonstration is provided by the On/Off cluster. Since the
device supports the On/Off cluster server, its operation is passive, and it responds to commands sent by bound
devices. It responds to an OnOff Toggle command from a bound controller device by toggling the LED1 on the board if
there's one available. On boards where no LEDs are available, only an internal boolean state will be toggled.

## Rejoining a network

As a Router, when this device is restarted in a state, which is not factory-new, it resumes operation in its
previous state. All application, binding, group, and network parameters are preserved within the non-volatile
memory of the device.

## Performing a factory reset

The Router can be returned to its factory-new state (erasing all persistent data except the outgoing network
frame counter) as follows:
- Hold down the USER button and press the RESET button on the board.
- Alternatively, use the command `factory reset`

The Router then broadcasts a Leave Indication on the old network. It also deletes all persistent data (except the
outgoing network frame counter) and performs a software reset.
There are two supported over-the-air commands for removing a device from the network. These commands are
listed below:
- Network Leave Request without rejoin
- ZDO Management Network Leave Request without rejoin

The Reset command of the Basic cluster causes the ZCL to be reset to its factory-new defaults, resetting
all attributes and configured reports. This does not remove the device from the network and all network
parameters, groups, and bindings remain in place.

## Binding devices

The Router supports the On/Off cluster as a server and implement the "Finding and Binding" process as a
target. To trigger "Finding and Binding" as a target, perform the following steps:
1. Press the USER button on the board of the target device. Alternatively, use the `find` command.
2. Start "Finding and Binding" on the initiator device.

This step causes the Router to self-identify for 180 seconds. In this duration, the initiator tries
to find the identifying devices, queries their capabilities, and creates bindings on the devices with matching
operational clusters. As part of this process, the Router can receive an `Add Group` command and/or a `Binding Request command`.

Reporting is a mandatory feature in ZigBee 3.x. The Router supports the `On/Off` cluster as a server and the OnOff
attribute of this cluster is a reportable attribute as defined in
[ZigBee Base Device Behavior Specification](https://zigbeealliance.org/wp-content/uploads/2019/12/docs-13-0402-13-00zi-Base-Device-Behavior-Specification-2-1.pdf)
The Router holds a default configuration for reporting the state of the `OnOff` attribute. Once a device wishing to receive
these periodic and on-change reports creates a remote binding, the Router starts to send reports to this bound device.
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
| `find` | Steers the network and starts a Find&Bind procedure |
| `factory reset` | Sends a Leave Indication, deletes all persistent data and performs a software reset |
| `soft reset` | Performs a software reset |
