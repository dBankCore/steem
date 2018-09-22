#include <dpay/follow/follow_operations.hpp>

#include <dpay/protocol/operation_util_impl.hpp>

namespace dpay { namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } //dpay::follow

DEFINE_OPERATION_TYPE( dpay::follow::follow_plugin_operation )
