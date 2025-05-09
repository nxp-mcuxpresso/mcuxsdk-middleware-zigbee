# Appendix C.2: Application coding

The application on a cluster client can initiate an extended attribute discovery on the cluster server by calling the **eZCL\_SendDiscoverAttributesExtendedRequest\(\)** function, which sends a ‘discover attributes extended’ request to the server. This function allows a range of attributes to be searched for, defined by:

-   The ‘start’ attribute in the range \(the attribute identifier must be specified\).

-   The number of attributes in the range.


Initially, the start attribute should be set to the first attribute of the cluster. If the discovery request does not return all the attributes used on the cluster server, the above function should be called again with the start attribute set to the next ‘undiscovered’ attribute. Multiple function calls may be required to discover all of the attributes used on the server.

On receiving a discover attributes extended request, the server handles the request automatically \(provided that extended attribute discovery has been enabled in the compile-time options - see above\) and replies with a ‘discover attributes extended’ response containing the requested information.

The arrival of the response at the client results in the event E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_EXTENDED\_RESPONSE for each attribute reported in the response. Therefore, multiple events normally result from a single discover attributes extended request. This event contains details of the reported attribute in a `tsZCL_AttributeDiscoveryExtendedResponse` structure \(see [Section 6.1.11](../../ZCL_structures/topics/tszcl_attributediscoveryextendedresponse.md#id_007da05d-ef21-441e-9f00-1ab9660c0426)\).

Following the event for the final attribute reported, the event E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES\_EXTENDED\_RESPONSE is generated to indicate that all attributes from the discover attributes extended response have been reported.

**Parent topic:**[Appendix C: Extended attribute discovery](../../appendix/topics/extended_attribute_discovery.md)

