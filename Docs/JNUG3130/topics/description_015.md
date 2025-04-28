# Description

This function can be used to request a link key from the Trust Centre for application-level security. The possible key types that can be requested are:

-   **Application link key:** This key is used to encrypt/decrypt communications with another ‘partner node’. The IEEE/MAC address of this partner node must be specified as part of the function call. The Trust Centre responds by sending the application link key to both the local node and the partner node. When it arrives, the stack automatically saves this key. Also, the event ZPS\_EVENT\_ZDO\_LINK\_KEY is generated once the link key has been installed and is ready for use.
-   **Trust Centre Link Key \(TCLK\):** This key is used to encrypt/decrypt communications between the Trust Centre and the local node. The Trust Centre responds by sending the TCLK to the requesting node.

While requesting a TCLK, the function parameter *u64IeeePartnerAddr*is ignored.

For more information on requesting link keys, refer to [Section 6.8.3.2](application-level_security_set-up.md).

**Parent topic:**[ZPS\_eAplZdoRequestKeyReq](../topics/zps_eaplzdorequestkeyreq.md)

