# Battery-powered components

There are many wireless applications that benefit from battery power, including light-switches, active tags and security detectors. The ZigBee and IEEE 802.15.4 protocols are specifically designed for battery-powered applications. From a user perspective, battery power has certain advantages:

-   <strong>Easy and low-cost installation of nodes:</strong>No need to connect node to separate power supply.
-   <strong>Flexible location of nodes:</strong>Nodes can be installed in difficult places where there is no power supply, and can even be used as mobile devices.
-   <strong>Easily modified network:</strong>Nodes can easily be added or removed, on a temporary or permanent basis.

Since these devices are generally small, they use low-capacity batteries and therefore battery use must be optimized. This is achieved by restricting the amount of time for which energy is required by the device.

-   Since the major power drain in the system is the operation of the radio, data may be transmitted infrequently \(perhaps once per hour or even once per week\), which results in a low duty cycle \(transmission time as proportion of time interval between transmissions\).
-   When data is not being sent, the device may revert to a low-power ‘sleep’ mode to minimize power consumption.

In practice, not all nodes on a network can be battery-powered, notably those that need to be switched on all the time for routing purposes \(and therefore cannot sleep\). These devices can often be installed in a mains-powered appliance that is permanently connected to the mains supply \(even if not switched on\) - for example, a ceiling lamp or an electric radiator. This avoids the need to install a dedicated mains power connection for the node. Only End Devices are normally battery-powered.

**Note:**

A network device can also potentially use "energy harvesting" to absorb and store energy from its surroundings - for example, the use of a solar cell panel on a device in a well-lit environment.

**Parent topic:**[ZigBee overview](../topics/zigbee_overview.md)

