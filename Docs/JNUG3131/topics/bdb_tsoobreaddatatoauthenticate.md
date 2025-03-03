# BDB\_tsOobReadDataToAuthenticate

The following structure contains data values that are read from the local node during out-of-band commissioning of the node.

```
typedef struct{
uint8 au8Key[16]__attribute__((aligned(16)));
uint64 u64TcAddress;
uint64 u64PanId;
uint16 u16ShortPanId;
uint8 u8ActiveKeySeq;
uint8 u8Channel;
}BDB_tsOobReadDataToAuthenticate;

```

where:

-   `au8Key[16]__attribute__((aligned (16)))` is an array containing the current network key, with one byte per array element.
-   `u64TcAddress` is the IEEE/MAC address of the Trust Centre of the network to which the node is being commissioned.
-   `u64PanId` is the Extended PAN ID of the network to which the node is being commissioned.
-   `u16ShortPanId` is the PAN ID of the network to which the node is being commissioned.
-   `u8ActiveKeySeq` is the key sequence number of the currently active network key.
-   `u8Channel` is the radio channel number on which the network operates.

**Parent topic:**[Structures](../topics/structures.md)

