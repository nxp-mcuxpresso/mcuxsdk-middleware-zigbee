# teCLD\_AnalogOutputBasic\_Reliability

The following structure contains the enumerations used to report the value of the `u8Reliability` attribute \(see [Section 19.2.2](analogue_output_basic_structure_and_attributes.md#id_faec7125-e579-40da-8886-6ecc29232249)\).

```
typedef enum 
{ 
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_OVER_RANGE,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_UNDER_RANGE,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_OPEN_LOOP,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_SHORTED_LOOP,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_PROCESS_ERROR,
   E_CLD_ANALOG_OUTPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR
}teCLD_AnalogOutputBasic_Reliability;

```

**Parent topic:**[Enumerations](../../Binary_Input_Basic_cluster/topics/enumerations_01.md)

