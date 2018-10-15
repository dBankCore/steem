#pragma once
#include <dpay/plugins/block_api/block_api_objects.hpp>

#include <dpay/protocol/types.hpp>
#include <dpay/protocol/transaction.hpp>
#include <dpay/protocol/block_header.hpp>

#include <dpay/plugins/json_rpc/utility.hpp>

namespace dpay { namespace plugins { namespace block_api {

/* get_block_header */

struct get_block_header_args
{
   uint32_t block_num;
};

struct get_block_header_return
{
   optional< block_header > header;
};

/* get_block */
struct get_block_args
{
   uint32_t block_num;
};

struct get_block_return
{
   optional< api_signed_block_object > block;
};

} } } // dpay::block_api

FC_REFLECT( dpay::plugins::block_api::get_block_header_args,
   (block_num) )

FC_REFLECT( dpay::plugins::block_api::get_block_header_return,
   (header) )

FC_REFLECT( dpay::plugins::block_api::get_block_args,
   (block_num) )

FC_REFLECT( dpay::plugins::block_api::get_block_return,
   (block) )

