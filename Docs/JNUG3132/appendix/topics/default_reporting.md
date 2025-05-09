# Appendix B.2: Default reporting

For each cluster, the ZCL specification states that certain attributes must be reportable. These attributes are specified in the cluster descriptions in this manual. Reports on these attributes are optional and can be enabled on an individual basis using a ‘reportable flag’, as described in [Appendix B.3.6](configuring_default_reporting_on_server.md#id_0ee5c3fa-71ff-4e90-8062-e0a7201c793e). The attributes for which the flag is set will always be reported, defining a set of attributes for ‘default reporting’.

Default reporting is a form of automatic reporting \(see [Appendix B.1](automatic_attribute_reporting.md#id_ff57abcc-c007-4561-ad92-72e73d561f70)\) for the restricted set of attributes described above. It is configured on the cluster server as described in [Appendix B.3.6](configuring_default_reporting_on_server.md#id_0ee5c3fa-71ff-4e90-8062-e0a7201c793e). The attributes enabled for default reporting are also included in attribute reporting initiated by the server application though a call to the function **eZCL\_ReportAllAttributes\(\)**.

**Parent topic:**[Appendix B: Attribute reporting](../../appendix/topics/attribute_reporting.md)

