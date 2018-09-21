#pragma once

#include <dpay/protocol/types.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define DPAY_NUM_RESOURCE_TYPES     5

namespace dpay { namespace protocol {
struct signed_transaction;
} } // dpay::protocol

namespace dpay { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, DPAY_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const dpay::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // dpay::plugins::rc

FC_REFLECT_ENUM( dpay::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( dpay::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( dpay::plugins::rc::resource_count_type )
