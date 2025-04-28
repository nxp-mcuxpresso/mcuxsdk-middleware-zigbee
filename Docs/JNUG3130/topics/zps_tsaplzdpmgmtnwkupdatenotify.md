# ZPS\_tsAplZdpMgmtNwkUpdateNotify

This structure is used to store Mgmt\_NWK\_Update\_notify message data - a notification which can be sent in response to a call to the function **ZPS\_eAplZdpMgmtNwkUpdateRequest\(\)**. This notification reports the results of an energy scan on the wireless network radio channels.

The `ZPS_tsAplZdpMgmtNwkUpdateNotify`structure is detailed below.

Sample Codeblock:

```
typedef struct {
     uint8 u8Status;
     uint32 u32ScannedChannels;
     uint16 u16TotalTransmissions;
    uint16 u16TransmissionFailures;
    uint8 u8ScannedChannelListCount;
    /* Rest of the message is variable Length */
    uint8* u8EnergyValuesList;
} ZPS_tsAplZdpMgmtNwkUpdateNotify;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpMgmtNwkUpdateRequest\(\)**
-   `u32ScannedChannels`is a bitmask of the set of scanned radio channels \(‘1’ means scanned, ‘0’ means not scanned\):
    -   Bits 0 to 26 respectively represent channels 0 to 26 \(only bits 11 to 26 are relevant to the 2400-MHz band\)
    -   Bits 27 to 31 are reserved
-   `u16TotalTransmissions`is the total number of transmissions \(from other networks\) detected during the scan
-   `u16TransmissionFailures`is the number of failed transmissions detected during the scan
-   `u8ScannedChannelListCount`is the number of energy-level measurements \(one per scanned channel\) reported in this notification \(through `u8EnergyValuesList`\)
-   `u8EnergyValuesList`is a pointer to the first in the set of reported energy-level measurements \(the value 0xFF indicates there is too much interference on the channel\)

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

