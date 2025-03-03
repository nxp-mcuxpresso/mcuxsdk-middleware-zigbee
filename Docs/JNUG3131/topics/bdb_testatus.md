# BDB\_teStatus

The following enumerations indicate the status of certain function calls.

```
typedef enum
{
    BDB_E_SUCCESS,
    BDB_E_FAILURE,
    BDB_E_ERROR_INVALID_PARAMETER,
    BDB_E_ERROR_INVALID_DEVICE,
    BDB_E_ERROR_NODE_IS_ON_A_NWK,
    BDB_E_ERROR_IMPROPER_COMMISSIONING_MODE,
    BDB_E_ERROR_COMMISSIONING_IN_PROGRESS,
}BDB_teStatus;

```

The enumerations are listed and described in the [Table 11](#TABLE_BBD393A0-D6CC-4667-A841-50792BB981CE):

| Enumeration                             | Description                                                               |
| --------------------------------------- | ------------------------------------------------------------------------- |
| BDB_E_SUCCESS                           | Function call is successful in its purpose                                |
| BDB_E_FAILURE                           | Function call fails in its purpose and no other error code is appropriate |
| BDB_E_ERROR_INVALID_PARAMETER           | A specified parameter value is invalid                                    |
| BDB_E_ERROR_INVALID_DEVICE              | Device type is not valid for the operation                                |
| BDB_E_ERROR_NODE_IS_ON_A_NWK            | Node is already in a network                                              |
| BDB_E_ERROR_IMPROPER_COMMISSIONING_MODE | The commissioning mode is not appropriate                                 |
| BDB_E_ERROR_COMMISSIONING_IN_PROGRESS   | The commissioning process is in progress                                  |
|

**Parent topic:**[Enumerations](../topics/enumerations.md)

