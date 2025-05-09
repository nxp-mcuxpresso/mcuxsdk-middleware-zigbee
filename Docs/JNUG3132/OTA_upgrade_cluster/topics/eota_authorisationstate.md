# eOTA\_AuthorisationState

The following enumerations represent the authorisation options concerning which clients are allowed to obtain upgrade images from the server:

```
typedef enum 
{
    E_CLD_OTA_STATE_ALLOW_ALL,
    E_CLD_OTA_STATE_USE_LIST
}eOTA_AuthorisationState;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_OTA\_STATE\_ALLOW\_ALL|Allow all clients to obtain upgrade images from this server|
|E\_CLD\_OTA\_STATE\_USE\_LIST|Only allow clients in authorisation list to obtain upgrade images from this server|

**Parent topic:**[Enumerations](../../OTA_upgrade_cluster/topics/enumerations.md)

