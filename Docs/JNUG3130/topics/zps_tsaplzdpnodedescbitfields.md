# ZPS\_tsAplZdpNodeDescBitFields

The `ZPS_tsAplZdpNodeDescBitFields`structure is used by the `sBitFields`

element in the Node descriptor structure \(see above\), and is shown below:

```
typedef struct {
    unsigned eFrequencyBand : 5;
    unsigned eApsFlags : 3;
    unsigned eReserved : 3; /* reserved */
    unsigned bUserDescAvail : 1;
    unsigned bComplexDescAvail : 1;
    unsigned eLogicalType : 3;
}ZPS_tsAplZdpNodeDescBitFields;
```

where:

-   `eFrequencyBand`is a 5-bit value representing the IEEE 802.15.4 radio- frequency band used by the node:
    -   0: 868-MHz band
    -   2: 915-MHz band
    -   3: 2400-MHz band
-   `eApsFlags`is a 3-bit value containing flags that indicate the ZigBee APS capabilities of the node \(not currently supported and should be set to 0\).
-   `eReserved`is a 3-bit reserved value.
-   `bUserDescAvail`is a 1-bit value indicating whether a User descriptor is available for the node - 1 indicates available, 0 indicates unavailable.
-   `bComplexDescAvail`is a 1-bit value indicating whether a Complex descriptor is available for the node - 1 indicates available, 0 indicates unavailable.
-   `eLogicalType`is a 3-bit value indicating the ZigBee device of the node:
    -   0: Coordinator
    -   1: Router
    -   2: End Device

**Parent topic:**[ZPS\_tsAplZdpNodeDescriptor](../topics/zps_tsaplzdpnodedescriptor.md)

