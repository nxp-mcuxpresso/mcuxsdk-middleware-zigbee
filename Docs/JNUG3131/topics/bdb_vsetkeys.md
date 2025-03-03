# BDB\_vSetKeys

```
void BDB_vSetKeys(void);

```

## Description 

This function loads into memory the appropriate pre-configured link key on the local node for the initial security state of the node. The function is automatically called by **BDB\_vInit\(\)**. However, it must be called explicitly to restore the link keys after a reset which removes the keys from memory.

The type of link key that is loaded depends on the node type, as follows:

-   On a Coordinator, the Default Global Trust Centre Link Key is loaded for participation in a centralized security network.

-   On a Router or End Device, both of the following keys are loaded:

    -   Default Global Trust Centre Link Key for participation in a centralized security network.

    -   Distributed Security Global Link Key for participation in a distributed security network.


The pre-configured link keys are defined in the file **bdb\_link\_keys.c**, from where they are loaded.

Network security is described in [Section 2.3](network_security.md#ID_4C903549-A2A4-4958-A885-54D50242FB72).

## Parameters 
-   None

## Returns 
-   None

**Parent topic:**[Functions](../topics/functions.md)

