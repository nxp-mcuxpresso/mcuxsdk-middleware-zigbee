# Appendix B.4: Sending attribute reports

If automatic attribute reporting has been configured between the cluster server and a client \(as described in [Appendix B.3](configuring_attribute_reporting.md#id_8f4a2099-2cfd-4173-ae40-941bc28e2989)\), the reporting of the relevant attributes will begin immediately after configuration. Attribute reports are automatically generated:

-   periodically with the configured time-interval between consecutive reports

-   when the attribute value changes by at least the configured minimum amount


Automatic reporting normally employs both of the above mechanisms simultaneously but can be configured to operate without periodic reporting, if required.

If a periodic report becomes overdue, the event E\_ZCL\_CBET\_REPORT\_TIMEOUT is generated on the server.

The application on the server can also generate an attribute report, when needed, by calling one of the following functions:

-   **eZCL\_ReportAllAttributes\(\)**, which sends an attribute report for all the reportable attributes

-   **eZCL\_ReportAttribute\(\)**, which sends an attribute report for an individual reportable attribute


The above functions send an attribute report containing the current attribute value\(s\) to one or more clients specified in the function call. Only the standard attributes can be reported - this does not include manufacturer-specific attributes. Use of these functions for attribute reporting requires no special configuration on the server \(but a recipient client will need attribute reporting to be enabled in its compile-time options\).

**Note:** The event E\_ZCL\_CBET\_REPORT\_REQUEST is automatically generated on the server before sending an attribute report, allowing the application to update the attribute values in the shared structure, if required.

CAUTION:

The application must not rely on the above event as a prompt to update the shared structure when an attribute changes its value. The event is only generated when the change in attribute value is large enough for an attribute report to be produced. Smaller changes will not result in the event or a report.

**Parent topic:**[Appendix B: Attribute reporting](../../appendix/topics/attribute_reporting.md)

