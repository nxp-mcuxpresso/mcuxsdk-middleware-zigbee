# Description

This function obtains the effective payload size, in bytes, within an IEEE802.15.4 data frame to be sent to the node with the specified network address. The handle of the relevant Application layer instance must also be specified, which can be obtained using **ZPS\_pvAplZdoGetAplHandle\(\)**.

An IEEE802.15.4 data frame contains 127 bytes, but the effective payload is reduced by the various IEEE802.15.4 and ZigBee headers. The function returns the size of the payload available for data but does not take into account bytes needed for ZCL cluster headers \(so may not reflect the exact amount of space available for data\).

**Parent topic:**[ZPS\_u8AplGetMaxPayloadSize](../topics/zps_u8aplgetmaxpayloadsize.md)

