#pragma once

#include <steem/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace dpay { namespace app {
   struct api_context;
} }

namespace dpay { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const dpay::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // dpay::account_statistics

FC_API( dpay::account_statistics::account_statistics_api, )