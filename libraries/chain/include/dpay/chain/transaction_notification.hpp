#pragma once

#include <dpay/protocol/block.hpp>

namespace dpay { namespace chain {

struct transaction_notification
{
   transaction_notification( const dpay::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   dpay::protocol::transaction_id_type          transaction_id;
   const dpay::protocol::signed_transaction&    transaction;
};

} }
