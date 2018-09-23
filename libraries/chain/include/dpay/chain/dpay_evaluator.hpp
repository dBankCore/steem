#pragma once

#include <dpay/protocol/dpay_operations.hpp>

#include <dpay/chain/evaluator.hpp>

namespace dpay { namespace chain {

using namespace dpay::protocol;

DPAY_DEFINE_EVALUATOR( account_create )
DPAY_DEFINE_EVALUATOR( account_create_with_delegation )
DPAY_DEFINE_EVALUATOR( account_update )
DPAY_DEFINE_EVALUATOR( transfer )
DPAY_DEFINE_EVALUATOR( transfer_to_vesting )
DPAY_DEFINE_EVALUATOR( witness_update )
DPAY_DEFINE_EVALUATOR( account_witness_vote )
DPAY_DEFINE_EVALUATOR( account_witness_proxy )
DPAY_DEFINE_EVALUATOR( withdraw_vesting )
DPAY_DEFINE_EVALUATOR( set_withdraw_vesting_route )
DPAY_DEFINE_EVALUATOR( comment )
DPAY_DEFINE_EVALUATOR( comment_options )
DPAY_DEFINE_EVALUATOR( delete_comment )
DPAY_DEFINE_EVALUATOR( vote )
DPAY_DEFINE_EVALUATOR( custom )
DPAY_DEFINE_EVALUATOR( custom_json )
DPAY_DEFINE_EVALUATOR( custom_binary )
DPAY_DEFINE_EVALUATOR( pow )
DPAY_DEFINE_EVALUATOR( pow2 )
DPAY_DEFINE_EVALUATOR( feed_publish )
DPAY_DEFINE_EVALUATOR( convert )
DPAY_DEFINE_EVALUATOR( limit_order_create )
DPAY_DEFINE_EVALUATOR( limit_order_cancel )
DPAY_DEFINE_EVALUATOR( report_over_production )
DPAY_DEFINE_EVALUATOR( limit_order_create2 )
DPAY_DEFINE_EVALUATOR( escrow_transfer )
DPAY_DEFINE_EVALUATOR( escrow_approve )
DPAY_DEFINE_EVALUATOR( escrow_dispute )
DPAY_DEFINE_EVALUATOR( escrow_release )
DPAY_DEFINE_EVALUATOR( placeholder_a )
DPAY_DEFINE_EVALUATOR( placeholder_b )
DPAY_DEFINE_EVALUATOR( request_account_recovery )
DPAY_DEFINE_EVALUATOR( recover_account )
DPAY_DEFINE_EVALUATOR( change_recovery_account )
DPAY_DEFINE_EVALUATOR( transfer_to_savings )
DPAY_DEFINE_EVALUATOR( transfer_from_savings )
DPAY_DEFINE_EVALUATOR( cancel_transfer_from_savings )
DPAY_DEFINE_EVALUATOR( decline_voting_rights )
DPAY_DEFINE_EVALUATOR( reset_account )
DPAY_DEFINE_EVALUATOR( set_reset_account )
DPAY_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef DPAY_ENABLE_SMT
DPAY_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
DPAY_DEFINE_EVALUATOR( delegate_vesting_shares )
DPAY_DEFINE_EVALUATOR( witness_set_properties )
#ifdef DPAY_ENABLE_SMT
DPAY_DEFINE_EVALUATOR( smt_setup )
DPAY_DEFINE_EVALUATOR( smt_cap_reveal )
DPAY_DEFINE_EVALUATOR( smt_refund )
DPAY_DEFINE_EVALUATOR( smt_setup_emissions )
DPAY_DEFINE_EVALUATOR( smt_set_setup_parameters )
DPAY_DEFINE_EVALUATOR( smt_set_runtime_parameters )
DPAY_DEFINE_EVALUATOR( smt_create )
#endif

} } // dpay::chain
