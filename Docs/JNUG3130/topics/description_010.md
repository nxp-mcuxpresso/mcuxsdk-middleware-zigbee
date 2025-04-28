# Description

This function can be used on the network Coordinator/Trust Centre to enable the persistent storage of the Trust Centre Link Keys \(TCLKs\) for all nodes in the network.

Each of these keys is a unique application-level link key for a node. The key is used to encrypt/decrypt communications between Trust Centre and the node during the commissioning of the node into the network \(and is issued by the Trust Centre to replace the pre-configured unique link key\).

The function allows these link keys to be stored in devices Flash memory.

-   Information about the Flash memory sector to be used to store the link keys is specified in a `ZPS_tsAfFlashInfoSet`structure.
-   Information about an individual link key is stored in RAM in a read-only `ZPS_TclkDescriptorEntry`structure, which is for internal use by the stack. An array of these structures must be allocated in RAM, with one element for each node in the network - for example, if there are up to 250 nodes in the network, the required allocation would be:

```
ZPS_TclkDescriptorEntry sData[250];
```

The application can determine at any time whether this feature is enabled by reading the Boolean variable `bSetTclkFlashFeature`, which reads as TRUE if the feature is enabled and as FALSE if it is disabled.

When a new Trust Centre Link Key has been negotiated for a node, the stack on the Trust Centre notifies the application by means of a ZPS\_EVENT\_TC\_STATUS event. The application can discover the IEEE/MAC address of the corresponding node by calling **ZPS\_u64GetFlashMappedIeeeAddress\(\)** with the value of `u16ExtAddrLkup`from the key descriptor passed in the event.

Please note that when the key table is held in RAM, **ZPS\_u64NwkNibGetMappedIeeeAddr\(\)** would be called instead.

**Parent topic:**[ZPS\_vTcInitFlash](../topics/zps_vtcinitflash.md)

