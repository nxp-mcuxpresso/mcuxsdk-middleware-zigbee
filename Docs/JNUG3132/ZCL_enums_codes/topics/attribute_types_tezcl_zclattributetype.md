# Attribute Types \(teZCL\_ZCLAttributeType\)

The following enumerations are used to represent the attribute types in the/ZCL clusters:

```
typedef enum 
{
    /* Null */
    E_ZCL_NULL            = 0x00,
    /* General Data */
    E_ZCL_GINT8           = 0x08,              // General 8 bit - not specified if signed
    E_ZCL_GINT16,
    E_ZCL_GINT24,
    E_ZCL_GINT32,
    E_ZCL_GINT40,
    E_ZCL_GINT48,
    E_ZCL_GINT56,
    E_ZCL_GINT64,
    /* Logical */
    E_ZCL_BOOL            = 0x10,
    /* Bitmap */
    E_ZCL_BMAP8           = 0x18,              // 8 bit bitmap
    E_ZCL_BMAP16,
    E_ZCL_BMAP24,
    E_ZCL_BMAP32,
    E_ZCL_BMAP40,
    E_ZCL_BMAP48,
    E_ZCL_BMAP56,
    E_ZCL_BMAP64,
    /* Unsigned Integer */
    E_ZCL_UINT8           = 0x20,              // Unsigned 8 bit
    E_ZCL_UINT16,
    E_ZCL_UINT24,
    E_ZCL_UINT32,
    E_ZCL_UINT40,
    E_ZCL_UINT48,
    E_ZCL_UINT56,
    E_ZCL_UINT64,
    /* Signed Integer */
    E_ZCL_INT8            = 0x28,           // Signed 8 bit
    E_ZCL_INT16,
    E_ZCL_INT24,
    E_ZCL_INT32,
    E_ZCL_INT40,
    E_ZCL_INT48,
    E_ZCL_INT56,
    E_ZCL_INT64,
    /* Enumeration */
    E_ZCL_ENUM8           = 0x30,           // 8 Bit enumeration
    E_ZCL_ENUM16,
    /* Floating Point */
    E_ZCL_FLOAT_SEMI      = 0x38,       // Semi precision
    E_ZCL_FLOAT_SINGLE,                // Single precision
    E_ZCL_FLOAT_DOUBLE,                 // Double precision
    /* String */
    E_ZCL_OSTRING         = 0x41,        // Octet string
    E_ZCL_CSTRING,                  // Character string
    E_ZCL_LOSTRING,                     // Long octet string
    E_ZCL_LCSTRING,                   // Long character string
    /* Ordered Sequence */
    E_ZCL_ARRAY           = 0x48,
    E_ZCL_STRUCT          = 0x4c,
    E_ZCL_SET             = 0x50,
    E_ZCL_BAG             = 0x51,
    /* Time */
    E_ZCL_TOD             = 0xe0,            // Time of day
    E_ZCL_DATE,                              // Date
    E_ZCL_UTCT,                              // UTC Time
    /* Identifier */
    E_ZCL_CLUSTER_ID      = 0xe8,          // Cluster ID
    E_ZCL_ATTRIBUTE_ID,                  // Attribute ID
    E_ZCL_BACNET_OID,                    // BACnet OID
    /* Miscellaneous */
    E_ZCL_IEEE_ADDR       = 0xf0,        // 64 Bit IEEE Address
    E_ZCL_KEY_128,                   // 128 Bit security key
    /* Unknown */
    E_ZCL_UNKNOWN         = 0xff
} teZCL_ZCLAttributeType;

```

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

