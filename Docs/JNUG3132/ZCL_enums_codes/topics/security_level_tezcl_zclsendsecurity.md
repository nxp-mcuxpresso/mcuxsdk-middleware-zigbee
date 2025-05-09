# Security Level \(teZCL\_ZCLSendSecurity\)

The following enumerations are used to indicate the security level for transmissions:

```
typedef enum 
{
    E_ZCL_SECURITY_NETWORK = 0x00,
    E_ZCL_SECURITY_APPLINK,
    E_ZCL_SECURITY_TEMP_APPLINK,
    E_ZCL_SECURITY_ENUM_END
} teZCL_ZCLSendSecurity;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_ZCL\_SECURITY\_NETWORK|Network-level security, using a network key|
|E\_ZCL\_SECURITY\_APPLINK|Application-level security, using an application link key|
|E\_ZCL\_SECURITY\_TEMP\_APPLINK|Temporary application-level security. This option is for internal use only. This is used for situations in which an application link key is to be used temporarily. For example, it can be used for an individual communication.|

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

