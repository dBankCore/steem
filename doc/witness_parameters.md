# Witness Parameters

The role of a witness in the Steem Blockchain is verify incoming transactions, produce blocks when scheduled, and partake in the Steem governance model by voting on several parameters.

These parameters control various aspects of the operation of the blockchain that are not easily defined in code at compile time. One example is the STEEM price feed that defines the conversion rate between STEEM and SBD.

Witnesses are able to use the `witness_set_properties_operation` to change witness specific properties and vote on paramters.

Unless otherwise noted, the median of the top 20 elected witnesses is used for all calculations needing the parameter.

This operation was added in Steem v0.20.0 to replace the `witness_update_operation` which was not easily extendable. While it is recommended to use `witness_set_properties_operation`, `witness_update_operation` will continue to work.

## Properties

### account_creation_fee

This is the fee in STEEM that must be paid to create an account. This field must be non-negative.

### account_subsidy_budget

The account subsidies to be added to the account subisidy per block. This is the maximum rate that accounts can be created via subsidization.
The value must be between `1` and `268435455`.

### account_subsidy_decay

The per block decay of the account subsidy pool. Must be between `64` and `4294967295` where `4294967295` is 100% decay per block.

Below are some example values:

| Half-Life | `account_subsidy_decay` |
|:----------|------------------------:|
| 1 Hour | 2480150 |
| 2 Hours | 1240260 |
| 4 Hours | 620173 |
| 8 Hours | 310098 |
| 12 Hours | 206734 |
| 1 Day | 103368 |
| 2 Days | 51684 |
| 4 Days | 25842 |
| 1 Week | 14767 |

### maximum_block_size

The maximum size of a single block in bytes. The value must be larger than `65536`.

### sbd_interest_rate

The annual interest rate paid to SBD holders. SBD interest is compounded on balance changes, no more than once every 30 days.

### sbd_exchange_rate

The exchange rate for STEEM/SDB to be used for printing SBD as rewards as well as SBD->STEEM conversions.
The actual price feed is the median of medians. Every round (21 blocks) the median exchange rate is pushed to a queue and the oldest is removed. The median value of the queue is used for any calculations.

### url

A witness published URL, usually to a public seed node they operate. The URL must not be longer than 2048 characters.

### new_signing_key

Sets the signing key for the witness required to validate produced blocks.