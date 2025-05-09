# Attribute Discovery

A ZigBee cluster may have mandatory and/or optional attributes. The desired optional attributes are enabled in the cluster structure. An application running on a cluster client may need to discover which optional attributes are supported by the cluster server.

The ZCL provides functionality to perform the necessary ‘attribute discovery’, as described in the rest of this section.

**Note:**

1.  ‘Extended’ attribute discovery is also available. When this optional attribute is used, the accessibility of each reported attribute is also indicated. This is described in [Appendix C.](../../appendix/topics/extended_attribute_discovery.md#id_4de9f37f-2e55-4866-bd0f-eb81cf7eee2d)
2.  Alternatively, the application on a cluster client can check whether a particular attribute exists on the cluster server by attempting to read the attribute \(see [Section 2.3.2](reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae)\) - if the attribute does not exist on the server, an error is returned.

## Compile-time Options 

If required, the attribute discovery feature must be explicitly enabled on the cluster server and client at compile time by including the relevant defines, from those below, in the **zcl\_options.h** files:

```
#define ZCL_ATTRIBUTE_DISCOVERY_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_DISCOVERY_EXTENDED_SERVER_SUPPORTED 
#define ZCL_ATTRIBUTE_DISCOVERY_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_DISCOVERY_EXTENDED_CLIENT_SUPPORTED

```

## Application Coding 

The application on a cluster client can initiate a discovery of the attributes on the cluster server by calling the function **eZCL\_SendDiscoverAttributesRequest\(\)**, which sends a ‘discover attributes’ request to the server. This function allows a range of attributes to be searched for, defined by:

-   The ‘start’ attribute in the range \(the attribute identifier must be specified\)

-   The number of attributes in the range


Initially, the start attribute should be set to the first attribute of the cluster. If the discovery request does not return all the attributes used on the cluster server, the above function should be called again with the start attribute set to the next ‘undiscovered’ attribute. Multiple function calls may be required to discover all of the attributes used on the server.

On receiving a discover attributes request, the server handles the request automatically \(provided that attribute discovery has been enabled in the compile-time options - see above\) and replies with a ‘discover attributes’ response containing the requested information.

The arrival of this response at the client results in an E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event for each attribute reported in the response. Therefore, multiple events normally result from a single discover attributes request. This event contains details of the reported attribute in a `tsZCL_AttributeDiscoveryResponse` structure \(see [Section 6.1.10](../../ZCL_structures/topics/tszcl_attributediscoveryresponse.md#id_87716210-2818-4a28-a46a-12db46ad90c9)\).

Following the event for the final attribute reported, the event E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES\_RESPONSE is generated to indicate that all attributes from the discover attributes response have been reported.

**Parent topic:**[Accessing Attributes](../../ZCL_fundamentals/topics/accessing_attributes.md)

