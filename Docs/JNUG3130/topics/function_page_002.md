# Function page

1.  [ZPS\_vAplSecSetInitialSecurityState](zps_vaplsecsetinitialsecuritystate.md)
2.  [ZPS\_eAplZdoTransportNwkKey](zps_eaplzdotransportnwkkey.md)
3.  [ZPS\_eAplZdoSwitchKeyReq](zps_eaplzdoswitchkeyreq.md)
4.  [ZPS\_eAplZdoRequestKeyReq](zps_eaplzdorequestkeyreq.md)
5.  [ZPS\_eAplZdoAddReplaceLinkKey](zps_eaplzdoaddreplacelinkkey.md)
6.  [ZPS\_eAplZdoAddReplaceInstallCodes](zps_eaplzdoaddreplaceinstallcodes.md)
7.  [ZPS\_eAplZdoRemoveLinkKey](zps_eaplzdoremovelinkkey.md)
8.  [ZPS\_eAplZdoRemoveDeviceReq](zps_eaplzdoremovedevicereq.md)
9.  [ZPS\_eAplZdoSetDevicePermission](zps_eaplzdosetdevicepermission.md)
10. [ZPS\_bAplZdoTrustCenterSetDevicePermissions](zps_baplzdotrustcentersetdevicepermissions.md)
11. [ZPS\_bAplZdoTrustCenterGetDevicePermissions](zps_baplzdotrustcentergetdevicepermissions.md)
12. [ZPS\_bAplZdoTrustCenterRemoveDevice](zps_baplzdotrustcenterremovedevice.md)
13. [ZPS\_vTcInitFlash](zps_vtcinitflash.md)
14. [ZPS\_vSetTCLockDownOverride](zps_vsettclockdownoverride.md)
15. [ZPS\_psGetActiveKey](zps_psgetactivekey.md)
16. [ZPS\_vTCSetCallback](zps_vtcsetcallback.md)

**Note:**

1.  Before using the above functions on a node, security must be enabled on the node via the device parameter `Security Enabled` in the ZPS Configuration Editor \(security is enabled by default\).
2.  Enabling security also enables many-to-one routing toward the Trust Centre, which then becomes a network concentrator. You must set the maximum number of nodes to be serviced by the Trust Centre using its network parameter `Route Record Table Size` in the ZPS Configuration Editor \(the default number is 4\).
3.  Many of the security settings and keys that are set up using the above functions can alternatively be pre-configured via the ZPS Configuration Editor.

**Parent topic:**[Security functions](../topics/security_functions.md)

