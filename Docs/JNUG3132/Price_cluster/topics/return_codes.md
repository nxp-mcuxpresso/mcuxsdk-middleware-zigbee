# Return codes

In addition to some of the ZCL status enumerations, the following enumerations are returned by Price cluster functions \(see [Section 40.9](functions.md#id_9b700b63-9af9-4fe5-bace-72e8fdeb15d3)\) to indicate the outcome of the function call.

```
typedef enum PACK
{
    E_SE_PRICE_OVERLAP =0x80,
    E_SE_PRICE_TABLE_NOT_YET_ACTIVE,
    E_SE_PRICE_DATA_OLD,
    E_SE_PRICE_NOT_FOUND,
    E_SE_PRICE_TABLE_NOT_FOUND,
    E_SE_PRICE_OVERFLOW,
    E_SE_PRICE_DUPLICATE,
    E_SE_PRICE_NO_TABLES,
    E_SE_PRICE_BLOCK_PERIOD_TABLE_NOT_YET_ACTIVE,
    E_SE_PRICE_NO_BLOCKS,
    E_SE_PRICE_NUMBER_OF_BLOCK_THRESHOLD_MISMATCH,
    E_SE_BLOCK_PERIOD_OVERFLOW,
    E_SE_BLOCK_PERIOD_DUPLICATE,
    E_SE_BLOCK_PERIOD_DATA_OLD,
    E_SE_BLOCK_PERIOD_OVERLAP,
    E_SE_PRICE_STATUS_ENUM_END
} teSE_PriceStatus;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_SE\_PRICE\_OVERLAP|New price overlaps \(in time\) with existing price in price list|
|E\_SE\_PRICE\_TABLE\_NOT\_YET\_ACTIVE|No active price at head of price list|
|E\_SE\_PRICE\_DATA\_OLD|Attempt made to add price which overlaps \(in time\) with existing price in price list and which is older than existing price \*|
|E\_SE\_PRICE\_NOT\_FOUND|Specified price was not found in price list|
|E\_SE\_PRICE\_TABLE\_NOT\_FOUND|Specified price list was not found|
|E\_SE\_PRICE\_OVERFLOW|Attempt to add price to price list failed because end-time for new price \(start-time + duration x 60\) exceeds maximum permissible time value of 0xFFFFFFFFF \(UTC\)|
|E\_SE\_PRICE\_DUPLICATE|Specified price information already exists in price list|
|E\_SE\_PRICE\_NO\_TABLES|Reserved for future use \(for Block mode\)|
|E\_SE\_PRICE\_BLOCK\_PERIOD\_TA-BLE\_NOT\_YET\_ACTIVE|Reserved for future use \(for Block mode\)|
|E\_SE\_PRICE\_NO\_BLOCKS|Reserved for future use \(for Block mode\)|
|E\_SE\_PRICE\_NUMBER\_OF\_BLOCK\_THRESHOLD\_MISMATCH|Reserved for future use \(for Block mode\)|
|E\_SE\_BLOCK\_PERIOD\_OVERFLOW|Reserved for future use \(for Block mode\)|
|E\_SE\_BLOCK\_PERIOD\_DUPLICATE|Reserved for future use \(for Block mode\)|
|E\_SE\_BLOCK\_PERIOD\_DATA\_OLD|Reserved for future use \(for Block mode\)|
|E\_SE\_BLOCK\_PERIOD\_OVERLAP|Reserved for future use \(for Block mode\)|

\* Value of `u32IssuerEventId` in `tsSE_PricePublishPriceCmdPayload` structure \(see [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a)\) is less for the price to be added than for the existing \(overlapping\) price.

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

