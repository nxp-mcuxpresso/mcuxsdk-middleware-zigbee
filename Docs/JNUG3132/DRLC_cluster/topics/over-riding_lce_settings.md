# Over-riding LCE Settings

The client application can over-ride certain aspects of an LCE using the function **eSE\_DRLCSetEventUserData\(\)**, which allows load control data values to be modified, including:

-   Criticality level

-   Cooling temperature set-point

-   Heating temperature set-point

-   Load adjustment percentage

-   Duty cycle


For example, the ESP/server may request an HVAC device to set its cooling level to 24oC, but the user may choose to over-ride this with a cooling level of 20oC. The above data values and their formats are detailed in the LCE structure description in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1).

The function **eSE\_DRLCSetEventUserData\(\)** modifies one load control data value on each call. Therefore, in order to modify more than one data value, the function must be called multiple times.

When a change is made, the cluster client automatically notifies the cluster server by sending a Report Event Status message containing the change.

**Parent topic:**[LCE Handling on Clients](../../DRLC_cluster/topics/lce_handling_on_clients.md)

