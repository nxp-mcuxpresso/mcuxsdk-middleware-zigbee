# Optional Attributes

The optional attributes of the Time cluster are set as follows:

## i32TimeZone 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_TIME\_ZONE and which indicates the local time-zone.

The local time-zone is expressed as an offset from UTC, where this offset is quantified in seconds. Therefore:

Current local standard time = `utctTime` + `i32TimeZone`

where `i32TimeZone` is negative if the local time is behind UTC.

## u32DstStart 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_DST\_START and which contains the start-time \(in seconds\) for daylight saving for the current year.

If `u32DstStart` is used then `u32DstEnd` and `i32DstShift` are also required.

## u32DstEnd 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_DST\_END and which contains the end-time \(in seconds\) for daylight saving for the current year.

If `u32DstEnd` is used then `u32DstStart` and `i32DstShift` are also required.

## i32DstShift 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_DST\_SHIFT and which contains the local time-shift \(in seconds\), relative to standard local time, that is applied during the daylight saving period \(between `u32DstStart` and `u32DstEnd`\). During this period:

Current local time = `utctTime` + `i32TimeZone` + `i32DstShift`

This time-shift varies between territories, but is 3600 seconds \(1 hour\) for Europe and North America.

If `i32DstShift` is used then `u32DstStart` and `u32DstEnd` are also required.

## u32StandardTime 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_STANDARD\_TIME and which contains the local standard time \(equal to `utctTime` + `i32TimeZone`\).

## u32LocalTime 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_LOCAL\_TIME and which contains the local time taking into account daylight saving, if applicable \(equal to `utctTime` + `i32TimeZone` + `i32DstShift` during the daylight saving period and equal to `u32StandardTime` outside of the daylight saving period\).

## u32LastSetTime 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_LAST\_SET\_TIME and which indicates the most recent UTC time at which the Time attribute \(`utctTime`\) was set, either internally or over the ZigBee network.

## u32ValidUntilTime 

This is an optional attribute which is enabled using the macro CLD\_TIME\_ATTR\_VALID\_UNTIL\_TIME and indicates a UTC time \(later than `u32LastSetTime`\) up to which the Time attribute \(`utctTime`\) value may be trusted.

**Parent topic:**[Attribute Settings](../../Time_cluster/topics/attribute_settings.md)

