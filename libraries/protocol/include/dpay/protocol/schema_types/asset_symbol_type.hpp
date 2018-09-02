
#pragma once

#include <dpay/schema/abstract_schema.hpp>
#include <dpay/schema/schema_impl.hpp>

#include <dpay/protocol/asset_symbol.hpp>

namespace dpay { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   DPAY_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< dpay::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
