#pragma once

#include <fc/container/flat.hpp>
#include <dpay/protocol/operations.hpp>
#include <dpay/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace dpay { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const dpay::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const dpay::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // dpay::app
