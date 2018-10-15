#pragma once

#include <vector>

namespace dpay{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds;
#endif

} } } // dpay::plugins::p2p
