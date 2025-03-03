# General constants

The table below lists the ZigBee Base Device constants that can be used on all nodes and also shows the corresponding macros used to define the constant values in the **bdb\_options.h** file. <br>

**Table: ZBD General Constants and Macros**
| Constant                        | Macro                                |
| ------------------------------- | ------------------------------------ |
| bdbcMaxSameNetworkRetryAttempts | BDBC_MAX_SAME_NETWORK_RETRY_ATTEMPTS |
| bdbcMinCommissioningTime        | BDBC_MIN_COMMISSIONING_TIME          |
| bdbcRecSameNetworkRetryAttempts | BDBC_REC_SAME_NETWORK_RETRY_ATTEMPTS |
| bdbcTCLinkKeyExchangeTimeout    | BDBC_TC_LINK_KEY_EXCHANGE_TIMEOUT    |


## bdbcMaxSameNetworkRetryAttempts 

This constant specifies the maximum number of join or key exchange attempts that the node can make on the same network. The value of this constant is defined using the macro BDBC\_MAX\_SAME\_NETWORK\_RETRY\_ATTEMPTS and should be set to 10 \(as recommended in the *ZigBee BDB Specification*\).

## bdbcMinCommissioningTime 

This constant specifies the minimum time-interval \(in seconds\) for which a network is open to allow new nodes to join or for a device to identify itself. The value of this constant is defined using the macro BDBC\_MIN\_COMMISSIONING\_TIME and should be set to 180 \(as recommended in the *ZigBee BDB Specification*\).

## bdbcRecSameNetworkRetryAttempts 

This constant specifies the recommended number of join or key exchange attempts that the node can make on the same network. The value of this constant is defined using the macro BDBC\_REC\_SAME\_NETWORK\_RETRY\_ATTEMPTS and should be set to 3 \(as recommended in the *ZigBee BDB Specification*\).

## bdbcTCLinkKeyExchangeTimeout 

This constant specifies the maximum time \(in seconds\) for which a joining node will wait for a response after an APS key request has been sent to the Trust Centre. The value of this constant is defined using the macro `BDBC_TC_LINK_KEY_EXCHANGE_TIMEOUT` and should be set to 5 \(as recommended in the *ZigBee BDB Specification*\).

**Parent topic:**[Constants](../topics/constants.md)

