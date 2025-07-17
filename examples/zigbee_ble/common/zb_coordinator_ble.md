# Zigbee coordinator BLE wireless UART demo example

This application is provided in the context of demonstrating the Zigbee commissioning over Bluetooth LE
and is part of the wireless examples for Zigbee. 

Depending on the underlying board, the application is available in two flavours:

- `zigbee_coordinator_ble_uart`: the zigbee application part is based on the Zigbee Coordinator example and the
Bluetooth LE application part is based on the Wireless UART peripheral demo. Targeted boards: MCX-W71-EVK, FRDM-MCXW71, MCX-W72-EVK, FRDM-MCXW72.

- `zigbee_coordinator_ble_wu`: the zigbee application is based on the Zigbee Coordinator example and the 
Bluetooth LE application part is based on the EdgeFast Wireless UART demo. Targeted boards: RD-RW612-BGA, FRDM-RW612.

The Narrow Band Unit (NBU) firmware for this application is included in the SDK folder and should be updated based on targeted board. The NBU firmware
to be written for Bluetooth LE - Zigbee dynamic mode applications is the same image used for Zigbee example applications.

After reboot, the device running the application is ready to receive commands over Bluetooth LE through the Wireless UART profile. The communication over Bluetooth LE between the application can be intermediated by a mobile application. 

To test the application the `IoT Toolbox` application can be used which is available for both Android and iOS.
`IoT Toolbox` provides an application called `ZigBee shell` that can be used to send CLI commands over Bluetooth LE through the Wireless UART profile.

The functionality of the Coordinator application is described as follows:
- The Coordinator is responsible for initially forming the network. It also manages other devices that can join
the network via the Trust center functionality. It also distributes security materials to those devices that are
allowed to join. The Coordinator supports the mandatory clusters and features of the Base Device as defined
in the ZigBee Base Device Behavior Specification.
- For demonstrating the "Finding and Binding" functionality, the Coordinator also supports the On/Off Cluster as
a client.
- The commands should be sent over Bluetooth LE through the Wireless UART profile. 
Refer to the [Available CLI commands](#available-cli-commands) chapter for more information on the available commands.

## Forming a network

A network can be formed from a factory-new Coordinator by sending the `zigbee_create_network` command.
The Coordinator then forms a network. Optionnaly, A ZigBee packet sniffer
(running separately on a USB Dongle) might be used to validate if the network is correctly formed.
The periodic "link status" messages must be present on the operational channel.

## Allowing other devices to join the network

Commissioning description and step by step procedure are provided in:
[commissioning.md](commissioning.md)

## Operating the device

The operational functionality of this device in this demonstration is provided by the On/Off cluster. Before being able
to send On/Off toggle commands to other devices, the Coordinator must start a Find and Bind as an initiator, this is done
by using the `zigbee_find` command. The other devices must start a Find and Bind procedure as a target. Once bound, the Coordinator
can send On/Off toggle commands using `zigbee_toggle` command to the bound devices.

## Rejoining a network

As a Coordinator, when this device is restarted in a state that is not factory-new, it resumes operation in
its previous state. All applications, bindings, groups, and network parameters are preserved in non-volatile
memory.

## Performing a factory reset

The Coordinator can be returned to its factory-new state, which erases all persistent data except the outgoing
network frame counter. To perform a factory reset, send the `zigbee_factoryreset` command over BLE Wireless UART profile.

## LED indication table

| LED1 | LED2 | NOTES |
| - | - | - |
| OFF | OFF | The device is not on the network |
| OFF | ON | The device is active |
| OFF | Blinking every 1s | Find and Bind active |

## Available CLI commands

| Command | Description |
| - | - |
| `zigbee_factoryreset` | Resets the device to its factory state |
| `zigbee_get_network_status` | Returns the network status NETWORK_CREATED or NETWORK_NOT_CREATED |
| `zigbee_get_network_info` | Returns the network info, Network Info would be serialized in the TLV format if created or NETWORK_NOT_CREATED (if the network is not formed) |
| `zigbee_create_network` | Allows to create a zigbee network, NETWORK_ALREADY_CREATED will be retured if the network is already formed |
| `zigbee_find` | Start Find & Bind as an initiator, make sure to trigger Find & Bind on a TARGET device |
| `zigbee_toggle` | Sends on\off toggle command to bound devices |

## OTA

The Coordinator example supports the OTA Server cluster. As many factors depend on the platform used, please check the
platform specific documentation:
- [RW612](../../../platform/RW612/docs/README.md)