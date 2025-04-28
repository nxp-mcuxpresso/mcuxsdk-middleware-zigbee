# ZPS\_tsAplZdpMgmtPermitJoiningReq

This structure is used by the function **ZPS\_eAplZdpMgmtPermitJoiningRequest\(\)**. It requests a remote node \(Router or Coordinator\) to enable or disable joining for a specified amount of time.

The `ZPS_tsAplZdpMgmtPermitJoiningReq`structure is detailed below.

`typedef struct {`

`uint8 u8PermitDuration; bool_t bTcSignificance;`

`} ZPS_tsAplZdpMgmtPermitJoiningReq;`

where:

-   `u8PermitDuration`is the time period, in seconds, during which joining will be allowed \(0x00 means that joining is enabled or disabled with no time limit\)
-   `bTcSignificance`determines whether the remote device is a ‘Trust Centre’:
    -   TRUE: A Trust Centre
    -   FALSE: Not a Trust Centre

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

