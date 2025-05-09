# B.3.6: Configuring Default Reporting \(on Server\)

Default reporting is a form of automatic reporting for a restricted set of attributes \(see [Appendix B.2](default_reporting.md#id_acce1fe2-421f-4f0b-81f4-89c1cd3d81b1)\). It is configured on the cluster server.

An individual attribute can be configured as potentially reportable through default reporting by setting the ‘reportable flag’ E\_ZCL\_AF\_RP in either of the following ways:

-   The flag can be incorporated in the line for the attribute in the `tsZCL_AttributeDefinition` structure for the cluster server. For example, in the following line of code, attribute reporting is enabled for the `bOnOff` attribute of the On/Off cluster:


```
E_CLD_ONOFF_ATTR_ID_ONOFF, (E_ZCL_AF_RD|E_ZCL_AF_SE|**E\_ZCL\_AF\_RP**), E_ZCL_BOOL,     
    (uint32)(&((tsCLD_OnOff*)(0))->bOnOff),0},

```

-   The flag can be set by the server application by calling the function **eZCL\_SetReportableFlag\(\)**.


The reporting of these attributes can be configured by the server application by calling the function **eZCL\_CreateLocalReport\(\)** for each attribute. The configuration values are similar to those for automatic reporting, described in [Appendix B.3.5](configuring_automatic_attribute_reports_from_clien.md#id_a5332bea-91c9-42be-aa55-63eb5b644490). The reporting configuration is passed to the function in a `sZCL_AttributeReportingConfigurationRecord` structure. The application can then enable default reporting for reportable attributes using the function **vZCL\_SetDefaultReporting\(\)**, which checks whether the E\_ZCL\_AF\_RP flag has been set for each attribute and, if so, sets the ‘default reporting flag’ E\_ZCL\_ACF\_RP.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

