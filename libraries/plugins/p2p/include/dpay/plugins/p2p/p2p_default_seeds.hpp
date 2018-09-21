#pragma once

#include <vector>

namespace dpay{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#elif IS_JACKSON_NET
const std::vector< std::string > default_seeds;
#elif IS_JEFFERSON_NET
const std::vector< std::string > default_seeds;
#elif IS_FRANKLIN_NET
const std::vector< std::string > default_seeds;
#elif IS_KENNEDY_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {

};
#endif

} } } // dpay::plugins::p2p
