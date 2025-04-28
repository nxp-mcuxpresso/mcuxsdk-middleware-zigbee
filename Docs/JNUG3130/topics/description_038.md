# Description

This function can be used on a Router or the Coordinator to control whether new child nodes are allowed to join it - that is, to set the node’s ‘permit joining’ status. The function can be used to enable joining permanently or for a fixed duration, or to disable joining \(permanently\).

The specified parameter value determines the ‘permit joining’ status, as follows:

-   `0`: Disables joining
-   `1- 254`: Enables joining for specified time interval, in seconds
-   `255`: Enables joining permanently

For example, if the parameter is set to 60, joining is enabled for the next 60 seconds and then automatically disabled.

**Note:** The ‘permit joining’ setting of a device is ignored during a join attempt in which a non-zero Extended PAN ID is specified on the joining device and during any rejoin attempt.



**Parent topic:**[ZPS\_eAplZdoPermitJoining](../topics/zps_eaplzdopermitjoining.md)

