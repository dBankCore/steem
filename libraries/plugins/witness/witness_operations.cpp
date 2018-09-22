#include <dpay/witness/witness_operations.hpp>

#include <dpay/protocol/operation_util_impl.hpp>

namespace dpay { namespace witness {

void enable_content_editing_operation::validate()const
{
   chain::validate_account_name( account );
}

} } // dpay::witness

DEFINE_OPERATION_TYPE( dpay::witness::witness_plugin_operation )
