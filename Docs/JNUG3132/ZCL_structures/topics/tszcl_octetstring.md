# tsZCL\_OctetString

This structure contains information on a ZCL octet \(byte\) string. This string is of the format:

|**Octet Count, N**

 \(1 octet\)

|**Data**

 \(N octets\)

|

which contains N+1 octets, where the leading octet indicates the number of octets \(N\) of data in the remainder of the string \(valid values are from 0x00 to 0xFE\).

The `tsZCL_OctetString` structure incorporates this information as follows:

```
typedef struct
{
    uint8    u8MaxLength;
    uint8    u8Length;
    uint8   *pu8Data;
} tsZCL_OctetString;

```

Where:

-   `u8MaxLength` is the maximum number of data octets in an octet string

-   `u8Length` is the actual number of data octets \(N\) in this octet string

-   `pu8Data` is a pointer to the first data octet of this string


Note that there is also a `tsZCL_LongOctetString` structure in which the octet count \(N\) is represented by two octets, thus allowing double the number of data octets.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

