# ZPS\_tsNwkNlmeCfmEdScan

This structure is used by the structure `ZPS_tsAfNwkEdScanConfEvent`, which is created as part of the ZPS\_EVENT\_NWK\_ED\_SCAN event which reports the results of an ‘energy detect’ scan in the 2.4-GHz radio band.

The `ZPS_tsNwkNlmeCfmEdScant`structure is detailed below.

```
typedef struct
{
    uint8 u8Status;
    uint8 u8ResultListSize;
    uint8 au8EnergyDetect[ZPS_NWK_MAX_ED_RESULTS];
} ZPS_tsNwkNlmeCfmEdScan;
```

where

-   `u8Status`is one of the status codes from the lower stack layers, detailed in [Section 11.2](return_status_codes.md).
-   `u8ResultListSize`is the number of entries in the results list \(see below\).
-   `au8EnergyDetect[]`is an array containing the list of results of the energy scan \(8-bit values representing the detected energy levels in the channels\). There is one array element for each channel scanned, where element 0 is for the first channel scanned, element 1 is for the second channel scanned, etc.

**Parent topic:**[Other structures](../topics/other_structures.md)

