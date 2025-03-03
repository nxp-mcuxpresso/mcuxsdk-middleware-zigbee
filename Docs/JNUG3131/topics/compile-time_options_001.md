# Compile-time Options

Compile-time options can be configured through definitions in the file **bdb\_options.h**. This option allows custom values to be defined for ZigBee Base Device attributes and constants. If the value of an attribute or constant is not defined in this file, the default value for the attribute or constant is used.

## Attributes 

The following macros can be used to pre-configure values for the ZigBee Base Device attributes \(listed and described in [Section 2.5.1](attributes.md#ID_B7F86901-30A4-44E5-8C11-E17BF8CEBC8F)\):

-   BDB\_COMMISSIONING\_GROUP\_ID

-   BDB\_COMMISSIONING\_MODE

-   BDB\_COMMISSIONING\_STATUS

-   BDB\_JOINING\_NODE\_EUI64

-   BDB\_JOIN\_USES\_INSTALL\_CODE\_KEY

-   BDB\_NODE\_JOIN\_LINK\_KEY\_TYPE

-   BDB\_PRIMARY\_CHANNEL\_SET

-   BDB\_SCAN\_DURATION

-   BDB\_SECONDARY\_CHANNEL\_SET

-   BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS

-   BDB\_TC\_LINK\_KEY\_EXCHANGE\_ATTEMPTS\_MAX

-   BDB\_TC\_LINK\_KEY\_EXCHANGE\_METHOD

-   BDB\_TRUST\_CENTER\_NODE\_JOIN\_TIMEOUT

-   BDB\_TRUST\_CENTER\_REQUIRE\_KEYEXCHANGE


For example, to set the maximum number of key establishment attempts to 5, include the following line:

```
#define BDB_TC_LINK_KEY_EXCHANGE_ATTEMPTS_MAX5

```

## Constants 

The following macros can be used to set values for the ZigBee Base Device constants \(listed and described in [Section 2.5.2](constants.md#ID_CB648524-D2DB-4870-A0F0-C766A7E87AA0)\):

-   BDBC\_MAX\_SAME\_NETWORK\_RETRY\_ATTEMPTS

-   BDBC\_MIN\_COMMISSIONING\_TIME

-   BDBC\_REC\_SAME\_NETWORK\_RETRY\_ATTEMPTS

-   BDBC\_TC\_LINK\_KEY\_EXCHANGE\_TIMEOUT

-   BDBC\_TL\_INTERPAN\_TRANS\_ID\_LIFETIME

-   BDBC\_TL\_MIN\_STARTUP\_DELAY\_TIME

-   BDBC\_TL\_PRIMARY\_CHANNEL\_SET

-   BDBC\_TL\_RX\_WINDOW\_DURATION

-   BDBC\_TL\_SCAN\_TIME\_BASE\_DURATION\_MS

-   BDBC\_TL\_SECONDARY\_CHANNEL\_SET


For example, to set the minimum commissioning time for which a network is open to join to 240 seconds, include the following line:

```
#define BDBC_MIN_COMMISSIONING_TIME240
```

\(this minimum commissioning time should set to a value below 255 seconds\)

**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

