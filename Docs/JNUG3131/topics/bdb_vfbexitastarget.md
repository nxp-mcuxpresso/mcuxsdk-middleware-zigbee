# BDB_vFbExitAsTarget

```
void BDB_vFbExitAsTarget(uint8 u8SourceEndpoint);
```

## Description

This function stops an on-going Finding and Binding process on a target endpoint and must be called locally by the application on the target endpoint. The function may be called as the result of a user action, such as a button-press or button-release.

Finding and Binding mode is described in [Section 2.2.4](finding_and_binding.md#ID_0189A083-F683-4848-A875-19C22F73C47E).

## Parameters 

-   *u8SourceEndpoint*: Number of target endpoint

## Returns 

-   None

**Parent topic:**[Functions](../topics/functions.md)

