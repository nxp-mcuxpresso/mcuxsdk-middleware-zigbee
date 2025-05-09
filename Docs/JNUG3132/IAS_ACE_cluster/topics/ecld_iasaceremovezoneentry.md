# eCLD\_IASACERemoveZoneEntry

```
teZCL_CommandStatus eCLD_IASACERemoveZoneEntry(
  uint8 u8SourceEndPointId,
    uint8 u8ZoneID,
    uint64 *pu64IeeeAddress);

```

## Description

This function can be used on an IAS ACE cluster server to remove an existing entry from the local Zone table - that is, to delete the details of a zone in the table and release the table entry for re-use. Thus, this function can be used to unenroll a zone.

The zone to be removed is specified by means of the Zone ID. The function checks that the supplied pointer to a location to receive the IEEE address is not NULL. The function then searches for the relevant table entry using the supplied Zone ID and, if found, returns its IEEE address via the supplied location and frees the table entry by setting the IEEE address in the table entry to zero. The returned IEEE address can be used by a \(local\) CIE device application to send a request to the relevant Zone device to set its IAS Zone cluster attribute `u64IASCIEAddress` to all zeros \(writing to remote attributes is described in [Section 2.3.3.1](../../ZCL_fundamentals/topics/writing_to_attributes_of_a_remote_cluster.md#id_a5f67377-e001-4080-a5ab-ee4676a2daa5)\).

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *u8ZoneID*: Zone ID of zone to be removed from table
-   *pu64IeeeAddress*: Pointer to location to receive the IEEE address found in the table entry to be removed

## Returns 

-   E\_ZCL\_CMDS\_SUCCESS \(zone successfully removed from Zone table\)
-   E\_ZCL\_CMDS\_FAILURE \(cluster instance not found\)
-   E\_ZCL\_CMDS\_INVALID\_FIELD \(pointer to IEEE address location is NULL\)
-   E\_ZCL\_CMDS\_NOT\_FOUND \(entry with specified Zone ID not found in table\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

