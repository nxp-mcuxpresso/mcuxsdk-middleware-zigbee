# Compile-time options

This section describes the compile-time options that may be enabled in the **zcl\_options.h** file of an application that uses the Simple Metering cluster.

The Simple Metering cluster is enabled by defining CLD\_SIMPLE\_METERING.

## Optional Attributes 

The optional attributes for the Simple Metering cluster are enabled/disabled by defining:

-   For optional attributes from ‘Reading Information’ attribute set:

    -   CLD\_SM\_ATTR\_CURRENT\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_MAX\_DEMAND\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_MAX\_DEMAND\_RECEIVED

    -   CLD\_SM\_ATTR\_DFT\_SUMMATION

    -   CLD\_SM\_ATTR\_DAILY\_FREEZE\_TIME

    -   CLD\_SM\_ATTR\_POWER\_FACTOR

    -   CLD\_SM\_ATTR\_READING\_SNAPSHOT\_TIME

    -   CLD\_SM\_ATTR\_CURRENT\_MAX\_DEMAND\_DELIVERED\_TIME

    -   CLD\_SM\_ATTR\_CURRENT\_MAX\_DEMAND\_RECEIVED\_TIME

-   For optional attributes from ‘Time-Of-Use \(TOU\) Information’ attribute set:

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_1\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_1\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_2\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_2\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_3\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_3\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_4\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_4\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_5\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_5\_SUMMATION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_6\_SUMMATION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_TIER\_6\_SUMMATION\_RECEIVED

-   For optional attributes from ‘Block Information’ attribute set:

    -   CLD\_SM\_ATTR\_NO\_TIER\_BLOCK\_CURRENT\_SUMMATION\_DELIVERED\_MAX\_COUNT \(maximum value of 16\)

    -   CLD\_SM\_ATTR\_NUM\_OF\_TIERS\_CURRENT\_SUMMATION\_DELIVERED

        \(maximum value of 15\)

    -   CLD\_SM\_ATTR\_NUM\_OF\_BLOCKS\_IN\_EACH\_TIER\_CURRENT\_SUMMATION\_DELIVERED

        \(maximum value of 16\)

-   For optional attributes from ‘Formatting’ attribute set:

    -   CLD\_SM\_ATTR\_MULTIPLIER

    -   CLD\_SM\_ATTR\_DIVISOR

    -   CLD\_SM\_ATTR\_DEMAND\_FORMATING

    -   CLD\_SM\_ATTR\_HISTORICAL\_CONSUMPTION\_FORMATTING

-   For optional attributes from ‘ESP Historical Consumption’ attribute set:

    -   CLD\_SM\_ATTR\_INSTANTANEOUS\_DEMAND

    -   CLD\_SM\_ATTR\_CURRENT\_DAY\_CONSUMPTION\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_DAY\_CONSUMPTION\_RECEIVED

    -   CLD\_SM\_ATTR\_PREVIOUS\_DAY\_CONSUMPTION\_DELIVERED

    -   CLD\_SM\_ATTR\_PREVIOUS\_DAY\_CONSUMPTION\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_START\_TIME\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_START\_TIME\_RECEIVED

    -   CLD\_SM\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_VALUE\_DELIVERED

    -   CLD\_SM\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_VALUE\_RECEIVED

-   For optional attribute from ‘Load Profile’ attribute set:

    -   CLD\_SM\_ATTR\_MAX\_NUMBER\_OF\_PERIODS\_DELIVERED

-   For optional attributes from ‘Supply Limit’ attribute set:

    -   CLD\_SM\_ATTR\_CURRENT\_DEMAND\_DELIVERED

    -   CLD\_SM\_ATTR\_DEMAND\_LIMIT

    -   CLD\_SM\_ATTR\_DEMAND\_INTEGRATION\_PERIOD

    -   CLD\_SM\_ATTR\_NUMBER\_OF\_DEMAND\_SUBINTERVALS


## Mirroring 

If the mirroring of metering data is to be enabled \(see [Section 42.5](mirroring_metering_data.md#id_5c7e7e7a-7756-4e07-8334-371d731931ac)\), the following options must be defined in the **zcl\_options.h** file.

On the Simple Metering server on the Metering Device \(which will request and report to a mirror on a mirroring server, such as the ESP\), there is no need to define anything.

On the Simple Metering client on the mirroring server, such as the ESP, the mirroring option must be enabled by including:

```
#define CLD_SM_SUPPORT_MIRROR

```

In addition, the following defines must be added on the mirroring server \(e.g. ESP\):

```
#define CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT

```

        \(flags support for mirroring via a non-zero value of the `u8PhysicalEnvironment` attribute of the Basic cluster\)

```
#define CLD_SM_NUMBER_OF_MIRRORS            <n>

```

\(sets the maximum number of mirrors supported on the mirroring server to the value `n`\)

```
#define ZCL_ATTRIBUTE_REPORTING_CLIENT_SUPPORTED

```

\(enables support for attribute reporting clients\)

The Simple Metering cluster attributes that are supported by mirroring must be defined on the mirroring server \(the same set of attributes are mirrored on all endpoints\):

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_MAX\_DEMAND\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_MAX\_DEMAND\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_DFT\_SUMMATION

-   CLD\_SM\_MIRROR\_ATTR\_DAILY\_FREEZE\_TIME

-   CLD\_SM\_MIRROR\_ATTR\_POWER\_FACTOR

-   CLD\_SM\_MIRROR\_ATTR\_READING\_SNAPSHOT\_TIME

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_MAX\_DEMAND\_DELIVERED\_TIME

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_MAX\_DEMAND\_RECEIVED\_TIME

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_1\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_1\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_2\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_2\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_3\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_3\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_4\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_4\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_5\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_5\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_6\_SUMMATION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_TIER\_6\_SUMMATION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_MULTIPLIER

-   CLD\_SM\_MIRROR\_ATTR\_DIVISOR

-   CLD\_SM\_MIRROR\_ATTR\_DEMAND\_FORMATING

-   CLD\_SM\_MIRROR\_ATTR\_HISTORICAL\_CONSUMPTION\_FORMATTING

-   CLD\_SM\_MIRROR\_ATTR\_INSTANTANEOUS\_DEMAND

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_DAY\_CONSUMPTION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_DAY\_CONSUMPTION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_PREVIOUS\_DAY\_CONSUMPTION\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_PREVIOUS\_DAY\_CONSUMPTION\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_START\_TIME\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_START\_TIME\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_VALUE\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_PARTIAL\_PROFILE\_INTERVAL\_VALUE\_RECEIVED

-   CLD\_SM\_MIRROR\_ATTR\_MAX\_NUMBER\_OF\_PERIODS\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_CURRENT\_DEMAND\_DELIVERED

-   CLD\_SM\_MIRROR\_ATTR\_DEMAND\_LIMIT

-   CLD\_SM\_MIRROR\_ATTR\_DEMAND\_INTEGRATION\_PERIOD

-   CLD\_SM\_MIRROR\_ATTR\_NUMBER\_OF\_DEMAND\_SUBINTERVALS


The Basic cluster attributes that are supported by mirroring must also be defined on the mirroring server \(the same set of attributes are mirrored on all endpoints\), from the following:

-   CLD\_BAS\_MIRROR\_ATTR\_APPLICATION\_VERSION

-   CLD\_BAS\_MIRROR\_ATTR\_STACK\_VERSION

-   CLD\_BAS\_MIRROR\_ATTR\_HARDWARE\_VERSION

-           CLD\_BAS\_MIRROR\_ATTR\_MANUFACTURER\_NAME

-   CLD\_BAS\_MIRROR\_ATTR\_MODEL\_IDENTIFIER

-   CLD\_BAS\_MIRROR\_ATTR\_DATE\_CODE

-   CLD\_BAS\_MIRROR\_ATTR\_LOCATION\_DESCRIPTION

-   CLD\_BAS\_MIRROR\_ATTR\_PHYSICAL\_ENVIRONMENT

-   CLD\_BAS\_MIRROR\_ATTR\_DEVICE\_ENABLED

-           CLD\_BAS\_MIRROR\_ATTR\_ALARM\_MASK

-   CLD\_BAS\_MIRROR\_ATTR\_DISABLE\_LOCAL\_CONFIG


## Get Profile 

If the ‘Get Profile’ feature is to be used \(see [Section 42.6](consumption_data_archive_get_profile.md#id_3743a5ad-3be5-4696-afc6-152bd4d5b1ad)\), the following options must be defined in the **zcl\_options.h** file.

The ‘Get Profile’ option must be enabled on the server and clients by including:

```
#define CLD_SM_SUPPORT_GET_PROFILE

```

Then, the following must be included on the server \(only\):

```
#ifdef CLD_SM_SUPPORT_GET_PROFILE
#define      CLD_SM_GETPROFILE_MAX_NO_INTERVALS       <n>
#endif

```

where &lt;n&gt; is the maximum number of consumption intervals to be held on the server \(and therefore determines the amount of memory to be reserved for the circular buffer that is used to store the data for these consumption intervals\).

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

