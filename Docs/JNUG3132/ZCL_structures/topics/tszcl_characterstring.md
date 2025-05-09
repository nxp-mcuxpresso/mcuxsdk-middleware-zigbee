# tsZCL\_CharacterString

This structure contains information on a ZCL character string. This string is of the format:


| Character Data Length, L<br> | Character Data<br> |
| ---------------------------- | ------------------ |
| (1 byte)                     | (L bytes)          |
|

which contains L+1 bytes, where the leading byte indicates the number of bytes \(L\) of character data in the remainder of the string \(valid values are from 0x00 to 0xFE\). This value represents the number of characters in the string only if the character set used encodes each character using one byte \(this is the case for ISO 646 ASCII but not in all character sets, for example, UTF8\).

The `tsZCL_CharacterString` structure incorporates this information as follows:

```
typedef struct 
{
    uint8    u8MaxLength;
    uint8    u8Length;
    uint8   *pu8Data;
} tsZCL_CharacterString;

```

where:

-   `u8MaxLength` is the maximum number of character data bytes

-   `u8Length` is the actual number of character data bytes \(L\) in this string

-   `pu8Data` is a pointer to the first character data byte of this string


The string is not null-terminated and may therefore contain null characters mid-string.

Note that there is also a `sZCL_LongCharacterString` structure in which the character data length \(L\) is represented by two bytes, thus allowing double the number of characters.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

