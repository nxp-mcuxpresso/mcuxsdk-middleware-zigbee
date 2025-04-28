# Network joining

During network joining, a form of packet filtering is applied to the results of the network discovery phase. Any potential parents that have been discovered are filtered such that nodes with link costs greater than 5 \(low LQI values\) are discarded. This feature aids the formation of networks with strong links between neighbors and is most effective in dense networks. For more information about this process during network joining, refer to the ZigBee specification.

**Parent topic:**[Packet filtering in operation](../topics/packet_filtering_in_operation.md)

