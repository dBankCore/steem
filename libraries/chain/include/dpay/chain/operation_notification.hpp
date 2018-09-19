#pragma once

#include <dpay/protocol/operations.hpp>

#include <dpay/chain/dpay_object_types.hpp>

namespace dpay { namespace chain {

struct operation_notification
{
   operation_notification( const operation& o ) : op(o) {}

   transaction_id_type trx_id;
   uint32_t            block = 0;
   uint32_t            trx_in_block = 0;
   uint16_t            op_in_trx = 0;
   uint64_t            virtual_op = 0;
   const operation&    op;
};

} }
