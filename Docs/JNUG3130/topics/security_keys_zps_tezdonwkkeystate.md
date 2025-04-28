# Security keys \(ZPS\_teZdoNwkKeyState\)

This structure `ZPS_teZdoNwkKeyState`contains the enumerations used to specify a type of security key:

```
typedef enum
{
ZPS_ZDO_NO_NETWORK_KEY,
ZPS_ZDO_PRECONFIGURED_LINK_KEY,
ZPS_ZDO_DISTRIBUTED_LINK_KEY,
ZPS_ZDO_PRCONFIGURED_INSTALLATION_CODE
} PACK ZPS_teZdoNwkKeyState
```

These enumerations are described in the table below:

**Security Key Enumerations**

|**Enumeration**|**Description**|
|---------------|---------------|
|ZPS\_ZDO\_NO\_NETWORK\_KEY|No network key should be used.|
|ZPS\_ZDO\_PRECONFIGURED\_LINK\_KEY|A pre-configured link key should be used. This key can be fixed at the time of manufacture.|
|ZPS\_ZDO\_DISTRIBUTED\_LINK\_KEY|A pre-configured ZigBee Light Link \(ZLL\) link key should be used. This key can be fixed at the time of manufacture. A ZLL node contains both a ZPS\_ZDO\_PRECONFIG- URED\_LINK\_KEY for Home Automation \(HA\) compatibility and a ZPS\_ZDO\_ZLL\_LINK\_KEY for ZLL networks.|
|ZPS\_ZDO\_PRCONFIGURED\_INSTALLATION\_CODE|A preconfigured install code is to be used. This results in a key being generated from the install code.|

**Parent topic:**[ZDO enumerations](../topics/zdo_enumerations.md)

