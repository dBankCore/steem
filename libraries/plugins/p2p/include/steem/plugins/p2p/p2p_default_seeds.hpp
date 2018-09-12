#pragma once

#include <vector>

namespace steem{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "d.dpays.io:6620"              // distributed webs project
};
#endif

} } } // steem::plugins::p2p
