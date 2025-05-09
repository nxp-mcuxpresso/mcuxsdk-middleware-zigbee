# Attribute settings

The Price cluster structure \(see [Section 40.2](price_cluster_structure_and_attributes.md#id_040fd477-8263-48cc-9679-a5e34621e8f9)\) contains no mandatory elements. All elements are optional, each being enabled/disabled through a corresponding macro defined in the **zcl\_options.h** file - for example, the commodity type attribute is enabled/disabled through the macro CLD\_P\_ATTR\_COMMODITY\_TYPE. The attributes that are used depend on the number of tiers implemented \(and Block mode attributes must be disabled\).

**Note:**

-   The Tier Label attributes are connected to the tier-related attributes in the Simple Metering cluster, e.g. `u48CurrentTier6SummationDelivered` for Tier 6. For a complete list of these Simple Metering attributes, refer to [Section 42.2](../../Simple_Metering_cluster/topics/simple_metering_cluster_structure_and_attributes.md#id_1c898ead-e5b8-46b9-9117-d5b84c56d269).
-   The price information for Time-Of-Use \(TOU\) mode is stored in the structure `tsSE_PricePublishPriceCmdPayload` described in [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a).

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

