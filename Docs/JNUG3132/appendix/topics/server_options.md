# B.3.2: Server Options

## Generate Attribute Reports 

To enable a server to generate attribute reports according to configured reporting rules, add the following option:

```
#define ZCL_ATTRIBUTE_REPORTING_SERVER_SUPPORTED

```

**Note:** Attribute reporting does not need to be enabled with this macro if the reports are generated only via function calls.

## Handle ‘Configure Reporting’ Commands 

To enable a server to handle ‘configure reporting’ commands and reply with ‘configure reporting’ responses, add the following option:

```
#define ZCL_CONFIGURE_ATTRIBUTE_REPORTING_SERVER_SUPPORTED

```

## Handle ‘Read Reporting Configuration’ Commands 

To enable a server to handle ‘read reporting configuration’ commands and reply with ‘read reporting configuration’ responses, add the following option:

```
#define ZCL_READ_ATTRIBUTE_REPORTING_CONFIGURATION_SERVER_SUPPORTED

```

## Number of Attribute Reports 

The number of reportable attributes can be set \(to n\) using the following line:

```
#define ZCL_NUMBER_OF_REPORTS   n

```

The default value is 10.

## Number of String Attribute Reports 

The number of reportable string attributes can be set \(to n\) using the following line:

```
#define ZCL_NUMBER_OF_STRING_REPORTS   n

```

The default value is 0 \(meaning that string attribute reports are disabled by default\).

## Maximum Size of Reportable String Attribute 

The maximum size, in bytes, of a string attribute that can be reported can be set \(to n\) using the following line:

```
#define ZCL_ATTRIBUTE_REPORT_STRING_MAXIMUM_SIZE   n

```

The default value is 32 bytes.

## Minimum Attribute Reporting Interval 

The minimum time-interval, in seconds, between consecutive attribute reports can be set \(to n\) using the following line:

```
#define ZCL_SYSTEM_MIN_REPORT_INTERVAL   n

```

The default value is 1 second.

## Maximum Attribute Reporting Interval 

The maximum time-interval, in seconds, between consecutive attribute reports can be set \(to n\) using the following line:

```
#define ZCL_SYSTEM_MAX_REPORT_INTERVAL   n

```

The default value is 61 seconds.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

