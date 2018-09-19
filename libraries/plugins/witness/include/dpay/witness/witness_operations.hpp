#pragma once

#include <dpay/protocol/base.hpp>
#include <dpay/protocol/operation_util.hpp>

#include <dpay/app/plugin.hpp>

namespace dpay { namespace witness {

using namespace std;
using dpay::protocol::base_operation;
using dpay::chain::database;

class witness_plugin;

struct enable_content_editing_operation : base_operation
{
   protocol::account_name_type   account;
   fc::time_point_sec            relock_time;

   void validate()const;

   void get_required_active_authorities( flat_set< protocol::account_name_type>& a )const { a.insert( account ); }
};

typedef fc::static_variant<
         enable_content_editing_operation
      > witness_plugin_operation;

DEFINE_PLUGIN_EVALUATOR( witness_plugin, witness_plugin_operation, enable_content_editing );

} } // dpay::witness

FC_REFLECT( dpay::witness::enable_content_editing_operation, (account)(relock_time) )

FC_REFLECT_TYPENAME( dpay::witness::witness_plugin_operation )

DECLARE_OPERATION_TYPE( dpay::witness::witness_plugin_operation )
