file(GLOB HEADERS "include/dpay/account_by_key/*.hpp")

add_library( dpay_account_by_key
             account_by_key_plugin.cpp
             account_by_key_api.cpp
           )

target_link_libraries( dpay_account_by_key dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_account_by_key
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_account_by_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
