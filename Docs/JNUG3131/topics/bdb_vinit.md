# BDB\_vInit

```
void BDB_vInit(BDB_tsInitArgs *psInitArgs);
```

## Description 

This function initializes the ZigBee Base Device \(ZBD\) and must be the first ZigBee Base Device function called in your code. The function must be called after initializing the ZigBee PRO stack via a call to **ZPS\_eAplAfInit\(\)**. The ZigBee Base Device attribute *bbdbNodeIsOnANetwork* is restored from persistent storage \(if relevant\) before calling this function.

**Note:** Before calling this function, the application must initialize the required ZigBee software timers using the function **ZTIMER\_eInit\(\)** from the ZigBee PRO Stack libraries. In doing so, it must add a number of timers for internal use by the ZigBee Base Device, where this number is defined by the macro BDB\_ZTIMER\_STORAGE.

The initialization performed by this function includes the following:

-   Sets the ZigBee Base Device attributes to their default values, unless other values are defined by the application in the file **bdb\_options.h**.

-   Registers the ZigBee Base Device message queue passed into this function - this message queue is used by the ZigBee Base Device to capture stack events.

-   Calls **BDB\_vSetKeys\(\)** to set the initial pre-configured security keys \(defined in the file **bdb\_link\_keys.c**\), according to the node type:

    -   For a Coordinator, the Default Global Trust Centre Link Key is set.

    -   For a Router or End Device, both the Default Global Trust Centre Link Key and Distributed Security Global Link Key are set.

-   Opens timers for ZigBee Base Device internal use


For more information on the security keys, refer to [Section 2.3](network_security.md#ID_4C903549-A2A4-4958-A885-54D50242FB72).

## Parameters 

-   *psInitArgs*: Handle of the ZigBee Base Device event queue

## Returns 

-   None

**Parent topic:**[Functions](../topics/functions.md)

