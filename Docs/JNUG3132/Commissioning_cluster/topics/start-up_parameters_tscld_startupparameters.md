# Start-up Parameters \(tsCLD\_StartupParameters\)

The `tsCLD_StartupParameters` structure below contains the attributes of the Start-up Parameters attribute set:

```
typedef struct
{
#ifdef     CLD_COMMISSIONING_ATTR_SHORT_ADDRESS
    uint16              u16ShortAddress;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_EXTENED_PAN_ID
    zieeeaddress        u64ExtPanId;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_PAN_ID
    uint16              u16PANId;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_CHANNEL_MASK
    zbmap32             u32ChannelMask;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_PROTOCOL_VERSION
    uint8               u8ProtocolVersion;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_STACK_PROFILE
    uint8               u8StackProfile;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_START_UP_CONTROL
    zenum8               e8StartUpControl;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_TC_ADDR
    zieeeaddress         u64TcAddr;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_TC_MASTER_KEY
    tsZCL_Key            sTcMasterKey;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_NWK_KEY
    tsZCL_Key           sNwkKey;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_USE_INSECURE_JOIN
    bool_t              bUseInsecureJoin;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_PRE_CONFIG_LINK_KEY
    tsZCL_Key           sPreConfigLinkKey;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_NWK_KEY_SEQ_NO
    uint8               u8NwkKeySeqNo;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_NWK_KEY_TYPE
    zenum8              e8NwkKeyType;
#endif
#ifdef     CLD_COMMISSIONING_ATTR_NWK_MANAGER_ADDR
    uint16              u16NwkManagerAddr;
#endif
} tsCLD_StartupParameters;

```

where:

-   `u``16ShortAddress` is the intended 16-bit network address of the device \(which will be used provided that the address is not to be obtained from the parent - that is, on the Co-ordinator or on other ZigBee PRO devices for which `e8StartUpControl` is set to 0x00\).

-   `u64ExtPanId` is the 64-bit Extended PAN ID of the network which the device should join \(the special value of 0xFFFFFFFF can be used to specify no particular network\).

-   `u16PANId` is the 16-bit PAN ID of the network which the device should join \(which will be used provided that the PAN ID is not to be obtained from the parent - that is, on the Co-ordinator or on other ZigBee PRO devices for which `e8StartUpControl` is set to 0x00\).

-   `u32ChannelMask` is a 32-bit bitmap representing an IEEE 802.15.4 channel mask which indicates the set of radio channels that the device should scan as part of the network join or formation process.

-   `u8ProtocolVersion` is used to indicate the ZigBee protocol version that the device is to support \(only needed if the device potentially supports multiple versions\).

-   `u8StackProfile` is used to indicate the stack profile to be implemented on the device - the possible values are 0x01 for ZigBee Stack profile and 0x02 for ZigBee PRO Stack profile.

-   `e8StartUpControl` is an enumeration which is used to indicate the start-up mode of the device \(e.g. device should form a network with the specified Extended PAN ID\) and therefore determines how certain other attributes will be used. For further information on how this attribute is used, refer to the ZCL Specification.

-   `u64TcAddr` is the 64-bit IEEE/MAC address of the Trust Centre node for the network with the specified Extended PAN ID \(this is needed if security is to be implemented\).

-   `sTcMasterKey` is the master key to be used during key establishment with the specified Trust Centre \(this is needed if security is to be implemented\). The default is a 128-bit zero value indicating that the key is unspecified.

-   `sNwkKey` is the network key to be used when communicating within the network with the specified Extended PAN ID \(this is needed if security is to be implemented\). The default is a 128-bit zero value indicating that the key is unspecified.

-   `bUseInsecureJoin` is a Boolean flag which, when set to TRUE, allows an unsecured join as a fall-back \(even if security is enabled\).

-   `sPreConfigLinkKey` is the pre-configured link key between the device and the Trust Centre \(this is needed if security is to be implemented\). The default is a 128-bit zero value indicating that the key is unspecified.

-   `u8NwkKeySeqNo` is the 8-bit sequence number for the network key. The default value is 0x00.

-   `e8NwkKeyType` is the type of the network key. The default value is 0x01 when `u8StackProfile` is 0x01 and 0x05 when `u8StackProfile` is 0x02.

-   `u16NwkManagerAddr` is the 16-bit network address of the Network Manager. The default value is 0x0000, indicating that the Network Manager is the ZigBee Co-ordinator.


**Parent topic:**[Commissioning Cluster structure and attributes](../../Commissioning_cluster/topics/commissioning_cluster_structure_and_attributes.md)

