# Network key modification

It is possible to store more than one network key on a node, although only one key can be active at any one time. Each network key is identified by means of a unique ‘key sequence number’ assigned by the Trust Centre application.

A new network key can be installed in a node in one of two ways:

-   Distributed by the Trust Centre to one or multiple nodes of the network using the function **zps\_eAplZdoTransportNwkKey\(\)**, which requires the associated key sequence number to be specified
-   Requested from the Trust Centre by calling the function

**zps\_eAplZdoRequestKeyReq\(\)** on the node that needs the network key

On reaching its destination\(s\), the transported key is automatically saved but not activated. A stored network key can be adopted as the active key using the function **zps\_eAplZdoSwitchKeyReq\(\)**, which is called on the Trust Centre and which identifies the required key by means of its unique sequence number.

**Parent topic:**[Security key modification](../topics/security_key_modification.md)

