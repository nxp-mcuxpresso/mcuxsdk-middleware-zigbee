# Frame counters

The use of frame counters prevents sending the same message twice, and freshness checking rejects any such repeated messages, preventing message replay attacks on the network. An example of a replay attack would be someone recording the open command for a garage door opener, and then replaying it to gain unauthorized entry into the property. Frame counters are described in more detail in the Appendix A, [Appendix C: Implementation of frame counters](implementation_of_frame_counters.md).

**Parent topic:**[Secure operating environment](../topics/secure_operating_environment.md)

