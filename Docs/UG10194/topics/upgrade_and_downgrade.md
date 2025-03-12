# Upgrade and downgrade

The decision to accept an image following a query response is under the control of the application. The code, as supplied, accepts an upgrade or a downgrade. As long as the notified image has the right credentials and a version number, which is different from the current version number, the image is downloaded.

For example, if a client is running a v3 image and a server is loaded with a v2 image then the v2 image is downloaded. The application callbacks the function responsible for handling the image in the following two scenarios:

-   When the client is required to accept only the upgraded images \(v2 \> v3 \> v5\)
-   When the client is required to accept only the sequential upgrade images \(v2 \> v3 \> v4 \> v5\)

.

**Parent topic:**[ZigBee over-the-air upgrade](../topics/zigbee_over-the-air_ota_upgrade.md)

