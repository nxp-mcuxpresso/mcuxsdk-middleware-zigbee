# BDB\_tsOobWriteDataToCommission

The following structure contains the data values used to initialize a node at the start of out-of-band commissioning of the node.

```
typedef struct{
uint64 u64PanId;
uint64 u64TrustCenterAddress;
uint8* pu8NwkKey;
uint8* pu8InstallCode;
uint16 u16PanId;
uint16 u16ShortAddress;
bool_t bRejoin;
uint8 u8ActiveKeySqNum;
uint8 u8DeviceType;
uint8 u8RxOnWhenIdle;
uint8 u8Channel;
uint8 u8NwkUpdateId;
}BDB_tsOobWriteDataToCommission;

```

where:

-   `u64PanId` is the Extended PAN ID of the network to be joined.
-   `u64TrustCenterAddress` is the IEEE/MAC address of the Trust Centre in the centralized network to be joined.
-   `pu8NwkKey` is a pointer to the network key.
-   `pu8InstallCode` is a pointer to an initial link key derived from an install code \(see Section 2.3.1\).
-   `u16PanId` is the PAN ID of the network to be joined.
-   `u16ShortAddress` is the network address assigned to the node.
-   `bRejoin` is the ‘rejoin flag’ which indicates whether the node should attempt to rejoin the network if it leaves \(TRUE: rejoin, FALSE: do not rejoin\).
-   `u8ActiveKeySqNum` is the key sequence number associated with the active network key.
-   `u8DeviceType` is a value indicating the type of ZigBee node:

    -   0: Coordinator
    -   1: Router
    -   2: End Device
    All other values are reserved.

-   `u8RxOnWhenIdle` is a value indicating whether the receiver of the node is enabled during idle periods:

    -   0: Receiver off when idle \(sleeping device\)
    -   1: Receiver on when idle \(non-sleeping device\)
    All other values are reserved.

-   `u8Channel` is the radio channel number on which the network operates.
-   `u8NwkUpdateId` is a unique byte value which is incremented when the network parameters are updated \(and is therefore used to determine whether a receiving node has missed an update\).

**Parent topic:**[Structures](../topics/structures.md)

