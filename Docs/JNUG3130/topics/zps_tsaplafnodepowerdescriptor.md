# ZPS\_tsAplAfNodePowerDescriptor

The AF Node Power descriptor structure `ZPS_tsAplAfNodePowerDescriptor`is shown below.

```
typedef struct {
    uint32 eCurrentPowerMode         : 4;
    uint32 eAvailablePowerSources    : 4;
    uint32 eCurrentPowerSource       : 4;
    uint32 eCurrentPowerSourceLevel  : 4;
} ZPS_tsAplAfNodePowerDescriptor;
```

where:

-   `eCurrentPowerMode`contains 4 bits \(bits 0-3\) indicating the power mode currently used by the node, as follows:
    -   0000: Receiver configured according to “Receiver on when idle” MAC flag in the Node Descriptor \(see [Section 8.2.1.1](zps_tsaplafnodedescriptor.md)\)
    -   0001: Receiver switched on periodically
    -   0010: Receiver switched on when stimulated, for example, by pressing a button
    -   All other values are reserved
-   `eAvailablePowerSources`contains 4 bits \(bits 0-3\) indicating the available power sources for the node, as follows \(a bit is set to 1 if the corresponding power source is available\):
    -   Bit 0: Permanent mains supply
    -   Bit 1: Rechargeable battery
    -   Bit 2: Disposable battery
    -   Bit 4: Reserved
-   `eCurrentPowerSource`contains 4 bits \(bits 0-3\) indicating the current power source for the node, as detailed for the element above \(the bit corresponding to the current power source is set to 1, all other bits are set to 0\).
-   `eCurrentPowerSourceLevel`contains 4 bits \(bit 0-3\) indicating the current level of charge of the node’s power source \(mainly useful for batteries\), as follows:
    -   0000: Critically low
    -   0100: Approximately 33%
    -   1000: Approximately 66%
    -   1100: Approximately 100% \(near fully charged\)

**Parent topic:**[Descriptor structures](../topics/descriptor_structures.md)

