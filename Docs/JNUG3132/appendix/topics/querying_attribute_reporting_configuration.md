# Appendix B.6: Querying attribute reporting configuration

Any authorised device in a ZigBee wireless network can obtain the attribute reporting configuration of a cluster server. Such a query follows the process below:

1. The cluster client sends a ‘read reporting configuration’ command to the server.

2. The server receives and processes the command, retrieves the required configuration information and generates a ‘read reporting configuration’ response, which it sends back to requesting client.

3. The client receives the ‘read reporting configuration’ response and the ZCL generates events to inform the application of the reporting configuration.

These steps are described separately below.

## Sending a ‘Read Reporting Configuration’ Command \(from Client\) 

The application on the cluster client device can request the attribute reporting configuration on the server using **eZCL\_SendConfigureReportingCommand\(\)**. This function sends a ‘read reporting configuration’ command to the server.

In this function call, a `tsZCL_AttributeReadReportingConfigurationRecord` structure must be specified which indicates the required configuration information - this structure includes a pointer to an array of records, one per attribute for which reporting configuration information is needed \(see [Section 6.1.7](../../ZCL_structures/topics/tszcl_attributereadreportingconfigurationrecord.md#id_56f15456-6c97-48b3-a90b-1f697c28b53a)\).

## Receiving a ‘Read Reporting Configuration’ Command \(on Server\) 

The server automatically processes an incoming ‘read reporting configuration’ command without assistance from the application. Callback events are not generated. However, the server generates a ‘read reporting configuration’ response and send it back to the requesting client.

## Receiving a ‘Read Reporting Configuration’ Response \(on Client\)

A ‘read reporting configuration’ response from the cluster server contains an Attribute Reporting Configuration Record for each attribute that was included in the corresponding ‘read reporting configuration’ command. For each attribute in the response, the ZCL on the client generates an event of the type:

E\_ZCL\_CBET\_REPORT\_READ\_INDIVIDUAL\_ATTRIBUTE\_CONFIGURATION\_RESPONSE

In the `tsZCL_CallBackEvent` structure \(see [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1)\) for this event, the `uMessage` field contains a structure of the type `tsZCL_AttributeReportingConfigurationResponse` \(see [Section 6.1.6](../../ZCL_structures/topics/tszcl_attributereportingconfigurationresponse.md#id_a270eb1c-242e-476a-a02b-614926e23e4f)\) - this is the same structure as used in attribute reporting configuration, described in [Appendix B.3.5](configuring_automatic_attribute_reports_from_clien.md#id_a5332bea-91c9-42be-aa55-63eb5b644490).

In this structure:

-   The `eCommandStatus` field indicates the status of the request.

-   The `tsZCL_AttributeReportingConfigurationRecord` structure \(see [Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\) includes:

    -   `u16AttributeEnum` which identifies the attribute

    -   other fields containing the attribute reporting configuration information


Once the above event has been generated for each valid attribute in the response, a single E\_ZCL\_CBET\_REPORT\_READ\_ATTRIBUTE\_CONFIGURATION\_RESPONSE event is generated to conclude the response.

**Parent topic:**[Appendix B: Attribute reporting](../../appendix/topics/attribute_reporting.md)

