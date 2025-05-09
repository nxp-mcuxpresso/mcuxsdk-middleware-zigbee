# Simple Metering Cluster structure and attributes

The Simple Metering cluster is contained in the following `tsSE_SimpleMetering` structure:

```
typedef struct
{
    /* Reading information attribute set attribute ID's (D.3.2.2.1) */
    zuint48            u48CurrentSummationDelivered;        /
* Mandatory */
#ifdef CLD_SM_ATTR_CURRENT_SUMMATION_RECEIVED
    zuint48            u48CurrentSummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MAX_DEMAND_DELIVERED
    zuint48            u48CurrentMaxDemandDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MAX_DEMAND_RECEIVED
    zuint48            u48CurrentMaxDemandReceived;
#endif
#ifdef CLD_SM_ATTR_DFT_SUMMATION
    zuint48            u48DFTSummation;
#endif
#ifdef CLD_SM_ATTR_DAILY_FREEZE_TIME
    zuint16            u16DailyFreezeTime;
#endif
#ifdef CLD_SM_ATTR_POWER_FACTOR
    zint8              i8PowerFactor;
#endif
#ifdef CLD_SM_ATTR_READING_SNAPSHOT_TIME
    zutctime           utctReadingSnapshotTime;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MAX_DEMAND_DELIVERED_TIME
    zutctime           utctCurrentMaxDemandDeliveredTime;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MAX_DEMAND_RECEIVED_TIME
    zutctime           utctCurrentMaxDemandReceivedTime;
#endif
#ifdef CLD_SM_ATTR_DEFAULT_UPDATE_PERIOD
    uint8              u8DefaultUpdatePeriod;
#endif
#ifdef CLD_SM_ATTR_FAST_POLL_UPDATE_PERIOD
    uint8              u8FastPollUpdatePeriod;
#endif
#ifdef CLD_SM_ATTR_CURRENT_BLOCK_PERIOD_CONSUMPTION_DELIVERED
    zuint48            u48CurrentBlockPeriodConsumptionDelivered;
#endif
#ifdef CLD_SM_ATTR_DAILY_CONSUMPTION_TARGET
    zuint24            u24DailyConsumptionTarget;
#endif
#ifdef CLD_SM_ATTR_CURRENT_BLOCK
    zenum8             e8CurrentBlock;
#endif
#ifdef CLD_SM_SUPPORT_GET_PROFILE
#ifdef CLD_SM_ATTR_PROFILE_INTERVAL_PERIOD
    zenum8             eProfileIntervalPeriod;
#endif
#ifdef CLD_SM_ATTR_INTERVAL_READ_REPORTING_PERIOD
    uint16             u16IntervalReadReportingPeriod;
#endif
#endif  // CLD_SM_SUPPORT_GET_PROFILE
#ifdef CLD_SM_ATTR_PREVIOUS_BLOCK_PERIOD_CONSUMPTION_DELIVERED
    zuint48            u48PreviousBlockPeriodConsumptionDelivered;
#endif
#ifdef CLD_SM_ATTR_PRESET_READING_TIME
    uint16             u16PresetReadingTime;
#endif
#ifdef CLD_SM_ATTR_VOLUME_PER_REPORT
    uint16             u16VolumePerReport;
#endif
#ifdef CLD_SM_ATTR_FLOW_RESTRICTION
    uint8              u8FlowRestriction;
#endif
#ifdef CLD_SM_ATTR_SUPPLY_STATUS
    zbmap8             u8SupplyStatus;
#endif
#ifdef CLD_SM_ATTR_CURRENT_INLET_ENERGY_CARRIER_SUMMATION
    zuint48            u48CurrentInletEnergyCarrierSummation;
#endif
#ifdef CLD_SM_ATTR_CURRENT_OUTLET_ENERGY_CARRIER_SUMMATION
    zuint48            u48CurrentOutletEnergyCarrierSummation;
#endif
#ifdef CLD_SM_ATTR_INLET_TEMPERATURE
    int16              i16InletTemperature;
#endif
#ifdef CLD_SM_ATTR_OUTLET_TEMPERATURE
    int16              i16OutletTemperature;
#endif
#ifdef CLD_SM_ATTR_CONTROL_TEMPERATURE
    int16              i16ControlTemperature;
#endif
#ifdef CLD_SM_ATTR_CURRENT_INLET_ENERGY_CARRIER_DEMAND
    zint24             i24CurrentInletEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_OUTLET_ENERGY_CARRIER_DEMAND
    zint24             i24CurrentOutletEnergyCarrierDemand;
#endif
    /* Time Of Use Information attribute attribute ID's set (D.3.2.2.2) */
#ifdef CLD_SM_ATTR_CURRENT_TIER_1_SUMMATION_DELIVERED
    zuint48            u48CurrentTier1SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_1_SUMMATION_RECEIVED
    zuint48            u48CurrentTier1SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_2_SUMMATION_DELIVERED
    zuint48            u48CurrentTier2SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_2_SUMMATION_RECEIVED
    zuint48            u48CurrentTier2SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_3_SUMMATION_DELIVERED
    zuint48            u48CurrentTier3SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_3_SUMMATION_RECEIVED
    zuint48            u48CurrentTier3SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_4_SUMMATION_DELIVERED
    zuint48            u48CurrentTier4SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_4_SUMMATION_RECEIVED
    zuint48            u48CurrentTier4SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_5_SUMMATION_DELIVERED
    zuint48            u48CurrentTier5SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_5_SUMMATION_RECEIVED
    zuint48            u48CurrentTier5SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_6_SUMMATION_DELIVERED
    zuint48            u48CurrentTier6SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_6_SUMMATION_RECEIVED
    zuint48            u48CurrentTier6SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_7_SUMMATION_DELIVERED
    zuint48            u48CurrentTier7SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_7_SUMMATION_RECEIVED
    zuint48            u48CurrentTier7SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_8_SUMMATION_DELIVERED
    zuint48            u48CurrentTier8SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_8_SUMMATION_RECEIVED
    zuint48            u48CurrentTier8SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_9_SUMMATION_DELIVERED
    zuint48            u48CurrentTier9SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_9_SUMMATION_RECEIVED
    zuint48            u48CurrentTier9SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_10_SUMMATION_DELIVERED
    zuint48            u48CurrentTier10SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_10_SUMMATION_RECEIVED
    zuint48            u48CurrentTier10SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_11_SUMMATION_DELIVERED
    zuint48            u48CurrentTier11SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_11_SUMMATION_RECEIVED
    zuint48            u48CurrentTier11SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_12_SUMMATION_DELIVERED
    zuint48            u48CurrentTier12SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_12_SUMMATION_RECEIVED
    zuint48            u48CurrentTier12SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_13_SUMMATION_DELIVERED
    zuint48            u48CurrentTier13SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_13_SUMMATION_RECEIVED
    zuint48            u48CurrentTier13SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_14_SUMMATION_DELIVERED
    zuint48            u48CurrentTier14SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_14_SUMMATION_RECEIVED
    zuint48            u48CurrentTier14SummationReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_15_SUMMATION_DELIVERED
    zuint48            u48CurrentTier15SummationDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_TIER_15_SUMMATION_RECEIVED
    zuint48            u48CurrentTier15SummationReceived;
#endif
    /* Meter status attribute set attribute ID's (D.3.2.2.3) */
    zbmap8             u8MeterStatus;                        /* Mandatory */
#ifdef CLD_SM_ATTR_REMAINING_BATTERY_LIFE
    uint8              u8RemainingBatteryLife;
#endif
#ifdef CLD_SM_ATTR_HOURS_IN_OPERATION
    zuint24            u24HoursInOperation;
#endif
#ifdef CLD_SM_ATTR_HOURS_IN_FAULT
    zuint24            u24HoursInFault;
#endif
    /* Formatting attribute set attribute ID's (D.3.2.2.4) */
    zenum8             eUnitOfMeasure;                        /* Mandatory */
#ifdef CLD_SM_ATTR_MULTIPLIER
    zuint24            u24Multiplier;
#endif
#ifdef CLD_SM_ATTR_DIVISOR
    zuint24            u24Divisor;
#endif
    zbmap8             u8SummationFormatting;                /* Mandatory */
#ifdef CLD_SM_ATTR_DEMAND_FORMATING
    zbmap8             u8DemandFormatting;
#endif
#ifdef CLD_SM_ATTR_HISTORICAL_CONSUMPTION_FORMATTING
    zbmap8             u8HistoricalConsumptionFormatting;
#endif
    zbmap8             eMeteringDeviceType;                /* Mandatory */
#ifdef CLD_SM_ATTR_SITE_ID
    tsZCL_OctetString  sSiteId;
    uint8              au8SiteId[SE_SM_SITE_ID_MAX_STRING_LENGTH];
#endif
#ifdef CLD_SM_ATTR_METER_SERIAL_NUMBER
   tsZCL_OctetString  sMeterSerialNumber;
 uint8   au8MeterSerialNumber[SE_SM_METER_SERIAL_NUMBER_MAX_STRING_LENGTH];
#endif
#ifdef CLD_SM_ATTR_ENERGY_CARRIER_UNIT_OF_MEASURE
    zenum8         e8EnergyCarrierUnitOfMeasure;
#endif
#ifdef CLD_SM_ATTR_ENERGY_CARRIER_SUMMATION_FORMATTING
    zbmap8         u8EnergyCarrierSummationFormatting;
#endif
#ifdef CLD_SM_ATTR_ENERGY_CARRIER_DEMAND_FORMATTING
    zbmap8         u8EnergyCarrierDemandFormatting;
#endif
#ifdef CLD_SM_ATTR_TEMPERATURE_UNIT_OF_MEASURE
    zenum8         e8TemperatureUnitOfMeasure;
#endif
#ifdef CLD_SM_ATTR_TEMPERATURE_FORMATTING
    zbmap8          u8TemperatureFormatting;
#endif
    /* ESP Historical Consumption set attribute ID's (D.3.2.2.5) */
#ifdef CLD_SM_ATTR_INSTANTANEOUS_DEMAND
    zint24         i24InstantaneousDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_CONSUMPTION_DELIVERED
    zuint24         u24CurrentDayConsumptionDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_CONSUMPTION_RECEIVED
    zuint24         u24CurrentDayConsumptionReceived;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_CONSUMPTION_DELIVERED
    zuint24         u24PreviousDayConsumptionDelivered;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_CONSUMPTION_RECEIVED
    zuint24         u24PreviousDayConsumptionReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_PARTIAL_PROFILE_INTERVAL_START_TIME_DELIVERED
 zutctime     utctCurrentPartialProfileIntervalStartTimeDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_PARTIAL_PROFILE_INTERVAL_START_TIME_RECEIVED
 zutctime      utctCurrentPartialProfileIntervalStartTimeReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_PARTIAL_PROFILE_INTERVAL_VALUE_DELIVERED
 zuint24  u24CurrentPartialProfileIntervalValueDelivered;
#endif
#ifdef CLD_SM_ATTR_CURRENT_PARTIAL_PROFILE_INTERVAL_VALUE_RECEIVED
 zuint24   u24CurrentPartialProfileIntervalValueReceived;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_MAXIMUM_PRESSURE
 zuint48  u48CurrentDayMaxPressure;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_MINIMUM_PRESSURE
 zuint48    u48CurrentDayMinPressure;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_MAXIMUM_PRESSURE
  zuint48  u48PreviousDayMaxPressure;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_MINIMUM_PRESSURE
   zuint48     u48PreviousDayMinPressure;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_MAXIMUM_DEMAND
  zint24   i24CurrentDayMaxDemand;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_MAXIMUM_DEMAND
  zint24      i24PreviousDayMaxDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MONTH_MAXIMUM_DEMAND
  zint24      i24CurrentMonthMaxDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_YEAR_MAXIMUM_DEMAND
    zint24     i24CurrentYearMaxDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_DAY_MAXIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24CurrentDayMaxEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_PREVIOUS_DAY_MAXIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24PreviousDayMaxEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MONTH_MAXIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24CurrentMonthMaxEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_MONTH_MINIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24CurrentMonthMinEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_YEAR_MAXIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24CurrentYearMaxEnergyCarrierDemand;
#endif
#ifdef CLD_SM_ATTR_CURRENT_YEAR_MINIMUM_ENERGY_CARRIER_DEMAND
  zint24         i24CurrentYearMinEnergyCarrierDemand;
#endif
/* Load Profile attribute set attribute ID's (D.3.2.2.6) */
#ifdef CLD_SM_ATTR_MAX_NUMBER_OF_PERIODS_DELIVERED
  zuint8   u8MaxNumberOfPeriodsDelivered;
#endif
/* Supply Limit attribute set attribute ID's (D.3.2.2.7) */
#ifdef CLD_SM_ATTR_CURRENT_DEMAND_DELIVERED
 zuint24      u24CurrentDemandDelivered;
#endif
#ifdef CLD_SM_ATTR_DEMAND_LIMIT
    zuint24    u24DemandLimit;
#endif
#ifdef CLD_SM_ATTR_DEMAND_INTEGRATION_PERIOD
    zuint8      u8DemandIntegrationPeriod;
#endif
#ifdef CLD_SM_ATTR_NUMBER_OF_DEMAND_SUBINTERVALS
    zuint8      u8NumberOfDemandSubintervals;
#endif
/* Block Information attribute set attribute ID's (D.3.2.2.8) */
/* No Tier Block */
#if (CLD_SM_ATTR_NO_TIER_BLOCK_CURRENT_SUMMATION_DELIVERED_MAX_COUNT != 0)
 zuint48  au48CurrentNoTierBlockSummationDelivered
[CLD_SM_ATTR_NO_TIER_BLOCK_CURRENT_SUMMATION_DELIVERED_MAX_COUNT];
#endif
    /* Tier 1 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 0)&&
 (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
 zuint48  au48CurrentTier1BlockSummationDelivered
   [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 2 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 1)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
zuint48  au48CurrentTier2BlockSummationDelivered
   [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
/* Tier 3 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 2)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
  zuint48    au48CurrentTier3BlockSummationDelivered
    [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 4 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 3)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48   au48CurrentTier4BlockSummationDelivered
    [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 5 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 4)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48   au48CurrentTier5BlockSummationDelivered
    [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 6 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 5)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48      au48CurrentTier6BlockSummationDelivered
      [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 7 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 6)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48     au48CurrentTier7BlockSummationDelivered
      [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 8 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 7)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48      au48CurrentTier8BlockSummationDelivered
      [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 9 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 8)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48      au48CurrentTier9BlockSummationDelivered
       [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 10 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 9)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48     au48CurrentTier10BlockSummationDelivered
      [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 11 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 10)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48  au48CurrentTier11BlockSummationDelivered
       [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 12 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 11)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48   au48CurrentTier12BlockSummationDelivered
       [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 13 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 12)&&
     (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48   au48CurrentTier13BlockSummationDelivered
      [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 14 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 13)&&
  CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
  zuint48     au48CurrentTier14BlockSummationDelivered
   [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Tier 15 Block Set */
#if ((CLD_SM_ATTR_NUM_OF_TIERS_CURRENT_SUMMATION_DELIVERED > 14)&&
   (CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED != 0))
    zuint48  au48CurrentTier15BlockSummationDelivered
     [CLD_SM_ATTR_NUM_OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED];
#endif
    /* Alarm attribute set attribute ID's (D.3.2.2.9) */
#ifdef CLD_SM_ATTR_GENERIC_ALARM_MASK
    zbmap16     u16GenericAlarmMask;
#endif
#ifdef CLD_SM_ATTR_ELECTRICITY_ALARM_MASK
    zbmap32     u32ElectricityAlarmMask;
#endif
#ifdef CLD_SM_ATTR_PRESSURE_ALARM_MASK
    zbmap16      u16PressureAlarmMask;
#endif
#ifdef CLD_SM_ATTR_WATER_SPECIFIC_ALARM_MASK
    zbmap16      u16WaterSpecificAlarmMask;
#endif
#ifdef CLD_SM_ATTR_HEAT_AND_COOLING_ALARM_MASK
    zbmap16      u16HeatAndCoolingSpecificAlarmMask;
#endif
#ifdef CLD_SM_ATTR_GAS_ALARM_MASK
    zbmap16      u16GasAlarmMask;
#endif
} tsCLD_SimpleMetering; 

```

where:

## ‘Reading Information’ Attribute Set 

-   `u48CurrentSummationDelivered` is the total amount of the measured resource \(e.g. electrical energy\) delivered to the premises so far, expressed in the units specified in `eUnitOfMeasure` and in the format specified in `u8SummationFormatting`

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*:


```
u48CurrentSummationReceived
u48CurrentMaxDemandDelivered
u48CurrentMaxDemandReceived
u48DFTSummation
u16DailyFreezeTime
i8PowerFactor
utctReadingSnapshotTime
utctCurrentMaxDemandDeliveredTime
utctCurrentMaxDemandReceivedTime

```

-   The following are optional attributes that relate to Fast Polling mode \(*both attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):

    -   `u32DefaultUpdatePeriod` is the default poll-period, in seconds, that is used in updating metering data outside of fast polling episodes

    -   `u8FastPollUpdatePeriod` is the minimum poll-period, in seconds, that can be used in updating metering data during fast polling episodes \(should not be set to less than 2 seconds\)

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
u48CurrentBlockPeriodConsumptionDelivered
u24DailyConsumptionTarget
e8CurrentBlock

```

-   The following are optional attributes that relate to the ‘Get Profile’ feature:

    -   `eProfileIntervalPeriod` is the time-interval over which one set of consumption data will be collected

    -   `u32IntervalReadReportingPeriod` is the time-interval, in minutes, after which a sleepy End Device should wake up to provide metering data

-   The following are optional attributes are fully described in the *ZigBee Smart Energy Profile Specification* \(*all these attributes except*`u8SupplyStatus` *are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
u16PresetReadingTime
u16VolumePerReport
u8FlowRestriction
u8SupplyStatus
u48CurrentInletEnergyCarrierSummation
u48CurrentOutletEnergyCarrierSummation
i16InletTemperature
i16OutletTemperature
i16ControlTemperature
i24CurrentInletEnergyCarrierDemand
i24CurrentOutletEnergyCarrierDemand

```

## ‘Time-Of-Use \(TOU\) Information’ Attribute Set 

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*the attributes for tiers 7 to 15 are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
u48CurrentTier1SummationDelivered
u48CurrentTier1SummationReceived
u48CurrentTier2SummationDelivered
u48CurrentTier2SummationReceived
...
...
...
...
u48CurrentTier15SummationDelivered
u48CurrentTier15SummationReceived

```

```

```

## ‘Meter Status’ Attribute Set 

-   `u``8MeterStatus` is an 8-bit bitmap representing the status of the meter. Enumerated masks are provided that correspond to the possible settings - see [Section 42.10.2](meter_status_enumerations.md#id_e348bd95-336b-4f5c-bfdc-948d60dc84e5)*\(this attribute is only certifiable for electricity meters in SE 1.1.1\)*

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*all the attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
u8RemainingBatteryLife
u24HoursInOperation
u24HoursInFault

```

## ‘Formatting’ Attribute Set 

-   `eUnitOfMeasure` indicates the unit of measure for the resource quantity contained above in `u48CurrentSummationDelivered` and below in `i24InstantaneousDemand`. Enumerations for the possible units are provided - see [Section 42.10.3](unit_of_measure_enumerations.md#id_ee7f39b7-56bc-4008-b2e9-3e13449c50d0)

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*:


```
u24Multiplier
u24Divisor

```

-   `u8SummationFormatting` indicates the formatting for the resource quantity contained above in `u48CurrentSummationDelivered`. Enumerations for the possible formats are provided - see [Section 42.10.4](summation_formatting_enumerations.md#id_0dd55d84-6982-431a-a9c9-f46539124377)

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*:


```
u8DemandFormatting
u8HistoricalConsumptionFormatting

```

-   `eMeteringDeviceType` indicates the type of Metering Device in terms of the resource type which it measures. Enumerations for the possible device types are provided - see [Section 42.10.6](metering_device_type_enumerations.md#id_67ec54ac-d1b7-4ffe-adc7-1ce5ec2e3c08)

-   The following pair of elements represents an optional attribute which identifies the location of a Metering Device \(*this attribute is not certifiable in SE 1.1.1 or earlier and is for future use*\):

    -   `sSiteId` is a `tsZCL_OctetString` structure containing information on the site identifier. This element is paired with `au8SiteId` \(below\)

    -   `au8SiteId` is an array containing the site identifier. This element is paired with `sSiteId` \(above\)


**Note:** This identifier is known in the UK as the M-PAN for electricity and MPRN for gas, and in South Africa as as the 'Stand Point'. The field is large enough to accommodate the number of characters typically used in the UK and Europe \(16 digits\).

-   The following pair of elements represents an optional attribute, which indicates the serial number of a Metering Device \(*this attribute is not certifiable in SE 1.1.1 or earlier and is for future use*\):

    -   `sMeterSerialNumber` is a `tsZCL_OctetString` structure containing information on the serial number of a Metering Device. This element is paired with `au8SiteId` \(below\)

    -   `au8MeterSerialNumber` is an array containing the serial number of a Metering Device. This element is paired with `sMeterSerialNumber` \(above\)

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
e8EnergyCarrierUnitOfMeasure
u8EnergyCarrierSummationFormatting
u8EnergyCarrierDemandFormatting
e8TemperatureUnitOfMeasure
u8TemperatureFormatting

```

## ‘Historical Consumption’ Attribute Set 

-   `i24InstantaneousDemand` is an optional attribute containing the current rate of consumption of the metered resource with respect to time. The unit of measure for the relevant resource is as specified in `eUnitOfMeasure`

    -   If this attribute is used, the metering application should update its value on a regular basis, between once every second and once every five seconds. The attribute value can be negative, meaning that the relevant resource is currently being supplied from the premises to the utility company - for example, the case of locally generated electricity from roof-mounted solar panels being supplied to the national grid.
-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*:


```
u24CurrentDayConsumptionDelivered
u24CurrentDayConsumptionReceived
u24PreviousDayConsumptionDelivered
u24PreviousDayConsumptionReceived
utctCurrentPartialProfileIntervalStartTimeDelivered
utctCurrentPartialProfileIntervalStartTimeReceived
u24CurrentPartialProfileIntervalValueDelivered
u24CurrentPartialProfileIntervalValueReceived

```

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):


```
u48CurrentDayMaxPressure
u48CurrentDayMinPressure
u48PreviousDayMaxPressure
u48PreviousDayMinPressure
i24CurrentDayMaxDemand
i24PreviousDayMaxDemand
i24CurrentMonthMaxDemand
i24CurrentYearMaxDemand
i24CurrentDayMaxEnergyCarrierDemand
i24PreviousDayMaxEnergyCarrierDemand
i24CurrentMonthMaxEnergyCarrierDemand
i24CurrentMonthMinEnergyCarrierDemand
i24CurrentYearMaxEnergyCarrierDemand
i24CurrentYearMinEnergyCarrierDemand

```

## ‘Load Profile Configuration’ Attribute Set 

-   `u8MaxNumberOfPeriodsDelivered` is an optional attribute from the Simple Metering ‘Load Profile Configuration’ attribute set and is fully described in the *ZigBee Smart Energy Profile Specification*.


## ‘Supply Limit’ Attribute Set 

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*:


```
u24CurrentDemandDelivered
u24DemandLimit
u8DemandIntegrationPeriod
u8NumberOfDemandSubintervals

```

## ‘Block Information’ Attribute Set 

-   The following are optional attributes and are fully described in the *ZigBee Smart Energy Profile Specification*\(*these attributes are not certifiable in SE 1.1.1 or earlier and are for future use*\):

    ```
     au48CurrentNoTierBlockSummationDelivered[CLD_SM_ATTR_NO_TIER_BLOCK_CU
    RRENT_SUMMATION_DELIVERED_MAX_COUNT]
     au48CurrentTier1BlockSummationDelivered[CLD_SM_ATTR_NUM_OF
    _BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier2BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier3BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier4BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier5BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier6BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier7BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier8BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier9BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier10BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier11BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier12BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier13BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier14BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
     au48CurrentTier15BlockSummationDelivered[CLD_SM_ATTR_NUM_
    OF_BLOCKS_IN_EACH_TIER_CURRENT_SUMMATION_DELIVERED]
    ```


**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

