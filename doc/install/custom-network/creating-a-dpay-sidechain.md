# Creating A dPay SideChain 

## Generating Your Chain ID, Init Public Key, Private Key and SideChain Name

- Go to dPay's config within the `stable` branch and edit the [dPay Config](https://github.com/dpays/dpay/blob/stable/libraries/protocol/include/dpay/protocol/config.hpp)
by looking for `IS_TEST_NET` variable and changing the name of the testnet blockchain on [Line 19](https://github.com/dpays/dpay/blob/stable/libraries/protocol/include/dpay/protocol/config.hpp#L19) to the
name of your blockchain.
- Startup the blockchain by building dPay with the `-DBUILD_DPAY_TESTNET=ON`
- After the build completes, start `dpayd` and quickly stop it. You will then see your chainID, init public key and the corresponding private key.


## Editing config.hpp
- Now add the public key to the `IS_LIVE_NET` portion of dPay's config file to the config variable  `DPAY_INIT_PUBLIC_KEY_STR` on [Line 236](https://github.com/dpays/dpay/blob/stable/libraries/protocol/include/dpay/protocol/config.hpp#L236), then change the sidechain's name to the same name that you used for the testnet name under the config variable `DPAY_CHAIN_ID ` at [Line 237](https://github.com/dpays/dpay/blob/stable/libraries/protocol/include/dpay/protocol/config.hpp#L237) and on [Line 280](https://github.com/dpays/dpay/blob/stable/libraries/protocol/include/dpay/protocol/config.hpp#L280) under the config variable `DPAY_INIT_MINER_NAME`, add the name  of the initial  


## Editing config.ini
- Edit the `config.ini` via `~/.dpayd/config.ini` and add the private key that you got when generating the chainID in the first few steps under the `private-key` variable and under the `witness` config variable, add the name of the initminer you put within the `config.hpp` file for the `DPAY_INIT_MINER_NAME` config variable.

## Startup Your Network
- Simply type `dpayd` and your network should start right up.

## TODO: Expanding This Documentation
Throughout the next few days, we will be expanding this documentation, with corresponding [dSite.io](https://dsite.io) posts, about how to setup your own dPay-based sidechain or even a completely separate network.
