# ‘Simple Metering Status’ Enumerations

The following enumerations are used to report status in the Simple Metering cluster.

```
typedef enum PACK
{
    E_CLD_SM_STATUS_SUCCESS,
    E_CLD_SM_STATUS_UNDEFINED_INTERVAL_CHANNEL,
    E_CLD_SM_STATUS_INTERVAL_NOT_SUPPORTED,
    E_CLD_SM_STATUS_INVALID_END_TIME,
    E_CLD_SM_STATUS_MORE_PERIODS_REQUESTED_THAN_SUPPORTED,
    E_CLD_SM_STATUS_NO_INTERVALS_AVAILABLE_FOR_REQUESTED_TIME,
    E_CLD_SM_STATUS_EP_NOT_AVAILABLE
}teSM_Status;

```

|**Status Enumeration**|**Description**|
|----------------------|---------------|
|E\_CLD\_SM\_STATUS\_SUCCESS|Success|
|E\_CLD\_SM\_STATUS\_UNDEFINED\_INTERVAL\_CHANNEL|Undefined `eIntervalChannel` value speci-fied in ‘Get Profile’ request \(see [Section](tssm_getprofilerequestcommand.md#id_fdfdc3c8-933b-4e97-a9cc-334ccc4ed745)42.11.8\)|
|E\_CLD\_SM\_STATUS\_INTERVAL\_NOT\_SUPPORTED|Unsupported consumption data specifed through `eIntervalChannel` in ‘Get Profile’ request \(see [Section 42.11.8](tssm_getprofilerequestcommand.md#id_fdfdc3c8-933b-4e97-a9cc-334ccc4ed745)\)|
|E\_CLD\_SM\_STATUS\_INVALID\_END\_TIME|Invalid end-time specified in ‘Get Profile’ request \([Section 42.11.8](tssm_getprofilerequestcommand.md#id_fdfdc3c8-933b-4e97-a9cc-334ccc4ed745)\)|
|E\_CLD\_SM\_STATUS\_MORE\_PERIODS\_REQUESTED\_THAN\_SUPPORTED|More periods specified in ‘Get Profile’ request than can be returned|
|E\_CLD\_SM\_STATUS\_NO\_INTERVALS\_AVAILABLE\_FOR\_REQUESTED\_TIME|No intervals available for the end-time specified in ‘Get Profile’ request|
|E\_CLD\_SM\_STATUS\_EP\_NOT\_AVAILABLE|Specified endpoint not available|

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

