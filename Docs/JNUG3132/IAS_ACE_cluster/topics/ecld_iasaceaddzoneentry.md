# eCLD\_IASACEAddZoneEntry

```
teZCL_CommandStatus eCLD_IASACEAddZoneEntry(
    uint8 u8SourceEndPointId,
    uint16 u16ZoneType,
    uint64 u64IeeeAddress,
    uint8 *pu8ZoneID);

```

## Description 

This function can be used on an IAS ACE cluster server to create an entry in the local Zone table - that is, to add the details of a zone to the table after receiving a Zone Enrollment Request \(and before sending a Zone Enrollment Response\).

The details of the zone are provided in the function parameters. The function checks that the supplied pointer to the Zone ID is not NULL and that the supplied IEEE address is valid. The function can then add the zone details to the Zone table, provided that there is a free entry in the table.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *u16ZoneType*: Value indicating the type of zone to be added to the table \(for the possible values, refer to the description of the attribute `e``16ZoneType` of the IAS Zone cluster in [Section 37.2](../../IAS_Zone_cluster/topics/ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)
-   *u64IeeeAddress*: IEEE address of the device which hosts the zone
-   *pu8ZoneID*: Pointer to an identifier of the zone to be added to the table

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS \(zone successfully added to Zone table\)
-   E\_ZCL\_CMDS\_FAILURE \(cluster instance not found\)
-   E\_ZCL\_CMDS\_INVALID\_FIELD \(pointer to Zone ID is NULL\)
-   E\_ZCL\_CMDS\_INVALID\_VALUE \(IEEE address is invalid\)
-   E\_ZCL\_CMDS\_INSUFFICIENT\_SPACE \(no free entry in Zone table\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

