# Attribute Access Permissions

For each attribute of a cluster, access permissions should be defined for the different types of access to the attribute. These permissions are configured using control flags, with one flag for each access type, as follows:

|**Access Type**|**Flag**|**Description**|
|---------------|--------|---------------|
|Read|E\_ZCL\_AF\_RD|Global commands can read the attribute value|
|Write|E\_ZCL\_AF\_WR|Global commands can write a new value to the attribute|
|Report|E\_ZCL\_AF\_RP|Global commands can report the value of the attribute or configure the attribute for default reporting|
|Scene|E\_ZCL\_AF\_SE|The attribute can be accessed through a scene \(if the Scenes cluster is implemented on the same endpoint\)|

If a particular access type is required for an individual attribute, the corresponding flag must be defined for that attribute. This is done in the C header file for the cluster. For example, in the case of the On/Off cluster, the required flags must be defined for each attribute in the following structure in the **OnOff.c** file:

```
const tsZCL_AttributeDefinition asCLD_OnOffClusterAttributeDefinitions[] = {
#ifdef ONOFF_SERVER
  {E_CLD_ONOFF_ATTR_ID_ONOFF, (E_ZCL_AF_RD|E_ZCL_AF_SE|E_ZCL_AF_RP), E_ZCL_BOOL,
  (uint32)(&((tsCLD_OnOff*)(0))->bOnOff),0}, /* Mandatory */
#ifdef CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
  {E_CLD_ONOFF_ATTR_ID_GLOBAL_SCENE_CONTROL, (E_ZCL_AF_RD), _ZCL_BOOL,
  (uint32)(&((tsCLD_OnOff*)(0))->bGlobalSceneControl),0}, /* Optional */
#endif
#ifdef CLD_ONOFF_ATTR_ON_TIME
  {E_CLD_ONOFF_ATTR_ID_ON_TIME, E_ZCL_AF_RD|E_ZCL_AF_WR), E_ZCL_UINT16,
  (uint32)(&((tsCLD_OnOff*)(0))->u16OnTime),0}, /* Optional */
#endif
#ifdef CLD_ONOFF_ATTR_OFF_WAIT_TIME
  {E_CLD_ONOFF_ATTR_ID_OFF_WAIT_TIME, (E_ZCL_AF_RD|E_ZCL_AF_WR), E_ZCL_UINT16,
  (uint32)(&((tsCLD_OnOff*)(0))->u16OffWaitTime),0}, /* Optional */
#endif
#ifdef CLD_ONOFF_ATTR_STARTUP_ONOFF
  /* ZLO extension for OnOff Cluster */
  {E_CLD_ONOFF_ATTR_ID_STARTUP_ONOFF, E_ZCL_AF_RD|E_ZCL_AF_WR), E_ZCL_ENUM8,
  (uint32)(&((tsCLD_OnOff*)(0))->eStartUpOnOff),0}, /* Optional */
#endif
#endif
  {E_CLD_GLOBAL_ATTR_ID_CLUSTER_REVISION, (E_ZCL_AF_RD|E_ZCL_AF_GA), E_ZCL_UINT16,
  (uint32)(&((tsCLD_OnOff*)(0))->u16ClusterRevision),0}, /* Mandatory */
  #if (defined ONOFF_SERVER) && (defined CLD_ONOFF_ATTR_ATTRIBUTE_REPORTING_STATUS)
  {E_CLD_GLOBAL_ATTR_ID_ATTRIBUTE_REPORTING_STATUS,(E_ZCL_AF_RD|E_ZCL_AF_GA), E_ZCL_ENUM8,
  (uint32)(&((tsCLD_OnOff*)(0))->u8AttributeReportingStatus),0}, /* Optional */
#endif
};
```

**Note:** The flag *E\_ZCL\_AF\_GA* indicates a global attribute.

**Parent topic:**[Accessing Attributes](../../ZCL_fundamentals/topics/accessing_attributes.md)

