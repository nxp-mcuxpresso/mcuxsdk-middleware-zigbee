# tsCLD\_Commissioning\_ModifyStartupParametersPayload

The following structure contains the payload of the following commands: Save Start-up Parameters, Restore Start-up Parameters and Reset Start-up Parameters.

```
typedef struct
{
    zbmap8                  u8Options;
    uint8                   u8Index;
} tsCLD_Commissioning_ModifyStartupParametersPayload;

```

where:

```
u8Options is an 8-bit bitmap specifying the required reset options for the Reset Start-up Parameters command (it is not used by the other commands):

```

|**Bits**|**Option**|**Description**|
|--------|----------|---------------|
|0|Reset Current|Determines whether the current Start-up Parameters will be reset to their default values:

 -   1: Reset to default values

-   0: Do not reset \(remain unchanged\)


|
|1|Reset All|Determines whether all stored Start-up Parameter sets will be reset to their default values:

 -   1: Reset all stored Start-up Parameter sets

-   0: Reset the stored Start-up Parameter set with specified index


|
|2|Erase Index|Determines whether the stored Start-up Parameter set with speci-fied index will be erased:

 -   1: Erase Start-up Parameter set with specified index

-   0: Do not erase Start-up Parameter set with specified index


|
|3-7|-|Reserved|

```
u8Index is the index of the saved Start-up Parameter set to which actions specified in u8Options relate (this index is ignored if no actions are specified).

```

**Parent topic:**[Structures](../../Commissioning_cluster/topics/structures.md)

