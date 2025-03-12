# Summary of serial interface commands

The serial port connection to the Coordinator application is set up with the following configuration settings:

-   Baud rate = 115200
-   Data = 8 bits
-   Stop = 1 bit
-   Parity = None

The serial commands are not case-sensitive.

|Serial command|Action|
|--------------|------|
|`toggle`|Sends an On/Off Toggle command to bound devices|
|`steer`|Triggers Network Steering for a device on the network|
|`form`|Triggers network formation for a device not on a network|
|`find`|Triggers Finding and Binding as an initiator|
|`factory reset`|Factory resets the device, erasing persistent data|
|`soft reset`|Triggers a software reset \(no loss of data\)|

**Parent topic:**[Coordinator functionality](../topics/coordinator_functionality.md)

