# Touchlink constants

The table below lists the ZigBee Base Device constants that can be used on nodes that support Touchlink commissioning and also shows the corresponding macros used to define the constant values in the **bdb\_options.h** file.<br>

  ZBD Touchlink Constants and |      Macros                         |
| ---------------------------------- | ---------------------------------- |
| **Constant**                           | **Macro**                             |
| bdbcTLInterPANTransIdLifetime      | BDBC_TL_INTERPAN_TRANS_ID_LIFETIME |
| bdbcTLMinStartupDelayTime          | BDBC_TL_MIN_STARTUP_DELAY_TIME     |
| bdbcTLPrimaryChannelSet            | BDBC_TL_PRIMARY_CHANNEL_SET        |
| bdbcTLRxWindowDuration             | BDBC_TL_RX_WINDOW_DURATION         |
| bdbcTLScanTimeBaseDuration         | BDBC_TL_SCAN_TIME_BASE_DURATION_MS |
| bdbcTLSecondaryChannelSet          | BDBC_TL_SECONDARY_CHANNEL_SET      |


## bdbcTLInterPANTransIdLifetime 

This constant specifies the maximum length of time \(in seconds\) that an inter-PAN transaction ID remains valid. The value of this constant is defined using the macro BDBC\_TL\_INTERPAN\_TRANS\_ID\_LIFETIME and should be set to 8 \(as recommended in the ZigBee BDB Specification\).

## bdbcTLMinStartupDelayTime 

This constant specifies the length of time \(in seconds\) that a Touchlink initiator waits for the target to complete its network start-up procedure. The value of this constant is defined using the macro BDBC\_TL\_MIN\_STARTUP\_DELAY\_TIME and should be set to 2 \(as recommended in the ZigBee BDB Specification\).

## bdbcTLPrimaryChannelSet 

This constant specifies the bitmap for the primary \(first-choice\) set of 2.4 GHz radio channels that is used for a non-extended Touchlink scan. The value of this constant is defined using the macro BDBC\_TL\_PRIMARY\_CHANNEL\_SET and should be set to 0x02108800, corresponding to channels 11, 15, 20 and 25 \(as recommended in the ZigBee BDB Specification\).

## bdbcTLRxWindowDuration 

This constant specifies the maximum duration \(in seconds\) for which the radio receiver of node remains enabled during Touchlink commissioning, in order to receive responses. The value of this constant is defined using the macro BDBC\_TL\_RX\_WINDOW\_DURATION and should be set to 5 \(as recommended in the ZigBee BDB Specification\).

## bdbcTLScanTimeBaseDuration 

This constant specifies the base duration \(in milliseconds\) for which the radio receiver of node remains enabled after transmitting a scan request during a Touchlink scan operation, in order to receive responses. The value of this constant is defined using the macro BDBC\_TL\_SCAN\_TIME\_BASE\_DURATION\_MS and should be set to 250 \(as recommended in the ZigBee BDB Specification\).

## bdbcTLSecondaryChannelSet 

This constant specifies the bitmap for the secondary \(second-choice\) set of 2.4 GHz radio channels that is used for an extended Touchlink scan. It should contain the channels that remain from those specified in *bdbcTLPrimaryChannelSet*. The value of this constant is defined using the macro BDBC\_TL\_SECONDARY\_CHANNEL\_SET and should be set to 0x07FFF800 XOR BDBC\_TL\_PRIMARY\_CHANNEL\_SET.

**Parent topic:**[Constants](../topics/constants.md)

