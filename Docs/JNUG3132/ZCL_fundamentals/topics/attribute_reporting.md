# Attribute Reporting

A cluster client can poll the value of an attribute on the cluster server by sending a ‘read attributes’ request, as described in [Section 2.3.2](reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae). Alternatively, the server can issue unsolicited attribute reports to the client using the ‘attribute reporting’ feature \(in which case there is no need for the client to request attribute values\).

The attribute reporting mechanism reduces network traffic compared with the polling method. It also allows a sleeping server to report its attribute values while it is awake. Attribute reporting is an optional feature and is not supported by all devices.

An ‘attribute report’ \(from server to client\) can be triggered in one of the following ways:

-   by the user application \(on the server device\)

-   automatically \(triggered by a change in the attribute value or periodically\)


Automatic attribute reporting for an attribute can be enabled and configured remotely from the client or, for some attributes, locally on the server \(see below\). If it is required, automatic attribute reporting must be enabled at compile-time on both the cluster server and client. Automatic attribute reporting is more fully described in [Appendix B.1](../../appendix/topics/automatic_attribute_reporting.md#id_ff57abcc-c007-4561-ad92-72e73d561f70) and the configuration of attribute reporting is detailed in [Appendix B.3](../../appendix/topics/configuring_attribute_reporting.md#id_8f4a2099-2cfd-4173-ae40-941bc28e2989).

The ZCL specification states that certain attributes of a cluster must be reportable. Attribute reporting for these attributes remains optional but can be enabled for the individual attributes using a flag \(E\_ZCL\_AF\_RP\) in the attribute definition structure - see the example code for the On/Off cluster in [Section 2.3.1](attribute_access_permissions.md#id_b9c8257a-3935-4e57-a73d-26b186de0b60). This defines those attributes that the cluster server will report by default, known as ‘default reporting’, but reports on other attributes can be requested/configured by the cluster client.

**Note:** Attribute reporting configuration data should be preserved in Non-Volatile Memory \(NVM\) to allow automatic attribute reporting to resume following a reset of the server device. Persisting this data in NVM is described in [Appendix B.7](../../appendix/topics/storing_an_attribute_reporting_configuration.md#id_bb145e35-b98e-4c1b-9144-cbc7de57f069).

An attribute report can be issued directly by the server application as follows:

-   For all reportable attributes using the function **eZCL\_ReportAllAttributes\(\)**

-   For an individual reportable attribute using the function **eZCL\_ReportAttribute\(\)**


Only standard attributes can be reported \(this does not include manufacturer-specific attributes\) and only those attributes for which reporting has been enabled. This method of attribute reporting does not require any configuration, apart from enabling reports for the desired attributes. In this case, attribute reporting does not need to be enabled at compile-time on the server, but it still needs to be enabled at compile-time on the client to allow the client to receive attribute reports.

Sending an attribute report from the server is further described in [Appendix B.4](../../appendix/topics/sending_attribute_reports.md#id_42d44dc8-5502-479c-a256-c8cc7a4b7807) and receiving an attribute report on the client is described in [Appendix B.5](../../appendix/topics/receiving_attribute_reports.md#id_7d67801f-7339-466c-afe7-d946f508aeb1).

**Parent topic:**[Accessing Attributes](../../ZCL_fundamentals/topics/accessing_attributes.md)

