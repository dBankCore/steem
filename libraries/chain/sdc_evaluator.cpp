
#include <steem/chain/steem_evaluator.hpp>
#include <steem/chain/database.hpp>
#include <steem/chain/steem_objects.hpp>
#include <steem/chain/sdc_objects.hpp>

#include <steem/chain/util/reward.hpp>

#include <steem/protocol/sdc_operations.hpp>

#include <steem/protocol/sdc_operations.hpp>
#ifdef STEEM_ENABLE_SDC
namespace dpay { namespace chain {

namespace {

/// Return SDC token object controlled by this account identified by its symbol. Throws assert exception when not found!
inline const sdc_token_object& get_controlled_sdc( const database& db, const account_name_type& control_account, const asset_symbol_type& sdc_symbol )
{
   const sdc_token_object* sdc = db.find< sdc_token_object, by_symbol >( sdc_symbol );
   // The SDC is supposed to be found.
   FC_ASSERT( sdc != nullptr, "SDC numerical asset identifier ${sdc} not found", ("sdc", sdc_symbol.to_nai()) );
   // Check against unotherized account trying to access (and alter) SDC. Unotherized means "other than the one that created the SDC".
   FC_ASSERT( sdc->control_account == control_account, "The account ${account} does NOT control the SDC ${sdc}",
      ("account", control_account)("sdc", sdc_symbol.to_nai()) );

   return *sdc;
}

}

namespace {

class sdc_setup_parameters_visitor : public fc::visitor<bool>
{
public:
   sdc_setup_parameters_visitor(sdc_token_object& sdc_token) : _sdc_token(sdc_token) {}

   bool operator () (const sdc_param_allow_voting& allow_voting)
   {
      _sdc_token.allow_voting = allow_voting.value;
      return true;
   }

   bool operator () (const sdc_param_allow_vesting& allow_vesting)
   {
      _sdc_token.allow_vesting = allow_vesting.value;
      return true;
   }

private:
   sdc_token_object& _sdc_token;
};

const sdc_token_object& common_pre_setup_evaluation(
   const database& _db, const asset_symbol_type& symbol, const account_name_type& control_account )
{
   const sdc_token_object& sdc = get_controlled_sdc( _db, control_account, symbol );

   // Check whether it's not too late to setup emissions operation.
   FC_ASSERT( sdc.phase < sdc_phase::setup_completed, "SDC pre-setup operation no longer allowed after setup phase is over" );

   return sdc;
}

} // namespace

void sdc_create_evaluator::do_apply( const sdc_create_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );
   const dynamic_global_property_object& dgpo = _db.get_dynamic_global_properties();

   // Check that SDC with given nai has not been created already.
   // Note that symbols with the same nai and different precision (decimal places) are not allowed,
   // therefore we use a method that strips the symbol from precision info when searching.
   const auto& idx = _db.get_index< sdc_token_index >().indices().get< by_symbol >();
   auto stripped_symbol_num = o.symbol.get_stripped_precision_sdc_num();
   auto it = idx.lower_bound( asset_symbol_type::from_asset_num( stripped_symbol_num ) );
   FC_ASSERT( (it == idx.end()) || (it->liquid_symbol.get_stripped_precision_sdc_num() != stripped_symbol_num),
              "SDC ${nai} has already been created.", ("nai", o.symbol.to_nai()));

   asset effective_elevation_fee;

   FC_ASSERT( dgpo.sdc_creation_fee.symbol == BEX_SYMBOL || dgpo.sdc_creation_fee.symbol == BBD_SYMBOL,
      "Unexpected internal error - wrong symbol ${s} of SDC creation fee.", ("s", dgpo.sdc_creation_fee.symbol) );
   FC_ASSERT( o.sdc_creation_fee.symbol == BEX_SYMBOL || o.sdc_creation_fee.symbol == BBD_SYMBOL,
      "Asset fee must be BEX or BBD, was ${s}", ("s", o.sdc_creation_fee.symbol) );
   if( o.sdc_creation_fee.symbol == dgpo.sdc_creation_fee.symbol )
   {
      effective_elevation_fee = dgpo.sdc_creation_fee;
   }
   else
   {
      const auto& fhistory = _db.get_feed_history();
      FC_ASSERT( !fhistory.current_median_history.is_null(), "Cannot pay the fee using SBD because there is no price feed." );
      if( o.sdc_creation_fee.symbol == BEX_SYMBOL )
      {
         effective_elevation_fee = _db.to_sbd( o.sdc_creation_fee );
      }
      else
      {
         effective_elevation_fee = _db.to_steem( o.sdc_creation_fee );
      }
   }

   FC_ASSERT( o.sdc_creation_fee >= effective_elevation_fee,
      "Fee of ${of} is too small, must be at least ${ef}", ("of", o.sdc_creation_fee)("ef", effective_elevation_fee) );
   FC_ASSERT( _db.get_balance( o.control_account, o.sdc_creation_fee.symbol ) >= o.sdc_creation_fee,
    "Account does not have sufficient funds for specified fee of ${of}", ("of", o.sdc_creation_fee) );

   _db.adjust_balance( o.control_account , -o.sdc_creation_fee );
   _db.adjust_balance( STEEM_NULL_ACCOUNT,  o.sdc_creation_fee );

   // Create SDC object common to both liquid and vesting variants of SDC.
   _db.create< sdc_token_object >( [&]( sdc_token_object& token )
   {
      token.liquid_symbol = o.symbol;
      token.control_account = o.control_account;
      token.market_maker.token_balance = asset( 0, token.liquid_symbol );
   });
}

struct sdc_setup_evaluator_visitor
{
   const sdc_token_object& _token;
   database& _db;

   sdc_setup_evaluator_visitor( const sdc_token_object& token, database& db ): _token( token ), _db( db ){}

   typedef void result_type;

   void operator()( const sdc_capped_generation_policy& capped_generation_policy ) const
   {
      _db.modify( _token, [&]( sdc_token_object& token )
      {
         token.capped_generation_policy = capped_generation_policy;
      });
   }
};

void sdc_setup_evaluator::do_apply( const sdc_setup_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );
#pragma message ("TODO: Adjust assertion below and add/modify negative tests appropriately.")
   const auto* _token = _db.find< sdc_token_object, by_symbol >( o.symbol );
   FC_ASSERT( _token, "SDC ${ac} not elevated yet.",("ac", o.control_account) );

   _db.modify(  *_token, [&]( sdc_token_object& token )
   {
#pragma message ("TODO: Add/modify test to check the token phase correctly set.")
      token.phase = sdc_phase::setup_completed;
      token.control_account = o.control_account;
      token.max_supply = o.max_supply;

      token.generation_begin_time = o.generation_begin_time;
      token.generation_end_time = o.generation_end_time;
      token.announced_launch_time = o.announced_launch_time;
      token.launch_expiration_time = o.launch_expiration_time;

      /*
         We should override precision in: 'lep_abs_amount', 'rep_abs_amount', 'liquid_symbol'
         in case when new precision differs from old.
      */
      asset_symbol_type old_symbol = _token->liquid_symbol;
      uint8_t old_decimal_places = old_symbol.decimals();

      if( old_decimal_places != o.decimal_places )
      {
         uint32_t nai = old_symbol.to_nai();
         asset_symbol_type new_symbol = asset_symbol_type::from_nai( nai, o.decimal_places );

         token.liquid_symbol = new_symbol;
         token.lep_abs_amount = asset( token.lep_abs_amount, new_symbol );
         token.rep_abs_amount = asset( token.rep_abs_amount, new_symbol );
      }
   });

   sdc_setup_evaluator_visitor visitor( *_token, _db );
   o.initial_generation_policy.visit( visitor );

   _db.create< sdc_event_token_object >( [&]( sdc_event_token_object& event_token )
   {
      event_token.parent = _token->id;

      event_token.generation_begin_time = _token->generation_begin_time;
      event_token.generation_end_time = _token->generation_end_time;
      event_token.announced_launch_time = _token->announced_launch_time;
      event_token.launch_expiration_time = _token->launch_expiration_time;
   });
}

void sdc_cap_reveal_evaluator::do_apply( const sdc_cap_reveal_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );

   const sdc_token_object& sdc = get_controlled_sdc( _db, o.control_account, o.symbol );
   // Check whether it's not too early to reveal a cap.
   FC_ASSERT( sdc.phase >= sdc_phase::setup_completed, "SDC setup operation must succeed before cap reveal operaton is allowed" );
   // Check whether it's not too late to reveal a cap.
   FC_ASSERT( sdc.phase < sdc_phase::launch_failed, "Cap reveal operaton is allowed only until SDC ICO is concluded" );

   // As there's no information in cap reveal operation about which cap it reveals,
   // we'll check both, unless they are already revealed.
   FC_ASSERT( sdc.steem_units_min_cap < 0 || sdc.steem_units_hard_cap < 0, "Both min cap and max hard cap have already been revealed" );

   if( sdc.steem_units_min_cap < 0 )
      try
      {
         o.cap.validate( sdc.capped_generation_policy.min_steem_units_commitment );
         _db.modify( sdc, [&]( sdc_token_object& sdc_object )
         {
            sdc_object.steem_units_min_cap = o.cap.amount;
         });
         return;
      }
      catch( const fc::exception& e )
      {
         if( sdc.steem_units_hard_cap >= 0 )
            throw;
      }

   o.cap.validate( sdc.capped_generation_policy.hard_cap_steem_units_commitment );
   _db.modify( sdc, [&]( sdc_token_object& sdc_object )
   {
      sdc_object.steem_units_hard_cap = o.cap.amount;
   });
}

void sdc_refund_evaluator::do_apply( const sdc_refund_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );
   // TODO: Check whether some impostor tries to hijack SDC operation.
}

void sdc_setup_emissions_evaluator::do_apply( const sdc_setup_emissions_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );

   const sdc_token_object& sdc = common_pre_setup_evaluation(_db, o.symbol, o.control_account);

   FC_ASSERT( o.lep_abs_amount.symbol == sdc.liquid_symbol );
   // ^ Note that rep_abs_amount.symbol has been matched to lep's in validate().

   _db.modify( sdc, [&]( sdc_token_object& token )
   {
      token.schedule_time = o.schedule_time;
      token.emissions_unit = o.emissions_unit;
      token.interval_seconds = o.interval_seconds;
      token.interval_count = o.interval_count;
      token.lep_time = o.lep_time;
      token.rep_time = o.rep_time;
      token.lep_abs_amount = o.lep_abs_amount;
      token.rep_abs_amount = o.rep_abs_amount;
      token.lep_rel_amount_numerator = o.lep_rel_amount_numerator;
      token.rep_rel_amount_numerator = o.rep_rel_amount_numerator;
      token.rel_amount_denom_bits = o.rel_amount_denom_bits;
   });
}

void sdc_set_setup_parameters_evaluator::do_apply( const sdc_set_setup_parameters_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );

   const sdc_token_object& sdc_token = common_pre_setup_evaluation(_db, o.symbol, o.control_account);

   _db.modify( sdc_token, [&]( sdc_token_object& token )
   {
      sdc_setup_parameters_visitor visitor(token);

      for (auto& param : o.setup_parameters)
         param.visit(visitor);
   });
}

struct sdc_set_runtime_parameters_evaluator_visitor
{
   const sdc_token_object& _token;
   database& _db;

   sdc_set_runtime_parameters_evaluator_visitor( const sdc_token_object& token, database& db ): _token( token ), _db( db ){}

   typedef void result_type;

   void operator()( const sdc_param_windows_v1& param_windows ) const
   {
      _db.modify( _token, [&]( sdc_token_object& token )
      {
         token.cashout_window_seconds = param_windows.cashout_window_seconds;
         token.reverse_auction_window_seconds = param_windows.reverse_auction_window_seconds;
      });
   }

   void operator()( const sdc_param_vote_regeneration_period_seconds_v1& vote_regeneration ) const
   {
      _db.modify( _token, [&]( sdc_token_object& token )
      {
         token.vote_regeneration_period_seconds = vote_regeneration.vote_regeneration_period_seconds;
         token.votes_per_regeneration_period = vote_regeneration.votes_per_regeneration_period;
      });
   }

   void operator()( const sdc_param_rewards_v1& param_rewards ) const
   {
      _db.modify( _token, [&]( sdc_token_object& token )
      {
         token.content_constant = param_rewards.content_constant;
         token.percent_curation_rewards = param_rewards.percent_curation_rewards;
         token.percent_content_rewards = param_rewards.percent_content_rewards;
         token.author_reward_curve = param_rewards.author_reward_curve;
         token.curation_reward_curve = param_rewards.curation_reward_curve;
      });
   }
};

void sdc_set_runtime_parameters_evaluator::do_apply( const sdc_set_runtime_parameters_operation& o )
{
   FC_ASSERT( _db.has_hardfork( STEEM_SDC_HARDFORK ), "SDC functionality not enabled until hardfork ${hf}", ("hf", STEEM_SDC_HARDFORK) );

   const sdc_token_object& _token = common_pre_setup_evaluation(_db, o.symbol, o.control_account);

   sdc_set_runtime_parameters_evaluator_visitor visitor( _token, _db );

   for( auto& param: o.runtime_parameters )
      param.visit( visitor );
}

} }
#endif
