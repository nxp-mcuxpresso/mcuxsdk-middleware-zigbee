# Description

This function can be called on a Router or End Device to configure whether various tabulated context data must be cleared from the node when it leaves the network without the intention to rejoin.

By default, the Neighbor table, Binding table and Group table are cleared on a Router, and the network key is cleared on a Router and End Device. In addition, other devices remove the node from their Binding tables on detecting the leave request \(without the rejoin flag set\).

This function can be used to over-ride this behavior in order to preserve this table data. It can also be used to later reinstate the default behavior.

**Parent topic:**[ZPS\_vSetTablesClearOnLeaveWithoutRejoin](../topics/zps_vsettablesclearonleavewithoutrejoin.md)

