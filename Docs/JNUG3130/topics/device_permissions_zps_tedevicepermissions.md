# Device permissions \(ZPS\_teDevicePermissions\)

This structure `ZPS_teDevicePermissions` contains the enumerations used on a device to specify the permissions for certain requests from other nodes:

```
typedef enum
{
ZPS_DEVICE_PERMISSIONS_ALL_PERMITED = 0,
ZPS_DEVICE_PERMISSIONS_JOIN_DISALLOWED = 1,
ZPS_DEVICE_PERMISSIONS_DATA_REQUEST_DISALLOWED = 2,
ZPS_DEVICE_PERMISSIONS_REJOIN_DISALLOWED = 4,
} PACK ZPS_teDevicePermissions;
```

These enumerations are described in the table below:

**Device permissions**

|**Enumeration**|**Description**|
|---------------|---------------|
|ZPS\_DEVICE\_PERMISSIONS\_ALL\_PERMITED|Allow all requests from other nodes|
|ZPS\_DEVICE\_PERMISSIONS\_JOIN\_DISALLOWED|Do not allow join requests from other nodes|
|ZPS\_DEVICE\_PERMISSIONS\_DATA\_REQUEST\_DISALLOWED|Do not allow data requests from other nodes and disable end-to-end acknowledgments|
|ZPS\_DEVICE\_PERMISSIONS\_REJOIN\_DISALLOWED|Do not allow insecure rejoin.|

**Parent topic:**[ZDO enumerations](../topics/zdo_enumerations.md)

