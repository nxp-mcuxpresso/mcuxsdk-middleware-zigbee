# Compile-time options

This section describes the compile-time options that may be enabled in the **zcl\_options.h** file of an application that uses the Price cluster.

The Price cluster is enabled by defining CLD\_PRICE.

Client and server versions of the cluster are defined by PRICE\_CLIENT and PRICE\_SERVER, respectively.

## Price List Size 

The maximum number of prices that can be stored in the price list on a server and client defaults to five and two respectively. These default values can be over-ridden by assigning values to the corresponding macro below:

-   SE\_PRICE\_NUMBER\_OF\_SERVER\_PRICE\_RECORD\_ENTRIES

-   SE\_PRICE\_NUMBER\_OF\_CLIENT\_PRICE\_RECORD\_ENTRIES


## Price Tier Label Attribute Set 

The maximum number of supported Price Tier Label Attribute Sets can be defined by assigning a value between 1 and 15 \(inclusive\) to CLD\_P\_ATTR\_TIER\_PRICE\_LABEL\_MAX\_COUNT.

## Block Threshold Attribute Set 

The maximum number of supported Block Threshold Attribute Sets can be defined by assigning a value between 1 to 15 \(inclusive\) to CLD\_P\_ATTR\_BLOCK\_THRESHOLD\_MAX\_COUNT.

## Block Price Information Attribute Set 

The maximum number of supported Block Price Information Attribute Sets can be defined by assigning a value \(the maximum of which is shown below in brackets\) to each of the following:

-   CLD\_P\_ATTR\_NO\_TIER\_BLOCK\_PRICES\_MAX\_COUNT \(16\)

-   CLD\_P\_ATTR\_NUM\_OF\_TIERS\_PRICE \(15\)

-   CLD\_P\_ATTR\_NUM\_OF\_BLOCKS\_IN\_EACH\_TIER\_PRICE \(16\)


## Conversion Factor \(Gas Only\) 

Conversion factor in the Price cluster is enabled by defining the macro PRICE\_CONVERSION\_FACTOR.

The attributes for conversion factor are enabled by defining the following macros:

-   CLD\_P\_ATTR\_CONVERSION\_FACTOR

-   CLD\_P\_ATTR\_CONVERSION\_FACTOR\_TRAILING\_DIGIT


The default value of the maximum number of entries that can be stored in the conversion factor list which is maintained on the Price cluster server and client is 2. This value can be over-ridden by assigning another value to the macro:

SE\_PRICE\_NUMBER\_OF\_CONVERSION\_FACTOR\_ENTRIES

## Calorific Value \(Gas Only\) 

Calorific value in the Price cluster is enabled by defining the macro PRICE\_CALORIFIC\_VALUE.

The attributes for calorific value are enabled by defining the following macros:

-   CLD\_P\_ATTR\_CALORIFIC\_VALUE

-   CLD\_P\_ATTR\_CALORIFIC\_VALUE\_UNIT

-   CLD\_P\_ATTR\_CALORIFIC\_VALUE\_TRAILING\_DIGIT


The default value of the maximum number of entries that can be stored in the calorific value list which is maintained on the server and client is 2. This value can be over-ridden by assigning another value to the macro:

SE\_PRICE\_NUMBER\_OF\_CALORIFIC\_VALUE\_ENTRIES

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

