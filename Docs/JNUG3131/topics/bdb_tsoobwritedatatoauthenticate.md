# BDB\_tsOobWriteDataToAuthenticate

The following structure contains authentication data that is used to encrypt a security key during out-of-band commissioning of the node.

```
typedef struct{
    uint64 u64ExtAddr;
    uint8* pu8InstallCode;
}BDB_tsOobWriteDataToAuthenticate;

```

where:

-   `u64ExtAddr` is the IEEE/MAC address of the node.

-   `pu8InstallCode` is a pointer to a 16-bit install code to be used in the key encryption.


**Parent topic:**[Structures](../topics/structures.md)

