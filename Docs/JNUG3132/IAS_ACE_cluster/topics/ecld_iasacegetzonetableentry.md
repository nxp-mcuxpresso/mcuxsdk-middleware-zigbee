# eCLD\_IASACEGetZoneTableEntry

```
teZCL_CommandStatus eCLD_IASACEGetZoneTableEntry(
    uint8 u8SourceEndPointId,
    uint8 u8ZoneID,
    tsCLD_IASACE_ZoneTable **ppsZoneTable);

```

## Description 

This function can be used on an IAS ACE cluster server to obtain the details of a specified zone from the local Zone table.

The zone of interest is specified by means of its Zone ID. The function searches for the relevant table entry using the supplied Zone ID and, if found, returns the zone information from the table entry via the supplied structure \(see [Section 38.7.2](zone_table_entry.md#id_917bf1dd-14fe-4c05-87cf-cc071f948c45)\).

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *u8ZoneID*: Zone ID of zone for which details required from table
-   *ppsZoneTable*: Pointer to a pointer to a structure to receive obtained zone information \(see [Section 38.7.2](zone_table_entry.md#id_917bf1dd-14fe-4c05-87cf-cc071f948c45)\)

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS \(zone details successfully obtained from Zone table\)
-   E\_ZCL\_CMDS\_FAILURE \(cluster instance not found\)
-   E\_ZCL\_CMDS\_NOT\_FOUND \(entry with specified Zone ID not found in table\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

