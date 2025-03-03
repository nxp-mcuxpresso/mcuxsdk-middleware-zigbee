# BDB\_bIsBaseIdle

```
bool_t BDB_bIsBaseIdle(void);

```

## Description 

This function determines whether the ZigBee Base Device is busy or idle, and therefore whether the node can enter sleep mode. The function returns a Boolean indicating the activity status of the ZigBee Base Device.

If the ZigBee Base Device is idle and the node can go to sleep \(indicated by TRUE\), it is then the responsibility of the application to put the device into sleep mode.

## Parameters 

-   None

## Returns 

-   TRUE indicates that the ZigBee Base Device is idle and the node can sleep.
-   FALSE indicates that the ZigBee Base Device is busy.

**Parent topic:**[Functions](../topics/functions.md)

