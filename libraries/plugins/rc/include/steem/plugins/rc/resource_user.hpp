#pragma once

#include <steem/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace dpay { namespace protocol {
struct signed_transaction;
} } // dpay::protocol

namespace dpay { namespace plugins { namespace rc {

using dpay::protocol::account_name_type;
using dpay::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // dpay::plugins::rc
