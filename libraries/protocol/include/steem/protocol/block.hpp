#pragma once
#include <steem/protocol/block_header.hpp>
#include <steem/protocol/transaction.hpp>

namespace dpay { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // dpay::protocol

FC_REFLECT_DERIVED( dpay::protocol::signed_block, (dpay::protocol::signed_block_header), (transactions) )
