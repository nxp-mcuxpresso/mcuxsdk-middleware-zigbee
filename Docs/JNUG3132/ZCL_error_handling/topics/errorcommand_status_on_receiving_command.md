# Error/Command Status on Receiving Command

When a device receives a command, an error might be generated. If receiving a command results in an error, an event of the type E\_ZCL\_CBET\_ERROR is generated on the device. In such cases, the following status codes may be used:

-   The ZCL status of the event \(`sZCL_CallBackEvent.eZCL_Status`\) is set to one of the error codes detailed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541).

-   A ‘default response’ \(see [Section 6.1.9](../../ZCL_structures/topics/tszcl_defaultresponse.md#id_6adc0c37-aa71-4b92-9597-53c4af5d35e1)\) may be generated which contains one of the command status codes detailed in [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832). This response is sent to the source node of the received command \(and can be intercepted using an over-air sniffer\).


The table below details the error and command status codes that may be generated.

|**Error Status \(in Event\)**|**Command Status \(in Response\)**|**Notes**|
|-----------------------------|----------------------------------|---------|
|E\_ZCL\_ERR\_ZRECEIVE\_FAIL \*|None|A receive error has occurred. This error is often security-based due to key establishment not being successfully completed - ZPS error is ZPS\_APL\_APS\_E\_SECURITY\_FAIL.|
|E\_ZCL\_ERR\_EP\_UNKNOWN|E\_ZCL\_CMDS\_SOFTWARE\_FAILURE|Destination endpoint for the command is not registered with the ZCL.|
|E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND|E\_ZCL\_CMDS\_UNSUPPORTED\_CLUSTER|Destination cluster for the command is not registered with the ZCL.|
|E\_ZCL\_ERR\_SECURITY\_INSUFFICIENT\_FOR\_CLUSTER|E\_ZCL\_CMDS\_FAILURE|Attempt made to access a cluster using a packet without the necessary application-level \(APS\) encryption.|
|None|E\_ZCL\_CMDS\_UNSUP\_GENERAL\_COMMAND|Command has no handler enabled in **zcl\_options.h** file.|
|E\_ZCL\_ERR\_CUSTOM\_COMMAND\_HANDLER\_NULL\_OR\_RETURNED\_ERR|E\_ZCL\_CMDS\_UNSUP\_CLUSTER\_COMMAND|Custom command has no registered handler or its handler has not returned E\_ZCL\_SUCCESS.|
|E\_ZCL\_ERR\_KEY\_ESTABLISH-MENT\_END\_POINT\_NOT\_FOUND|None|Key Establishment cluster has not been registered correctly.|
|E\_ZCL\_ERR\_KEY\_ESTABLISH-MENT\_CALLBACK\_ERROR|None|Key Establishment cluster callback function has returned an error.|
|None|E\_ZCL\_CMDS\_MALFORMED\_COMMAND|A received message is incomplete due to some missing command-specific data.|

\* ZigBee PRO stack raises an error which can be retrieved using **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Error Handling](../../ZCL_error_handling/topics/error_handling.md)

