# B.3.7: ZCL Configuration for Attribute Reporting

This section describes aspects of ZCL configuration related to attribute reporting.

**Note:** The information in this section is only useful to developers who wish to adjust the standard ZCL configuration for attribute reporting.

Each attribute for which automatic reporting is enabled requires a `tsZCL_ReportRecord` structure. These structures are maintained internally by the ZCL and space for them is allocated on the ZCL heap. The heap is allocated using the **u32ZCL\_Heap** macro - for example:

``````
PRIVATE uint32 u32ZCL_Heap[
ZCL_HEAP_SIZE(ZCL_NUMBER_OF_ENDPOINTS,
ZCL_NUMBER_OF_TIMERS,
ZCL_NUMBER_OF_REPORTS)];

``````
The number of reportable attributes and the maximum/minimum reporting intervals are passed into the internal `eZCL_CreateZCL` structure via the `sConfig` parameter - for example:

```
sConfig.u8NumberOfReports = ZCL_NUMBER_OF_REPORTS;
sConfig.u16SystemMinimumReportingInterval = 
                            ZCL_SYSTEM_MIN_REPORT_INTERVAL;
sConfig.u16SystemMaximumReportingInterval =   
                            ZCL_SYSTEM_MAX_REPORT_INTERVAL;

```

The above macros have default values that can be over-ridden in the application’s **zcl\_options.h** file, as indicated in [Appendix B.3.1](compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a).

A server that supports automatic attribute reporting should have the ‘reportable flag’ E\_ZCL\_AF\_RP set for any attributes that are reportable. While creating a cluster instance, the **vZCL\_SetDefaultReporting\(\)** function should be called, which will set the ‘default reporting flag’ E\_ZCL\_ACF\_RP to enable default reporting for all the attributes that have the E\_ZCL\_AF\_RP flag set. If a server receives a ‘configure reporting’ command for an attribute that does not have E\_ZCL\_ACF\_RP flag set, it will return an error and not allow the attribute to be reported. This bit setting is also required for attribute reports generated through calls to the function **eZCL\_ReportAllAttributes\(\)**.

Attribute definitions will normally have the ‘reportable flag’ set only for the mandatory reportable attribute. The application on the server can set the E\_ZCL\_ACF\_RP flag for those attributes on which reporting is not mandatory. This can be done using the function **eZCL\_SetReportableFlag\(\)**.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

