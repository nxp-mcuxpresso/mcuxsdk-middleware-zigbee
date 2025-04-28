# Clearing stack context data before a rejoin

If a node rejoins the same secured network \(with ZigBee PRO security enabled\) but its stack context data was cleared before the rejoin \(by calling **_NvErase_\(\)**\), data sent by the node will be rejected by the destination node since the frame counter has been reset on the source node - frame counters are described in [Section 2.8](secure_operating_environment.md) and [Appendix A](implementation_of_frame_counters.md).

-   Sent data will be accepted again by the destination node when the frame counter for the source node reaches its last count known before the rejoin. Therefore, you are not recommended to clear the stack context data before a rejoin.

However, it is worth noting that frame counters are reset across the entire network when a new network key is broadcast by the Trust Centre using the function **ZPS\_eAplZdoTransportNwkKey\(\)** - see [Section 6.8.4](security_key_modification.md). Thus, if stack context data is cleared before a rejoin, the frame counter problem can be avoided by broadcasting a new network key from the Trust Centre \(normally the Coordinator\) immediately after the rejoin.

To restore the stack to a default state and not clear the frame counters **`ZPS\_vDefaultStack`** should be used - see [Section 7.1.1](network_deployment_functions.md).

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

