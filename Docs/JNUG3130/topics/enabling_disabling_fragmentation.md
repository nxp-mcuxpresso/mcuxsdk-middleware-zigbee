# Enabling/disabling fragmentation

In order to allow fragmented data transfers between two nodes, you must appropriately configure two ZigBee network parameters:

-   Set the parameter *Maximum Number of Transmitted Simultaneous Fragmented Messages*to a non-zero value on the sending node, to allow transmitted messages to be fragmented.
-   Set the parameter *Maximum Number of Received Simultaneous Fragmented Messages*to a non-zero value on the receiving node, to allow received fragmented messages to be re-assembled.

**Note:** Setting either of these parameters to zero would disable the corresponding fragmentation feature but reduce the size of your compiled application code.

**Parent topic:**[Fragmented data transfers](../topics/fragmented_data_transfers.md)

