# B.3.5: Configuring Automatic Attribute Reports \(from Client\)

If automatic attribute reporting is to be employed between a cluster server and client, the reporting rules must be configured. These rules include the following parameters for each attribute:

-   Time-interval between consecutive reports in periodic reporting

-   Minimum time-interval between consecutive triggered attribute reports

-   Minimum change in the attribute value that will trigger an attribute report


**Note 1:** Setting the periodic reporting time-interval to the special value of 0x0000 disables periodic reporting for the attribute. Setting this time-interval to the special value of 0xFFFF disables automatic reporting completely \(periodic and triggered\) for the attribute.

**Note 2:** Automatic attributes reports are normally produced on a timescale of seconds. However, reports generated on the change of an attribute value can be speeded up to occur on a timescale of milliseconds, as described in [Appendix B.3.8](speeding_up_automatic_attribute_reports.md#id_cbf1864f-17d4-4690-a0b3-157b8c06cbe4).

**Note 3:** Before automatic reporting can be configured on an attribute, the ‘reportable flag’ must be set for the attribute on the cluster server using the function **eZCL\_SetReportableFlag\(\)**.

This configuration is conducted on the cluster server but is normally directed from a remote device via ‘configure reporting’ commands.

The configuration of automatic attribute reporting follows the process:

1. The client sends a ‘configure reporting’ command to the server.

2. The server receives and processes the command, configures the attribute reporting and generates a ‘configure reporting’ response, which it sends back to the requesting client.

3. The client receives the ‘configure reporting’ response and the ZCL generates events to indicate the status of the request to the client.

These steps are described separately below.

## 1. Sending a ‘Configure Reporting’ Command \(from Client\) 

The application on the cluster client device can configure attribute reporting for a set of attributes on the cluster server using the function **eZCL\_SendConfigureReportingCommand\(\)**. This function sends a ‘configure reporting’ command to the server.

In this function call, a pointer must be provided to an array of `tsZCL_AttributeReportingConfigurationRecord` structures, where each structure contains the configuration details for one attribute on which reporting is to be configured \(see [Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\).

## 2. Receiving a ‘Configure Reporting’ Command \(on Server\) 

The server will automatically process an incoming ‘configure reporting’ command and perform the required configuration without assistance from the application. For each attribute \(in the configuration request\), the reporting configuration values are parsed, after which the ZCL generates an event of the type:

E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE

In the `tsZCL_CallBackEvent` structure \(see [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1)\) for this event:

-   The `uMessage` field contains a structure of the type `tsZCL_AttributeReportingConfigurationRecord` \(see [Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\).

-   The `eZCL_Status` field indicates the outcome of parsing the configuration values for the attribute \(success or failure\)


Thus, the configuration of reporting for a set of attributes will result in a sequence of events of the above type, one for each attribute. The application should copy the contents of the `tsZCL_AttributeReportingConfigurationRecord` structure for each attribute to RAM \(for information on storage format, refer to [Appendix B.7.2](formatting_an_attribute_reporting_configuration_re.md#id_db6af465-b641-4d27-890f-e09f3f861493)\).

Note that the `tsZCL_AttributeReportingConfigurationRecord` structure for an attribute contains the field `u16MaximumReportingInterval` which specifies a time-period for periodic reporting. Periodic reporting should not be too frequent, since a sleepy device must wake to send a report and frequent reports are be a significant drain on power resources. Therefore, the period for periodic reporting is not allowed to be set to a value less than `sConfig.u16SystemMaximumReportingInterval` in the ZCL configuration \(see [Appendix B.3.7](zcl_configuration_for_attribute_reporting.md#id_dbc32ec9-5df8-41f1-ba42-e6f373ed2a88)\). If a ‘configure reporting’ command attempts to set a smaller \(non-zero\) value, the ZCL discards the reporting configuration for this attribute and set the status for this attribute configuration to E\_ZCL\_CMDS\_INVALID\_VALUE in the ‘configure reporting’ response \(see below\).

Once attribute reporting has been configured \(or not\) for all the attributes \(in the request\), a single event is generated of the type:

E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE

Finally, the server generates a ‘configure reporting’ response and sends it back to the requesting client.

**Note:** The application and ZCL hold the attribute reporting configuration data in RAM. To preserve this data through episodes of power loss, the application should also save the data to NVM, as described in [Appendix B.7](storing_an_attribute_reporting_configuration.md#id_bb145e35-b98e-4c1b-9144-cbc7de57f069).

## 3. Receiving a ‘Configure Reporting’ Response \(on Client\) 

A ‘configure reporting’ response from the cluster server contains an Attribute Status Record for each attribute that was included in the corresponding ‘configure reporting’ command. For each attribute in the response, the ZCL on the client generates an event of the type:

E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE\_RESPONSE

In the `tsZCL_CallBackEvent` structure \(see [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1)\) for this event, the `uMessage` field contains a structure of the type `tsZCL_AttributeReportingConfigurationResponse` \(see [Section 6.1.6](../../ZCL_structures/topics/tszcl_attributereportingconfigurationresponse.md#id_a270eb1c-242e-476a-a02b-614926e23e4f)\). In this structure:

-   The `eCommandStatus` field indicates the status of the attribute reporting configuration for the attribute.

-   The `tsZCL_AttributeReportingConfigurationRecord` structure \([Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\) contains other data but only the following fields are used:

    -   `u16AttributeEnum` which identifies the attribute

    -   `u8DirectionIsReceived` which should read 0x01 to indicate that reports of the attribute value are received by the client


Once the above event has been generated for each valid attribute in the response, a single E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE\_RESPONSE event is generated to conclude the response.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

