# Parameters

-   *u64IeeeAddr* 64-bit IEEE/MAC address of node for which the generated link key is valid.
-   *au8InstallCode\[\]* Array containing the install code - the array length ZPS\_INSTALL\_CODE\_LENGTH is given below in *u8InstallCodeSize*.
-   *u8InstallCodeSize* Number of characters in the install code - this is the size of the array *au8InstallCode\[\]*.
-   *eKeyType* Type of the key to be used by the node \(see above\), one of the below:
    -   ZPS\_APS\_UNIQUE\_LINK\_KEY
    -   ZPS\_APS\_GLOBAL\_LINK\_KEY

**Parent topic:**[ZPS\_eAplZdoAddReplaceInstallCodes](../topics/zps_eaplzdoaddreplaceinstallcodes.md)

