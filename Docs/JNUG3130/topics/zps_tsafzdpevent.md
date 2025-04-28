# ZPS\_tsAfZdpEvent

This structure is used when a ZPS\_EVENT\_APS\_DATA\_INDICATION event is generated containing a response which is destined for the ZDO at endpoint 0. The application can extract the response data from the event using the function **ZPS\_bAplZdpUnpackResponse\(\)** and this structure is used to receive the extracted data.

The `ZPS_tsAfZdpEvent`structure is detailed below.

```
typedef struct {
    uint8 u8SequNumber;
    uint16 u16ClusterId;
    union {
        ZPS_tsAplZdpDeviceAnnceReq sDeviceAnnce;
        ZPS_tsAplZdpMgmtNwkUpdateReq sMgmtNwkUpdateReq;
        ZPS_tsAplZdpMgmtPermitJoiningReq sPermitJoiningReq;
        ZPS_tsAplZdpDiscoveryCacheRsp sDiscoveryCacheRsp;
        ZPS_tsAplZdpDiscoveryStoreRsp sDiscoveryStoreRsp;
        ZPS_tsAplZdpNodeDescStoreRsp sNodeDescStoreRsp;
        ZPS_tsAplZdpActiveEpStoreRsp sActiveEpStoreRsp;
        ZPS_tsAplZdpSimpleDescStoreRsp sSimpleDescStoreRsp;
        ZPS_tsAplZdpRemoveNodeCacheRsp sRemoveNodeCacheRsp;
        ZPS_tsAplZdpEndDeviceBindRsp sEndDeviceBindRsp;
        ZPS_tsAplZdpBindRsp sBindRsp;
        ZPS_tsAplZdpUnbindRsp sUnbindRsp;
        ZPS_tsAplZdpReplaceDeviceRsp sReplaceDeviceRsp;
        ZPS_tsAplZdpStoreBkupBindEntryRsp sStoreBkupBindEntryRsp;
        ZPS_tsAplZdpRemoveBkupBindEntryRsp sRemoveBkupBindEntryRsp;
        ZPS_tsAplZdpBackupSourceBindRsp sBackupSourceBindRsp;
        ZPS_tsAplZdpMgmtLeaveRsp sMgmtLeaveRsp;
        ZPS_tsAplZdpMgmtDirectJoinRsp sMgmtDirectJoinRsp;
        ZPS_tsAplZdpMgmtPermitJoiningRsp sPermitJoiningRsp;
        ZPS_tsAplZdpNodeDescRsp sNodeDescRsp;
        ZPS_tsAplZdpPowerDescRsp sPowerDescRsp;
        ZPS_tsAplZdpSimpleDescRsp sSimpleDescRsp;
        ZPS_tsAplZdpNwkAddrRsp sNwkAddrRsp;
        ZPS_tsAplZdpIeeeAddrRsp sIeeeAddrRsp;
        ZPS_tsAplZdpUserDescConf sUserDescConf;
        ZPS_tsAplZdpSystemServerDiscoveryRsp sSystemServerDiscoveryRsp;
        ZPS_tsAplZdpPowerDescStoreRsp sPowerDescStoreRsp;
        ZPS_tsAplZdpUserDescRsp sUserDescRsp;
        ZPS_tsAplZdpActiveEpRsp sActiveEpRsp;
        ZPS_tsAplZdpMatchDescRsp sMatchDescRsp;
        ZPS_tsAplZdpComplexDescRsp sComplexDescRsp;
        ZPS_tsAplZdpFindNodeCacheRsp sFindNodeCacheRsp;
        ZPS_tsAplZdpExtendedSimpleDescRsp sExtendedSimpleDescRsp;
        ZPS_tsAplZdpExtendedActiveEpRsp sExtendedActiveEpRsp;
        ZPS_tsAplZdpBindRegisterRsp sBindRegisterRsp;
        ZPS_tsAplZdpBackupBindTableRsp sBackupBindTableRsp;
        ZPS_tsAplZdpRecoverBindTableRsp sRecoverBindTableRsp;
        ZPS_tsAplZdpRecoverSourceBindRsp sRecoverSourceBindRsp;
        ZPS_tsAplZdpMgmtNwkDiscRsp sMgmtNwkDiscRsp;
        ZPS_tsAplZdpMgmtLqiRsp sMgmtLqiRsp;
        ZPS_tsAplZdpMgmtRtgRsp sRtgRsp;
        ZPS_tsAplZdpMgmtBindRsp sMgmtBindRsp;
        ZPS_tsAplZdpMgmtCacheRsp sMgmtCacheRsp;
        ZPS_tsAplZdpMgmtNwkUpdateNotify sMgmtNwkUpdateNotify;
    }uZdpData;
    union {
        ZPS_tsAplZdpBindingTableEntry asBindingTable[5];
        ZPS_tsAplZdpNetworkDescr asNwkDescTable[5];
        ZPS_tsAplZdpNtListEntry asNtList[2];
        ZPS_tsAplDiscoveryCache aDiscCache[5];
        uint16 au16Data[34];
        uint8 au8Data[77];
        uint64 au64Data[9];
    }uLists;
}ZPS_tsAfZdpEvent;
```

where:

-   `u8SequNumber`is the sequence number of the ZDP request/response
-   `u16ClusterId`is the ID of the cluster to which the request/response relates
-   `uZdpData`is a union of the different ZDP request/response types:
    -   `sDeviceAnnce`is a structure of the type `ZPS_tsAplZdpDeviceAnnceReq`, described in [Section 9.2.2.3](zps_tsaplzdpdeviceanncereq.md)
-   `sMgmtNwkUpdateReq`is a structure of the type `ZPS_tsAplZdpMgmtNwkUpdateReq`, described in [Section 9.2.2.41](zps_tsaplzdpmgmtnwkupdatereq.md)
-   `sPermitJoiningReq`is a structure of the type `ZPS_tsAplZdpMgmtPermitJoiningReq`, described in [Section 9.2.3.39](zps_tsaplzdpmgmtpermitjoiningrsp.md)
-   `sDiscoveryCacheRsp`is a structure of the type `ZPS_tsAplZdpDiscoveryCacheRsp`, described in [Section 9.2.3.14](zps_tsaplzdpdiscoverycachersp.md)
-   `sDiscoveryStoreRsp`is a structure of the type `ZPS_tsAplZdpDiscoveryStoreRsp`, described in [Section 9.2.3.15](zps_tsaplzdpdiscoverystorersp.md)
-   `sNodeDescStoreRsp`is a structure of the type `ZPS_tsAplZdpNodeDescStoreRsp`, described in [Section 9.2.3.16](zps_tsaplzdpnodedescstorersp.md)
-   `sActiveEpStoreRsp`is a structure of the type `ZPS_tsAplZdpActiveEpStoreRsp`, described in [Section 9.2.3.19](zps_tsaplzdpactiveepstorersp.md)
-   `sSimpleDescStoreRsp`is a structure of the type `ZPS_tsAplZdpSimpleDescStoreRsp`, described in [Section 9.2.3.18](zps_tsaplzdpsimpledescstorersp.md)
-   `sRemoveNodeCacheRsp`is a structure of the type `ZPS_tsAplZdpRemoveNodeCacheRsp`, described in [Section 9.2.3.21](zps_tsaplzdpremovenodecachersp.md)
-   `sEndDeviceBindRsp`is a structure of the type `ZPS_tsAplZdpEndDeviceBindRsp`, described in [Section 9.2.3.22](zps_tsaplzdpenddevicebindrsp.md)
-   `sBindRsp`is a structure of the type `ZPS_tsAplZdpBindRsp`, described in [Section 9.2.3.23](zps_tsaplzdpbindrsp.md)
-   `sUnbindRsp`is a structure of the type `ZPS_tsAplZdpUnbindRsp`, described in [Section 9.2.3.24](zps_tsaplzdpunbindrsp.md)
-   `sReplaceDeviceRsp`is a structure of the type `ZPS_tsAplZdpReplaceDeviceRsp`, described in [Section 9.2.3.26](zps_tsaplzdpreplacedevicersp.md)
-   `sStoreBkupBindEntryRsp`is a structure of the type `ZPS_tsAplZdpStoreBkupBindEntryRsp`, described in [Section](zps_tsaplzdpstorebkupbindentryreq.md)[9.2.2.27](zps_tsaplzdpstorebkupbindentryreq.md)
-   `sRemoveBkupBindEntryRsp`is a structure of the type `ZPS_tsAplZdpRemoveBkupBindEntryRsp`, described in [Section](zps_tsaplzdpremovebkupbindentryreq.md)[9.2.2.28](zps_tsaplzdpremovebkupbindentryreq.md)
-   `sBackupSourceBindRsp`is a structure of the type `ZPS_tsAplZdpBackupSourceBindRsp`, described in [Section 9.2.3.31](zps_tsaplzdpbackupsourcebindrsp.md)
-   `sMgmtLeaveRsp`is a structure of the type `ZPS_tsAplZdpMgmtLeaveRsp`, described in [Section 9.2.3.37](zps_tsaplzdpmgmtleaversp.md)
-   `sMgmtDirectJoinRsp`is a structure of the type `ZPS_tsAplZdpMgmtDirectJoinRsp`, described in [Section 9.2.3.38](zps_tsaplzdpmgmtdirectjoinrsp.md)
-   `sPermitJoiningRsp`is a structure of the type `ZPS_tsAplZdpMgmtPermitJoiningRsp`, described in [Section 9.2.3.39](zps_tsaplzdpmgmtpermitjoiningrsp.md)
-   `sNodeDescRsp`is a structure of the type `ZPS_tsAplZdpNodeDescRsp`, described in [Section 8.2.3.3](zps_tsaplzdpnodedescrsp.md)
-   `sPowerDescRsp`is a structure of the type `ZPS_tsAplZdpPowerDescRsp`, described in [Section 9.2.3.4](zps_tsaplzdppowerdescrsp.md)
-   `sSimpleDescRsp`is a structure of the type `ZPS_tsAplZdpSimpleDescRsp`, described in [Section 9.2.3.5](zps_tsaplzdpsimpledescrsp.md)
-   `sNwkAddrRsp`is a structure of the type `ZPS_tsAplZdpNwkAddrRsp`, described in [Section 9.2.3.1](zps_tsaplzdpnwkaddrrsp.md)
-   `sIeeeAddrRsp`is a structure of the type `ZPS_tsAplZdpIeeeAddrRsp`, described in [Section 9.2.3.2](zps_tsaplzdpieeeaddrrsp.md)
-   `sUserDescConf`is a structure of the type `ZPS_tsAplZdpUserDescConf`, described in [Section 9.2.3.12](zps_tsaplzdpuserdescconf.md)
-   `sSystemServerDiscoveryRsp`is a structure of the type `ZPS_tsAplZdpSystemServerDiscoveryRsp`, described in [Section](zps_tsaplzdpsystemserverdiscoveryrsp.md)[9.2.3.13](zps_tsaplzdpsystemserverdiscoveryrsp.md)
-   `sPowerDescStoreRsp`is a structure of the type `ZPS_tsAplZdpPowerDescStoreRsp`, described in [Section 9.2.3.17](zps_tsaplzdppowerdescstorersp.md)
-   `sUserDescRsp`is a structure of the type `ZPS_tsAplZdpUserDescRsp`, described in [Section 9.2.3.8](zps_tsaplzdpuserdescrsp.md)
-   `sActiveEpRsp`is a structure of the type `ZPS_tsAplZdpActiveEpRsp`, described in [Section 9.2.3.10](zps_tsaplzdpactiveeprsp.md)
-   `sMatchDescRsp`is a structure of the type `ZPS_tsAplZdpMatchDescRsp`, described in [Section 9.2.3.9](zps_tsaplzdpmatchdescrsp.md)
-   `sComplexDescRsp`is a structure of the type `ZPS_tsAplZdpComplexDescRsp`, described in [Section 9.2.3.7](zps_tsaplzdpcomplexdescrsp.md)
-   `sFindNodeCacheRsp`is a structure of the type `ZPS_tsAplZdpFindNodeCacheRsp`, described in [Section 9.2.3.20](zps_tsaplzdpfindnodecachersp.md)
-   `sExtendedSimpleDescRsp`is a structure of the type `ZPS_tsAplZdpExtendedSimpleDescRsp`, described in [Section 9.2.3.6](zps_tsaplzdpextendedsimpledescrsp.md)
-   `sExtendedActiveEpRsp`is a structure of the type `ZPS_tsAplZdpExtendedActiveEpRsp`, described in [Section 9.2.3.11](zps_tsaplzdpextendedactiveeprsp.md)
-   `sBindRegisterRsp`is a structure of the type `ZPS_tsAplZdpBindRegisterRsp`, described in [Section 9.2.3.25](zps_tsaplzdpbindregisterrsp.md)
-   `sBackupBindTableRsp`is a structure of the type `ZPS_tsAplZdpBackupBindTableRsp`, described in [Section 9.2.3.29](zps_tsaplzdpbackupbindtablersp.md)
-   `sRecoverBindTableRsp`is a structure of the type `ZPS_tsAplZdpRecoverBindTableRsp`, described in [Section 9.2.3.30](zps_tsaplzdprecoverbindtablersp.md)
-   `sRecoverSourceBindRsp`is a structure of the type `ZPS_tsAplZdpRecoverSourceBindRsp`, described in [Section 9.2.3.32](zps_tsaplzdprecoversourcebindrsp.md)
-   `sMgmtNwkDiscRsp`is a structure of the type `ZPS_tsAplZdpMgmtNwkDiscRsp`, described in [Section 9.2.3.33](zps_tsaplzdpmgmtnwkdiscrsp.md)
-   `sMgmtLqiRsp`is a structure of the type `ZPS_tsAplZdpMgmtLqiRsp`, described in [Section 9.2.3.34](zps_tsaplzdpmgmtlqirsp.md)
-   `sRtgRsp`is a structure of the type `ZPS_tsAplZdpMgmtRtgRsp`, described in [Section 9.2.3.35](zps_tsaplzdpmgmtrtgrsp.md)
-   `sMgmtBindRsp`is a structure of the type `ZPS_tsAplZdpMgmtBindRsp`, described in [Section 9.2.3.36](zps_tsaplzdpmgmtbindrsp.md)
-   `sMgmtCacheRsp`is a structure of the type `ZPS_tsAplZdpMgmtCacheRsp`, described in [Section 9.2.3.40](zps_tsaplzdpmgmtcachersp.md)
-   `sMgmtNwkUpdateNotify`is a structure of the type `ZPS_tsAplZdpMgmtNwkUpdateNotify`, described in [Section 9.2.3.41](zps_tsaplzdpmgmtnwkupdatenotify.md)
-   `uLists`is a union of the different arrays/tables which act as temporary storage for data elements used by the stack \(and are therefore for internal use only\)

**Parent topic:**[Event structures](../topics/event_structures.md)

