# ZPS\_tsAplZdpMgmtNwkDiscReq

This structure is used by the function **ZPS\_eAplZdpMgmtNwkDiscRequest\(\)**. It represents a request to a remote node to discover any other wireless networks that are operating in the neighborhood.

The `ZPS_tsAplZdpMgmtNwkDiscReq`structure is detailed below.

```
typedef struct {
 uint32 u32ScanChannels;
 uint8 u8ScanDuration;
 uint8 u8StartIndex;
} ZPS_tsAplZdpMgmtNwkDiscReq;
```

where:

-   `u32ScanChannels`is a bitmask of the radio channels to scan \(‘1’ means scan, ‘0’ means do not scan\):
    -   Bits 0 to 26 respectively represent channels 0 to 26 \(only bits 11 to 26 are relevant to the 2400-MHz band\)
    -   Bits 27 to 31 are reserved
-   `u8ScanDuration`is a value in the range 0x00 to 0x0E that determines the time spent scanning each channel - this time is proportional to 2`u8ScanDuration`+1
-   `u8StartIndex`is the index of the first result from the results list to include in the response to this request

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

