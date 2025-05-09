# Persisting an attribute reporting configuration

The attribute reporting configuration data is stored in RAM on the cluster server. To allow the server device to recover from an interruption of service involving a loss of power, this configuration data should also be saved in Non-Volatile Memory \(NVM\). In this case, the attribute reporting configuration data can be recovered from NVM during a ‘cold start’ of the device and automatic attribute reporting can resume without further configuration.

The storage of attribute reporting configuration data in NVM should be performed during the updates of this data on the server, described in [Appendix B.3.5](configuring_automatic_attribute_reports_from_clien.md#id_a5332bea-91c9-42be-aa55-63eb5b644490). When an E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE event is generated for an attribute, the contents of the incorporated structure `tsZCL_AttributeReportingConfigurationRecord` should be saved to NVM as well as to RAM \(for information on storage format, refer to [Appendix B.7.2](formatting_an_attribute_reporting_configuration_re.md#id_db6af465-b641-4d27-890f-e09f3f861493)\). Data storage in NVM can be performed under application control using the Non-Volatile Memory Manager \(NVM\), described in the *Connectivity Framework Reference Manual*.

On a ‘cold start’ of the device, the application must retrieve the Attribute Reporting Configuration Record for each attribute from NVM and update the ZCL with the reporting configuration \(this must be done after the ZCL has been initialized\). To do this, the NVM can be used to retrieve the configuration record for an attribute and the function **eZCL\_CreateLocalReport\(\)** must then be called to register this data with the ZCL. This function must not be called for attributes that have not been configured for automatic attribute reporting \(e.g. those for which the maximum reporting interval is set to REPORTING\_MAXIMUM\_TURNED\_OFF\).

**Note:** The maximum reporting interval in NVM must be set to REPORTING\_MAXIMUM\_TURNED\_OFF \(0xFFFF\) during a factory reset in order to prevent reporting from being enabled for attributes for which reporting was not previously enabled.

**Parent topic:**[Appendix B.7: Storing an attribute reporting configuration](../../appendix/topics/storing_an_attribute_reporting_configuration.md)

