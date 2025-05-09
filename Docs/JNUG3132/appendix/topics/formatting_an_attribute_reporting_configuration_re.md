# Formatting an attribute reporting configuration record

The format in which the server application stores attribute reporting configuration data in RAM and, optionally, in NVM is at the discretion of the application developer.

The most general method is to store this data in an array of structures, in which there is one array element for each attribute for which automatic reporting is implemented \(the size of this array should correspond to the value of the compile-time option SE\_NUMBER\_OF\_REPORTS - see [Appendix B.3.1](compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a)\). The information stored for each attribute may include the relevant cluster ID and endpoint number, as well as details of the configured change that can result in an attribute report. However, this method of data storage may require significant memory space and may only be necessary for more complex applications.

Alternative storage formats for this data are possible which economize on the memory requirements. These methods are outlined below.

## Reduced Data Storage 

A simple extension of the above general scheme uses application knowledge of the attributes being reported. In this case, certain static information about the reportable attributes is built into the compiled application and only the changeable information about these attributes is saved to an array in RAM \(and NVM\). In this way, the required memory space to store the attribute reporting configuration data is reduced.

An example of this method with five reportable attributes is given below.

```
#define SE_NUMBER_OF_REPORTS 5
typedef struct
  {
   uint16 u16Min;
   uint16 u16Max;
   tuZCL_AttributeReportable uChangeValue;
  } tsLocalStruct;
static tsLocalStruct asLocalConfigStruct[SE_NUMBER_OF_REPORTS];
typedef struct
 {
  uint16 u16AttEnum;
  teZCL_ZCLAttributeType eAttType;
 }tsLocalDefs;
static const tsLocalDefs asLocalDefs[SE_NUMBER_OF_REPORTS] = {
   {TPRC_MATCH_1,E_ZCL_UINT32}, 
   {TPRC_MATCH_6,E_ZCL_BMAP48}, 
   {TPRC_MATCH_7,E_ZCL_GINT56}, 
   {TPRC_MATCH_5,E_ZCL_UINT56}, 
   {TPRC_MATCH_3,E_ZCL_BOOL}
  };

```

In the above example:

-   The fixed data \(attribute identifier and type\) is held in an array of `tsLocalDefs` structures, with one array element per attribute - this array is defined at compile-time and therefore does not need to be updated in RAM or persisted in NVM.

-   The attribute reporting configuration data is held in an array of `tsLocalStruct` structures, with one array element per attribute - only this array needs to be updated in RAM and persisted in NVM, thus saving storage space.


Note that both arrays have SE\_NUMBER\_OF\_REPORTS elements and there is a one-to-one correspondence between the elements of the two arrays - elements with the same number relate to the same attribute.

## Minimized Data Storage 

It may be possible to optimize the format in which the attribute reporting configuration data is saved in order to suit the attributes reported. For example, if there are only two attributes to be reported, then it may be sufficient to store the attribute reporting configuration data in a single structure, like the following:

```
typedef struct
{
    uint16   u16MinimumReportingIntervalForAttA;
    uint16   u16MaximumReportingIntervalForAttA;
    zint32   u32AttAReportableChange;
    uint16   u16MinimumReportingIntervalForAttB;
    uint16   u16MaximumReportingIntervalForAttB;
        // Attribute B is a discrete type (for example, a bitmap), so does not have a reportable change
} tsZCL_PersistedAttributeReportingConfigurationRecord;

```

**Parent topic:**[Appendix B.7: Storing an attribute reporting configuration](../../appendix/topics/storing_an_attribute_reporting_configuration.md)

