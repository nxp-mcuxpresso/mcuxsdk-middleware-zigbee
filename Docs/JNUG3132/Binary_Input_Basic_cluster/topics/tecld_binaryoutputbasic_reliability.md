# teCLD\_BinaryOutputBasic\_Reliability

The following structure contains the enumerations used to report the value of the `u8Reliability` attribute \(see [Section 19.4.2](binary_output_basic_structure_and_attributes.md#id_02215436-44b7-465f-a8f9-ffd02c25195d)\).

```
typedef enum 
{ 
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_OVER_RANGE,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_UNDER_RANGE,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_OPEN_LOOP,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_SHORTED_LOOP,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_PROCESS_ERROR,
    E_CLD_BINARY_OUTPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR 
 }teCLD_BinaryOutputBasic_Reliability;

```

**Parent topic:**[Enumerations](../../Binary_Input_Basic_cluster/topics/enumerations_03.md)

