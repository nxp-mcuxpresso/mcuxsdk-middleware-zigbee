# Description

This function can be used to remove the current application link key that is used to encrypt and decrypt communications between the local node and the specified ‘partner node’.

The function must be called on both the local node and the partner node. Note that the Trust Centre’s record of the application link key for this pair of nodes remains unchanged.

In the absence of an application link key, communications between these nodes is subsequently secured using the network key.

**Parent topic:**[ZPS\_eAplZdoRemoveLinkKey](../topics/zps_eaplzdoremovelinkkey.md)

