# ZPS\_tsAplAfNodeDescriptor

The AF Node descriptor structure `ZPS_tsAplAfNodeDescriptor`is shown below.

```
typedef struct {
    uint32 :                      8;/* padding */
    uint32 eLogicalType :         3;
    uint32 bComplexDescAvail :    1;
    uint32 bUserDescAvail :       1;
    uint32 eReserved :            3; /* reserved */
    uint32 eFrequencyBand :       5;
    uint32 eApsFlags :            3;
    uint32 u8MacFlags :           8;
    uint16 u16ManufacturerCode;
    uint8 u8MaxBufferSize;
    uint16 u16MaxRxSize;
    uint16 u16ServerMask;
    uint16 u16MaxTxSize;
    uint8 u8DescriptorCapability;
} ZPS_tsAplAfNodeDescriptor;
```

where:

-   `eLogicalType`contains 3 bits \(bits 0-2\) indicating the ZigBee device type of the node, as follows:
    -   000: Coordinator
    -   001: Router
    -   010: End Device
-   `bComplexDescAvail`is set to 1 if there is a Complex descriptor available for node.
-   `bUserDescAvail`is set to 1 if there is a User descriptor available for node.
-   `eReserved`is reserved.
-   `eFrequencyBand`contains 5 bits detailing the frequency bands supported by the node, as follows \(a bit is set to 1 if the corresponding band is supported\):
    -   Bit 0: 868-868.6 MHz
    -   Bit 2: 902-928 MHz
    -   Bit 3: 2400-2483.5 MHz
    -   Bits 1 and 4 are reserved
-   `eApsFlags`is not currently supported and set to zero.
-   `eMacFlags`contains 8 bits \(bits 0-7\) indicating the node capabilities, as required by the IEEE 802.15.4 MAC sub-layer. These node capability flags are described in the table: [Table](zps_tsafnwkjoinindevent.md#TABLE_026A2BDC-B736-4A72-8700-BD9FF0F39F3E).
-   `u16ManufacturerCode`contains 16 bits \(bits 0-15\) indicating the manufacturer code for the node, where this code is allocated to the manufacturer by the ZigBee Alliance.
-   `u8MaxBufferSize`is the maximum size, in bytes, of an NPDU \(Network Protocol Data Unit\).
-   `u16MaxRxSize`is the maximum size, in bytes, of an APDU \(Application Protocol Data Unit\). This value can be greater than the value of `u8MaxBufferSize`, due to the fragmentation of an APDU into NPDUs.
-   `u16ServerMask`contains 8 bits \(bits 0-7\) indicating the server status of the node. This server mask is detailed in the table: [Table](zps_tsaplzdpsystemserverdiscoveryreq.md#TABLE_513DD1A6-40B0-4762-A264-9910574C47C6).
-   `u16MaxTxSize`is the maximum size, in bytes, of the ASDU \(Application Sub-layer Data Unit\) in which a message can be sent \(the message may actually be transmitted in smaller fragments\)
-   `u8DescriptorCapability`contains 8 bits \(bits 0-7\) indicating the properties of the node that can be used by other nodes in network discovery, as follows:

**Bit description of u8DescriptorCapability**

|**Bit**|**Description**|
|-------|---------------|
|0|Set to 1 if Extended Active Endpoint List is available on the node, 0 otherwise.|
|1|Set to 1 if Extended Simple Descriptor List is available on the node, 0 otherwise.|
|2-7|Reserved|

**Parent topic:**[Descriptor structures](../topics/descriptor_structures.md)

