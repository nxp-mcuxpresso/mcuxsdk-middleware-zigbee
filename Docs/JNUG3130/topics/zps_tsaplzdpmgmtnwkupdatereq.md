# ZPS\_tsAplZdpMgmtNwkUpdateReq

This structure is used by the function **ZPS\_eAplZdpMgmtNwkUpdateRequest\(\)**. It requests an update of network parameters related to radio communication and may optionally initiate an energy scan in the 2400-MHz band.

The `ZPS_tsAplZdpMgmtNwkUpdateReq`structure is detailed below.

`typedef struct {`

`uint32 u32ScanChannels; uint8 u8ScanDuration; uint8 u8ScanCount; uint8 u8NwkUpdateId;`

`uint16 u16NwkManagerAddr;`

`} ZPS_tsAplZdpMgmtNwkUpdateReq;`

where:

-   `u32ScanChannels`is a bitmask of the radio channels to be scanned \(‘1’ means scan, ‘0’ means do not scan\):
    -   Bits 0 to 26 respectively represent channels 0 to 26 \(only bits 11 to 26 are relevant to the 2400-MHz band\)
    -   Bits 27 to 31 are reserved
-   `u8ScanDuration`is a key value used to determine the action to be taken, as follows:
    -   0x00-0x05: Indicates that an energy scan is required and determines the time to be spent scanning each channel - this time is proportional to 2`u8ScanDuration`+1. The set of channels to scan is specified through

`u32ScanChannels`and the maximum number of scans is equal to the value of `u8ScanCount`. Valid for unicasts only

-   0x06-0xFD: Reserved
-   0xFE: Indicates that radio channel is to be changed to single channel specified through `u32ScanChannels`and that network manager address to be set to that specified through `u16NwkManagerAddr`. Valid for broadcasts only
-   0xFF: Indicates that stored radio channel mask to be updated with that specified through `u32ScanChannels`\(but scan not required\). Valid for broadcasts only.

-   `u8ScanCount`is the number of energy scans to be conducted and reported. Valid only if a scan has been enabled through `u8ScanDuration`\(0x00-0x05\)
-   `u8NwkUpdateId`is a value set by the Network Channel Manager before the request is sent. Valid only if `u8ScanDuration`set to 0xFE or 0xFF
-   `u16NwkManagerAddr`is the 16-bit network address of the Network Manager \(node nominated to manage radio-band operation of network\). Valid only if `u8ScanDuration`set to 0xFF

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

