# ZPS\_tsAfDataIndEvent

This structure is used in the ZPS\_EVENT\_APS\_DATA\_INDICATION event, which indicates the arrival of data on the local node.

The `ZPS_tsAfDataIndEvent`structure is detailed below.

```
typedef struct
{
uint8              u8DstAddrMode;
ZPS_tuAddress      uDstAddress;
uint8              u8DstEndpoint;
uint8              u8SrcAddrMode;
ZPS_tuAddress      uSrcAddress;
uint8              u8SrcEndpoint;
uint16             u16ProfileId;
uint16             u16ClusterId;
PDUM_thAPduInstance hAPduInst;
uint8              eStatus;
uint8              eSecurityStatus;
uint8              u8LinkQuality;
uint32             u32RxTime;
} ZPS_tsAfDataIndEvent;
```

where:

-   `u8DstAddrMode`indicates the type of destination address specified through the element `uDstAddress`\(see the [Table](zps_tsafdataindevent.md#TABLE_A30EAAD5-7B0D-42FD-BADD-CCCA93492DCA) below.\)
-   `uDstAddress`is the address of the destination node for the data packet \(the type of address is specified using the element `u8DstAddrMode`above\).
-   `u8DstEndpoint`is the number of the destination endpoint \(in range 0-240\).
-   `u8SrcAddrMode`indicates the type of source address specified through the element `uSrcAddress`\(below\) - this can be a 64-bit MAC/IEEE address or a 16-bit network address.
-   `uSrcAddress`is the address of the source node for the data packet \(the type of address is specified using the element `u8SrcAddrMode`above\).
-   `u8SrcEndpoint`is the number of the source endpoint \(in range 1-240\).
-   `u16ProfileId`is the identifier of the ZigBee device profile of the device which can interpret the data.
-   `u16ClusterId`is the identifier of the cluster \(which belongs to the device profile specified in `u16ProfileId`\) which is capable of interpreting the data.
-   `hAPduInst`is the handle of the APDU which contains the data.
-   `eStatus`is one of the status codes from the NWK layer or MAC layer, detailed in [Section 11.2.3](nwk_codes.md) and [Section 11.2.4](mac_codes.md).
-   `eSecurityStatus`indicates the type of security with which the packet was sent. It can be: unsecured \(0xAF\), secured with network key \(0xAC\), or secured with link key \(0xAB\).
-   `u8LinkQuality`is a measure of the signal strength of the radio link over which the data packet was sent \(for the last hop\).
-   `u32RxTime`is reserved for future use.

**Addressing modes**

|**u8DstAddrMode**|**Code**|**Description**|
|-----------------|--------|---------------|
|0x00|ZPS\_E\_ADDR\_MODE\_BOUND|Bound endpoint|
|0x01|ZPS\_E\_ADDR\_MODE\_GROUP|16-bit Group address|
|0x02|ZPS\_E\_ADDR\_MODE\_SHORT|16-bit Network \(Short\) address|
|0x03|ZPS\_E\_ADDR\_MODE\_IEEE|64-bit IEEE/MAC address|

**Parent topic:**[Event structures](../topics/event_structures.md)

