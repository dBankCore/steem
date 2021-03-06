#include <dpay/plugins/follow/follow_operations.hpp>

#include <dpay/protocol/operation_util_impl.hpp>

namespace dpay { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //dpay::plugins::follow

DPAY_DEFINE_OPERATION_TYPE( dpay::plugins::follow::follow_plugin_operation )
