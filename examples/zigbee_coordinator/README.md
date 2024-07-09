# Table of Content

- [Table of Content](#table-of-content)
- [Zigbee Coordinator demo example](#zigbee-coordinator-demo-example)
  - [Forming a network](#forming-a-network)
  - [Allowing other devices to join the network](#allowing-other-devices-to-join-the-network)
  - [Operating the device](#operating-the-device)
  - [Rejoining a network](#rejoining-a-network)
  - [Performing a factory reset](#performing-a-factory-reset)
  - [LED indication table](#led-indication-table)
  - [Available CLI commands](#available-cli-commands)

# Zigbee Coordinator demo example

The functionality of the Coordinator application is described as follows:
- The Coordinator is responsible for initially forming the network. It also manages other devices that can join
the network via the Trust center functionality. It also distributes security materials to those devices that are
allowed to join. The Coordinator supports the mandatory clusters and features of the Base Device as defined
in the ZigBee Base Device Behavior Specification.
- For demonstrating the "Finding and Binding" functionality, the Coordinator also supports the On/Off Cluster as
a client.
- The serial commands issued from a terminal program control the Coordinator. The terminal program runs on
a PC connected to the Zigbee device through a USB connection. The Coordinator application is configured to
communicate at 115200 baud, 8-bit data, 1 stop bit, no parity, or flow control. The serial interface is not case sensitive.
Refer to the [Available CLI commands](#available-cli-commands) chapter for more information on the available commands.

## Forming a network

A network can be formed from a factory-new Coordinator (Network Steering while not on a network). Enter the
`form` command on the serial interface. The Coordinator then forms a network. Optionnaly, A ZigBee packet sniffer
(running separately on a USB Dongle) might be used to validate if the network is correctly formed.
The periodic "link status" messages must be present on the operational channel.

## Allowing other devices to join the network

Once a network has been formed, it must be opened to allow other devices to join it, referred to as Network
Steering while on a network. To initiate Network Steering, enter the `steer` command on the serial interface (Dongle or
Carrier Board).
The Coordinator then broadcasts a Management Permit Join Request to the network to open the "permit join"
window for 180 seconds. The Network Steering process (for devices not on a network) can now be triggered on
the devices that are to join the network.

## Operating the device

The operational functionality of this device in this demonstration is provided by the On/Off cluster. Before being able
to send On/Off toggle commands to other devices, the Coordinator must start a Find and Bind as an initiator, this is done
by using the `find` command. The other devices must start a Find and Bind procedure as a target. Once bound, the Coordinator
can send On/Off toggle commands. Enter the `toggle` in the serial interface (Carrier Board) to send an OnOff Toggle
command to the bound devices (in the Binding table).

## Rejoining a network

As a Coordinator, when this device is restarted in a state that is not factory-new, it resumes operation in
its previous state. All applications, bindings, groups, and network parameters are preserved in non-volatile
memory.

## Performing a factory reset

The Coordinator can be returned to its factory-new state, which erases all persistent data except the outgoing
network frame counter. To perform a factory reset, enter the `factory reset` command on the serial interface.

## LED indication table

| LED1 | LED2 | NOTES |
| - | - | - |
| OFF | OFF | The device is not on the network |
| OFF | Blinking every 500ms | Network steering / permit to join is active |
| OFF | Blinking every 1s | Find and Bind active |
| OFF | ON | The device is active |
| OFF | Blinking every 250ms | Both network steering and Find and Bind are active |

## Available CLI commands

| Command | Description |
| - | - |
| `toggle` | Sends an On/Off toggle command to bound devices |
| `steer` | Starts Network Steering (opens permit join window) |
| `form` | Forms a network |
| `find` | Starts a Find&Bind procedure as an initiator |
| `factory reset` | Deletes all persistent data and performs a software reset |
| `soft reset` | Performs a software reset |
