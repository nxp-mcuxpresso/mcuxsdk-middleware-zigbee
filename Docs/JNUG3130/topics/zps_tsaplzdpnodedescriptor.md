# ZPS\_tsAplZdpNodeDescriptor

The ZDP Node descriptor structure `ZPS_tsAplZdpNodeDescriptor`is shown below.

```
typedef struct {
    union
    {
        ZPS_tsAplZdpNodeDescBitFields sBitFields;
        uint16 u16Value;
    } uBitUnion;
    uint8 u8MacFlags;
    uint16 u16ManufacturerCode;
    uint8 u8MaxBufferSize;
    uint16 u16MaxRxSize;
    uint16 u16ServerMask;
    uint16 u16MaxTxSize;
    uint8 u8DescriptorCapability;
} ZPS_tsAplZdpNodeDescriptor;
```

where:

-   `sBitFields`is a structure of the type `ZPS_tsAplZdpNodeDescBitFields`

\(described below\) containing various items of information about the node.

-   `u16Value`is used for the union and should be set to 0x0000.
-   `eMacFlags`contains 8 bits \(bits 0-7\) indicating the node capabilities, as required by the IEEE 802.15.4 MAC sub-layer. These node capability flags are described in Table 8.
-   `u16ManufacturerCode`contains 16 bits \(bits 0-15\) indicating the manufacturer code for the node, where this code is allocated to the manufacturer by the ZigBee Alliance.
-   `u8MaxBufferSize`is the maximum size, in bytes, of an NPDU \(Network Protocol Data Unit\).
-   `u16MaxRxSize`is the maximum size, in bytes, of an APDU \(Application Protocol Data Unit\). This value can be greater than the value of `u8MaxBufferSize`, due to the fragmentation of an APDU into NPDUs.
-   `u16ServerMask`contains 8 bits \(bits 0-7\) indicating the server status of the node. This server mask is detailed in Table 18 on page 389.
-   `u16MaxTxSize`is the maximum size, in bytes, of the ASDU \(Application Sub- layer Data Unit\) in which a message can be sent \(the message may actually be transmitted in smaller fragments\)
-   `u8DescriptorCapability`contains 8 bits \(bits 0-7\) indicating the properties of the node that can be used by other nodes in network discovery, as indicated in the table below.

|**Bit**|**Description**|
|--|--|
|0|Set to 1 if Extended Active Endpoint List is available on the node, 0 otherwise.|
|1|Set to 1 if Extended Simple Descriptor List is available on the node, 0 otherwise.|
|2-7|Reserved|


```{include} ../topics/zps_tsaplzdpnodedescbitfields.md
:heading-offset: 4
```

**Parent topic:**[Descriptor structures](../topics/descriptor_structures_001.md)

