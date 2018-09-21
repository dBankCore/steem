# dPay Build Variables

## Compile-Time Options (cmake)

### CMAKE_BUILD_TYPE=[Release/Debug]

Specifies whether to build with or without optimization and without or with
the symbol table for debugging. Unless you are specifically debugging or
running tests, it is recommended to build as release.

### LOW_MEMORY_NODE=[OFF/ON]

Builds `dpayd` to be a consensus-only low memory node. Data and fields not
needed for consensus are not stored in the object database.  This option is
recommended for witnesses and seed-nodes.

### CLEAR_VOTES=[ON/OFF]

Clears old votes from memory that are no longer required for consensus.

### BUILD_DPAY_JEFFERSON=[OFF/ON]

Builds for dPay's `Jefferson Dev Network`.

### BUILD_DPAY_JACKSON=[OFF/ON]

Builds for dPay's `Jackson Test Network`.

### BUILD_DPAY_FRANKLIN=[OFF/ON]

Builds for dPay's `Franklin Test Network`.

### BUILD_DPAY_KENNEDY=[OFF/ON]

Builds for dPay's `Kennedy Test Network`.

### BUILD_DPAY_TESTNET=[OFF/ON]

Launches a new custom dPay blockchain.

### SKIP_BY_TX_ID=[OFF/ON]

By default this is off. Enabling will prevent the account history plugin querying transactions
by id, but saving around 65% of CPU time when reindexing. Enabling this option is a
huge gain if you do not need this functionality.
