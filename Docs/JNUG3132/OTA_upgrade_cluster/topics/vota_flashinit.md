# vOTA\_FlashInit

```
void vOTA_FlashInit(void *pvFlashTable,
    tsNvmDefs *psNvmStruct);

```

## Description 

This function initializes the Flash memory device to be used by the OTA Upgrade cluster. Information about the device must be provided, such as the device type and sector size.

If a custom or unsupported Flash memory device is used then user-defined callback functions must be provided to perform Flash memory read, write, erase and initialization operations \(if an NXP-supported device is used, standard callback functions will be used\):

-   A general set of functions \(for use by all software components\) can be specified through *pvFlashTable*.

-   Optionally, an additional set of functions specifically for use by the OTA Upgrade cluster can be specified in the structure referenced by *psNvmStruct*.


This function must be called after the OTA Upgrade cluster has been created \(after **eOTA\_Create\(\)** has been called either directly or indirectly\) and before any other OTA Upgrade functions are called.

## Parameters 

-   *pvFlashTable*: Pointer to general set of callback functions to perform Flash memory read, write, erase and initialization operations. If using an NXP-supported Flash memory device, set a null pointer to use standard callback functions
-   *psNvmStruct*: Pointer to structure containing information on Flash memory device - see [Section 49.11.4](tsnvmdefs.md#id_74ac02e1-704c-4bd9-bc7e-50f17bc835b2)

## Returns 

-   None

**Parent topic:**[General Functions](../../OTA_upgrade_cluster/topics/general_functions.md)

