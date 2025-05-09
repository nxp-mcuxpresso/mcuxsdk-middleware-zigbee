# ‘LCE Participation’ Enumerations

The options to participate or not participate in an LCE are enumerated in the `teSE_DRLCUserEventOption` structure below:

```
typedef enum PACK
{
    E_SE_DRLC_EVENT_USER_OPT_IN =0x00,
    E_SE_DRLC_EVENT_USER_OPT_OUT
} teSE_DRLCUserEventOption;

```

The above options are described in the table below.

|**LCE Participation Enumeration**|**Description**|
|---------------------------------|---------------|
|E\_SE\_DRLC\_EVENT\_USER\_OPT\_OUT|User has opted not to participate in the LCE. The device sends this message and does not adjust the load when the LCE becomes active.|
|E\_SE\_DRLC\_EVENT\_USER\_OPT\_IN|User has opted to participate in the LCE. The device only sends this message following an OPT\_OUT \(when the user has changed their mind and decided to participate after all\)|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

