# Parameters

-   *pvApl:* Handle for the relevant Application layer instance.
-   *u8RemoteOverride:* Boolean specifying whether remote overrides of Trust Centre policy are to be permitted:
    -   TRUE - Does not allow remote over-rides; stack does not allow the permit join remotely sent to change its local state.
    -   FALSE - Allows remote over-rides; stack accepts permit join requests coming in and obeys them.

-   *bDisableAuthentications:* Boolean specifying whether network join authentications are to be disabled:
    -   TRUE - Disable authentications

    -   FALSE - Do not disable authentications

        When this flag is set to TRUE, permit join is not accepted remotely and the TC does not transport a key to any joiner.


**Parent topic:**[ZPS\_vSetTCLockDownOverride](../topics/zps_vsettclockdownoverride.md)

