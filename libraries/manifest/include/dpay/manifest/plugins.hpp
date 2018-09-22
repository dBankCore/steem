
#pragma once

#include <memory>
#include <string>
#include <vector>

namespace dpay { namespace app {

class abstract_plugin;
class application;

} }

namespace dpay { namespace plugin {

void initialize_plugin_factories();
std::shared_ptr< dpay::app::abstract_plugin > create_plugin( const std::string& name, dpay::app::application* app );
std::vector< std::string > get_available_plugins();

} }
