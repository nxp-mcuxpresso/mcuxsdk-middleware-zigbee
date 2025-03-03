# Out-Of-Band Commissioning

A node is commissioned to a ZigBee network via out-of-band means - that is, not using IEEE802.15.4 packets operating in the radio channel used by the target network. For example, the out-of-band commissioning is conducted from another ZigBee device using inter-PAN packets \(operating in a different radio channel\) or by a commissioning device that uses NFC \(Near Field Communication\).

Out-of-band commissioning creates a new network by starting the Coordinator or to join a Router or End Device to an existing network. To do this, commissioning data must be sent to the node via an out-of-band means. This data includes details of the network \(see [Section 2.7.5](bdb_tsoobwritedatatocommission.md#ID_40AA20CC-B50E-4012-AC92-16437AB3A3FB)\). The application must pass the received commissioning data to the ZigBee Base Device and start out-of-band commissioning using the function **BDB\_u8OutOfBandCommissionStartDevice\(\)**. The data is then stored locally.

As part of the out-of-band commissioning of a node to an existing centralized network, the Trust Centre of the joined network must validate the new node by checking that the node contains appropriate data values, such as the correct network key and Trust Centre address. If such a validation request is received by the node, the required data values are obtained by the application in either of two ways:

-   The function **BDB\_vOutOfBandCommissionGetData\(\)** is used to read the relevant data values. In this case, the application should encrypt the obtained network key before sending the data to the Trust Centre. The install code for the node should be used in this encryption.

-   The function **BDB\_eOutOfBandCommissionGetDataEncrypted\(\)** is used to read the relevant data values and encrypt the obtained network key - therefore, the network key is delivered encrypted. The install code for the node used in this encryption must be specified in the function call. The application then sends the obtained data to the Trust Centre.


Once the Trust Centre receives the requested data, it decrypts the obtained network key using the function **BDB\_bOutOfBandCommissionGetKey\(\)** and then checks if the correct key is used. This function requires the install code for the new node, which must be supplied to the Trust Centre via out-of-band means \(for example, via a keypad\).

Security keys and install codes are described in [Section 2.3](network_security.md).

**Parent topic:**[Network commissioning](../topics/network_commissioning.md)

