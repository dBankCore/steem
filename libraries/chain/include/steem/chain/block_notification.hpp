#pragma once

#include <steem/protocol/block.hpp>

namespace dpay { namespace chain {

struct block_notification
{
   block_notification( const dpay::protocol::signed_block& b ) : block(b)
   {
      block_id = b.id();
      block_num = block_header::num_from_id( block_id );
   }

   dpay::protocol::block_id_type          block_id;
   uint32_t                                block_num = 0;
   const dpay::protocol::signed_block&    block;
};

} }
