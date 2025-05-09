# ‘LCE Cancellation’ Enumerations

The cancelation options \(immediate or randomized\) that are available for an LCE are enumerated in the `teSE_DRLCCancelControl` structure below:

```
typedef enum PACK
{
    E_SE_DRLC_CANCEL_CONTROL_IMMEDIATE =0x00,
    E_SE_DRLC_CANCEL_CONTROL_USE_RANDOMISATION =0x10
} teSE_DRLCCancelControl;

```

The above options are described in the table below.

|**LCE Cancellation Enumeration**|**Description**|
|--------------------------------|---------------|
|E\_SE\_DRLC\_CANCEL\_CONTROL\_IMMEDIATE|LCE is cancelled immediately by moving it directly to the ‘Deallocated’ list - a randomized end-time configured in the LCE is ignored|
|E\_SE\_DRLC\_CANCEL\_CONTROL\_USE\_RANDOMISATION|A random delay will be applied to the LCE cancellation, if a randomised end-time was configured in the LCE - the LCE is moved to the ‘Cancelled’ list where it will stay \(and remain valid\) until the random delay has expired, when it will be moved to the ‘Deallocated’ list \(an upper limit on the delay is defined in the cluster - see [Section](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)41.2\)|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

