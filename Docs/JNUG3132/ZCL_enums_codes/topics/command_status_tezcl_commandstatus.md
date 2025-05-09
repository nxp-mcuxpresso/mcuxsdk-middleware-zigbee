# Command Status \(teZCL\_CommandStatus\)

The following enumerations are used to indicate the status of a command:

```
typedef enum 
{
    E_ZCL_CMDS_SUCCESS =0x00,
    E_ZCL_CMDS_FAILURE,
    E_ZCL_CMDS_NOT_AUTHORIZED =0x7e,
    E_ZCL_CMDS_RESERVED_FIELD_NOT_ZERO,
    E_ZCL_CMDS_MALFORMED_COMMAND =0x80,
    E_ZCL_CMDS_UNSUP_CLUSTER_COMMAND,
    E_ZCL_CMDS_UNSUP_GENERAL_COMMAND,
    E_ZCL_CMDS_UNSUP_MANUF_CLUSTER_COMMAND,
    E_ZCL_CMDS_UNSUP_MANUF_GENERAL_COMMAND,
    E_ZCL_CMDS_INVALID_FIELD,
    E_ZCL_CMDS_UNSUPPORTED_ATTRIBUTE,
    E_ZCL_CMDS_INVALID_VALUE,
    E_ZCL_CMDS_READ_ONLY,
    E_ZCL_CMDS_INSUFFICIENT_SPACE,
    E_ZCL_CMDS_DUPLICATE_EXISTS,
    E_ZCL_CMDS_NOT_FOUND,
    E_ZCL_CMDS_UNREPORTABLE_ATTRIBUTE,
    E_ZCL_CMDS_INVALID_DATA_TYPE,
    E_ZCL_CMDS_INVALID_SELECTOR,
    E_ZCL_CMDS_WRITE_ONLY,
    E_ZCL_CMDS_INCONSISTENT_STARTUP_STATE,
    E_ZCL_CMDS_DEFINED_OUT_OF_BAND,
    E_ZCL_CMDS_INCONSISTENT,
    E_ZCL_CMDS_ACTION_DENIED,
    E_ZCL_CMDS_TIMEOUT,
    E_ZCL_CMDS_HARDWARE_FAILURE =0xc0,
    E_ZCL_CMDS_SOFTWARE_FAILURE,
    E_ZCL_CMDS_CALIBRATION_ERROR,
    E_ZCL_CMDS_UNSUPPORTED_CLUSTER,
    E_ZCL_CMDS_ENUM_END
} teZCL_CommandStatus;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_ZCL\_CMDS\_SUCCESS|Command was successful|
|E\_ZCL\_CMDS\_FAILURE|Command was unsuccessful|
|E\_ZCL\_CMDS\_NOT\_AUTHORIZED|Sender does not have authorisation to issue the command|
|E\_ZCL\_CMDS\_RESERVED\_FIELD\_NOT\_ZERO|A reserved field of command is not set to zero|
|E\_ZCL\_CMDS\_MALFORMED\_COMMAND|Command has missing fields or invalid field values|
|E\_ZCL\_CMDS\_UNSUP\_CLUSTER\_COMMAND|The specified cluster has not been registered with the ZCL on the device|
|E\_ZCL\_CMDS\_UNSUP\_GENERAL\_COMMAND|Command does not have a handler enabled in the **zcl\_options.h** file|
|E\_ZCL\_CMDS\_UNSUP\_MANUF\_CLUSTER\_COMMAND|Manufacturer-specific cluster command is not sup-ported or has unknown manufacturer code|
|E\_ZCL\_CMDS\_UNSUP\_MANUF\_GENERAL\_COMMAND|Manufacturer-specific ZCL command is not sup-ported or has unknown manufacturer code|
|E\_ZCL\_CMDS\_INVALID\_FIELD|Command has field which contains invalid value|
|E\_ZCL\_CMDS\_UNSUPPORTED\_ATTRIBUTE|Specified attribute is not supported on the device|
|E\_ZCL\_CMDS\_INVALID\_VALUE|Specified attribute value is out of range or a reserved value|
|E\_ZCL\_CMDS\_READ\_ONLY|Attempt to write to read-only attribute|
|E\_ZCL\_CMDS\_INSUFFICIENT\_SPACE|Not enough memory space to perform requested operation|
|E\_ZCL\_CMDS\_DUPLICATE\_EXISTS|Attempt made to create a table entry that already exists in the target table|
|E\_ZCL\_CMDS\_NOT\_FOUND|Requested information cannot be found|
|E\_ZCL\_CMDS\_UNREPORTABLE\_ATTRIBUTE|Periodic reports cannot be produced for this attribute|
|E\_ZCL\_CMDS\_INVALID\_DATA\_TYPE|Invalid data type specified for attribute|
|E\_ZCL\_CMDS\_INVALID\_SELECTOR|Incorrect selector for this attribute|
|E\_ZCL\_CMDS\_WRITE\_ONLY|Issuer of command does not have authorisation to read specified attribute|
|E\_ZCL\_CMDS\_INCONSISTENT\_STARTUP\_STATE|Setting the specified values would put device into an inconsistent state on start-up|
|E\_ZCL\_CMDS\_DEFINED\_OUT\_OF\_BAND|Attempt has been made to write to attribute using an out-of-band method or not over-air|
|E\_ZCL\_CMDS\_HARDWARE\_FAILURE|Command was unsuccessful due to hardware failure|
|E\_ZCL\_CMDS\_SOFTWARE\_FAILURE|Command was unsuccessful due to software failure|
|E\_ZCL\_CMDS\_CALIBRATION\_ERROR|Error occurred during calibration|
|E\_ZCL\_CMDS\_UNSUPPORTED\_CLUSTER|The cluster is not supported|

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

