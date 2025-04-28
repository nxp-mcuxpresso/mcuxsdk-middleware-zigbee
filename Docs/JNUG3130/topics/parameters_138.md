# Parameters

-   *u64DeviceAddr:* 64-bit IEEE/MAC address of node for which permissions are to be obtained.
-   *pu8DevicePermissions:* Pointer to bitmap containing permissions obtained, where:
    -   0 indicates all requests allowed.
    -   1 indicates join requests disallowed.
    -   2 indicates data requests disallowed.
    -   3 indicates data and join requests disallowed.
    -   Higher bits are reserved for future use

**Parent topic:**[ZPS\_bAplZdoTrustCenterGetDevicePermissions](../topics/zps_baplzdotrustcentergetdevicepermissions.md)

