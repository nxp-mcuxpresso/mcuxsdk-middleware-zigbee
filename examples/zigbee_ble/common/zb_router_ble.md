# Zigbee Router BLE wireless UART demo example

This application is provided in the context of demonstrating the Zigbee commissioning over Bluetooth LE
and is part of the wireless examples for Zigbee. 

Depending on the underlying board, the application is available in two flavours:

- `zigbee_router_ble_uart`: the zigbee application part is based on the Zigbee Router example and the
Bluetooth LE application part is based on the Wireless UART peripheral demo. Targeted boards: MCX-W71-EVK, FRDM-MCXW71.

- `zigbee_router_ble_wu`: the zigbee application is based on the Zigbee Router example and the 
Bluetooth LE application part is based on the EdgeFast Wireless UART demo. Targeted boards: RD-RW612-BGA, FRDM-RW612.

After reboot, the device running the application is ready to receive commands over Bluetooth LE through the Wireless UART profile. The communication over Bluetooth LE between the application can be intermediated by a mobile application. 

To test the application the `IoT Toolbox` application can be used which is available for both Android and iOS.
`IoT Toolbox` provides an application called `ZigBee shell` that can be used to send CLI commands over Bluetooth LE through the Wireless UART profile.

The Zigbee Router demo example demonstrates the Router device type and the "Find and Binding" functionality.
To do so, it supports the On/Off Cluster as a server.

A CLI similar to the Coordinator's one is provided.
Refer to the [Available CLI commands](#available-cli-commands) chapter for more information on the available commands.

## Joining a network

The commissioning procedure to join a network is described in:
[commissioning.md](commissioning.md)

## Operating the device

The operational functionality of this device in this demonstration is provided by the On/Off cluster. Since the
device supports the On/Off cluster server, its operation is passive, and it responds to commands sent by bound
devices. It responds to an OnOff Toggle command from a bound controller device by toggling the LED1 on the board if
there's one available.

## Rejoining a network

As a Router, when this device is restarted in a state, which is not factory-new, it resumes operation in its
previous state. All application, binding, group, and network parameters are preserved within the non-volatile
memory of the device.

## Performing a factory reset

The Router can be returned to its factory-new state (erasing all persistent data except the outgoing network
frame counter) by sending `zigbee_factoryreset` command over BLE Wireless UART profile.

The Router then broadcasts a Leave Indication on the old network. It also deletes all persistent data (except the
outgoing network frame counter) and performs a software reset.
There are two supported over-the-air commands for removing a device from the network. These commands are
listed below:
- Network Leave Request without rejoin
- ZDO Management Network Leave Request without rejoin

## Binding devices

The Router supports the On/Off cluster as a server and implement the "Finding and Binding" process as a
target. To trigger "Finding and Binding" as a target, perform the following step:
1. Press the USER button on the board of the target device.
2. Start "Finding and Binding" on the initiator device.

This step causes the Router to self-identify for 180 seconds. In this duration, the initiator tries
to find the identifying devices, queries their capabilities, and creates bindings on the devices with matching
operational clusters. As part of this process, the Router can receive an `Add Group` command and/or a `Binding Request command`.

## LED Indicator table

| LED1 | LED2 | Description |
| - | - | - |
| OFF | OFF | The device is not on the network |
| ON/OFF (Current On/Off cluster status) or Blinking (Identifying) | Blinking every 250ms | Find&Bind active |

## Available CLI commands

| Command | Description |
| - | - |
| `zigbee_factoryreset` | Resets the device to its factory state |
| `zigbee_get_network_status` | Returns the network status CONNECTED or NOT_CONNECTED |
| `zigbee_get_device_info` | Returns the device info (extended address, installation code, CRC), that would be serialized in the TLV format |
| `zigbee_set_network_info` | Set the network information, the device will automatically try to join the network at the end of the download |

