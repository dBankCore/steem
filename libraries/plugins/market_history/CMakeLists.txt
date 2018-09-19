file(GLOB HEADERS "include/dpay/market_history/*.hpp")

add_library( dpay_market_history
             market_history_plugin.cpp
             market_history_api.cpp
           )

target_link_libraries( dpay_market_history dpay_chain dpay_protocol dpay_app )
target_include_directories( dpay_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   dpay_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)