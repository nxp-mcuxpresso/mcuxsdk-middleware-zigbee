# Default Responses

The ZCL provides a default response which is generated in reply to a unicast command in the following circumstances:

-   When there is no other relevant response and the requirement for default responses has not been disabled on the endpoint that sent the command.

-   When an error results from a unicast command and there is no other relevant response, *even if the requirement for default responses has been disabled on the endpoint that sent the command*.

The default response disable setting is made in the `bDisableDefaultResponse` field of the structure `tsZCL_EndPointDefinition` detailed in [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38). This setting dictates the value of the ‘disable default response’ bit in messages sent by the endpoint. The receiving device then uses this bit to determine whether to return a default response to the source device.

The default response includes the ID of the command that triggered the response and a status field \(see [Section 6.1.9](../../ZCL_structures/topics/tszcl_defaultresponse.md#id_6adc0c37-aa71-4b92-9597-53c4af5d35e1)\). Therefore, in the case of an error, the command ID field of the default response contains the the identity of the command that caused the error.

**Note:** The default response can be generated on reception of all commands, including responses \(for example, a ‘read attributes’ response\) but not other default responses.

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

