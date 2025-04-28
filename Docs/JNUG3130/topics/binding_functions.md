# Binding functions

The ZDP Binding functions are concerned with binding nodes together, to aid communication between them, and managing binding tables.

1.  [ZPS\_eAplZdpEndDeviceBindRequest](zps_eaplzdpenddevicebindrequest.md)
2.  [ZPS\_eAplZdpBindUnbindRequest](zps_eaplzdpbindunbindrequest.md)
3.  [ZPS\_eAplZdpBindRegisterRequest](zps_eaplzdpbindregisterrequest.md)
4.  [ZPS\_eAplZdpReplaceDeviceRequest](zps_eaplzdpreplacedevicerequest.md)
5.  [ZPS\_eAplZdpStoreBkupBindEntryRequest](zps_eaplzdpstorebkupbindentryrequest.md)
6.  [ZPS\_eAplZdpRemoveBkupBindEntryRequest](zps_eaplzdpremovebkupbindentryrequest.md)
7.  [ZPS\_eAplZdpBackupBindTableRequest](zps_eaplzdpbackupbindtablerequest.md)
8.  [ZPS\_eAplZdpRecoverBindTableRequest](zps_eaplzdprecoverbindtablerequest.md)
9.  [ZPS\_eAplZdpBackupSourceBindRequest](zps_eaplzdpbackupsourcebindrequest.md)
10. [ZPS\_eAplZdpRecoverSourceBindRequest](zps_eaplzdprecoversourcebindrequest.md)
11. [ZPS\_eAplAibRemoveBindTableEntryForMacAddress](zps_eaplaibremovebindtableentryformacaddress.md)

**Note:**

1.  Some of the above binding functions cannot be used to send requests to nodes that run the NXP ZigBee PRO stack. They are supplied in the NXP ZDP API in order to facilitate interoperability with nodes based on non-NXP software, which supports the corresponding requests. If applicable, this restriction is noted in the function description.
2.  Further binding functions are provided in the ZDO API and are described in [Section 7.1.1, "Network Deployment Functions"](network_deployment_functions.md).


```{include} ../topics/zps_eaplzdpenddevicebindrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpbindunbindrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpbindregisterrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpreplacedevicerequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpstorebkupbindentryrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpremovebkupbindentryrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpbackupbindtablerequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdprecoverbindtablerequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdpbackupsourcebindrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplzdprecoversourcebindrequest.md
:heading-offset: 3
```

```{include} ../topics/zps_eaplaibremovebindtableentryformacaddress.md
:heading-offset: 3
```

**Parent topic:**[ZDP API functions](../topics/zdp_api_functions.md)

