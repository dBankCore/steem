#pragma once

#include <dpay/chain/util/asset.hpp>
#include <dpay/chain/dpay_objects.hpp>

#include <dpay/protocol/asset.hpp>
#include <dpay/protocol/config.hpp>
#include <dpay/protocol/types.hpp>
#include <dpay/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace dpay { namespace chain { namespace util {

using dpay::protocol::asset;
using dpay::protocol::price;
using dpay::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_bbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_dpay;
   price      current_dpay_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = DPAY_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return DPAY_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = DPAY_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t dpay_payout )
{
   return to_bbd( p, asset( dpay_payout, DPAY_SYMBOL ) ) < DPAY_MIN_PAYOUT_BBD;
}

} } } // dpay::chain::util

FC_REFLECT( dpay::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_bbd)
   (total_reward_shares2)
   (total_reward_fund_dpay)
   (current_dpay_price)
   (reward_curve)
   (content_constant)
   )
