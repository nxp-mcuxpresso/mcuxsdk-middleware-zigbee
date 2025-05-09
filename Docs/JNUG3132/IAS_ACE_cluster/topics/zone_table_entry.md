# Zone Table Entry

The following structure contains a Zone table entry, used to hold the enrollment details of a zone.

```
typedef struct
{
    zuint8              u8ZoneID;
    zbmap16             u16ZoneType;
    zieeeaddress        u64IeeeAddress;
} tsCLD_IASACE_ZoneTable;

```

where:

-   `u8ZoneID` is the identifier of the zone

-   `u16ZoneType` is a value indicating the type of zone \(for the possible values, refer to the description of the attribute `e``16ZoneType` of the IAS Zone cluster in [Section 37.2](../../IAS_Zone_cluster/topics/ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

-   `u64IeeeAddress` is the IEEE/MAC address of the device which hosts the zone


**Parent topic:**[Structures](../../IAS_ACE_cluster/topics/structures.md)

