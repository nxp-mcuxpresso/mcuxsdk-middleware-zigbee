# vOTA\_SetLowVoltageFlag

```
void vOTA_SetLowVoltageFlag(bool bValue);

```

## Description 

This function can be used to configure the low-voltage flag on a node hosting an OTA Upgrade cluster client. This flag should be set when the supply voltage to the underlying hardware is below that required for normal operation and the node should not participate in an OTA upgrade.

-   When the flag is set, the client stops sending Image Block Requests to the server

-   When the flag is cleared, the client resumes sending Image Block Requests to the server


Use of the low-voltage flag must be enabled at compile-time by including the macro OTA\_UPGRADE\_VOLTAGE\_CHECK in the **zcl\_options.h** file.

Use of the low-voltage flag is described further in [Section 49.8.7](low-voltage_flag.md#id_ef715ebe-050f-4c2d-9afc-6512764fed4d).

## Parameters 

-   *bValue*: Determines the state of the low-voltage flag, as follows:
    -   TRUE - Sets the flag
    -   FALSE - Clears the flag

## Returns 

-   None

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

