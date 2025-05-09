# Auto-Enroll-Request

The Auto-Enroll-Request method of enrollment is described below:

1. After the IAS Zone device joins the network, the CIE device performs a service discovery.

2. If the CIE device determines that it wants to enroll the Zone device, it sends a `Write Attribute` command to the Zone device in order to write its IEEE/MAC address to the relevant attribute.

3. The Zone device may optionally create a binding table entry for the CIE device and store the CIE device’s IEEE/MAC address there.

4. The Zone device sends a `Zone Enroll Request` command to the CIE device.

5. The CIE device assigns a `Zone ID` to the Zone device and sends a `Zone Enroll Response` command to it.

6. The Zone device updates its attributes to stored the assigned Zone ID and update its zone state to ‘enrolled’.

**Note:** The above Auto-Enroll-Request process is similar to the Trip-to-Pair process \(described in [Section 37.3.2](auto-enroll-response.md#id_f832d5a1-1468-45f8-a95a-bae52e661cbb)\) except that user authorization for the enrollment of the Zone device is not required.

**Parent topic:**[Enrollment](../../IAS_Zone_cluster/topics/enrollment.md)

