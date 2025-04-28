# Acknowledgment timeout

A timeout of approximately 1600 ms is applied to each acknowledgment, measured from the time at which the last data fragment in the relevant group was transmitted - if no acknowledgment is received within this timeout period, the entire group of fragments is automatically re-sent. Up to 3 more re-tries can subsequently be performed. For a fragmented data transfer, the time that elapses before a completely unacknowledged transmission is abandoned is difficult to estimate, since this time depends on the number of fragments, the network parameter *APS Max Window Size*and the network parameter *APS Inter-frame Delay*\(time between transmissions of consecutive fragments\).

**Parent topic:**[Fragmented data transfers](../topics/fragmented_data_transfers.md)

