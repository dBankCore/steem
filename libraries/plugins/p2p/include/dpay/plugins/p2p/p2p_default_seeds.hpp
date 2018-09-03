#pragma once

#include <vector>

namespace dpay{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "greatchain.dpays.io:6620",                 // Distributed Webs Project
   "jefferson.dpays.io:6620",                  // dPay Witness/Governance (Jared)
   "jackson.dpays.io:6620",                    // dPay Witness/Governance (Nickeles)
   "cointroller.dpays.io:6620",                // dPay Witness/Governance (Cointroller)
   "m.dpays.io:6620",                          // dPay Witness/Governance (M)
   "dpaystan.link:6620",                       // dPay Witness/Governance (Stan Larimer)
   "freedomfirst.dpays.io:6620",               // dPay Witness/Governance (FreedomFirst)
   "onceuponatime.dpays.io:6620",              // dPay Witness/Governance (OnceUponATime)
   "michaelx.dpays.io:6620",                   // dPay Witness/Governance (MichaelX)
   "lana.dpays.io:6620",                       // dPay Witness/Governance (Lana)
   "cryptokong.dpays.io:6620",                 // dPay Witness/Governance (CryptoKong)
   "nmh.dpays.io:6620",                        // dPay Witness/Governance (NMH)
};
#endif

} } } // dpay::plugins::p2p
