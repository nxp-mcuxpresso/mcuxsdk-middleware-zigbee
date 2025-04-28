# ZPS\_tsAfTCstatusEvent

This structure is used in the ZPS\_EVENT\_TC\_STATUS event, which indicates whether negotiations to establish a link key with the Trust Centre have been successful and, if so, which key is the active key.

The `ZPS_tsAfTCstatusEvent`structure is detailed below.

```
typedef struct
{
    ZPS_tuTcStatusData  uTcData;
    uint8               u8Status;
}ZPS_tsAfTCstatusEvent;
```

where:

-   `uTcData`is dependent on `u8Status`\(below\) and is either a pointer to the link key descriptor in the case of success or the address of the Trust Centre node in the case of failure. `ZPS_tuTcStatusData`is a union, detailed below.
-   `u8Status`indicates the results of the link key negotiations - one of:
    -   ZPS\_E\_SUCCESS \(link key successfully established\)
    -   ZPS\_APL\_APS\_E\_SECURITY\_FAIL \(link key not established\)

The `ZPS_tuTcStatusData`structure is detailed below.

```
typedef union {
   ZPS_tsAplApsKeyDescriptorEntry *pKeyDesc;
   uint64 u64ExtendedAddress;
} PS_tuTcStatusData;
```

where:

-   `pKeyDesc`is a pointer to the active link key, if successfully established, which is contained in the structure described in [Section 8.2.3.6](zps_tsaplapskeydescriptorentry.md).
-   `u64ExtendedAddress`is the IEEE/MAC address of the Trust Centre node with which link key negotiations failed.

**Parent topic:**[Event structures](../topics/event_structures.md)

