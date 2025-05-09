# Report Attribute Status \(teZCL\_ReportAttributeStatus\)

The following enumerations are used to indicate the status of a report attribute command.

```
typedef enum 
{
    E_ZCL_ATTR_REPORT_OK = 0x00,
    E_ZCL_ATTR_REPORT_EP_MISMATCH,
    E_ZCL_ATTR_REPORT_ADDR_MISMATCH,
    E_ZCL_ATTR_REPORT_ERR
} teZCL_ReportAttributeStatus;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_ZCL\_ATTR\_REPORT\_OK|Indicates that report is valid|
|E\_ZCL\_ATTR\_REPORT\_EP\_MISMATCH|Indicates that source endpoint does not match endpoint in mirror|
|E\_ZCL\_ATTR\_REPORT\_ADDR\_MISMATCH|Indicates that source address does not match address in mirror|
|E\_ZCL\_ATTR\_REPORT\_ERR|Indicates that there is an error in the report|

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

