#pragma once
#include <appbase/application.hpp>

#include <steem/plugins/chain/chain_plugin.hpp>

namespace steem { namespace plugins { namespace sdc_test {

using namespace appbase;

#define STEEM_SDC_TEST_PLUGIN_NAME "sdc_test"

class sdc_test_plugin : public appbase::plugin< sdc_test_plugin >
{
   public:
      sdc_test_plugin();
      virtual ~sdc_test_plugin();

      APPBASE_PLUGIN_REQUIRES( (steem::plugins::chain::chain_plugin) )

      static const std::string& name() { static std::string name = STEEM_SDC_TEST_PLUGIN_NAME; return name; }

      virtual void set_program_options( options_description& cli, options_description& cfg ) override;
      void plugin_initialize( const variables_map& options ) override;
      void plugin_startup() override;
      void plugin_shutdown() override;

   private:
      std::unique_ptr< class sdc_test_plugin_impl > my;
};

} } } // steem::plugins::sdc_test
