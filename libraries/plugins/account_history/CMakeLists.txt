file(GLOB HEADERS "include/dpay/account_history/*.hpp")

add_library( dpay_account_history
             account_history_plugin.cpp
           )

target_link_libraries( dpay_account_history dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
