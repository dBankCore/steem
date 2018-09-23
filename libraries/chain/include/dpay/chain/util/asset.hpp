#pragma once

#include <dpay/protocol/asset.hpp>

namespace dpay { namespace chain { namespace util {

using dpay::protocol::asset;
using dpay::protocol::price;

inline asset to_bbd( const price& p, const asset& dpay )
{
   FC_ASSERT( dpay.symbol == DPAY_SYMBOL );
   if( p.is_null() )
      return asset( 0, BBD_SYMBOL );
   return dpay * p;
}

inline asset to_dpay( const price& p, const asset& bbd )
{
   FC_ASSERT( bbd.symbol == BBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, DPAY_SYMBOL );
   return bbd * p;
}

} } }
