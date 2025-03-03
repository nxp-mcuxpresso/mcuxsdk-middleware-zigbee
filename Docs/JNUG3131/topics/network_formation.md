# Network Formation

Network Formation allows a new network to be created by a Coordinator or Router.

-   A Coordinator forms a centralized security network \(see [Section 2.3.1](centralised_security_networks.md#ID_961AFDAD-E2FD-4FE8-9C14-BBDDEEB660BA)\) and activate its Trust Centre functionality.

-   A Router forms a distributed security network \(see [Section 2.3.2](distributed_security_networks.md#ID_C8FD35B2-DA5D-4F5E-89D5-066C08482DDB)\).


If Network Formation is required on a node, enable it via the attribute *u8bdbCommissioningMode*. You can start Network Formation from your application by calling the function **BDB\_eNfStartNwkFormation\(\)**.

The node performs a scan of the primary set of radio channels specified through the *u32bdbPrimaryChannelSet* bitmap \(attribute\) to form a centralized or distributed network with a unique PAN ID on one of the free primary channels. If this network formation fails or the primary channel bitmap is set to zero, the node performs a scan of the secondary set of radio channels. these radio channels are specified through the *u32bdbSecondaryChannelSet* bitmap \(attribute\) to form a centralized or distributed network with a unique PAN ID on one of the free secondary channels.

During the formation of a distributed security network by a Router:

-   The above channel scans start with the first channel of the relevant set and cover all the specified channels.

-   If the macro RAND\_CHANNEL is TRUE \(in the application\), a channel is selected at random from the scanned channels.

-   The macro RAND\_DISTRIBUTED\_NWK\_KEY is set to TRUE to choose a network key at random \(but may be set to FALSE during application development in order to use a specific network key\).

-   The PAN ID and Extended PAN ID are allocated at random \(but must not clash with the other networks operating in the neighbourhood\).

-   The 16-bit network address of the local is allocated at random.


In all cases, successful Network Formation is indicated by the event BDB\_EVENT\_NWK\_FORMATION\_SUCCESS through the callback function **APP\_vBdbCallback\(\)**. The unsuccessful Network Formation is indicated by the event BDB\_EVENT\_NWK\_FORMATION\_FAILURE.

If Network Formation is successful, the new network consists of just one node. Further nodes are added to the network using Network Steering \(see [Network steering](network_steering.md#)\) or Touchlink \(see [Touchlink](touchlink.md)\).

**Parent topic:**[Network commissioning](../topics/network_commissioning.md)

