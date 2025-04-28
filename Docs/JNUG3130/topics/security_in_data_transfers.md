# Security in data transfers

The ‘send data’ functions for unicast, broadcast, group transfer and bound transfer contain a parameter to select the required security setting for the protection of the sent message. In the NXP ZigBee PRO software, there are currently three security options, as follows:

-   No security
-   Network-level security
-   Application-level security

Application-level security is only available for unicast and bound transfers, while network-level security is available for all transfer types except inter-PAN transfers.

Network-level and application-level security are detailed in [Section 5.8](implementing_zigbee_security.md).

**Note:**

1.  No security is available for inter-PAN transfers \(to other networks\).
2.  When application-level security is used in sending data, the IEEE/MAC address and network address of the target node must be available through the local Address Map table - see Section 5.2.3.

**Parent topic:**[Transferring data](../topics/transferring_data.md)

