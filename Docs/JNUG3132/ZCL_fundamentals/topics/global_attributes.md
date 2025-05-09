# Global Attributes

There are two global attributes that are used in multiple clusters. These attributes are additions to the ZCL r6 for ZigBee 3.0 and are described below.

## ClusterRevision 

The `ClusterRevision` global attribute is mandatory in all clusters. It indicates the revision of the cluster used by the current instance of the cluster on the local endpoint. The cluster specification from the ZCL r6 acts as the baseline for the revision numbering of a cluster - this is revision 1 of the cluster. The cluster revision number is incremented by one for each subsequent update of the cluster specification. Those cluster specifications that pre-date the ZCL r6 have assumed revision numbers of 0. To check that the local cluster instance is interoperable with a remote instance of the same cluster \(perhaps based on a different cluster revision\), the `ClusterRevision` attribute on the remote node should be read - if the remote cluster instance is based on an earlier cluster revision that does not support an essential feature, the two cluster instances will not be interoperable.

## AttributeReportingStatus 

The `AttributeReportingStatus` global attribute is optional and used only when attribute reporting is enabled for the cluster \(see [Section 2.3.5](attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). Where ‘attribute report’ messages are generated for multiple attributes, this attribute indicates whether there are reports pending \(0x00\) or the reports are complete \(0x01\).

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

