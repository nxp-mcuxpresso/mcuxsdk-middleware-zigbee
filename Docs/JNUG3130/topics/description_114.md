# Description

This function can be used on an End Device to configure a timeout period for the End Device Aging mechanism, which is described in [Section 6.10.1](end_device_aging.md).

The End Device communicates this timeout period to its parent on joining the network. The parent applies this timeout to the ‘keep-alive’ packets sent from the End Device child using the function **ZPS\_eAplAfSendKeepAlive\(\)**. If the parent does not receive a keep-alive packet from the End Device before the timeout expires, then the parent assumes the End Device is no longer active and discards it.

**Parent topic:**[ZPS\_bAplAfSetEndDeviceTimeout](../topics/zps_baplafsetenddevicetimeout.md)

