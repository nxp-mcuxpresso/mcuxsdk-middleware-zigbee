# ZPS\_tsAfFlashInfoSet

This structure contains information about the devices Flash memory sector used for the persistent storage of unique link keys on the Trust Centre, as enabled by the function **ZPS\_vTcInitFlash\(\)**.

```
typedef struct
{
    uint16   u16SectorSize;
    uint16   u16CredNodesCount;
    uint8    u8SectorSet;
} ZPS_tsAfFlashInfoSet;
```

where:

-   `u16SectorSize`is the size, in bytes, of the Flash memory sector used to store the link keys.
-   `u16CredNodesCount`is the maximum number of nodes for which link keys can be stored in the Flash memory sector.
-   `u8SectorSet`is the number of the Flash memory sector used for this storage.

**Note:** Care should be taken that this sector is set greater than the current flash usage of the image you are running. If this clashes with something else \(image or user data\), it would lead to flash corruption and the behavior might become non-deterministic.

**Parent topic:**[Other structures](../topics/other_structures.md)

