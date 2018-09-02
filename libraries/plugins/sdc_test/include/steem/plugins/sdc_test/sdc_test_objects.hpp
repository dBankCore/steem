#pragma once
#include <steem/chain/steem_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace steem { namespace plugins { namespace sdc_test {

using namespace std;
using namespace steem::chain;

#ifndef STEEM_SDC_TEST_SPACE_ID
#define STEEM_SDC_TEST_SPACE_ID 13
#endif

enum sdc_test_object_types
{
   sdc_token_object_type = ( STEEM_SDC_TEST_SPACE_ID << 8 )
};

class sdc_token_object : public object< sdc_token_object_type, sdc_token_object >
{
   public:
      template< typename Constructor, typename Allocator >
      sdc_token_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      id_type                 id;

      account_name_type       control_account;
      uint8_t                 decimal_places = 0;
      int64_t                 max_supply = STEEM_MAX_SHARE_SUPPLY;

      time_point_sec          generation_begin_time;
      time_point_sec          generation_end_time;
      time_point_sec          announced_launch_time;
      time_point_sec          launch_expiration_time;
};

typedef sdc_token_object::id_type sdc_token_id_type;

using namespace boost::multi_index;

struct by_control_account;

typedef multi_index_container<
   sdc_token_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< sdc_token_object, sdc_token_id_type, &sdc_token_object::id > >,
      ordered_unique< tag< by_control_account >,
         composite_key< sdc_token_object,
            member< sdc_token_object, account_name_type, &sdc_token_object::control_account >
         >
      >
   >,
   allocator< sdc_token_object >
> sdc_token_index;

} } } // steem::plugins::sdc_test

FC_REFLECT( steem::plugins::sdc_test::sdc_token_object,
   (id)
   (control_account)
   (decimal_places)
   (max_supply)
   (generation_begin_time)
   (generation_end_time)
   (announced_launch_time)
   (launch_expiration_time)
   )
CHAINBASE_SET_INDEX_TYPE( steem::plugins::sdc_test::sdc_token_object, steem::plugins::sdc_test::sdc_token_index )
