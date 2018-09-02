#pragma once

#include <steem/chain/evaluator.hpp>

#include <steem/private_message/private_message_operations.hpp>
#include <steem/private_message/private_message_plugin.hpp>

namespace dpay { namespace private_message {

STEEM_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, dpay::private_message::private_message_plugin_operation, private_message )

} }
