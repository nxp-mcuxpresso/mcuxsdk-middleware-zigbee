# Attributes

The attributes of the ZigBee Base Device are contained in the structure `BDB_tsAttrib`, shown below:

```
typedefstruct
{
    uint16 u16bdbCommissioningGroupID;
    uint8 u8bdbCommissioningMode;
    BDB_teCommissioningStatusebdbCommissioningStatus;
    uint64 u64bdbJoiningNodeEui64;
    uint8 au8bdbJoiningNodeNewTCLinkKey[16];
    bool_tbbdbJoinUsesInstallCodeKey;
    const uint8 u8bdbNodeCommissioningCapability;
    bool_tbbdbNodeIsOnANetwork;
    uint8 u8bdbNodeJoinLinkKeyType;
    uint32 u32bdbPrimaryChannelSet;
    uint8 u8bdbScanDuration;
    uint32 u32bdbSecondaryChannelSet;
    uint8 u8bdbTCLinkKeyExchangeAttempts;
    uint8 u8bdbTCLinkKeyExchangeAttemptsMax;
    uint8 u8bdbTCLinkKeyExchangeMethod;
    uint8 u8bdbTrustCenterNodeJoinTimeout;
    bool_tbbdbTrustCenterRequireKeyExchange;
    bool_tbTLStealNotAllowed;
    bool_tbLeaveRequested;
}BDB_tsAttrib;

```
For information on compile-time options, refer to [Compile-time Options](compile-time_options_001.md#). The attributes are written to or read at run time through the above structure.
The ZigBee Base Device attribute values are initialized at compile time in the **bdb\_options.h** file using the macros listed in the table below. 

**Note:** Both `bTLStealNotAllowed` and `bLeaveRequested` are NXP proprietary variables and not ZigBee attributes.
**Table: ZBD Attributes and Initialization Macros**

|Attribute|Initialization Macro|
|-------|-----------|
`u16bdbCommissioningGroupID`|BDB\_COMMISSIONING\_GROUP\_ID
`u8bdbCommissioningMode`|BDB\_COMMISSIONING\_MODE
`ebdbCommissioningStatus`|BDB\_COMMISSIONING\_STATUS
`u64bdbJoiningNodeEui64`|BDB\_JOINING\_NODE\_EUI64
`au8bdbJoiningNodeNewTCLinkKey[16]`|-
`bbdbJoinUsesInstallCodeKey`|BDB\_JOIN\_USES\_INSTALL\_CODE\_KEY
`u8bdbNodeCommissioningCapability`|-
`bbdbNodeIsOnANetwork`|-
`u8bdbNodeJoinLinkKeyType`|BDB\_NODE\_JOIN\_LINK\_KEY\_TYPE
`u32bdbPrimaryChannelSet`|BDB\_PRIMARY\_CHANNEL\_SET
`u8bdbScanDuration`|BDB\_SCAN\_DURATION
`u32bdbSecondaryChannelSet`|BDB\_SECONDARY\_CHANNEL\_SET
`u8bdbTCLinkKeyExchangeAttempts`|BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS
`u8bdbTCLinkKeyExchangeAttemptsMax`|BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS\_MAX
`u8bdbTCLinkKeyExchangeMethod`|BDB\_TC\_LINK\_KEY\_EXCHANGE\_METHOD
`u8bdbTrustCenterNodeJoinTimeout`|BDB\_TRUST\_CENTER\_NODE\_JOIN\_TIMEOUT
`bbdbTrustCenterRequireKeyExchange`|BDB\_TRUST\_CENTER\_REQUIRE\_KEYEXCHANGE
`bTLStealNotAllowed`|-
`bLeaveRequested`|-

The attributes are individually described below. For further details, refer to the *ZigBee Base Device Behavior Specification \(13-0402-08\)*.

## u16bdbCommissioningGroupID 

This attribute can only be used on a Finding and Binding initiator endpoint. It contains the identifier of the group in which the initiator puts the target endpoints. If it is equal to 0xFFFF, individual \(rather than group\) bindings are created. The value of this attribute can be initialized at compile time using the macro BDB\_COMMISSIONING\_GROUP\_ID.

Use of this attribute requires Finding and Binding to be enabled in the `u8bdbCommissioningMode` attribute.

The Finding and Binding commissioning mode is described in [Finding and Binding](finding_and_binding.md#ID_0189A083-F683-4848-A875-19C22F73C47E).

## u8bdbCommissioningMode 

This attribute is a bitmap used to indicate which commissioning modes are enabled on an endpoint. Each bit corresponds to a commissioning mode and is set \(to ‘1’\) when the mode is enabled - this means that the node is able to implement this commissioning mode, if necessary. The value of this attribute can be initialized at compile time using the macro BDB\_COMMISSIONING\_MODE. The bitmap, along with the enumerations used to set the bits is illustrated in the table below.   

**Table: u8bdbCommissioningMode bitmap**
| Bit | Commissioning Mode    | Enumeration                              |
| --- | --------------------- | ---------------------------------------- |
| 0   | Touchlink             | BDB_COMMISSIONING_MODE_TOUCHLINK         |
| 1   | Network Steering      | BDB_COMMISSIONING_MODE_NWK_STEERING      |
| 2   | Network Formation     | BDB_COMMISSIONING_MODE_NWK_FORMATION     |
| 3   | Finding and Binding   | BDB_COMMISSIONING_MODE_FINDING_N_BINDING |
| 4-7 | Reserved (set to ‘0’) | \-                                       |

The commissioning modes are described in [Network commissioning](network_commissioning.md).

**Note:** The attribute is used on all node types. However, in order to enable a commissioning mode, it must be available on the node, as indicated through the attribute `u8bdbNodeCommissioningCapability`. The enabled commissioning modes are a subset of the commissioning capabilities of the node.

## ebdbCommissioningStatus

This attribute indicates the status of the commissioning process that is underway on an endpoint. The attribute takes one of the values defined in the `BDB_teCommissioningStatus` enumerations \(see [BDB_teCommissioningStatus](bdb_tecommissioningstatus.md#ID_4BA7B9DC-BAA0-4633-B8BC-AFFC42470FBD)\). The attribute is used on all node types. The value of this attribute is updated internally by the ZigBee Base Device implementation, but can be read by the application.

## u64bdbJoiningNodeEui64

This attribute contains the 64-bit IEEE/MAC address of a node that is in the process of joining a centralized security network. It is used on the network Coordinator only. The value of this attribute is updated internally by the ZigBee Base Device implementation.

## au8bdbJoiningNodeNewTCLinkKey

This attribute contains a new link key for use with a node that is joining the network but has not yet been granted full network membership. The value of this attribute is updated internally by the ZigBee Base Device implementation \(on a joining node and its parent\).

## bbdbJoinUsesInstallCodeKey 

This attribute indicates whether a pre-configured link key must be available for a node before it is allowed to join the network - this may be a pre-installed link key or may be derived from an install code. A value of TRUE means that a link key is required, while FALSE means that a link key is not required. It is used on the network Co-ordinator/Trust Centre only. The value of this attribute can be initialized at compile time using the macro BDB\_JOIN\_USES\_INSTALL\_CODE\_KEY. By default, the attribute should be set to FALSE. The attribute is not used by the ZigBee Base Device. If the attribute is set to TRUE, it is the responsibility of the application to handle this functionality directly and to set the required key \(see the attribute [u8bdbNodeJoinLinkKeyType](attributes.md/#u8bdbnodejoinlinkkeytype)\).

## u8bdbNodeCommissioningCapability 

This attribute is a bitmap indicating the commissioning capabilities of the node. Each bit corresponds to a commissioning capability and is set \(to ‘1’\) if the capability is present. The attribute is used on all node types. The application cannot write directly to these bits - they are set according to the options defined in the application makefile. The bitmap and the related makefile options are detailed in the Table below.

**Table: bdbCommissioningCapability Bitmap**

| Bit | Capability            | Makefile Options                                                                                                                                                                   |
| --- | --------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 0   | Network Steering      | Is set to ‘1’ if BDB_SUPPORT_NWK_STEERING is defined                                                                                                                               |
| 1   | Network Formation     | Is set to ‘1’ if BDB_SUPPORT_NWK_FORMATION is defined                                                                                                                              |
| 2   | Finding and Binding   | Is set to ‘1’ if either of the following is defined:<br>•  BDB_SUPPORT_FIND_AND_BIND_INITIATOR<br>•  BDB_SUPPORT_FIND_AND_BIND_TARGET                                              |
| 3   | Touchlink             | Is set to ‘1’ if any of the following is defined:<br>•  BDB_SUPPORT_TOUCHLINK_INITIATOR_END_DEVICE<br>•  BDB_SUPPORT_TOUCHLINK_INITIATOR_ROUTER<br>•  BDB_SUPPORT_TOUCHLINK_TARGET |
| 4-7 | Reserved (set to ‘0’) | \-                                                                                                                                                                                 |

The above commissioning modes are described in [Network commissioning](network_commissioning.md#).

**Note:** In order to use one of the available commissioning modes, the mode must also be enabled through the attribute `u8bdbCommissioningMode`. The enabled commissioning modes are a subset of the commissioning capabilities of the node.

## bbdbNodeIsOnANetwork

This attribute indicates whether the local node is a member of a network. A value of TRUE means that it is in a network \(but not necessarily bound to any remote nodes\), while FALSE means that it is not in a network. The attribute is used on all node types but the ZigBee Base Device does not maintain it. The application is responsible for persisting the attribute value and initializing the attribute following a power-cycle \(before any other ZigBee Base Device functions are called\).

## u8bdbNodeJoinLinkKeyType 

This attribute indicates the type of link key with which the node is able to decrypt the encrypted network key received over-air when the node joins a new network. The attribute is used by Router and End Device nodes. The attribute values and the corresponding link key types as well as the macros use to define the link keys are listed in the table below. <br>
**Table: bdbNodeJoinLinkKeyType Values and Macros**

| Value | Link Key Type                                | Link Key Definition Macro                      |
| ----- | -------------------------------------------- | ---------------------------------------------- |
| 0x00  | Default global trust Centre link key         | DEFAULT_GLOBAL_TRUST_CENTER_LINK_KEY           |
| 0x01  | Distributed security global link key         | DISTRIBUTED_SECURITY_GLOBAL_LINK_KEY           |
| 0x02  | Install code derived pre-configured link key | INSTALL_CODE_DERIVED_PRECONFIGURED_LINK \_ KEY |
| 0x03  | Touchlink pre-configured link key            | TOUCHLINK_PRECONFIGURED_LINK_KEY               |

## u32bdbPrimaryChannelSet 
This attribute specifies the primary \(first-choice\) set of 2.4 GHz radio channels that are used in channel scans. The attribute is a bitmap in which each bit corresponds to a channel and should be set to ‘1’ if the channel is to be included in a scan. The bit number corresponds directly to the channel number - for example, bit 11 corresponds to the 2.4 GHz channel 11 and bit 26 corresponds to channel 26. This attribute is used on all node types. The value of this attribute can be initialized at compile time using the macro BDB\_PRIMARY\_CHANNEL\_SET.

## u8bdbScanDuration 

This attribute determines the duration of a scan operation per 2.4 GHz radio channel. The actual scan duration is calculated from the attribute value as follows:

*aBaseSuperframeDuration x \(2bdbScanDuration + 1\)*

where aBaseSuperframeDuration is defined in the IEEE 802.15.4 specification.

The attribute is used on all node types. The value of this attribute is taken from the Scan Duration Time set in the ZPS Configuration Editor.

## u32bdbSecondaryChannelSet 

This attribute specifies the secondary \(second-choice\) set of 2.4 GHz radio channels that are used in channel scans. This channel set is used if the scan of primary channels is unsuccessful. The attribute is a bitmap in which each bit corresponds to a channel. In order to include the channel in a scan, set each bit to ‘1’. The bit number corresponds directly to the channel number - for example, bit 11 corresponds to the 2.4 GHz channel 11 and bit 26 corresponds to channel 26. If a scan of secondary channels is not required, the attribute should be set to zero. The attribute is used on all node types. The value of this attribute can be initialized at compile time using the macro BDB\_SECONDARY\_CHANNEL\_SET.

## u8bdbTCLinkKeyExchangeAttempts 

This attribute indicates the number of attempts to request a new link key that were made when the node joined the network. The attribute is used on Router and End Device nodes. The value of this attribute can be initialized at compile time using the macro BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS.

## u8bdbTCLinkKeyExchangeAttemptsMax 

This attribute specifies the maximum number of key establishment attempts that are made before key establishment is abandoned when the node joins a new network. The attribute is used on Router and End Device nodes. The value of this attribute can initialized at compile time using the macro BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS\_MAX.

## u8bdbTCLinkKeyExchangeMethod 

This attribute specifies the method that was used to obtain a new link key when the node joined the network. The attribute values and corresponding methods are listed in the table below. This attribute is used on Router and End Device nodes.<br>   
**Table: bdbTCLinkKeyExchangeMethod Values**
| Value | Key Exchange Method                   |
| ----- | ------------------------------------- |
| 0x00  | APS Request Key                       |
| 0x01  | Certificate Based Key Exchange (CBKE) |

The value of this attribute can be initialized at compile time using the macro BDB\_TC\_LINK\_KEY\_EXCHANGE\_METHOD. It should be initialized to 0x00 \(APS Request Key\).

## u8bdbTrustCenterNodeJoinTimeout 

This attribute specifies a timeout \(in seconds\) for the Trust Centre to delete the Trust Centre-generated link key for a newly joined node when key establishment with the node was unsuccessful. The attribute is used on the network Co-ordinator/Trust Centre only. The value of this attribute can be initialized at compile time using the macro BDB\_TRUST\_CENTER\_NODE\_JOIN\_TIMEOUT.

## bbdbTrustCenterRequireKeyExchange 
This attribute specifies whether the Trust Centre requires a joining node to replace its initial link key with a new link key generated by the Trust Centre. A value of TRUE means that the joining node successfully completes the link key exchange procedure and failure to do so results in the node being removed from the network. A value of FALSE means that the joining node is allowed to remain in the network even if it does not successfully complete the link key exchange procedure. The attribute is used on the network Co-ordinator/Trust Centre only. The value of this attribute is initialized at compile time using the macro BDB\_TRUST\_CENTER\_REQUIRE\_KEYEXCHANGE. It should be initialized according to the Trust Centre policy that is implemented in the network - by default, set it to FALSE for backward compatibility.

## bTLStealNotAllowed 

This attribute is an NXP proprietary flag which the application can set to prevent Touchlink commissioning commands from another node in a different network from 'stealing' the local node. Clearing the flag allows the node to be stolen, in which case it leaves the current network and either joins the other network or forms a new distributed network, as instructed by Touchlink initiator.

## bLeaveRequested 

This attribute is an NXP proprietary flag which the application should only read and not write to. If Touchlink commissioning operations cause the ZigBee Base Device to initiate a network leave, then this flag is set by the Base Device. When a ZPS\_EVENT\_NWK\_LEAVE\_CONFIRM stack event is generated, the application should read this flag. If it reads as TRUE, the application should not handle the event \(since the ZigBee Base Device handles it\).

**Parent topic:**[Attributes and Constants](../topics/attributes_and_constants.md)

