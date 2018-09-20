/*
 * Copyright (c) 2016 Steemit, Inc., and contributors.
 * Copyright (c) 2018 dPay, DAO., and contributors.
 */
#pragma once

#define DPAY_BLOCKCHAIN_VERSION              ( version(0, 9, 0) )
#define DPAY_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( DPAY_BLOCKCHAIN_VERSION ) )

#ifdef IS_TEST_NET
/*
 * CUSTOM CHAIN CONFIGURATION
 * Configuration settings for a dPay-based CUSTOM CHAINS
 * For more information: https://library.dpays.io/build/
 */
// Change DPAY_CHAIN_ID from "custom" to whatever you would like to name your network. A SHA256 hash is created for the name and used as your dPay ChainID.
#define DPAY_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define DPAY_INIT_PUBLIC_KEY_STR             (std::string( dpay::protocol::public_key_type(DPAY_INIT_PRIVATE_KEY.get_public_key()) ))
#define DPAY_CHAIN_ID                        (fc::sha256::hash("custom"))

// Change the following dPay Asset symbols to what you would like your network's asset symbols to be.
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('C') << 8) | (uint64_t('H') << 16) | (uint64_t('A') << 24) | (uint64_t('I') << 32) | (uint64_t('N') << 40)) ///< Native Digital Currency with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('C') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< Native Currency-Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('C') << 8) | (uint64_t('H') << 16) | (uint64_t('N') << 24) | (uint64_t('D') << 32) ) ///< Native Currency-Backed Dollars with 3 digits of precision

// Change the following dPay Asset symbols to what you would like your network's asset symbols to be.
#define DPAY_ADDRESS_PREFIX                  "TST"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define DPAY_MIN_ACCOUNT_CREATION_FEE          0

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#elif IS_JACKSON_NET
/*
* DPAY'S JACKSON TEST NETWORK CONFIGURATION
* Configuration settings for dPay's Jackson Test Network.
* https://dpayjackson.com // https://api.dpayjackson.com
*/
#define DPAY_INIT_PUBLIC_KEY_STR             "AND6PnZaAX77eS3KGn7ZChXnceoKLf6xDWb4S96Ps9UaVhM7dqjVP"
#define DPAY_CHAIN_ID                        (fc::sha256::hash("jackson"))
/*
* JACKSON NETWORK CURRENCIES
* `AND` ADDRESS PREFIX
* VESTS
* JACKS (Native currency)
* JBD (FRANK-backed dollars)
* JCKD (FRANK Dollars with 3 digits of precisions)
*/
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('J') << 8) | (uint64_t('A') << 16) | (uint64_t('C') << 24) | (uint64_t('K') << 32) | (uint64_t('S') << 40)) ///< JACKS with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('J') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< JACKS Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('J') << 8) | (uint64_t('C') << 16) | (uint64_t('K') << 24) | (uint64_t('D') << 32) ) ///< JACKS Dollars with 3 digits of precision

#define DPAY_ADDRESS_PREFIX                  "AND"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define DPAY_MIN_ACCOUNT_CREATION_FEE          0

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1


#elif IS_JEFFERSON_NET
/*
* DPAY'S JEFFERSON TEST NETWORK CONFIGURATION
* Configuration settings for dPay's Jefferson Test Network.
* https://dpayjefferson.com // https://api.dpayjefferson.com
*/
#define DPAY_INIT_PUBLIC_KEY_STR             "JEF6SyB39dThzq94tPR2cYnf7gr391YuhqJajCvVssj1Ddj5qfwxN"
#define DPAY_CHAIN_ID                        (fc::sha256::hash("jefferson"))
/*
* JEFFERSON NETWORK CURRENCIES
* `JEF` ADDRESS PREFIX
* VESTS
* FREE (Native currency) aka FREEDOM
* FBD (FREEDOM-backed dollars)
* FRED (FREEDOM Dollars with 3 digits of precisions)
*/
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('R') << 16) | (uint64_t('E') << 24) | (uint64_t('E') << 32)) ///< FREE with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< FREE Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('R') << 16) | (uint64_t('E') << 24) | (uint64_t('D') << 32) ) ///< FREE Dollars with 3 digits of precision

#define DPAY_ADDRESS_PREFIX                  "JEF"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define DPAY_MIN_ACCOUNT_CREATION_FEE          0

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#elif IS_FRANKLIN_NET
/*
* DPAY'S FRANKLIN TEST NETWORK CONFIGURATION
* Configuration settings for dPay's Frankin Test Network.
* https://dpayfranklin.com // https://api.dpayfranklin.com
*/
#define DPAY_INIT_PUBLIC_KEY_STR             "BELL5hbK1d7stdVSfZZj23xaQHNydodEQnCuhHCGwm4MrrF3dWck71"
#define DPAY_CHAIN_ID                        (fc::sha256::hash("franklin"))
/*
* FRANKLIN NETWORK CURRENCIES
* `BELL` ADDRESS PREFIX
* VESTS
* FRANK (Native currency)
* FBD (FRANK-backed dollars)
* FRAD (FRANK Dollars with 3 digits of precisions)
*/
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('R') << 16) | (uint64_t('A') << 24) | (uint64_t('N') << 32) | (uint64_t('K') << 40)) ///< FRANK with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< FRANK Backed Dollars (FBD) with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('F') << 8) | (uint64_t('R') << 16) | (uint64_t('A') << 24) | (uint64_t('D') << 32) ) ///< FRANK Dollars with 3 digits of precision

#define DPAY_ADDRESS_PREFIX                  "BELL"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define DPAY_MIN_ACCOUNT_CREATION_FEE          0

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#elif IS_KENNEDY_NET
/*
* DPAY'S KENNEDY TEST NETWORK CONFIGURATION
* Configuration settings for dPay's Kennedy Test Network.
* https://dpaykennedy.com // https://api.dpaykennedy.com
*/
#define DPAY_INIT_PUBLIC_KEY_STR             "JFK7UhVHPw6kBCpA2thaAVgVXwGfGbH9r4fRoZ2ro9VbYZXzoY3Dm"
#define DPAY_CHAIN_ID                        (fc::sha256::hash("kennedy"))

/*
* KENNEDY NETWORK CURRENCIES
* `JFK` ADDRESS PREFIX
* VESTS
* KEN (Native currency)
* KBD (KEN-backed dollars)
* KEND (KEN Dollars with 3 digits of precisions)
*/
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('K') << 8) | (uint64_t('E') << 16) | (uint64_t('N') << 24)) ///< KEN with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('K') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< KEN Backed Dollars (FBD) with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('K') << 8) | (uint64_t('E') << 16) | (uint64_t('N') << 24) | (uint64_t('D') << 32) ) ///< KEN Dollars with 3 digits of precision

#define DPAY_ADDRESS_PREFIX                  "JFK"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (DPAY_CASHOUT_WINDOW_SECONDS)
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*10) /// 10 minutes
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE 0
#define DPAY_MIN_ACCOUNT_CREATION_FEE          0

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#else
#define DPAY_INIT_PUBLIC_KEY_STR             "DWB71hoefovfw8xjGiLpxEDBfc2iDJpAVkbR99PZaiLSR8JiYmp6V"
#define DPAY_CHAIN_ID                        (fc::sha256::hash("dpay"))
#define VESTS_SYMBOL  (uint64_t(6) | (uint64_t('V') << 8) | (uint64_t('E') << 16) | (uint64_t('S') << 24) | (uint64_t('T') << 32) | (uint64_t('S') << 40)) ///< VESTS with 6 digits of precision
#define DPAY_SYMBOL  (uint64_t(3) | (uint64_t('B') << 8) | (uint64_t('E') << 16) | (uint64_t('X') << 24)) ///< BEX with 3 digits of precision
#define BBD_SYMBOL    (uint64_t(3) | (uint64_t('B') << 8) | (uint64_t('B') << 16) | (uint64_t('D') << 24) ) ///< BEX Backed Dollars with 3 digits of precision
#define STMD_SYMBOL   (uint64_t(3) | (uint64_t('B') << 8) | (uint64_t('E') << 16) | (uint64_t('X') << 24) | (uint64_t('D') << 32) ) ///< BEX Dollars with 3 digits of precision
#define DPAY_ADDRESS_PREFIX                  "DWB"

#define DPAY_GENESIS_TIME                    (fc::time_point_sec(1536669076))
#define DPAY_MINING_TIME                     (fc::time_point_sec(1536669076))
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24)    /// 1 day
#define DPAY_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*12)    /// 12 hours
#define DPAY_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define DPAY_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define DPAY_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define DPAY_VOTE_CHANGE_LOCKOUT_PERIOD      (60*60*2)     /// 2 hours
#define DPAY_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define DPAY_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define DPAY_ORIGINAL_MIN_ACCOUNT_CREATION_FEE  100000
#define DPAY_MIN_ACCOUNT_CREATION_FEE           1

#define DPAY_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define DPAY_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define DPAY_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define DPAY_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 3186477

#endif

#define DPAY_BLOCK_INTERVAL                  3
#define DPAY_BLOCKS_PER_YEAR                 (365*24*60*60/DPAY_BLOCK_INTERVAL)
#define DPAY_BLOCKS_PER_DAY                  (24*60*60/DPAY_BLOCK_INTERVAL)
#define DPAY_START_VESTING_BLOCK             (DPAY_BLOCKS_PER_DAY * 7)
#define DPAY_START_MINER_VOTING_BLOCK        (DPAY_BLOCKS_PER_DAY * 30)

#define DPAY_INIT_MINER_NAME                 "initminer"
#define DPAY_NUM_INIT_MINERS                 21
#define DPAY_INIT_TIME                       (fc::time_point_sec());

#define DPAY_MAX_WITNESSES                   21

#define DPAY_MAX_VOTED_WITNESSES_HF0         19
#define DPAY_MAX_MINER_WITNESSES_HF0         1
#define DPAY_MAX_RUNNER_WITNESSES_HF0        1

#define DPAY_MAX_VOTED_WITNESSES_HF17        20
#define DPAY_MAX_MINER_WITNESSES_HF17        0
#define DPAY_MAX_RUNNER_WITNESSES_HF17       1

#define DPAY_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define DPAY_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define DPAY_MAX_MEMO_SIZE                   2048
#define DPAY_MAX_PROXY_RECURSION_DEPTH       4
#define DPAY_VESTING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define DPAY_VESTING_WITHDRAW_INTERVALS      13
#define DPAY_VESTING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define DPAY_MAX_WITHDRAW_ROUTES             10
#define DPAY_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define DPAY_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define DPAY_VOTE_REGENERATION_SECONDS       (5*60*60*24) // 5 day
#define DPAY_MAX_VOTE_CHANGES                5
#define DPAY_REVERSE_AUCTION_WINDOW_SECONDS  (60*30) /// 30 minutes
#define DPAY_MIN_VOTE_INTERVAL_SEC           3
#define DPAY_VOTE_DUST_THRESHOLD             (50000000)

#define DPAY_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define DPAY_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define DPAY_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define DPAY_POST_MAX_BANDWIDTH              (4*DPAY_100_PERCENT) // 2 posts per 1 days, average 1 every 12 hours
#define DPAY_POST_WEIGHT_CONSTANT            (uint64_t(DPAY_POST_MAX_BANDWIDTH) * DPAY_POST_MAX_BANDWIDTH)

#define DPAY_MAX_ACCOUNT_WITNESS_VOTES       30

#define DPAY_100_PERCENT                     10000
#define DPAY_1_PERCENT                       (DPAY_100_PERCENT/100)
#define DPAY_1_TENTH_PERCENT                 (DPAY_100_PERCENT/1000)
#define DPAY_DEFAULT_BBD_INTEREST_RATE       (10*DPAY_1_PERCENT) ///< 10% APR

#define DPAY_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define DPAY_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define DPAY_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define DPAY_CONTENT_REWARD_PERCENT          (75*DPAY_1_PERCENT) //75% of inflation, 7.125% inflation
#define DPAY_VESTING_FUND_PERCENT            (15*DPAY_1_PERCENT) //15% of inflation, 1.425% inflation

#define DPAY_MINER_PAY_PERCENT               (DPAY_1_PERCENT) // 1%
#define DPAY_MIN_RATION                      100000
#define DPAY_MAX_RATION_DECAY_RATE           (1000000)
#define DPAY_FREE_TRANSACTIONS_WITH_NEW_ACCOUNT 100

#define DPAY_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define DPAY_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define DPAY_MAX_COMMENT_DEPTH_PRE_HF17      6
#define DPAY_MAX_COMMENT_DEPTH               0xffff // 64k
#define DPAY_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define DPAY_MAX_RESERVE_RATIO               (20000)

#define DPAY_CREATE_ACCOUNT_WITH_DPAY_MODIFIER 30
#define DPAY_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define DPAY_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define DPAY_MINING_REWARD                   asset( 1000, DPAY_SYMBOL )
#define DPAY_EQUIHASH_N                      140
#define DPAY_EQUIHASH_K                      6

#define DPAY_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define DPAY_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define DPAY_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define DPAY_LIQUIDITY_REWARD_BLOCKS         (DPAY_LIQUIDITY_REWARD_PERIOD_SEC/DPAY_BLOCK_INTERVAL)
#define DPAY_MIN_LIQUIDITY_REWARD            (asset( 1000*DPAY_LIQUIDITY_REWARD_BLOCKS, DPAY_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define DPAY_MIN_CONTENT_REWARD              DPAY_MINING_REWARD
#define DPAY_MIN_CURATE_REWARD               DPAY_MINING_REWARD
#define DPAY_MIN_PRODUCER_REWARD             DPAY_MINING_REWARD
#define DPAY_MIN_POW_REWARD                  DPAY_MINING_REWARD

#define DPAY_ACTIVE_CHALLENGE_FEE            asset( 2000, DPAY_SYMBOL )
#define DPAY_OWNER_CHALLENGE_FEE             asset( 30000, DPAY_SYMBOL )
#define DPAY_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define DPAY_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define DPAY_POST_REWARD_FUND_NAME           ("post")
#define DPAY_COMMENT_REWARD_FUND_NAME        ("comment")
#define DPAY_RECENT_RSHARES_DECAY_RATE_HF17  (fc::days(30))
#define DPAY_RECENT_RSHARES_DECAY_RATE_HF19  (fc::days(15))
#define DPAY_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**DPAY_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for vesting
#define DPAY_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that DPAY_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define DPAY_APR_PERCENT_SHIFT_PER_BLOCK             87

#define DPAY_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define DPAY_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**DPAY_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define DPAY_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that DPAY_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define DPAY_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x vesting rewards*
#define DPAY_CURATE_APR_PERCENT              3875
#define DPAY_CONTENT_APR_PERCENT             3875
#define DPAY_LIQUIDITY_APR_PERCENT            750
#define DPAY_PRODUCER_APR_PERCENT             750
#define DPAY_POW_APR_PERCENT                  750

#define DPAY_MIN_PAYOUT_BBD                  (asset(20,BBD_SYMBOL))

#define DPAY_BBD_STOP_PERCENT                (5*DPAY_1_PERCENT ) // Stop printing BBD at 5% Market Cap
#define DPAY_BBD_START_PERCENT               (2*DPAY_1_PERCENT) // Start reducing printing of BBD at 2% Market Cap

#define DPAY_MIN_ACCOUNT_NAME_LENGTH          3
#define DPAY_MAX_ACCOUNT_NAME_LENGTH         16

#define DPAY_MIN_PERMLINK_LENGTH             0
#define DPAY_MAX_PERMLINK_LENGTH             256
#define DPAY_MAX_WITNESS_URL_LENGTH          2048

#define DPAY_INIT_SUPPLY                     int64_t(0)
#define DPAY_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define DPAY_MAX_SIG_CHECK_DEPTH             2

#define DPAY_MIN_TRANSACTION_SIZE_LIMIT      1024
#define DPAY_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define DPAY_BBD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define DPAY_MAX_TRANSACTION_SIZE            (1024*64)
#define DPAY_MIN_BLOCK_SIZE_LIMIT            (DPAY_MAX_TRANSACTION_SIZE)
#define DPAY_MAX_BLOCK_SIZE                  (DPAY_MAX_TRANSACTION_SIZE*DPAY_BLOCK_INTERVAL*2000)
#define DPAY_MIN_BLOCK_SIZE                  115
#define DPAY_BLOCKS_PER_HOUR                 (60*60/DPAY_BLOCK_INTERVAL)
#define DPAY_FEED_INTERVAL_BLOCKS            (DPAY_BLOCKS_PER_HOUR)
#define DPAY_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define DPAY_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define DPAY_MAX_FEED_AGE_SECONDS            (60*60*24*7) // 7 days
#define DPAY_MIN_FEEDS                       (DPAY_MAX_WITNESSES/3) /// protects the network from conversions before price has been established
#define DPAY_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define DPAY_CONVERSION_DELAY                (fc::hours(DPAY_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define DPAY_MIN_UNDO_HISTORY                10
#define DPAY_MAX_UNDO_HISTORY                10000

#define DPAY_MIN_TRANSACTION_EXPIRATION_LIMIT (DPAY_BLOCK_INTERVAL * 5) // 5 transactions per block
#define DPAY_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define DPAY_BLOCKCHAIN_PRECISION_DIGITS     3
#define DPAY_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define DPAY_MAX_AUTHORITY_MEMBERSHIP        10
#define DPAY_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define DPAY_MAX_URL_LENGTH                  127

#define DPAY_IRREVERSIBLE_THRESHOLD          (75 * DPAY_1_PERCENT)

#define VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define DPAY_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define DPAY_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define DPAY_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define DPAY_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define DPAY_ROOT_POST_PARENT                (account_name_type())
///@}
