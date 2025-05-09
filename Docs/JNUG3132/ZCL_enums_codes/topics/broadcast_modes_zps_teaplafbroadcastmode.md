# Broadcast Modes \(ZPS\_teAplAfBroadcastMode\)

The following enumerations are used to specify the type of broadcast \(when the addressing mode for a communication has been set to E\_ZCL\_AM\_BROADCAST \(see [Section 7.1.1](addressing_modes_tezcl_addressmode.md#id_770cb165-bfc2-4129-9db1-c205a6fe2fa9)\)\):

```
typedef enum 
{
    ZPS_E_APL_AF_BROADCAST_ALL,
    ZPS_E_APL_AF_BROADCAST_RX_ON,
    ZPS_E_APL_AF_BROADCAST_ZC_ZR
} ZPS_teAplAfBroadcastMode;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|ZPS\_E\_APL\_AF\_BROADCAST\_ALL|All End Devices|
|ZPS\_E\_APL\_AF\_BROADCAST\_RX\_ON|Nodes on which the radio receiver remains enabled when the node is idle \(e.g. sleeping\)|
|ZPS\_E\_APL\_AF\_BROADCAST\_ZC\_ZR|Only the Coordinator and Routers|

The required broadcast mode is specified in the structure `tsZCL_Address` \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\).

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

