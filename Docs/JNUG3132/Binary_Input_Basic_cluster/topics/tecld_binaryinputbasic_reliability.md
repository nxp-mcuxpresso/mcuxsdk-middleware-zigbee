# teCLD\_BinaryInputBasic\_Reliability

The following structure contains the enumerations used to report the value of the `u8Reliability` attribute \(see [Section 19.3.2](binary_input_basic_structure_and_attributes.md#id_80036992-711c-42db-94e2-41bdfde72c66)\).

```
typedef enum 
{ 
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_NO_SENSOR,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_OVER_RANGE,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_UNDER_RANGE,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_OPEN_LOOP,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_SHORTED_LOOP,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_NO_OUTPUT,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_PROCESS_ERROR,
   E_CLD_ BINARY_INPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR                 
}teCLD_BinaryInputBasic_Reliability;

```

**Parent topic:**[Enumerations](../../Binary_Input_Basic_cluster/topics/enumerations_02.md)

