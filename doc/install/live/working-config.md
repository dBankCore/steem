# Working Config For dPay Livenet

```
# Set larger shared-file-size than default
shared-file-size = 215G

# Set an API to be publicly available, may be specified multiple times
public-api = database_api login_api account_by_key_api network_broadcast_api tag_api follow_api market_history_api raw_block_api block_info_api

# Plugin(s) to enable, may be specified multiple times
enable-plugin = witness account_by_key tags follow market_history raw_block private_message block_info account_history

# JSON list of [nblocks,nseconds] pairs, see doc/bcd-trigger.md
bcd-trigger = [[0,10],[85,300]]

# Defines a range of accounts to track as a json pair ["from","to"] [from,to]

# track-account-range =

rpc-endpoint = 127.0.0.1:1776

p2p-endpoint = 0.0.0.0:80

# history-whitelist-ops = transfer_operation transfer_to_vesting_operation withdraw_vesting_operation interest_operation transfer_to_savings_operation transfer_from_savings_operation cancel_transfer_from_savings_operation escrow_transfer_operation escrow_approve_operation escrow_dispute_operation escrow_release_operation convert_operation fill_convert_request_operation fill_order_operation claim_reward_balance_operation author_reward_operation curation_reward_operation fill_vesting_withdraw_operation fill_transfer_from_savings_operation delegate_vesting_shares_operation return_vesting_delegation_operation comment_benefactor_reward_operation

# Ignore posting operations, only track transfers and account updates
# filter-posting-ops =

# Database edits to apply on startup (may specify multiple times)
# edit-script =

# RPC endpoint of a trusted validating node (required)
# trusted-node = 51.15.140.244:6620

# Set the maximum size of cached feed for an account
follow-max-feed-size = 500

# Track market history by grouping orders into buckets of equal size measured in seconds specified as a JSON array of numbers
bucket-size = [15,60,300,3600,86400]

# How far back in time to track history for each bucket size, measured in the number of buckets (default: 5760)
history-per-size = 5760

# Defines a range of accounts to private messages to/from as a json pair ["from","to"] [from,to)
# pm-account-range =

# Enable block production, even if the chain is stale.
enable-stale-production = false

# Percent of witnesses (0-99) that must be participating in order to produce blocks
required-participation = false

# Skip enforcing bandwidth restrictions. Default is true in favor of rc_plugin.
witness-skip-enforce-bandwidth = true

# name of witness controlled by this node (e.g. dpay )
witness = "xxx"

# WIF PRIVATE KEY to be used by one or more witnesses or miners
private-key = xxx

# declare an appender named "stderr" that writes messages to the console
[log.console_appender.stderr]
stream=std_error

# declare an appender named "p2p" that writes messages to p2p.log
[log.file_appender.p2p]
filename=logs/p2p/p2p.log
#filename can be absolute or relative to this config file

# route any messages logged to the default logger to the "stderr" logger we
# declared above, if they are info level are higher
[logger.default]
level=debug
appenders=stderr

# route messages sent to the "p2p" logger to stderr too
[logger.p2p]
level=info
appenders=stderr
```
