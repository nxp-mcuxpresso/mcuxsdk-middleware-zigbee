# Device permissions

The function **zps\_eAplZdoSetDevicePermission\(\)** allows certain permissions to be set on the local device. These permissions are as follows:

**Device permissions**

|**Enumeration**|**Description**|
|---------------|---------------|
|zps\_DEVICE\_PERMISSIONS\_ALL\_PERMITED|Allow all requests from other nodes|
|zps\_DEVICE\_PERMISSIONS\_JOIN\_DISALLOWED|Do not allow join requests from other nodes|
|zps\_DEVICE\_PERMISSIONS\_DATA\_REQUEST\_DISALLOWED|Do not allow data requests from other nodes and disable end-to-end acknowledgments|

When a device joins the network, the ALL\_PERMITED option is set by default, so the device can respond to requests from other nodes.

However, if the network employs security set up using the ZigBee Key Establishment cluster \(for example, a Smart Energy network\), it is necessary to disallow data requests and end-to-end acknowledgments on the newly joined node during the key establishment process. The application must do this as follows:

1.  Once an event has occurred to indicate that the device has joined the network \(the event zps\_EVENT\_NWK\_JOINED\_AS\_ROUTER or zps\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE\), the application must disallow data requests and APS end-to-end acknowledgments by calling **zps\_eAplZdoSetDevicePermission\(\)** with the option DATA\_REQUEST\_DISALLOWED.
2.  The key establishment process can then be started using the function provided for the Key Establishment cluster.
3.  Once the key establishment process has successfully completed, data requests and APS end-to-end acknowledgments can be allowed again by calling **zps\_eAplZdoSetDevicePermission\(\)** with the ALL\_PERMITED option.

The key establishment process and associated resources are fully described in the documentation for the Key Establishment cluster \(for example, in the *ZigBee Smart Energy User Guide\)*.

**Parent topic:**[Advanced features](../topics/advanced_features.md)

