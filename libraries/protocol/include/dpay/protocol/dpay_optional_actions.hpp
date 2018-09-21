#pragma once
#include <dpay/protocol/base.hpp>
#include <dpay/protocol/block_header.hpp>
#include <dpay/protocol/asset.hpp>
#include <dpay/protocol/validation.hpp>
#include <dpay/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace dpay { namespace protocol {

   struct optional_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // dpay::protocol

FC_REFLECT( dpay::protocol::optional_action, (account) )
