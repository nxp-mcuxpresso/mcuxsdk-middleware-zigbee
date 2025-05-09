# teCLD\_MultistateOutputBasic\_Reliability

The following structure contains the enumerations used to report the value of the `u8Reliability` attribute \(see [Section 19.6.2](multistate_output_basic_structure_and_attributes.md#id_7f9ef572-8a1a-4c9b-b1b6-ee51cd7f7478)\).

```
typedef enum 
{ 
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_OVER_RANGE,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_UNDER_RANGE,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_OPEN_LOOP,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_SHORTED_LOOP,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_PROCESS_ERROR,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_MULTISTATE_FAULT,
   E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR
}teCLD_MultistateOutputBasic_Reliability;

```

**Parent topic:**[Enumerations](../../Binary_Input_Basic_cluster/topics/enumerations_05.md)

