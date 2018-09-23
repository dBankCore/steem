#pragma once

#include <fc/io/raw.hpp>
#include <dpay/protocol/types_fwd.hpp>

#define DPAY_ASSET_SYMBOL_PRECISION_BITS    4
#define SMT_MAX_NAI                          99999999
#define SMT_MIN_NAI                          1
#define SMT_MIN_NON_RESERVED_NAI             10000000
#define DPAY_ASSET_SYMBOL_NAI_LENGTH        10
#define DPAY_ASSET_SYMBOL_NAI_STRING_LENGTH ( DPAY_ASSET_SYMBOL_NAI_LENGTH + 2 )

#define DPAY_PRECISION_BBD   (3)
#define DPAY_PRECISION_DPAY (3)
#define DPAY_PRECISION_VESTS (6)

// One's place is used for check digit, which means NAI 0-9 all have NAI data of 0 which is invalid
// This space is safe to use because it would alwasys result in failure to convert from NAI
#define DPAY_NAI_BBD   (1)
#define DPAY_NAI_DPAY (2)
#define DPAY_NAI_VESTS (3)

#define DPAY_ASSET_NUM_BBD \
  (((SMT_MAX_NAI + DPAY_NAI_BBD)   << DPAY_ASSET_SYMBOL_PRECISION_BITS) | DPAY_PRECISION_BBD)
#define DPAY_ASSET_NUM_DPAY \
  (((SMT_MAX_NAI + DPAY_NAI_DPAY) << DPAY_ASSET_SYMBOL_PRECISION_BITS) | DPAY_PRECISION_DPAY)
#define DPAY_ASSET_NUM_VESTS \
  (((SMT_MAX_NAI + DPAY_NAI_VESTS) << DPAY_ASSET_SYMBOL_PRECISION_BITS) | DPAY_PRECISION_VESTS)

#ifdef IS_TEST_NET

#define VESTS_SYMBOL_U64  (uint64_t('V') | (uint64_t('E') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('S') << 32))
#define DPAY_SYMBOL_U64  (uint64_t('B') | (uint64_t('E') << 8) | (uint64_t('T') << 16))
#define BBD_SYMBOL_U64    (uint64_t('B') | (uint64_t('B') << 8) | (uint64_t('D') << 16))

#else

#define VESTS_SYMBOL_U64  (uint64_t('V') | (uint64_t('E') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('S') << 32))
#define DPAY_SYMBOL_U64  (uint64_t('B') | (uint64_t('E') << 8) | (uint64_t('X'))
#define BBD_SYMBOL_U64    (uint64_t('B') | (uint64_t('B') << 8) | (uint64_t('D') << 16))

#endif

#define VESTS_SYMBOL_SER  (uint64_t(6) | (VESTS_SYMBOL_U64 << 8)) ///< VESTS|VESTS with 6 digits of precision
#define DPAY_SYMBOL_SER  (uint64_t(3) | (DPAY_SYMBOL_U64 << 8)) ///< BEX|TESTS with 3 digits of precision
#define BBD_SYMBOL_SER    (uint64_t(3) |   (BBD_SYMBOL_U64 << 8)) ///< BBD|TBD with 3 digits of precision

#define DPAY_ASSET_MAX_DECIMALS 12

namespace dpay { namespace protocol {

class asset_symbol_type
{
   public:
      enum asset_symbol_space
      {
         legacy_space = 1,
         smt_nai_space = 2
      };

      asset_symbol_type() {}

      // buf must have space for DPAY_ASSET_SYMBOL_MAX_LENGTH+1
      static asset_symbol_type from_string( const std::string& str );
      static asset_symbol_type from_nai_string( const char* buf, uint8_t decimal_places );
      static asset_symbol_type from_asset_num( uint32_t asset_num )
      {   asset_symbol_type result;   result.asset_num = asset_num;   return result;   }
      static uint32_t asset_num_from_nai( uint32_t nai, uint8_t decimal_places );
      static asset_symbol_type from_nai( uint32_t nai, uint8_t decimal_places )
      {   return from_asset_num( asset_num_from_nai( nai, decimal_places ) );          }

      std::string to_string()const;

      void to_nai_string( char* buf )const;
      std::string to_nai_string()const
      {
         char buf[ DPAY_ASSET_SYMBOL_NAI_STRING_LENGTH ];
         to_nai_string( buf );
         return std::string( buf );
      }

      uint32_t to_nai()const;

      /**Returns true when symbol represents vesting variant of the token,
       * false for liquid one.
       */
      bool is_vesting() const;
      /**Returns vesting symbol when called from liquid one
       * and liquid symbol when called from vesting one.
       * Returns back the BBD symbol if represents BBD.
       */
      asset_symbol_type get_paired_symbol() const;

      asset_symbol_space space()const;
      uint8_t decimals()const
      {  return uint8_t( asset_num & 0x0F );    }
      void validate()const;

      friend bool operator == ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num == b.asset_num);   }
      friend bool operator != ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num != b.asset_num);   }
      friend bool operator <  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <  b.asset_num);   }
      friend bool operator >  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >  b.asset_num);   }
      friend bool operator <= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <= b.asset_num);   }
      friend bool operator >= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >= b.asset_num);   }

      uint32_t asset_num = 0;
};

} } // dpay::protocol

FC_REFLECT(dpay::protocol::asset_symbol_type, (asset_num))

namespace fc { namespace raw {

// Legacy serialization of assets
// 0000pppp aaaaaaaa bbbbbbbb cccccccc dddddddd eeeeeeee ffffffff 00000000
// Symbol = abcdef
//
// NAI serialization of assets
// aaa1pppp bbbbbbbb cccccccc dddddddd
// NAI = (MSB to LSB) dddddddd cccccccc bbbbbbbb aaa
//
// NAI internal storage of legacy assets

template< typename Stream >
inline void pack( Stream& s, const dpay::protocol::asset_symbol_type& sym )
{
   switch( sym.space() )
   {
      case dpay::protocol::asset_symbol_type::legacy_space:
      {
         uint64_t ser = 0;
         switch( sym.asset_num )
         {
            case DPAY_ASSET_NUM_DPAY:
               ser = DPAY_SYMBOL_SER;
               break;
            case DPAY_ASSET_NUM_BBD:
               ser = BBD_SYMBOL_SER;
               break;
            case DPAY_ASSET_NUM_VESTS:
               ser = VESTS_SYMBOL_SER;
               break;
            default:
               FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
         }
         pack( s, ser );
         break;
      }
      case dpay::protocol::asset_symbol_type::smt_nai_space:
         pack( s, sym.asset_num );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
   }
}

template< typename Stream >
inline void unpack( Stream& s, dpay::protocol::asset_symbol_type& sym )
{
   uint64_t ser = 0;
   s.read( (char*) &ser, 4 );

   switch( ser )
   {
      case DPAY_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == DPAY_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = DPAY_ASSET_NUM_DPAY;
         break;
      case BBD_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == BBD_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = DPAY_ASSET_NUM_BBD;
         break;
      case VESTS_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == VESTS_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = DPAY_ASSET_NUM_VESTS;
         break;
      default:
         sym.asset_num = uint32_t( ser );
   }
   sym.validate();
}

} // fc::raw

inline void to_variant( const dpay::protocol::asset_symbol_type& sym, fc::variant& var )
{
   try
   {
      std::vector< variant > v( 2 );
      v[0] = sym.decimals();
      v[1] = sym.to_nai_string();
   } FC_CAPTURE_AND_RETHROW()
}

inline void from_variant( const fc::variant& var, dpay::protocol::asset_symbol_type& sym )
{
   try
   {
      auto v = var.as< std::vector< variant > >();
      FC_ASSERT( v.size() == 2, "Expected tuple of length 2." );

      sym = dpay::protocol::asset_symbol_type::from_nai_string( v[1].as< std::string >().c_str(), v[0].as< uint8_t >() );
   } FC_CAPTURE_AND_RETHROW()
}

} // fc
