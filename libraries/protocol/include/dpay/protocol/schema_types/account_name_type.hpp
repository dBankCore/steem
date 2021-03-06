
#pragma once

#include <dpay/schema/abstract_schema.hpp>
#include <dpay/schema/schema_impl.hpp>

#include <dpay/protocol/types.hpp>

namespace dpay { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   DPAY_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< dpay::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< dpay::protocol::account_name_type >
{
   static const char* name()
   {
      return "dpay::protocol::account_name_type";
   }
};

}
