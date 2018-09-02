#pragma once

#include <vector>

namespace dpay{ namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   // "greatchain.dpays.io:6620",                 // distributed webs project
   // "jefferson.dpays.io:6620",                  // distributed webs project
   // "jackson.dpays.io:6620",                    // distributed webs project
   // "cointroller.dpays.io:6620",                // dPay Witness/Governance
   // "m.dpays.io:6620",                          // dPay Witness/Governance
   // "dpaystan.link:6620",                       // dPay Witness/Governance
   // "jared.dpays.io:6620",                      // dPay Developer
   // "nickeles.dpays.io:6620",                   // dPay Witness/Governance
   // "freedomfirst.dpays.io:6620",               // dPay Witness/Governance
   // "onceuponatime.dpays.io:6620",              // dPay Witness/Governance
   // "michaelx.dpays.io:6620",                   // dPay Witness/Governance
   // "freedomfirst.dpays.io:6620",               // dPay Witness/Governance
   // "node.dgive.io:6620",                       // dGive Node - dPay dApp
   // "node.dpix.io:6620",                        // dPix Node - dPix dApp
   // "node.dbuy.io:6620",                        // dBuy Node - dBuy dApp
   // "node.dseek.io:6620",                       // dSeek Node - dSeek dApp
   // "node.dsite.io:6620",                       // dSite Node - dSite dApp
   // "node.dmemo.io:6620",                       // dMemo Node - dMemo dApp
   // "node.dpayid.io:6620",                      // dPayID Node - dPay dApp
   // "node.dsocial.io:6620",                     // dSocial Node - dPay dApp
   // "node.dwiki.io:6620",                       // dWiki Node - dPay dApp
   // "node.dpaystan.link:6620",                  // dPay Witness/Governance
   // "node.dpaymichael.link:6620",               // dPay Witness/Governance
   // "quin.dpays.io:6620",                       // dPay Witness/Governance
   // "morrison.dpays.io:6620",                   // dPay Witness/Governance
   // "lana.dpays.io:6620",                       // dPay Witness/Governance
   // "lune.dpays.io:6620",                       // dPay Witness/Governance
   // "cryptokong.dpays.io:6620",                 // dPay Witness/Governance
   // "whi.dpays.io:6620",                        // dPay Witness/Governance
   // "bigg.dpays.io:6620",                       // dPay Witness/Governance
   // "tablecafe.dpays.io:6620:6620",             // dPay Witness/Governance
   // "kusknee.dpays.io:6620",                    // dPay Witness/Governance
   // "bossdan.dpays.io:6620",                    // dPay Witness/Governance
   // "chiraag.dpays.io:6620",                    // dPay Witness/Governance
};
#endif

} } } // dpay::plugins::p2p
