# ‘Summation Formatting’ Enumerations

Enumerations for use with the `u8SummationFormatting` element in the Simple Metering cluster structure `u8SummationFormatting` are provided as \#defines. The enumerations allow the following formatting information to be extracted from the `u8SummationFormatting` bitmap:

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_RIGHT\_OF\_DP\_LS\_BIT|Position of least significant bit of bit-field indicating number of digits to right of decimal point|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_RIGHT\_OF\_DP\_NUMBER\_OF\_BITS|Number of bits in bit-field indicating number of digits to right of decimal point|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_RIGHT\_OF\_DP\_MASK|Bit-mask used to extract number of digits to right of decimal point|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_LEFT\_OF\_DP\_LS\_BIT|Position of least significant bit of bit-field indicating number of digits to left of decimal point|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_LEFT\_OF\_DP\_NUMBER\_OF\_BITS|Number of bits in bit-field indicating number of digits to left of decimal point|
|E\_CLD\_SM\_FORMATTING\_DIGITS\_TO\_LEFT\_OF\_DP\_MASK|Bit-mask used to extract number of digits to left of decimal point|
|E\_CLD\_SM\_FORMATTING\_SUPPRESS\_LEADING\_ZEROS\_BIT|Bit-mask used to extract bit indicating whether lead-ing zeros will be suppressed|

The following are examples of the use of the above enumerations.

## Extracting the number of digits to the right of the decimal point: 

```
u8BitsToRight = (u8SummationFormatting & E_CLD_SM_FORMATTING_DIGITS_TO_RIGHT_OF_DP_MASK) 
>> E_CLD_SM_FORMATTING_DIGITS_TO_RIGHT_OF_DP_LS_BIT

```

## Extracting the number of digits to the left of the decimal point: 

```
u8BitsToLeft = (u8SummationFormatting & E_CLD_SM_FORMATTING_DIGITS_TO_LEFT_OF_DP_MASK) 
>> E_CLD_SM_FORMATTING_DIGITS_TO_LEFT_OF_DP_LS_BIT

```

## Determining whether leading zeros will be suppressed: 

```
bSuppressZeros = !((u8SummationFormatting & E_CLD_SM_FORMATTING_SUPPRESS_LEADING_ZEROS_BIT) == 0)

```

**Parent topic:**[Enumerations](../../Simple_Metering_cluster/topics/enumerations.md)

