# Functions

This section details the C functions that are provided for the ZigBee Base Device. The functions are listed below along with the references to their descriptions.

1.  [BDB\_vInit](bdb_vinit.md#ID_8EF794FA-F34D-47E6-81B1-CCBD9FA4233E)
2.  [BDB\_vSetKeys](bdb_vsetkeys.md#ID_5F771C83-7D6B-4DEE-B5FE-124A3CD6E276)
3.  [BDB\_vStart](bdb_vstart.md#ID_3B638183-CFCB-44A4-AA70-A360F69115DF)
4.  [BDB\_eNfStartNwkFormation](bdb_enfstartnwkformation.md#ID_3D345D38-97ED-4359-995D-E67FDB9D51D5)
5.  [BDB\_eNsStartNwkSteering](bdb_ensstartnwksteering.md#ID_8FA47BCB-FF0A-42A4-A439-9C4A5FD4D100)
6.  [BDB\_eFbTriggerAsInitiator](bdb_efbtriggerasinitiator.md#ID_ED27D83B-E468-42A8-A319-C28CF11F0BD8)
7.  [BDB\_vFbExitAsInitiator](bdb_vfbexitasinitiator.md#ID_9C6CD5EC-02C7-42E1-BEE8-19FC8E7112A4)
8.  [BDB\_eFbTriggerAsTarget](bdb_efbtriggerastarget.md#ID_F52A29C2-8CF0-4A3F-8F0B-DD803E1F82B0)
9.  [BDB\_vFbExitAsTarget](bdb_vfbexitastarget.md#ID_9001C076-9618-4E24-A35C-B4C07A515AB7)
10. [BDB\_bIsBaseIdle](bdb_bisbaseidle.md#ID_0A923814-FAC0-4005-BF4D-5C8C96F8F9E2)
11. [BDB\_u8OutOfBandCommissionStartDevice](bdb_u8outofbandcommissionstartdevice.md#ID_A55D8620-8CC7-41D1-B5EC-3BB7958FDED3)
12. [BDB\_vOutOfBandCommissionGetData](bdb_voutofbandcommissiongetdata.md#ID_195D0F38-7882-4893-BD2B-4DB6D46068CE)
13. [BDB\_eOutOfBandCommissionGetDataEncrypted](bdb_eoutofbandcommissiongetdataencrypted.md#ID_7CA13F55-A605-495D-A2DC-EB9D2ABCE3B5)
14. [BDB\_bOutOfBandCommissionGetKey](bdb_boutofbandcommissiongetkey.md#ID_D1D5AF2A-A53E-4D9F-B2E3-26318F1956D5)

**Note:**  
1.  The application must provide a user-defined callback function, **APP\_vBdbCallback\(\)**, to handle ZigBee Base Device events. The prototype for this function is given in [Events](events.md#).
2.  The ZigBee Base Device supplies the callback function **BDB\_vZclEventHandler\(\)**, which handles certain ZCL events during the Finding and Binding process, as indicated in [Finding and Binding](finding_and_binding.md#).


```{include} ../topics/bdb_vinit.md
:heading-offset: 2
```

```{include} ../topics/bdb_vsetkeys.md
:heading-offset: 2
```

```{include} ../topics/bdb_vstart.md
:heading-offset: 2
```

```{include} ../topics/bdb_enfstartnwkformation.md
:heading-offset: 2
```

```{include} ../topics/bdb_ensstartnwksteering.md
:heading-offset: 2
```

```{include} ../topics/bdb_efbtriggerasinitiator.md
:heading-offset: 2
```

```{include} ../topics/bdb_vfbexitasinitiator.md
:heading-offset: 2
```

```{include} ../topics/bdb_efbtriggerastarget.md
:heading-offset: 2
```

```{include} ../topics/bdb_vfbexitastarget.md
:heading-offset: 2
```

```{include} ../topics/bdb_bisbaseidle.md
:heading-offset: 2
```

```{include} ../topics/bdb_u8outofbandcommissionstartdevice.md
:heading-offset: 2
```

```{include} ../topics/bdb_voutofbandcommissiongetdata.md
:heading-offset: 2
```

```{include} ../topics/bdb_eoutofbandcommissiongetdataencrypted.md
:heading-offset: 2
```

```{include} ../topics/bdb_boutofbandcommissiongetkey.md
:heading-offset: 2
```

**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

