#pragma once

#include <dpay/chain/evaluator.hpp>

#include <dpay/private_message/private_message_operations.hpp>
#include <dpay/private_message/private_message_plugin.hpp>

namespace dpay { namespace private_message {

DEFINE_PLUGIN_EVALUATOR( private_message_plugin, dpay::private_message::private_message_plugin_operation, private_message )

} }
