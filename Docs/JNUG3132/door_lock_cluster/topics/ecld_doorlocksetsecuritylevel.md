# eCLD\_DoorLockSetSecurityLevel

```
teZCL_Status eCLD_DoorLockSetSecurityLevel(
    uint8 u8SourceEndPointId,
    bool bServer,
    uint8 u8SecurityLevel);

```

## Description 

This function can be used to set the level of security to be used by the Door Lock cluster: Network-level security or Application-level security. By default, only Network-level security is implemented, but this function can be used to enable Application-level security \(in addition to Network-level security\). For more information on ZigBee security, refer to the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

Application-level security is an enhancement to the Door Lock cluster and is currently not certifiable. It is enabled through an optional attribute of the cluster, but the application must not write directly to this attribute - if required, Application-level security should be enabled only using this function.

To use Application-level security, it is necessary to call this function on the Door Lock cluster server and client nodes. If an application link key is to be used which is not the default one, the new link key must be subsequently specified on both nodes using the ZigBee PRO function **ZPS\_eAplZdoAddReplaceLinkKey\(\)**.

## Parameters 

-   *u8SourceEndPointId*                Number of the local endpoint on which the Door Lock cluster resides
-   *bIsServer*         Type of local cluster instance \(server or client\):
-           TRUE - server
-   FALSE - client
-   *u8SecurityLevel*        The security level to be set:
-           0: Network-level security only
-   1 or higher: Application-level security

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../door_lock_cluster/topics/functions.md)

