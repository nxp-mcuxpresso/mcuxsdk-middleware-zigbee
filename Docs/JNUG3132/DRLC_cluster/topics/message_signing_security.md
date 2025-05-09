# Message Signing \(Security\)

As a security measure, Report Event Status messages can be signed by the DRLC cluster client for non-repudiation purposes \(to provide the utility company with evidence that the cluster client sent the message\). On the DRLC cluster client, the process involves generating a hash value which is based on the content of the message, then using this value in combination with a device’s private key to generate a signature, which is then appended to the message to be sent to the ESP.

Upon message reception on the ESP, the hash value is recalculated based on the received message and then used in conjunction with the public key of the message originator \(derived from the originator’s certificate\) to check the appended signature. To facilitate this checking, the ESP must store the certificates of any nodes that send Report Event Status messages which require verification.

**Note:**

1.  It is recommended that signatures are supported by applications for backward compatibility.
2.  Signature fields are included in the Report Event Status structure, detailed in [Section 41.11.4](tsse_drlcreportevent.md#id_ad267160-eaa3-467d-b21b-caa82083dbd5).

Message signing must be enabled at compile-time, as described in [Section 41.12](compile-time_options.md#id_d99a7a68-c962-4f54-ab8a-35b360dbb023).

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

