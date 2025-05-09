# B.3.8: Speeding Up Automatic Attribute Reports

Automatic attribute reports \(configured as described in [Appendix B.3.5](configuring_automatic_attribute_reports_from_clien.md#id_a5332bea-91c9-42be-aa55-63eb5b644490)\) that are produced on changes in attribute values can be speeded up to occur with millisecond resolution. Normally, these reports can occur on a timescale of seconds, as they are dependent on the E\_ZCL\_CBET\_TIMER \(one second\) ticks for sampling. However, they can be made to occur on a timescale of milliseconds by providing E\_ZCL\_CBET\_TIMER\_MS \(one millisecond\) ticks.

In order to do this, the following code must be included in the application:

```
sCallBackEvent.eEventType = E_ZCL_CBET_TIMER_MS; 
vZCL_EventHandler(&sCallBackEvent);

```

Note that the E\_ZCL\_CBET\_TIMER ticks still need to be generated, as they are used by UTC time and by the ZCL report manager to keep track of time.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

