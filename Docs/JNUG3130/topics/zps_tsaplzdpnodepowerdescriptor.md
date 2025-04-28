# ZPS\_tsAplZdpNodePowerDescriptor

The ZDP Node Power descriptor structure `ZPS_tsAplZdpNodePowerDescriptor`is shown below.

```
typedef struct {
    union
    {
            ZPS_tsAplZdpPowerDescBitFields sBitFields;
            uint16 u16Value;
    }uBitUnion;
} ZPS_tsAplZdpNodePowerDescriptor;
```

where:

-   `sBitFields`is a structure of type `ZPS_tsAplZdpPowerDescBitFields`\(described below\) containing various items of information about the node’s power.
-   `u16value`is used for the union and should be set to 0x0000.


```{include} ../topics/zps_tsaplzdppowerdescbitfields.md
:heading-offset: 4
```

**Parent topic:**[Descriptor structures](../topics/descriptor_structures_001.md)

