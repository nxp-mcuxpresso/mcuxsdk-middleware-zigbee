# General Return codes \(ZCL Status\)

The following ZCL status enumerations are returned by many API functions to indicate the outcome of the function call.

```
typedef enum 
{
   // General
   E_ZCL_SUCCESS = 0x0,
   E_ZCL_FAIL,                  // 01
   E_ZCL_ERR_PARAMETER_NULL,    // 02
   E_ZCL_ERR_PARAMETER_RANGE,   // 03
   E_ZCL_ERR_HEAP_FAIL,         // 04
   // Specific ZCL status codes
   E_ZCL_ERR_EP_RANGE,          // 05
   E_ZCL_ERR_EP_UNKNOWN,        // 06
   E_ZCL_ERR_SECURITY_RANGE,    // 07
   E_ZCL_ERR_CLUSTER_0,         // 08
   E_ZCL_ERR_CLUSTER_NULL,      // 09
   E_ZCL_ERR_CLUSTER_NOT_FOUND, // 10
   E_ZCL_ERR_CLUSTER_ID_RANGE,  // 11
   E_ZCL_ERR_ATTRIBUTES_NULL,   // 12
   E_ZCL_ERR_ATTRIBUTES_0,      // 13
   E_ZCL_ERR_ATTRIBUTE_WO,      // 14
   E_ZCL_ERR_ATTRIBUTE_RO,      // 15
   E_ZCL_ERR_ATTRIBUTES_ACCESS, // 16
   E_ZCL_ERR_ATTRIBUTE_TYPE_UNSUPPORTED, // 17
   E_ZCL_ERR_ATTRIBUTE_NOT_FOUND,   // 18
   E_ZCL_ERR_CALLBACK_NULL,         // 19
   E_ZCL_ERR_ZBUFFER_FAIL,          // 20
   E_ZCL_ERR_ZTRANSMIT_FAIL,        // 21
   E_ZCL_ERR_CLIENT_SERVER_STATUS,  // 22
   E_ZCL_ERR_TIMER_RESOURCE,        // 23
   E_ZCL_ERR_ATTRIBUTE_IS_CLIENT,   // 24
   E_ZCL_ERR_ATTRIBUTE_IS_SERVER,   // 25
   E_ZCL_ERR_ATTRIBUTE_RANGE,       // 26
   E_ZCL_ERR_ATTRIBUTE_MISMATCH,    // 27
   E_ZCL_ERR_KEY_ESTABLISHMENT_MORE_THAN_ONE_CLUSTER, //28
   E_ZCL_ERR_INSUFFICIENT_SPACE,    // 29
   E_ZCL_ERR_NO_REPORTABLE_CHANGE,  // 30
   E_ZCL_ERR_NO_REPORT_ENTRIES,     // 31
   E_ZCL_ERR_ATTRIBUTE_NOT_REPORTABLE, //32
   E_ZCL_ERR_ATTRIBUTE_ID_ORDER,    // 33
   E_ZCL_ERR_MALFORMED_MESSAGE,     // 34
   E_ZCL_ERR_MANUFACTURER_SPECIFIC, // 35
   E_ZCL_ERR_PROFILE_ID,            // 36
   E_ZCL_ERR_INVALID_VALUE,         // 37
   E_ZCL_ERR_CERT_NOT_FOUND,        // 38
   E_ZCL_ERR_CUSTOM_DATA_NULL,      // 39
   E_ZCL_ERR_TIME_NOT_SYNCHRONISED, // 40
   E_ZCL_ERR_SIGNATURE_VERIFY_FAILED, //41
   E_ZCL_ERR_ZRECEIVE_FAIL,          // 42
   E_ZCL_ERR_KEY_ESTABLISHMENT_END_POINT_NOT_FOUND, // 43
   E_ZCL_ERR_KEY_ESTABLISHMENT_CLUSTER_ENTRY_NOT_FOUND, // 44
   E_ZCL_ERR_KEY_ESTABLISHMENT_CALLBACK_ERROR, // 45
   E_ZCL_ERR_SECURITY_INSUFFICIENT_FOR_CLUSTER, // 46
   E_ZCL_ERR_CUSTOM_COMMAND_HANDLER_NULL_OR_RETURNED_ERROR, // 47
   E_ZCL_ERR_INVALID_IMAGE_SIZE,         // 48
   E_ZCL_ERR_INVALID_IMAGE_VERSION,         // 49
   E_ZCL_READ_ATTR_REQ_NOT_FINISHED,         // 50
   E_ZCL_DENY_ATTRIBUTE_ACCESS,             // 51
   E_ZCL_ERR_SECURITY_FAIL,                 // 52
   E_ZCL_ERR_CLUSTER_COMMAND_NOT_FOUND,
   E_ZCL_ERR_ENUM_END
} teZCL_Status;

```

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_ZCL\_SUCCESS|Function call was successful in its purpose|
|E\_ZCL\_FAIL|Function call failed in its purpose and no other error code is appropriate|
|E\_ZCL\_ERR\_PARAMETER\_NULL|Specified parameter pointer was null|
|E\_ZCL\_ERR\_PARAMETER\_RANGE|A parameter value was out-of-range|
|E\_ZCL\_ERR\_HEAP\_FAIL|ZCL heap is out-of-memory|
|E\_ZCL\_ERR\_EP\_RANGE|Specified endpoint number was out-of-range|
|E\_ZCL\_ERR\_EP\_UNKNOWN|Specified endpoint has not been registered with the ZCL \(but endpoint number was in-range\)|
|E\_ZCL\_ERR\_SECURITY\_RANGE|Security value is out-of-range|
|E\_ZCL\_ERR\_CLUSTER\_0|Specified endpoint has no clusters|
|E\_ZCL\_ERR\_CLUSTER\_NULL|Specified pointer to a cluster was null|
|E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND|Specified cluster has not been registered with the ZCL|
|E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE|Specified cluster ID was out-of-range|
|E\_ZCL\_ERR\_ATTRIBUTES\_NULL|Specified pointer to an attribute was null|
|E\_ZCL\_ERR\_ATTRIBUTES\_0|List of attributes to be read was empty|
|E\_ZCL\_ERR\_ATTRIBUTE\_WO|Attempt was made to read write-only attribute|
|E\_ZCL\_ERR\_ATTRIBUTE\_RO|Attempt was made to write to read-only attribute|
|E\_ZCL\_ERR\_ATTRIBUTES\_ACCESS|Error occurred while accessing attribute|
|E\_ZCL\_ERR\_ATTRIBUTE\_TYPE\_UNSUPPORTED|Specified attribute was of unsupported type|
|E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND|Specified attribute was not found|
|E\_ZCL\_ERR\_CALLBACK\_NULL|Specified pointer to a callback function was null|
|E\_ZCL\_ERR\_ZBUFFER\_FAIL|No buffer available to transmit message|
|E\_ZCL\_ERR\_ZTRANSMIT\_FAIL\ (See Note 1 below this table)|ZigBee PRO stack has reported a transmission error|
|E\_ZCL\_ERR\_CLIENT\_SERVER\_STATUS|Cluster instance of wrong kind \(for example, client instead of server\)|
|E\_ZCL\_ERR\_TIMER\_RESOURCE|No timer resource was available|
|E\_ZCL\_ERR\_ATTRIBUTE\_IS\_CLIENT|Attempt made by a cluster client to read a client attribute|
|E\_ZCL\_ERR\_ATTRIBUTE\_IS\_SERVER|Attempt made by a cluster server to read a server attribute|
|E\_ZCL\_ERR\_ATTRIBUTE\_RANGE|Attribute value is out-of-range|
|E\_ZCL\_ERR\_ATTRIBUTE\_MISMATCH|Reserved for future use|
|E\_ZCL\_ERR\_KEY\_ESTABLISHMENT\_MORE\_THAN\_ONE\_CLUSTER|Attempt made to register more than one Key Establishment cluster on the device \(only one is permitted per device\)|
|E\_ZCL\_ERR\_INSUFFICIENT\_SPACE|Cluster does not have enough space in its list to store data item, for example **eSE\_PriceAddPriceEntry\(\)** may return this code|
|E\_ZCL\_ERR\_NO\_REPORTABLE\_CHANGE|Reserved for future use|
|E\_ZCL\_ERR\_NO\_REPORT\_ENTRIES|Reserved for future use|
|E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_REPORTABLE|Reserved for future use|
|E\_ZCL\_ERR\_ATTRIBUTE\_ID\_ORDER (See note 2 below  this table)|Attempt made to register a cluster with attribute IDs not defined in ascending order|
|E\_ZCL\_ERR\_MALFORMED\_MESSAGE|Received ZCL message is not formed correctly. This error code is used in a callback event on the receiving device|
|E\_ZCL\_ERR\_ATTRIBUTE\_ID\_ORDER \*\* (See note 2 below  this table)|Attempt made to register a cluster with attribute IDs not defined in ascending order|
|E\_ZCL\_ERR\_MANUFACTURER\_SPECIFIC \*\*|Inconsistency in a manufacturer-specific cluster definition has been found|
|E\_ZCL\_ERR\_ATTRIBUTE\_ID\_ORDER (See note 2 below  this table)|Attempt made to register a cluster with attribute IDs not defined in ascending order|
|E\_ZCL\_ERR\_PROFILE\_ID (See Note 2 below this table) |Profile ID of a cluster is not valid - for example, the cluster being registered is not manufacturer-specific but the profile ID is in range reserved for manufacturer-specific profiles|
|E\_ZCL\_ERR\_INVALID\_VALUE|An invalid value has been detected.|
|E\_ZCL\_ERR\_CERT\_NOT\_FOUND|Reserved for future use|
|E\_ZCL\_ERR\_CUSTOM\_DATA\_NULL|Custom data associated with cluster is NULL|
|E\_ZCL\_ERR\_TIME\_NOT\_SYNCHRONISED|Time has not been synchronized by calling **vZCL\_SetUTC**-**Time\(\)**. This error code is returned by functions that require time to be synchronised, for example, **eSE\_PriceAddPriceEntry\(\)**|
|E\_ZCL\_ERR\_SIGNATURE\_VERIFY\_FAILED|Reserved for future use|
|E\_ZCL\_ERR\_ZRECEIVE\_FAIL \* (See Note 1 below this table)|ZigBee PRO stack has reported a receive error|
|E\_ZCL\_ERR\_KEY\_ESTABLISHMENT\_END\_POINT\_NOT\_FOUND|Key Establishment endpoint has not been registered correctly|
|E\_ZCL\_ERR\_KEY\_ESTABLISHMENT\_CLUSTER\_ENTRY\_NOT\_FOUND|Key Establishment cluster has not been registered correctly|
|E\_ZCL\_ERR\_KEY\_ESTABLISHMENT\_CALLBACK\_ERROR|Key Establishment cluster callback function has returned an error|
|E\_ZCL\_ERR\_SECURITY\_INSUFFICIENT\_FOR\_CLUSTER|Cluster that requires application-level \(APS\) security has been accessed using a packet that has not been encrypted with the application link key|
|E\_ZCL\_ERR\_CUSTOM\_COMMAND\_HANDLER\_NULL\_OR\_RETURNED\_ERROR|No custom handler has been registered for the command or the custom handler for the command has not returned E\_ZCL\_SUCCESS|
|E\_ZCL\_ERR\_INVALID\_IMAGE\_SIZE|OTA image size is not in the correct range|
|E\_ZCL\_ERR\_INVALID\_IMAGE\_VERSION|OTA image version is not in the correct range|
|E\_ZCL\_READ\_ATTR\_REQ\_NOT\_FINISHED|‘Read attributes’ request not completely fulfilled|
|E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS|Write access to attribute is denied|
|E\_ZCL\_ERR\_SECURITY\_FAIL|Security failure|
|E\_ZCL\_ERR\_CLUSTER\_COMMAND\_NOT\_FOUND|The cluster command was not found|
|E\_ZCL\_ERR\_INVALID\_VALUE|Reserved for future use|

**Note1:** ZigBee PRO stack raises an error which can be retrieved using **eZCL\_GetLastZpsError\(\)**.

**Note2:** This error code is returned by **eZCL\_Register\(\)**, used in designing custom clusters.

**Parent topic:**[Enumerations and Status Codes](../../ZCL_enums_codes/topics/enumerations_and_status_codes.md)

