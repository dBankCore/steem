file(GLOB HEADERS "include/dpay/account_statistics/*.hpp")

add_library( dpay_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( dpay_account_statistics dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)