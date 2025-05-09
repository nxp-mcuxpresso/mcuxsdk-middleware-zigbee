# Low-Voltage Flag

An OTA Upgrade cluster client should not attempt to participate in an OTA upgrade if the supply voltage to the host hardware device is low \(below the normal operating voltage for the device\). On the device, sufficient voltage is required to write to the internal Flash There may be a number of reasons for a sudden drop in supply voltage - for example, the voltage on a battery-powered node may fall when the battery is near the end of its life.

The OTA Upgrade cluster incorporates a mechanism which, if enabled, stops the cluster client from sending Image Block Requests to the server when the local supply voltage becomes low. This mechanism allows the application to set a low-voltage flag which, when set, automatically suspends the block requests. When the flag is cleared, the block requests are automatically resumed.

If required, use of the low-voltage flag and associated mechanism must be enabled at compile-time by including the following line in the **zcl\_options.h** file:

```
#define OTA_UPGRADE_VOLTAGE_CHECK

```

It is the responsibility of the application to check the supply voltage. This check is system-specific and may be performed periodically or using a voltage monitoring feature - for example, on the device, the Supply Voltage Monitor \(SVM\) can be used, which is described in the MCUXpresso SDK API Reference Manual.

The application can use the function **vOTA\_SetLowVoltageFlag\(\)** to configure the low-voltage flag. This function is detailed in [Section 49.10.3](client_functions.md#id_ef35b87a-56ee-40c5-b17b-2f42538047a4).

When a low voltage is detected, the application should make the following function call to set the low-voltage flag and suspend Image Block Requests:

```
vOTA_SetLowVoltageFlag(TRUE);

```

When the voltage is restored to a normal level, the application should make the following function call to clear the low-voltage flag and resume Image Block Requests:

```
vOTA_SetLowVoltageFlag(FALSE);

```

**Parent topic:**[Ancillary Features and Resources for OTA Upgrade](../../OTA_upgrade_cluster/topics/ancillary_features_and_resources_for_ota_upgrade.md)

