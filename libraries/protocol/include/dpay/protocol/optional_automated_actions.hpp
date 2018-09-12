#pragma once

#include <dpay/protocol/dpay_optional_actions.hpp>

#include <dpay/protocol/operation_util.hpp>

namespace dpay { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            optional_action
         > optional_automated_action;

} } // dpay::protocol

DPAY_DECLARE_OPERATION_TYPE( dpay::protocol::optional_automated_action );
FC_REFLECT_TYPENAME( dpay::protocol::optional_automated_action );
