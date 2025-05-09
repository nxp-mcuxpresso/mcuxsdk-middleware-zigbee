# ‘LCE List’ Enumerations

The LCE lists are enumerated in the `teSE_DRLCEventList` structure below:

```
typedef enum PACK
{
    E_SE_DRLC_EVENT_LIST_SCHEDULED =0x00,
    E_SE_DRLC_EVENT_LIST_ACTIVE,
    E_SE_DRLC_EVENT_LIST_CANCELLED,
    E_SE_DRLC_EVENT_LIST_DEALLOCATED,
    E_SE_DRLC_EVENT_LIST_NONE
} teSE_DRLCEventList;

```

The above lists are described in the table below.

|**LCE List Enumeration**|**Description**|
|------------------------|---------------|
|E\_SE\_DRLC\_EVENT\_LIST\_SCHEDULED|**Scheduled list:** Contains LCEs that are due to be executed in the future|
|E\_SE\_DRLC\_EVENT\_LIST\_ACTIVE|**Active list:** Contains LCEs that are currently being executed|
|E\_SE\_DRLC\_EVENT\_LIST\_CANCELLED|**Cancelled list:** Contains LCEs that have been cancelled with a randomized end-time and whose random end-time has not yet been reached|
|E\_SE\_DRLC\_EVENT\_LIST\_DEALLOCATED|**Deallocated list:** Contains expired LCEs and therefore a record of the free storage for LCEs|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

