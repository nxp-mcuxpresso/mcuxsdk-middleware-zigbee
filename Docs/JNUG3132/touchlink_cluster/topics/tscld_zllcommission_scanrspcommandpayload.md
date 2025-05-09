# tsCLD\_ZllCommission\_ScanRspCommandPayload

This structure is used to hold the payload data for a Touchlink Scan Response command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8RSSICorrection;
    uint8   u8ZigbeeInfo;
    uint8   u8ZllInfo;
    uint16  u16KeyMask;
    uint32  u32ResponseId;
    uint64  u64ExtPanId;
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint8   u8NumberSubDevices;
    uint8   u8TotalGroupIds;
    uint8   u8Endpoint;
    uint16  u16ProfileId;
    uint16  u16DeviceId;
    uint8   u8Version;
    uint8   u8GroupIdCount;
} tsCLD_ZllCommission_ScanRspCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the response, which must take the same value as the identifier in the corresponding request.

-   `u8RSSICorrection` is the 8-bit RSSI correction offset for the node, in the range 0x00 to 0x20.

-   `u8ZigbeeInfo` is an 8-bit field containing the following ZigBee-related information:

    -   Bits 1-0: Node type \(00 - Co-ordinator, 01 - Router, 10 - End Device\)

    -   Bit 2: Rx on when idle \(1 - On, 0 - Off\)

    -   Bits 7-3: Reserved

-   `u8ZllInfo` is an 8-bit field containing the following information:

    -   Bit 0: Factory new \(1 - Yes, 0 - No\)

    -   Bit 1: Address assignment capability \(1 - Yes, 0 - No\)

    -   Bits 3-2: Reserved

    -   Bit 4: Touchlink initiator \(1 - Yes, 0 - No\)

    -   Bit 5: Touchlink priority request \(1 - Yes, 0 - No\)

    -   Bits 7-6: Reserved

-   `u16KeyMask` is a 16-bit bitmap indicating which link key is installed on the node - only one bit should be set to ‘1’, corresponding to the key that is in use. The possible values and keys are:

    -   0x0001 \(bit 0 set\): Development key \(defined by developer for use during application development\)

    -   0x0010 \(bit 4 set\): Master key \(obtained from the ZigBee Alliance after successful certification and agreement with the terms of the ‘ZLL Security Key Licence and Confidentialty Agreement’\)

    -   0x8000 \(bit 15 set\): Certification key \(defined in the ZLL Specification for use during development and during certification at test houses\)

-   `u``32ResponseId` is a 32-bit random identifier for the response, used during network key transfer.

-   `u64ExtPanId` is the 64-bit Extended PAN ID of a network to which the node already belongs, if any \(a zero value indicates no network membership\).

-   `u8NwkUpdateId` is the current value of the Network Update Identifier on the node \(see [Section 44.4.3](updating_network_settings.md#id_e5dc05bb-5560-4583-b109-fde47217dfe7)\).

-   `u8LogicalChannel` is the number of the IEEE 802.15.4 radio channel used by a network to which the node already belongs, if any \(a zero value indicates no network membership and therefore that no particular channel is used\).

-   `u16PanId` is the 16-bit PAN ID of a network to which the node already belongs, if any \(a zero value indicates no network membership\).

-   `u16NwkAddr` is the 16-bit network address currently assigned to the node \(the value 0xFFFF indicates that the node is ‘factory new’ and has no assigned network address\).

-   `u8NumberSubDevices` is the number of ZigBee devices on the node.

-   `u8TotalGroupIds` is the total number of groups \(of lights\) supported on the node \(across all devices\).

-   `u8Endpoint` is number of the endpoint \(in the range 1-240\) on which the ZigBee device is resident \(this field is only used when there is only one ZigBee device on the node\).

-   `u16ProfileId` is the 16-bit identifier of the ZigBee application profile that is supported by the device \(this field is only used when there is only one ZigBee device on the node\).

-   `u16DeviceId` is the 16-bit Device Identifier supported by the device \(this field is only used when there is only one ZigBee device on the node\).

-   `u8Version` is an 8-bit version number for the device - the four least significant bits are from the Application Device Version field of the appropriate Simple Descriptor and the four most significant bits are zero \(this field is only used when there is only one ZigBee device on the node\).

-   `u8GroupIdCount` is the number of groups \(of lights\) supported by the device \(this field is only used when there is only one ZigBee device on the node\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

