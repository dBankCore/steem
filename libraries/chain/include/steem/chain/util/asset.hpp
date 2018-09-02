#pragma once

#include <steem/protocol/asset.hpp>

namespace dpay { namespace chain { namespace util {

using dpay::protocol::asset;
using dpay::protocol::price;

inline asset to_sbd( const price& p, const asset& steem )
{
   FC_ASSERT( steem.symbol == BEX_SYMBOL );
   if( p.is_null() )
      return asset( 0, BBD_SYMBOL );
   return steem * p;
}

inline asset to_steem( const price& p, const asset& sbd )
{
   FC_ASSERT( sbd.symbol == BBD_SYMBOL );
   if( p.is_null() )
      return asset( 0, BEX_SYMBOL );
   return sbd * p;
}

} } }
