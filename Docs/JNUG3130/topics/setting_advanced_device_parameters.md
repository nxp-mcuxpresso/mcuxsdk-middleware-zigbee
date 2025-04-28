# Setting advanced device parameters

You can set the advanced device parameters \(detailed in [Section 12.7](advanced_device_parameters.md)\) for a device as follows:

**_Step 1:_** Click on the relevant device \(for example, Coordinator\) in the **Resource Set** pane.

**_Step 2:_** Click on the **Advanced Device Parameters** button in the tool bar of the lower pane \(indicated below\).

![](../images/image42.jpg)

**_Step 3:_** Edit the relevant parameters in the **Properties** tab of the lower pane.

**_Step 4:_** Save your settings.

The ZigBee PRO R22 version of the stack allows the presence of multiple MAC interfaces. This is to support both 2.4G and 868 MHz frequency bands using the single ZigBee stack. To address this, a MAC interface table needs to be configured in the ZPS Configuration diagram.

The MAC interface list can be found as an option for the node, for example, if you have ZigBee network with a router node. You can select the router node and press the right mouse button to provide the options. The MAC interface list can be found under **New Child &gt; Mac Interface List**.

After adding the MAC interface list, select and right-click on the MAC interface list to provide the options. The MAC interface can be found under **New Child &gt; MAC Interface**.

After adding the MAC interface, the properties can be updated. The default is 2.4G. This default can be kept. The “**Router Allowed**” properties should be set to “**true**”.

**Note:** Users should edit the advanced device parameters in order to change the Extended PAN ID \(APS Use Extended PAN ID parameter\) and the maximum number of children of the Coordinator or Router \(Active Neighbor Table Size parameter\) from the default values - see [Section 6.1.1](starting_the_coordinator.md) and [Section 6.1.2](starting_routers_and_end_devices.md).

**Parent topic:**[Using the ZPS Configuration Editor](../topics/using_the_zps_configuration_editor.md)

