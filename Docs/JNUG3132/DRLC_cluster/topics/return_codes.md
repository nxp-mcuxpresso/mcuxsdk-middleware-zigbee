# Return codes

In addition to some of the ZCL status enumerations \(detailed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)\), the following enumerations are returned by the DRLC cluster functions \(described in [Section 41.8](functions.md#id_49559f64-dfdb-4757-84bf-dca5908d6916)\) to indicate the outcome of the function call.

```
typedef enum PACK
{
 E_SE_DRLC_DUPLICATE_EXISTS = 0x80,
 E_SE_DRLC_EVENT_LATE,
 E_SE_DRLC_EVENT_NOT_YET_ACTIVE,
 E_SE_DRLC_EVENT_OLD,
 E_SE_DRLC_NOT_FOUND,
 E_SE_DRLC_EVENT_NOT_FOUND,
 E_SE_DRLC_EVENT_IGNORED,
 E_SE_DRLC_CANCEL_DEFERRED,
 E_SE_DRLC_BAD_DEVICE_CLASS,
 E_SE_DRLC_BAD_CRITICALITY_LEVEL,
 E_SE_DRLC_DURATION_TOO_LONG,
 E_SE_DRLC_ENUM_END
} teSE_DRLCStatus;

```

The above return codes are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_SE\_DRLC\_DUPLICATE\_EXISTS|An overlapping LCE \(in time\) has been found|
|E\_SE\_DRLC\_EVENT\_LATE|Function call refers to a time period that is earlier than the current ZCL time|
|E\_SE\_DRLC\_EVENT\_NOT\_YET\_ACTIVE|Not used - reserved for future use|
|E\_SE\_DRLC\_EVENT\_OLD|Not used - reserved for future use|
|E\_SE\_DRLC\_NOT\_FOUND|LCE cannot be found in lists \(used in LCE cancelation or opt out\)|
|E\_SE\_DRLC\_EVENT\_NOT\_FOUND|LCE cannot be found in lists \(used when searching for an LCE \)|
|E\_SE\_DRLC\_EVENT\_IGNORED|Not used - reserved for future use|
|E\_SE\_DRLC\_CANCEL\_DEFERRED|Cancellation has been processed but is deferred to act in the future|
|E\_SE\_DRLC\_BAD\_DEVICE\_CLASS|Specified device class not recognized|
|E\_SE\_DRLC\_BAD\_CRITICALITY\_LEVEL|Specified criticaility level not recognized|
|E\_SE\_DRLC\_DURATION\_TOO\_LONG|Specified duration exceeds maximum of 1440 minutes \(one day\)|

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

