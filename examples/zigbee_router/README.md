# Table of Content

- [Table of Content](#table-of-content)
- [Zigbee Router demo example](#zigbee-router-demo-example)
  - [Joining a network](#joining-a-network)
  - [Allowing other devices to join the network](#allowing-other-devices-to-join-the-network)
  - [Operating the device](#operating-the-device)
  - [Rejoining a network](#rejoining-a-network)
  - [Performing a factory reset](#performing-a-factory-reset)
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

## Available CLI commands

| Command | Description |
| - | - |
| `find` | Steers the network and starts a Find&Bind procedure |
| `factory reset` | Sends a Leave Indication, deletes all persistent data and performs a software reset |
| `soft reset` | Performs a software reset |