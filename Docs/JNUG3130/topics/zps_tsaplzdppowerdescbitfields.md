# ZPS\_tsAplZdpPowerDescBitFields

The `ZPS_tsAplZdpPowerDescBitFields`structure is used by the `sBitFields`

element in the Node Power descriptor structure \(see above\), and is shown below:

```
typedef struct {
    unsigned eCurrentPowerSourceLevel : 4;
    unsigned eCurrentPowerSource : 4;
    unsigned eAvailablePowerSource : 4;
    unsigned eCurrentPowerMode : 4;
}ZPS_tsAplZdpPowerDescBitFields;
```

where:

-   `eCurrentPowerSourceLevel`is a 4-bit value roughly indicating the level of charge of the node’s power source \(mainly useful for batteries\), as follows:
    -   0000: Critically low
    -   0100: Approximately 33%
    -   1000: Approximately 66%
    -   1100: Approximately 100% \(near fully charged\)
-   `eCurrentPowerSource`is a 4-bit value indicating the current power source for the node, as detailed below \(the bit corresponding to the current power source is set to 1, all other bits are set to 0\):
    -   Bit 0: Permanent mains supply
    -   Bit 1: Rechargeable battery
    -   Bit 2: Disposable battery
    -   Bit 4: Reserved
-   `eAvailablePowerSource`is a 4-bit value indicating the available power sources for the node, as detailed above \(a bit is set to 1 if the corresponding power source is available\).
-   `eCurrentPowerMode`is a 4-bit value indicating the power mode currently used by the node, as follows:
    -   0000: Receiver synchronized with the “receiver on when idle” subfield of the Node descriptor
    -   0001: Receiver switched on periodically, as defined by the Node Power descriptor
    -   0010: Receiver switched on when stimulated, for example, by pressing a button
    -   All other values are reserved.

**Parent topic:**[ZPS\_tsAplZdpNodePowerDescriptor](../topics/zps_tsaplzdpnodepowerdescriptor.md)

