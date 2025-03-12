# End Device RX On

The table below lists the LED states for End Device RX On.

| LED1                                                                    | LED2                            | Remarks                            |
| ----------------------------------------------------------------------- | ------------------------------- | -------------------------------- |
| OFF                                                                     | OFF                             | The device is not on the network |
| OFF/ON (Current ON/OFF cluster status) or Blinking ON/OFF (Identifying) | Blinking ON/OFF every 250 ms    | Find and Bind active             |
| OFF/ON (Current ON/OFF cluster status) or BlinkingG ON/OFF (Identifying) | Blinking ON/OFF every 2 seconds | OTA aborted or failed            |
| OFF/ON (Current ON/OFF cluster status) or Blinking ON/OFF (Identifying) | Blinking ON/OFF every 500 ms    | OTA in progress                  |

|

**Parent topic:**[LED indication table](../topics/led_indication_table.md)

