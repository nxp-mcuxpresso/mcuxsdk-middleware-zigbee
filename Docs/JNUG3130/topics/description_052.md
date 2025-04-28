# Description

This function can be used on the Trust Centre to generate a pre-configured unique link key from an install code, where this key is used to encrypt and decrypt communications between the Trust Centre and the specified node \(install codes are described in the *ZigBee Devices User Guide \(JNUG3131\)*\). If a pre-configured link key already exists for the node then it will be replaced.

The function must be called on the Trust Centre only. The other node will have the relevant pre-configured unique link key factory-installed.

If the JCU Non-Volatile Memory Manager \(NVM\) module is enabled, this function also saves the link key to Non-Volatile Memory. This allows the key to be automatically recovered during a subsequent cold start \(for example, following a power failure\).

The *eKeyType*parameter of this function can be used to specify ‘unique’ or ‘global’. This does not relate to the type of key being added or replaced, which is always a unique key.

-   Setting this parameter to ‘unique’ means that the Trust Centre only, ever uses the unique key with this node.
-   Setting the parameter to ‘global’ means that the Trust Centre uses the pre-configured global link key \(if available\) when there is no unique link key for the node.

**Parent topic:**[ZPS\_eAplZdoAddReplaceInstallCodes](../topics/zps_eaplzdoaddreplaceinstallcodes.md)

