# BDB\_teCommissioningStatus

The following enumerations are used to indicate the status of the commissioning process for the node.

```
typedef enum
{
    E_BDB_COMMISSIONING_STATUS_SUCCESS,
    E_BDB_COMMISSIONING_STATUS_IN_PROGRESS,
    E_BDB_COMMISSIONING_STATUS_NOT_AA_CAPABLE,
    E_BDB_COMMISSIONING_STATUS_NO_NETWORK,
    E_BDB_COMMISSIONING_STATUS_FORMATION_FAILURE,
    E_BDB_COMMISSIONING_STATUS_NO_IDENTIFY_QUERY_RESPONSE,
    E_BDB_COMMISSIONING_STATUS_BINDING_TABLE_FULL,
    E_BDB_COMMISSIONING_STATUS_NO_SCAN_RESPONSE,
    E_BDB_COMMISSIONING_STATUS_NOT_PERMITTED,
    E_BDB_COMMISSIONING_STATUS_TCLK_EX_FAILURE
}BDB_teCommissioningStatus;

```

The enumerations are listed and described in the table below: <br>

**Commissioning Status Enumerations**
| Enumeration                                              | Description                                        |
| -------------------------------------------------------- | -------------------------------------------------- |
| E_BDB_COMMISSIONING_STATUS_SUCCESS                       | Commissioning is successfully completed            |
| E_BDB_COMMISSIONING_STATUS_IN_PROGRESS                   | Commissioning is on-going                          |
| E_BDB_COMMISSIONING_STATUS_NOT_AA_CAPABLE                | Parent cannot assign address to joining node       |
| E_BDB_COMMISSIONING_STATUS_NO_NETWORK                    | No network is found that can be joined             |
| E_BDB_COMMISSIONING_STATUS_FORMATION_FAILURE             | Network formation failed                           |
| E_BDB_COMMISSIONING_STATUS_NO_IDENTIFY_QUERY \_ RESPONSE | No responses received to an Identify Query command |
| E_BDB_COMMISSIONING_STATUS_BINDING_TABLE_FULL            | The local Binding table is full                    |
| E_BDB_COMMISSIONING_STATUS_NO_SCAN_RESPONSE              | No responses received during a channel scan        |
| E_BDB_COMMISSIONING_STATUS_NOT_PERMITTED                 | Requested commissioning is not permitted           |
| E_BDB_COMMISSIONING_STATUS_TCLK_EX_FAILURE               | Trust Centre link key exchange failed              |

**Parent topic:**[Enumerations](../topics/enumerations.md)

