# Adding Device Types

Follow the steps below to add devices:

**_Step 1:_**Right-click on **ZigBee PRO Wireless Network**and select **New Child &gt; Coordinator**from the drop-down menu. This inserts a Coordinator with the minimum necessary child elements.

**_Step 2:_**Add Routers and End Devices in the same way, as required. The network can only have one Coordinator, but as many different Router or End Device types \(that is, running different application features and with different endpoints\) as required.

**_Step 3:_**For each new device, use the **Properties**tab \(bottom pane\) to enter the required top-level parameters. For a sleeping End Device, set **Sleeping**to True \(by right-clicking on the value and using the drop-down box\).

**Note:** To display the advanced properties, click the Advanced tool button to the right of the Properties view tab. Refer to Section 13.4.4 [Setting advanced device parameters](setting_advanced_device_parameters.md). These properties are all set to default values and can be left unchanged, unless specific changes are required.


```{include} ../topics/to_add_a_profile.md
:heading-offset: 3
```

```{include} ../topics/to_add_clusters_to_the_new_profile.md
:heading-offset: 3
```

**Parent topic:**[Using the ZPS Configuration Editor](../topics/using_the_zps_configuration_editor.md)

