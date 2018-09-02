#pragma once

#include <steem/chain/steem_object_types.hpp>
#include <steem/protocol/sdc_operations.hpp>

#ifdef STEEM_ENABLE_SDC

namespace dpay { namespace chain {

enum class sdc_phase : uint8_t
{
   account_elevated,
   setup_completed,
   contribution_begin_time_completed,
   contribution_end_time_completed,
   launch_time_completed,              /// launch window opened
   launch_failed,                      /// launch window closed with either not enough contributions or some cap not revealed
   launch_success                      /// enough contributions were declared and caps revealed before launch windows closed
};

/**Note that the object represents both liquid and vesting variant of SDC.
 * The same object is returned by indices when searched by liquid/vesting symbol/nai.
 */
class sdc_token_object : public object< sdc_token_object_type, sdc_token_object >
{
   sdc_token_object() = delete;

public:

   struct sdc_market_maker_state
   {
      asset    steem_balance;
      asset    token_balance;
      uint32_t reserve_ratio = 0;
   };

public:
   template< typename Constructor, typename Allocator >
   sdc_token_object( Constructor&& c, allocator< Allocator > a )
   {
      c( *this );
   }

   price    one_vesting_to_one_liquid() const
   {
      int64_t one_sdc = std::pow(10, liquid_symbol.decimals());
      return price ( asset( one_sdc, liquid_symbol.get_paired_symbol() ), asset( one_sdc, liquid_symbol ) );
      // ^ On the assumption that liquid and vesting SDC have the same precision. See issue 2212
   }

   price    get_vesting_share_price() const
   {
      if ( total_vesting_fund_sdc == 0 || total_vesting_shares == 0 )
         return one_vesting_to_one_liquid();
         // ^ In original method of globa_property_object it was one liquid to one vesting which seems to be a bug.

      return price( asset( total_vesting_shares, liquid_symbol.get_paired_symbol() ), asset( total_vesting_fund_sdc, liquid_symbol ) );
   }

   price    get_reward_vesting_share_price() const
   {
      share_type reward_vesting_shares = total_vesting_shares + pending_rewarded_vesting_shares;
      share_type reward_vesting_sdc = total_vesting_fund_sdc + pending_rewarded_vesting_sdc;

      if( reward_vesting_shares == 0 || reward_vesting_sdc == 0 )
          return one_vesting_to_one_liquid();
      // ^ Additional check not found in original get_reward_vesting_share_price. See issue 2212

      return price( asset( reward_vesting_shares, liquid_symbol.get_paired_symbol() ), asset( reward_vesting_sdc, liquid_symbol ) );
   }

   // id_type is actually oid<sdc_token_object>
   id_type           id;

   /**The object represents both liquid and vesting variant of SDC
    * To get vesting symbol, call liquid_symbol.get_paired_symbol()
    */
   asset_symbol_type liquid_symbol;
   account_name_type control_account;
   sdc_phase         phase = sdc_phase::account_elevated;

   share_type  current_supply = 0;
   share_type  total_vesting_fund_sdc = 0;
   share_type  total_vesting_shares = 0;
   share_type  pending_rewarded_vesting_shares = 0;
   share_type  pending_rewarded_vesting_sdc = 0;

   sdc_market_maker_state  market_maker;

   /// set_setup_parameters
   bool              allow_voting = false;
   bool              allow_vesting = false;

   /// set_runtime_parameters
   uint32_t cashout_window_seconds = 0;
   uint32_t reverse_auction_window_seconds = 0;

   uint32_t vote_regeneration_period_seconds = 0;
   uint32_t votes_per_regeneration_period = 0;

   uint128_t content_constant = 0;
   uint16_t percent_curation_rewards = 0;
   uint16_t percent_content_rewards = 0;
   protocol::curve_id author_reward_curve;
   protocol::curve_id curation_reward_curve;

   /// sdc_setup_emissions
   time_point_sec       schedule_time = STEEM_GENESIS_TIME;
   dpay::protocol::
   sdc_emissions_unit   emissions_unit;
   uint32_t             interval_seconds = 0;
   uint32_t             interval_count = 0;
   time_point_sec       lep_time = STEEM_GENESIS_TIME;
   time_point_sec       rep_time = STEEM_GENESIS_TIME;
   asset                lep_abs_amount = asset( 0, BEX_SYMBOL );
   asset                rep_abs_amount = asset( 0, BEX_SYMBOL );
   uint32_t             lep_rel_amount_numerator = 0;
   uint32_t             rep_rel_amount_numerator = 0;
   uint8_t              rel_amount_denom_bits = 0;

   ///parameters for 'sdc_setup_operation'
   int64_t                       max_supply = 0;
   dpay::protocol::
   sdc_capped_generation_policy  capped_generation_policy;
   time_point_sec                generation_begin_time;
   time_point_sec                generation_end_time;
   time_point_sec                announced_launch_time;
   time_point_sec                launch_expiration_time;

   // sdc_cap_reveal
   share_type  steem_units_min_cap = -1;
   share_type  steem_units_hard_cap = -1;
};

class sdc_event_token_object : public object< sdc_event_token_object_type, sdc_event_token_object >
{
   sdc_event_token_object() = delete;

public:
   template< typename Constructor, typename Allocator >
   sdc_event_token_object( Constructor&& c, allocator< Allocator > a )
   {
      c( *this );
   }

   // id_type is actually oid<sdc_event_token_object>
   id_type           id;

   sdc_token_id_type             parent;

   sdc_phase                     phase = sdc_phase::setup_completed;

   time_point_sec                generation_begin_time;
   time_point_sec                generation_end_time;
   time_point_sec                announced_launch_time;
   time_point_sec                launch_expiration_time;
};

struct by_symbol;
struct by_control_account;

/**Comparison operators that allow to return the same object representation
 * for both liquid and vesting symbol/nai.
 */
struct vesting_liquid_less
{
   bool operator ()( const asset_symbol_type& lhs, const asset_symbol_type& rhs ) const
   {
      // Compare as if both symbols represented liquid version.
      return ( lhs.is_vesting() ? lhs.get_paired_symbol() : lhs ) <
             ( rhs.is_vesting() ? rhs.get_paired_symbol() : rhs );
   }

   bool operator ()( const uint32_t& lhs, const uint32_t& rhs ) const
   {
      // Use the other operator, adding the same precision to both NAIs.
      return operator()( asset_symbol_type::from_nai( lhs, 0 ) , asset_symbol_type::from_nai( rhs, 0 ) );
   }
};

typedef multi_index_container <
   sdc_token_object,
   indexed_by <
      ordered_unique< tag< by_id >,
         member< sdc_token_object, sdc_token_id_type, &sdc_token_object::id > >,
      ordered_unique< tag< by_symbol >,
         member< sdc_token_object, asset_symbol_type, &sdc_token_object::liquid_symbol >, vesting_liquid_less >,
      ordered_non_unique< tag< by_control_account >,
         member< sdc_token_object, account_name_type, &sdc_token_object::control_account > >
   >,
   allocator< sdc_token_object >
> sdc_token_index;

struct by_interval_gen_begin;
struct by_interval_gen_end;
struct by_interval_launch;
struct by_interval_launch_exp;
typedef multi_index_container <
   sdc_event_token_object,
   indexed_by <
      ordered_unique< tag< by_id >,
         member< sdc_event_token_object, sdc_event_token_id_type, &sdc_event_token_object::id > >,

      ordered_non_unique< tag< by_interval_gen_begin >,
         composite_key< sdc_event_token_object,
            member< sdc_event_token_object, sdc_phase, &sdc_event_token_object::phase >,
            member< sdc_event_token_object, time_point_sec, &sdc_event_token_object::generation_begin_time >
         >
      >,
      ordered_non_unique< tag< by_interval_gen_end >,
         composite_key< sdc_event_token_object,
            member< sdc_event_token_object, sdc_phase, &sdc_event_token_object::phase >,
            member< sdc_event_token_object, time_point_sec, &sdc_event_token_object::generation_end_time >
         >
      >,
      ordered_non_unique< tag< by_interval_launch >,
         composite_key< sdc_event_token_object,
            member< sdc_event_token_object, sdc_phase, &sdc_event_token_object::phase >,
            member< sdc_event_token_object, time_point_sec, &sdc_event_token_object::announced_launch_time >
         >
      >,
      ordered_non_unique< tag< by_interval_launch_exp >,
         composite_key< sdc_event_token_object,
            member< sdc_event_token_object, sdc_phase, &sdc_event_token_object::phase >,
            member< sdc_event_token_object, time_point_sec, &sdc_event_token_object::launch_expiration_time >
         >
      >
   >,
   allocator< sdc_event_token_object >
> sdc_event_token_index;

} } // namespace dpay::chain

FC_REFLECT_ENUM( dpay::chain::sdc_phase,
                  (account_elevated)
                  (setup_completed)
                  (contribution_begin_time_completed)
                  (contribution_end_time_completed)
                  (launch_time_completed)
                  (launch_failed)
                  (launch_success)
)

FC_REFLECT( dpay::chain::sdc_token_object::sdc_market_maker_state,
   (steem_balance)
   (token_balance)
   (reserve_ratio)
)

FC_REFLECT( dpay::chain::sdc_token_object,
   (id)
   (liquid_symbol)
   (control_account)
   (phase)
   (current_supply)
   (total_vesting_fund_sdc)
   (total_vesting_shares)
   (pending_rewarded_vesting_shares)
   (pending_rewarded_vesting_sdc)
   (market_maker)
   (allow_voting)
   (allow_vesting)
   (schedule_time)
   (emissions_unit)
   (interval_seconds)
   (interval_count)
   (lep_time)
   (rep_time)
   (lep_abs_amount)
   (rep_abs_amount)
   (lep_rel_amount_numerator)
   (rep_rel_amount_numerator)
   (rel_amount_denom_bits)
   (max_supply)
   (capped_generation_policy)
   (generation_begin_time)
   (generation_end_time)
   (announced_launch_time)
   (launch_expiration_time)
   (steem_units_min_cap)
   (steem_units_hard_cap)
)

FC_REFLECT( dpay::chain::sdc_event_token_object,
   (id)
   (parent)
   (phase)
   (generation_begin_time)
   (generation_end_time)
   (announced_launch_time)
   (launch_expiration_time)
)

CHAINBASE_SET_INDEX_TYPE( dpay::chain::sdc_token_object, dpay::chain::sdc_token_index )
CHAINBASE_SET_INDEX_TYPE( dpay::chain::sdc_event_token_object, dpay::chain::sdc_event_token_index )

#endif
