# Application-level security set-up

Once network-level security has been set up \(as described in [Section 6.8.3.1](network-level_security_set-up.md)\), application-level security can be set up, if required. In application-level security, the communications between two nodes are encrypted/decrypted using a link key which may be global or unique:

-   <strong>Global link key:</strong> This is shared between all nodes on the network and is pre- configured in all the nodes. Frame counters are not checked for freshness when using a global link key.
-   <strong>Unique link key:</strong> This is exclusive to a pair of nodes that need to communicate privately. It may be a pre-configured unique link key, Trust Centre Link Key \(TCLK\) or application link key. Frame counters are checked for freshness to prevent rogue nodes replaying stale messages. This provides the most secure method of application security.

The different types of link key are described in [Section 6.8.2](security_key_types.md) and summarized in [Table 4](summary_of_api_functionality.md).

In order to set up application-level security with a unique link key between two nodes, the function <strong>zps\_eAplZdoRequestKeyReq\(\)</strong> must be called on one of the nodes to request a link key from the Trust Centre. There are two possibilities:

-   To request a Trust Centre Link Key \(TCLK\) for communication between the local node and the Trust Centre - the Trust Centre will respond with the requested link key
-   To request an application link key for communication with another node that is not the Trust Centre \(in this case, the IEEE/MAC address of the other node must be supplied in the function call\) - the Trust Centre will send the requested link key to both nodes

The Trust Centre will ignore the request if the node is not permitted to send APS secured data. The Trust Centre responses are encrypted as follows:

-   If a link key exists for communications between the Trust Centre and the target node \(for example, a pre-configured link key\), this key and the network key are both used to encrypt the requested link key.
-   Otherwise, only the network key is used to encrypt the requested link key.

On receiving the link key, the ZigBee stack on the node will automatically save the key. The event zps\_EVENT\_ZDO\_LINK\_KEY is generated to indicate that the link key is available. Any subsequent unicast or bound data transfer between these two nodes can opt to use this key \(zps\_E\_APL\_AF\_SECURE\_APL\).

**Note:** An application link key can be introduced directly by the application using the function **zps\_eAplZdoAddReplaceLinkKey\(\)**.

**Note:**

1.  When a link key is used to encrypt a data packet, the packet payload is encrypted at the application level using the link key and then the packet is encrypted at the ZigBee stack NWK layer using the network key \(therefore, both keys are used\).
2.  When application-level security is used in sending data, the IEEE/MAC address and network address of the target node must be available through the local Address Map table - see [Section 6.2.3](obtaining_and_maintaining_node_addresses.md).

**Parent topic:**[Setting up ZigBee security](../topics/setting_up_zigbee_security.md)

